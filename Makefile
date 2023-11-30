INCLUDE_PATH = -IC:\msys64\mingw64\include\SDL2
LIB_PATH = -LC:\msys64\mingw64\lib
LIBS = -lmingw32 -lSDL2main -lSDL2
FLAGS = -w -Wl,-subsystem,windows
SDL = $(INCLUDE_PATH) $(LIB_PATH) $(FLAGS) $(LIBS)
SRCS = src/main.cpp src/ventana.cpp src/biseccion.cpp
EXE = bin/Metodo_biseccion

all: $(EXE)

$(EXE): $(SRCS) include/*.hpp
	g++ $(SRCS) -o $@ $(SDL)
	./$@

%.o: %.cpp
	g++ -c $< -o $@ $(INCLUDE_PATH) $(FLAGS)

bin:
	mkdir -p bin

clean:
	rm -f $(SRCS) $(EXE)

.PHONY: all clean
.PHONY: run-%