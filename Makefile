INCLUDE_PATH = -IC:\msys64\mingw64\include\SDL2
LIB_PATH = -LC:\msys64\mingw64\lib
LIBS = -lmingw32 -lSDL2main -lSDL2
FLAGS = -w -Wl,-subsystem,windows
SDL = $(INCLUDE_PATH) $(LIB_PATH) $(FLAGS) $(LIBS)

bin/Metodo_biseccion: src/main.cpp src/ventana.cpp | bin
	g++ $< -o $@ $(INCLUDE_PATH) $(LIB_PATH) $(FLAGS) $(LIBS)
	./$@

bin:
	mkdir bin

.PHONY: clean
clean:
	rm -rf bin