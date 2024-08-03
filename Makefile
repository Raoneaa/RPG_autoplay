myprogram: main.o champion.o
	gcc main.o myfunctions.o -o myprogram
main.o: main.c champion.h
	gcc -c main.c -o main.o
champion.o: champion.c champion.h
	gcc -c champion.c -o champion.o
clean:
	rm -rf *.o
	rm myprogram