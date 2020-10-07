CC = g++
CFLAGS = -Wall -Wextra
OBJECTS = obj/MathTools.o obj/Schrodinger.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp headers/%.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
re: clean all
