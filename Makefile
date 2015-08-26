CC=gcc

array: array.c
	$(CC) array.c -o array

clean:
	rm array
