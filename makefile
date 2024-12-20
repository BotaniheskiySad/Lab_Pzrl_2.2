CC = gcc
CFLAGS = -O3 -g
TARGET = sed_simplified
SOURCES = main.c text_o.c file_o.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
 $(CC) $(CFLAGS) $^ -o $@

%.o: %.c
 $(CC) $(CFLAGS) -c $< -o $@

clean:
 rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
 ./$(TARGET) input.txt -r "old" "new"
 ./$(TARGET) input.txt -d "delete this"
 ./$(TARGET) input.txt -i -f ">> "
 ./$(TARGET) input.txt -i -b " << "

.PHONY: clean run
