INCLUDE = -I src/

main: build/main.o build/getpar.o build/mandelbrot.o
	@printf "Building modules..."
	@gcc -o ./bin/mandelbrot.run build/*.o
	@printf "[OK]\nDone! Here is the program ./build/mandelbrot.run\n"

build/main.o: src/main.c
	@echo "  cc src/main.c"
	@gcc -c -o build/main.o src/main.c $(INCLUDE)

build/getpar.o: src/getpar.c
	@echo "  cc src/getpar.c"
	@gcc -c -o build/getpar.o src/getpar.c $(INCLUDE)

build/mandelbrot.o: src/mandelbrot.c
	@echo "  cc src/mandelbrot.c"
	@gcc -c -o build/mandelbrot.o src/mandelbrot.c $(INCLUDE)

clean:
	@echo "Limpiando"
	@rm build/*