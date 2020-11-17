CC = g++
CFLAGS = -Wall
DEPS = list.h iterator.h generic-list.h
OBJ = main.o list.o iterator.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

leaks:
	valgrind --leak-check=yes ./go

clean:
	rm *.o go
