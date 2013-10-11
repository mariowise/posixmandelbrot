INCLUDE = -I src/
OUTPUT = ./bin/mandelbrot.run

main: build/main.o build/getpar.o build/edacor.o build/mandelbrot.o
	@printf "Building modules..."
	@gcc -o $(OUTPUT) build/*.o -lm
	@printf "[OK]\nDone! Here is the program " 
	@printf $(OUTPUT)
	@printf "\n"

build/main.o: src/main.c
	@echo "  cc src/main.c"
	@gcc -c -o build/main.o src/main.c $(INCLUDE)

# Helpers
build/getpar.o: src/getpar.c
	@echo "  cc src/getpar.c"
	@gcc -c -o build/getpar.o src/getpar.c $(INCLUDE)

build/edacor.o: src/edacor.c
	@echo "  cc src/edacor.c"
	@gcc -c -o build/edacor.o src/edacor.c $(INCLUDE)

# Mandelbrot
build/mandelbrot.o: src/mandelbrot.c
	@echo "  cc src/mandelbrot.c"
	@gcc -c -o build/mandelbrot.o src/mandelbrot.c $(INCLUDE)

# Runners
run:
	@clear
	@$(OUTPUT) -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f output.txt

runp:
	@clear
	@$(OUTPUT) -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.0001 -f output.txt -t 4

# Clean task
clean:
	@echo "Limpiando"
	@rm build/*