CC = g++
CFLAGS = -Wall -Wextra
OBJECTS = MathTools.o Schrodinger.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)
