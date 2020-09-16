CC = g++
CFLAGS = -Wall -Wextra
OBJECTS = MathTools.o Schrodinger.o
TARGET = main


%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ $<



.PHONY: clean
clean:
	rm -r $(OBJECTS) $(TARGET)