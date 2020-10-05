CC = g++
CFLAGS = -Wall
DEPS = sll.h
OBJ = main.o sll.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

leaks:
	valgrind --leak-check=yes ./go

clean:
	rm *.o go
