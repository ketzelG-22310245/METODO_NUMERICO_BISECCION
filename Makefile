INCLUDE_PATH = -Iinclude
LIBS = -lmingw32 -lSDL2main -lSDL2
FLAGS = -w -Wl,-subsystem,windows 

SRCS = src/main.cpp 
EXE = bin/Metodo_biseccion


$(EXE): $(SRCS) include/*.hpp
	g++ $(SRCS) -o $@ $(INCLUDE_PATH) $(FLAGS) $(LIBS)

run : $(EXE)
	./$(EXE)