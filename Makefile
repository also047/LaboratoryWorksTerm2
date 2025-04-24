# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra
INCLUDES = -I./$(LAB_DIR)/lib

# Находим все папки Lab1, Lab2, ...
LABS = $(wildcard Lab*)

# Цель по умолчанию: собираем все LabX.exe
all: $(foreach lab, $(LABS), $(lab)/$(notdir $(lab)).exe)

# Правило для сборки каждого LabX.exe
%/%.exe: %/%.c $(wildcard %/lib/*.c)
 $(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Очистка
clean:
 rm -f $(foreach lab, $(LABS), $(lab)/$(notdir $(lab)).exe)

.PHONY: all clean