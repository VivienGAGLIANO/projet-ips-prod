CC = g++
CFLAGS = -Wall -Wextra -larmadillo -lm
OBJECTS = obj/MathTools.o obj/Schrodinger.o obj/Poly.o
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
	cxxtestgen --error-printer -o tests/TestMandatory00.cpp tests/TestMandatory00.h
	g++ -o tests/testHermit tests/testHermit.cpp
	g++ -o tests/testSchrodinger tests/testSchrodinger.cpp
	g++ -o tests/TestMandatory00 tests/TestMandatory00.cpp obj/Poly.o
	./tests/testHermit
	./tests/testSchrodinger
	./tests/TestMandatory00

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
	rm -f tests/testHermit tests/testSchrodinger tests/TestMandatory00 tests/testHermit.cpp tests/testSchrodinger.cpp tests/TestMandatory00.cpp

re: clean all
