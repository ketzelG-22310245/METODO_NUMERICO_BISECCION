CXX = g++
TARGET = bin/Metodo_biseccion
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC) | bin
	$(CXX) $< -o $@
	./$@

bin:
	mkdir bin

.PHONY: clean
clean:
	rm -rf bin