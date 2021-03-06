Mandelbrot sobre procesos LINUX y memoria compartida POSIX
==========================================================

El siguiente programa da cuenta de una implementación realizada en C para el algoritmo Mandelbrot sobreun plano complejo, procesos concurrentes en el sistema LINUX y memoria compartida POSIX entre los procesos, para construir una imagen de un fractal Mandelbrot a color. El programa escribe la imagen en formato de byte, la cual puede ser procesada con MATLAB u OCTAVE para construir gráficamente. A continuación se muestra el procedimiento en OCTAVE para visualizar la imagen.

	f = fopen(’nombrearchivo.raw’, ’r’)
	M = fread(f, double’);
	M = reshape(M, P, Q);
	imagesc(M)


Compilacion
-----------

Para compilar es necesario ubicarse en el directorio del programa, y ejectuar el comando [make]. Se recomienza la instalación de la librería [build-essential].

El programa ejecutable se encontrará en la carpeta bin, bajo el nombre [mandelbrot.run].


Como ejecutar el programa
-------------------------

Para ejecutar el programa es necesario hacer uso de los parámetros p, a, b, c, d, s, f, t (opcional). En donde los parámetros tienen los siguientes formatos y significados.

	-p: (int) Corresponde a la profundidad de búsqueda del algoritmo Mandelbrot, también conocido como número de iteraciones (depth).
	-a: (double) Límite inferior del componente real
	-b: (double) Límite inferior del componente complejo
	-c: (double) Límite superior del componente real
	-d: (double) Límite superior del componente complejo
	-s: (double) Step o ancho de muestreo para discretizar sobre una matriz
	-f: (string) Nombre del archivo de salida
	-t: (int) Corresponde al número de procesos que de forma concurrente realizarán las tareas (opcional, si no se proporciona se asume iguala 1)

Un ejemplo de ejecución del programa se muestra a continuación.

	./mandelbrot.run -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f salida.raw
	
El siguiente ejemplo muestra la ejecución del mismo problema, pero con 8 procesos.

	./mandelbrot.run -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f salida.raw -t 8
