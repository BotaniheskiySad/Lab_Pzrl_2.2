#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_o.h"

void replace_text(const char* filename, const char* old_text, const char* new_text) {
    FILE* file = fopen(filename, "r");
    FILE* temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        perror("ошибка открытия");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    char buffer[1024];
    while (fgets(line, sizeof(line), file)) {
        char* pos = NULL;
        buffer[0] = '\0';

        while ((pos = strstr(line, old_text))) {
            *pos = '\0';
            strncat(buffer, line, sizeof(buffer) - strlen(buffer) - 1);
            strncat(buffer, new_text, sizeof(buffer) - strlen(buffer) - 1);
            strncpy(line, pos + strlen(old_text), sizeof(line) - 1);
        }

        strncat(buffer, line, sizeof(buffer) - strlen(buffer) - 1);
        fprintf(temp, "%s", buffer);
    }

    fclose(file);
    fclose(temp);

    if (rename("temp.txt", filename) != 0) {
        perror("ошибка названия ");
        exit(EXIT_FAILURE);
    }
}

void delete_lines(const char* filename, const char* pattern) {
    FILE* file = fopen(filename, "r");
    FILE* temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        perror("ошибка открытия");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (!strstr(line, pattern)) {
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);
    fclose(temp);

    if (rename("temp.txt", filename) != 0) {
        perror("ошибка переназвания файла");
        exit(EXIT_FAILURE);
    }
}

void add_text(const char* filename, const char* text, const char* position) {
    FILE* file = fopen(filename, "r");
    FILE* temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    char line[1024];

    // Добавить текст в начало
    if (strcmp(position, "-I") == 0) {
        fprintf(temp, "%s\n", text);
    }

    // Обработать каждую строку
    while (fgets(line, sizeof(line), file)) {
        fprintf(temp, "%s", line);
    }

    // Добавить текст в конец
    if (strcmp(position, "-b") == 0) {
        fprintf(temp, "%s\n", text);
    }

    fclose(file);
    fclose(temp);

    if (rename("temp.txt", filename) != 0) {
        perror("Ошибка переназвания");
        exit(EXIT_FAILURE);
    }
}
