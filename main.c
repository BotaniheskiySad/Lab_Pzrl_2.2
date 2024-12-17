#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_o.h"
#include "text_o.h"

void print_comands() 
{  
  printf("Ошибка!\n");
  printf("./sed_simplified input.txt -r “old text” “new text”\n"); 
  printf("./sed_simplified input.txt -d “text to delete”\n");
  printf("./sed_simplified input.txt -i -f “insert text front”\n");
  printf("./sed_simplified input.txt -i -b “insert text back”\n");
}
int main(argc, char *avrg[])
{
  if (atgc < 3)
  {
    print_comands();
    return 1;
  }
  
}


