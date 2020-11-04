CC = g++
CFLAGS = -Wall -Wextra -larmadillo -lm
OBJECTS = obj/MathTools.o obj/Schrodinger.o obj/Hermit.o
TARGET = main

all: $(TARGET)
run: all
	./$(TARGET)


$(TARGET): $(TARGET).cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp headers/%.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: obj/%.o

.PHONY: tests
tests: 
	cxxtestgen --error-printer -o tests/testHermit.cpp tests/test_hermit.h
	cxxtestgen --error-printer -o tests/testSchrodinger.cpp tests/test_schrodinger.h
	g++ -o tests/testHermit tests/testHermit.cpp
	g++ -o tests/testSchrodinger tests/testSchrodinger.cpp
	./tests/testHermit
	./tests/testSchrodinger

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
	rm -f tests/testHermit tests/testSchrodinger tests/testHermit.cpp tests/testSchrodinger.cpp

re: clean all
