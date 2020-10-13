CC = g++
CFLAGS = -Wall -Wextra -larmadillo -lm
OBJECTS = obj/MathTools.o obj/Schrodinger.o obj/Hermit.o
TARGET = main
WEIGHTS_N = 20

all: headers/GaussHermitWeights.h $(TARGET)
run: all
	./$(TARGET)

headers/GaussHermitWeights.h: generate_gausshermit_weights.py
	./generate_gausshermit_weights.py $(WEIGHTS_N)

$(TARGET): $(TARGET).cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp headers/%.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: obj/%.o

.PHONY: clean re
clean:
	rm -f $(OBJECTS) $(TARGET) *.out
re: clean all
