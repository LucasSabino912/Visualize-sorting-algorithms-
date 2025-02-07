#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // usleep()
#include <ncurses.h>

#define ARRAY_SIZE 20 

int arr[ARRAY_SIZE]; // Global array

void drawArray(int highlight1, int highlight2) {
    clear();  
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i == highlight1 || i == highlight2)
            attron(A_REVERSE);
        for (int j = 0; j < arr[i]; j++)
            mvprintw(ARRAY_SIZE - j, i * 2, "||");
        attroff(A_REVERSE);
    }
    refresh();
    usleep(100000);
}

// **Selection Sort**
void selectionSort() {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            drawArray(i, j);
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        drawArray(i, min_idx);
    }
}

// **Insertion Sort**
void insertionSort() {
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            drawArray(j, j + 1);
            j--;
        }
        arr[j + 1] = key;
        drawArray(j + 1, i);
    }
}

// **Merge Sort**
void merge(int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        drawArray(k - 1, mid);
    }
    while (i < n1) arr[k++] = L[i++], drawArray(k - 1, mid);
    while (j < n2) arr[k++] = R[j++], drawArray(k - 1, mid);
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

// **Quick Sort**
int partition(int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        drawArray(j, high);
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            drawArray(i, j);
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    drawArray(i + 1, high);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

// Select the algorithm
void menu() {
    int choice;
    while (1) {
        clear();
        mvprintw(2, 5, "Select a sorting algorithm:");
        mvprintw(4, 7, "1. Quick Sort");
        mvprintw(5, 7, "2. Selection Sort");
        mvprintw(6, 7, "3. Insertion Sort");
        mvprintw(7, 7, "4. Merge Sort");
        mvprintw(8, 7, "5. exit");
        refresh();
        choice = getch();
        if (choice == '5') break;

        // Initialize the array with random values
        for (int i = 0; i < ARRAY_SIZE; i++)
            arr[i] = rand() % ARRAY_SIZE + 1;
        
        switch (choice) {
            case '1': quickSort(0, ARRAY_SIZE - 1); break;
            case '2': selectionSort(); break;
            case '3': insertionSort(); break;
            case '4': mergeSort(0, ARRAY_SIZE - 1); break;
            default: continue;
        }

        mvprintw(ARRAY_SIZE + 2, 5, "Press any key to continue...");
        refresh();
        getch();
    }
}

int main() {
    initscr();  
    curs_set(0);  
    menu();
    endwin();  
    return 0;
}
