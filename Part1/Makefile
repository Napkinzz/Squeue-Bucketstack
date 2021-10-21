run: squeue.o squeue_client.o
	gcc -Wall -std=c99 -o squeue squeue.o squeue_client.c

test: squeue.o test.o
	gcc -Wall -std=c99 -o test test.o squeue.o

test2: squeue.o test2.o
	gcc -Wall -std=c99 -o test2 test2.o squeue.o

squeue_client.o: squeue_client.c squeue.h
	gcc -Wall -std=c99 -c squeue_client.c

squeue.o: squeue.c squeue.h
	gcc -Wall -std=c99 -c squeue.c

test.o: test.c squeue.h
	gcc -Wall -std=c99 -c test.c

test2.o: test2.c squeue.h
	gcc -Wall -std=c99 -c test2.c

clean:
	rm -f squeue_client squeue test test2 *.o
