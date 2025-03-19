CC = gcc
CFLAGS = -Wall

run: run.o util.o secrets.o
	$(CC) $(CFLAGS) -g -o $@ $^

run.o: run.c secrets.h util.h
	$(CC) $(CFLAGS) -g -c run.c -o $@

util.o: util.c secrets.h
	$(CC) $(CFLAGS) -g -c util.c -o $@

secrets.o: secrets.c
	$(CC) $(CFLAGS) -c secrets.c -o $@

clean:
	rm -f *.o *.gch run 
