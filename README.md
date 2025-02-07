# Sorting Algorithm Visualizer in C

This project is a **terminal-based sorting algorithm visualizer**, developed in **C** using the **ncurses** library. It provides a real-time visual representation of different sorting algorithms.

## 📌 Implemented Sorting Algorithms
- 🔹 **Quick Sort**
- 🔹 **Selection Sort**
- 🔹 **Insertion Sort**
- 🔹 **Merge Sort**

## ⚙️ Requirements
Before compiling, ensure you have the **ncurses** library installed.

### 📥 Installing ncurses  
#### 🐧 **Linux (Ubuntu/Debian)**  

```bash
sudo apt-get install libncurses5-dev
```

#### 🍏 **macOS**  

```bash
brew install ncurses

```
#### 🖥️ Windows  

Use WSL or Cygwin to compile with ncurses.


## 🔨 Compilation & Execution  

This project includes a Makefile for easy compilation.

### ✅ Compile the Program  
```bash
make
```

### ▶️ Run the Program  
```bash
./sort_visualizer

### 🧹 Clean Up Compiled Files  
```bash
make clean
```

## 🎮 How to Use

    1. Run the program to access the interactive menu.
    2. Select a sorting algorithm by pressing the corresponding number (1-4).
    3. Watch the sorting process in real-time.
    4. Press any key to return to the menu and choose another algorithm.
