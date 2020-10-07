CC = g++
CFLAGS = -Wall
DEPS = queue.h cll.h
OBJ = main.o cll.o queue.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

leaks:
	valgrind --leak-check=yes ./go

clean:
	rm *.o go
