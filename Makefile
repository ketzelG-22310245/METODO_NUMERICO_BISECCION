bin/Metodo_biseccion: src/main.cpp | bin
	g++ $< -o $@
	./$@

bin:
	mkdir bin

.PHONY: clean
clean:
	rm -rf bin