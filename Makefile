CC = g++
CFLAGS = -Wall -Wextra
OBJECTS = MathTools.o Schrodinger.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: src/%.cpp headers/%.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
re: clean all
