# Nombre del ejecutable
TARGET = sort_visualizer

# Compilador
CC = gcc

# Flags de compilación (-Wall muestra advertencias, -lncurses enlaza la librería ncurses)
CFLAGS = -Wall -lncurses

# Archivos fuente
SRC = visualizer.c

# Regla para compilar el programa
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

# Regla para limpiar archivos compilados
clean:
	rm -f $(TARGET)

