CC=gcc

array1: array.c
	$(CC) array.c -o array

clean:
	rm array1
