#ifndef TEXT_O_H
#define TEXT_O_H

void replace_text(const char *filename, const char *old_text,const char* new_text);
void delete_lines(const char *filename, const char *pattern);
void add_text(const char *filename, const char *text, const char *position);
#endif

