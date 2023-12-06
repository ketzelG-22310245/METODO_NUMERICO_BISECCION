## METODO_NUMERICO_BISECCION

El método se basa en el teorema del valor intermedio, conocido como método de la bisección, búsqueda binaria, partición de intervalos o de Bolzano.

![](https://mastersagan.files.wordpress.com/2021/11/1-metodo-biseccion-1.jpg)

Es un tipo de búsqueda incremental en el que:

- el intervalo se divide siempre en la mitad.
- Si la función cambia de signo sobre un intervalo, se evalúa el valor de la función 
en el punto medio.
- La posición de la raíz se determina en el punto medio del sub-intervalo, izquierdo o derecho,  dentro del cual ocurre un cambio de signo.
- el proceso se repite hasta obtener una mejor aproximación

La gráfica muestra el proceso en forma animada, observe la forma en que progresivamente se acercan los puntos [a,b], donde se mantienen valores con signo diferente entre f(a) y f(b).

Observamos la gráfica para una sola iteración y asi describir mejor el método.
Para la primera iteración se tiene como procedimiento que la función tiene un cambio de signo en el intervalo [a,b].

En intervalo se divide en la mitad, representado por el punto c, obteniendo el sub-intervalo izquierdo [a,c] o sub-intervalo derecho [c,b].

El sub-intervalo que contiene la función con un cambio de signo, se convierte en el nuevo intervalo a ser analizado en la siguiente iteración

![](http://blog.espol.edu.ec/analisisnumerico/files/2017/10/biseccion01.png)

# Librerias del programa

El proyecto se desarrollo sobre MinGW64 utilizando Msys2

Para la instalacion de Msys2 seguir el siguiente tutorial:                       https://code.visualstudio.com/docs/cpp/config-ming

Libreria SDL2:                                                                   https://packages.msys2.org/package/mingw-w64-x86_64-SDL2?repo=mingw64             pacman -S mingw-w64-x86_64-SDL2

Libreria SDL2_mixer (Ya que no esta inluida en SDL2):                            https://packages.msys2.org/package/mingw-w64-x86_64-SDL2_mixer?repo=mingw64         pacman -S mingw-w64-x86_64-SDL2_mixer

# Autores
Ketzel Gibran Carrillo Ibarra 22310245                                             Jose Gerardo Guerrero Lopez 22310244