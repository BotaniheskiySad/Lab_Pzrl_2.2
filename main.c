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
  char *filename = argv[1];
if (strcmp(argv[2], "-r") == 0 && argc == 5) {
        replace_text(filename, argv[3], argv[4]);
    } else if (strcmp(argv[2], "-d") == 0 && argc == 4) {
        delete_lines(filename, argv[3]);
    } else if (strcmp(argv[2], "-i") == 0 && argc == 5) {
        if (strcmp(argv[3], "-f") == 0) {
            add_text(filename, argv[4], 1);
        } else if (strcmp(argv[3], "-b") == 0) {
            add_text(filename, argv[4], 0);
        } else {
            print_usage();
            return 1;
        }
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
  
}


