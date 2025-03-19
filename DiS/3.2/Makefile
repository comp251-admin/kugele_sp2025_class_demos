CC=clang
CFLAGS=-Wall -Wno-unused-parameter -Werror
OBJS=gdb_main.o gdb_util.o gdb_mystery_op.o

all: $(OBJS)
	$(CC) -o run $^

gdb_main.o:
	$(CC) -g -c gdb_main.c

gdb_util.o:
	$(CC) -g -c gdb_util.c

gdb_mystery_op.o:
	$(CC) -c gdb_mystery_op.c

clean:
	rm -f run *.o
