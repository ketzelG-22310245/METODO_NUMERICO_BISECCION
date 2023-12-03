LIBS = -lmingw32 -lSDL2main -lSDL2
INCLUDE_PATH = -Iinclude

SRCS = src/main.cpp src/BisectionMethod.cpp src/NumericalMethod.cpp
EXE = bin/METODO_NUMERICO_BISECCION

bin/METODO_NUMERICO_BISECCION: $(SRCS)
	g++ $(SRCS) -o $@  $(INCLUDE_PATH) $(LIBS)

run: $(EXE)
	./$(EXE)
