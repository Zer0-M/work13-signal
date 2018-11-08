all : signal.o
	gcc -o sigtest signal.o
signal.o: signal.c
	gcc -c signal.c
run:
	./sigtest
clear:
	rm sigtest *.o interruptlog