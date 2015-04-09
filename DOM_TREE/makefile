G = g++
objetos = main.o

main : $(objetos)
	$(G) -o $@ $^
	
main.o : main.cpp
	$(G) -c -o $@ $^
	
clean :
	rm -rf main *.o
