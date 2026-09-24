# --- Variabili del Compilatore ---
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./include

# --- Directory ---
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# --- File Sorgente ---
# Trova tutti i file .c nelle rispettive cartelle
SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

# --- File Oggetto (.o) ---
# Sostituisce la cartella src/ o test/ con build/ e l'estensione .c con .o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# --- Nome dell'Eseguibile ---
TARGET = $(BUILD_DIR)/test_runner

# --- Regole Principali ---
# Il target di default (quello eseguito digitando solo "make")
all: $(TARGET)

# Come costruire l'eseguibile finale mettendo insieme i file .o
$(TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Come compilare i file .c di src/ in .o in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Come compilare i file .c di test/ in .o in build/
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regola per creare la cartella build se non esiste
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# --- Regole di Utilità ---
# Pulisce tutti i file generati (esegui con "make clean")
clean:
	rm -rf $(BUILD_DIR)

# Compila ed esegue automaticamente il test (esegui con "make run")
run: all
	./$(TARGET)

# Impedisce conflitti se ci sono file reali chiamati "all", "clean" o "run"
.PHONY: all clean run