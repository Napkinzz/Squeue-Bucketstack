CC = gcc
CFLAGS = -Wall -std=c99

client: bucketstack.o bucketstack_client.o
	$(CC) $(CFLAGS) -o bucketstack bucketstack.o bucketstack_client.o

test: bucketstack.o test.o
	$(CC) $(CFLAGS) -o test bucketstack.o test.o

test2: bucketstack.o test2.o
	$(CC) $(CFLAGS) -o test2 bucketstack.o test2.o

bucketstack.o:	bucketstack.c bucketstack.h
	$(CC) $(CFLAGS) -c bucketstack.c

bucketstack_client.o: bucketstack_client.c bucketstack.h
	$(CC) $(CFLAGS) -c bucketstack_client.c

test.o: test.c bucketstack.h
	$(CC) $(CFLAGS) -c test.c

test2.o: test2.c bucketstack.h
	$(CC) $(CFLAGS) -c test2.c

clean:
	rm -f test bucketstack test test2 *.o
