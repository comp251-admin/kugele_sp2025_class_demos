CC = gcc
CFLAGS = -g

route: route.o intersect.o
	$(CC) $(CFLAGS) -o $@ $^

route.o: route.c
	$(CC) $(CFLAGS) -c $^ -o $@

intersect.o: intersect.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o *.gch route 
