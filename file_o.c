#include <stdio.h>
#include <stdlib.h>
#include "filt_o.h"

FILE *open_file_read(const char *filename)
{
  FILE *file = fopen(filrname,"r");
  if (!file)
  {
    printf("ОШИБКА ОТКРЫТИЯ ФАЙЛА");
    return 1;
  }
  return file;
}
FILE *open_file_write(const char *filename)
{
  FILE *file = fopen(filename,"w");
  if (!file)
  {
    printf("ОШИБКА ОТКРЫТИЯ ФАЙЛА");
    return 1;
  }
  return file;
}
