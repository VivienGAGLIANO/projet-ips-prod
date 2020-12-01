CC = g++
CFLAGS = -Wall -Wextra -larmadillo -lm
OBJECTS = obj/MathTools.o obj/Schrodinger.o obj/Poly.o obj/Basis.o
TESTS = tests/*.h
TARGET = main

all: $(TARGET)
run: all
	./$(TARGET)

$(TARGET): $(TARGET).cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp headers/%.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: obj/%.o

tests/%.cpp: tests/%.h
	cxxtestgen --error-printer $^ -o $@

tests/%: tests/%.cpp
	$(CC) -o $@ $<

.PHONY: tests
tests: $(TESTS) obj/Poly.o obj/Basis.o
	cxxtestgen --error-printer -o tests/TestMandatory00.cpp tests/TestMandatory00.h
	cxxtestgen --error-printer -o tests/TestMandatory01.cpp tests/TestMandatory01.h
	cxxtestgen --error-printer -o tests/TestMandatory02.cpp tests/TestMandatory02.h
	cxxtestgen --error-printer -o tests/TestMandatory03.cpp tests/TestMandatory03.h
	$(CC) $(CFLAGS) -o tests/TestMandatory00 tests/TestMandatory00.cpp obj/Poly.o
	$(CC) $(CFLAGS) -o tests/TestMandatory01 tests/TestMandatory01.cpp obj/Basis.o
	$(CC) $(CFLAGS) -o tests/TestMandatory02 tests/TestMandatory02.cpp obj/Basis.o
	$(CC) $(CFLAGS) -o tests/TestMandatory03 tests/TestMandatory03.cpp obj/Basis.o
	./tests/TestMandatory00
	./tests/TestMandatory01
	./tests/TestMandatory02
	./tests/TestMandatory03

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
	rm -f tests/TestMandatory00 tests/TestMandatory01 tests/TestMandatory02 tests/TestMandatory03
	rm -f tests/TestMandatory00.cpp tests/TestMandatory01.cpp tests/TestMandatory02.cpp tests/TestMandatory03.cpp

re: clean all
