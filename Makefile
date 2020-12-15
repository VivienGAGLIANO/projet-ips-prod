CC = g++
CFLAGS = -g -Wall -Wextra -larmadillo -lm
OBJECTS = obj/MathTools.o obj/Poly.o obj/Basis.o obj/NaiveRho.o obj/OptimizedRho.o
TESTS = tests/TestMandatory00 tests/TestMandatory01 tests/TestMandatory02 tests/TestMandatory03 tests/TestNaiveRho
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

tests/%: tests/%.cpp $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: tests
tests: $(TESTS) $(OBJECTS)
	for test in $(TESTS); do $$test; done

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
	rm -f $(TESTS) tests/*.cpp

re: clean all
