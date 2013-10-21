INCLUDE = -I src/
OUTPUT = ./bin/mandelbrot.run

main: build/main.o build/getpar.o build/edacor.o build/mandelbrot.o build/mandelbrotp.o
	@printf "Building modules..."
	@gcc -o $(OUTPUT) build/*.o -lm -lrt
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

build/mandelbrotp.o: src/mandelbrotp.c
	@echo "  cc src/mandelbrotp.c"
	@gcc -c -o build/mandelbrotp.o src/mandelbrotp.c $(INCLUDE)

# Runners
run:
	@clear
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw
# @$(OUTPUT) -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f output.raw

	
runp:
	@clear
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 8
# @$(OUTPUT) -p 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f output.raw -t 4

testride:
	@clear
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 1
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 2
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 3
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 4
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 5
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 6
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 7
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 8
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 9
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 10
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 11
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 12
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 13
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 14
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 15
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 16
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 17
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 18
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 19
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 20
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 21
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 22
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 23
	@$(OUTPUT) -p 500 -a -0.748766713922161 -b 0.123640844894862 -c -0.748766707771757 -d 0.123640851045266 -s 0.000000000001 -f output.raw -t 24

# Clean task
clean:
	@echo "Limpiando"
	@rm build/*
