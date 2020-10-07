CC = g++
CFLAGS = -Wall
DEPS = stack.h sll.h
OBJ = main.o sll.o stack.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

leaks:
	valgrind --leak-check=yes ./go

clean:
	rm *.o go
