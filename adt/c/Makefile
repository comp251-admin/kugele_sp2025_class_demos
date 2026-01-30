CC=gcc
CFLAGS=-g -Wall

OBJS = 	person.o   \
				student.o  \
				main.o     \
       	# line eater

main: $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f *.o main
