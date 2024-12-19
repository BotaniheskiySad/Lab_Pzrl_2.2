#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"
#include "text_operations.h"

void replace_text(const char *filename, const char *old_text, const char *new_text) {
    FILE *file = open_file_read(filename);
    FILE *temp = open_file_write("temp.txt");

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *pos = NULL;
        while ((pos = strstr(line, old_text))) {
            *pos = '\0';
            fprintf(temp, "%s%s", line, new_text);
            strcpy(line, pos + strlen(old_text));
        }
        fprintf(temp, "%s", line);
    }

    fclose(file);
    fclose(temp);

    rename("temp.txt", filename);
}

void delete_lines(const char *filename, const char *pattern) 
{
    FILE *file = open_file_read(filename);
    FILE *temp = open_file_write("temp.txt");

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (!strstr(line, pattern)) {
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);
    fclose(temp);

    rename("temp.txt", filename);
}

void add_text(const char *filename, const char *text, int is_front) {
    FILE *file = open_file_read(filename);
    FILE *temp = open_file_write("temp.txt");

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (is_front) {
            fprintf(temp, "%s%s", text, line);
        } else {
            line[strcspn(line, "\n")] = '\0'; // Удаляем '\n' в конце строки
            fprintf(temp, "%s%s\n", line, text);
        }
    }

    fclose(file);
    fclose(temp);

    rename("temp.txt", filename);
}
