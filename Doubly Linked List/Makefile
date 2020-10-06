CC = g++
CFLAGS = -Wall
DEPS = dll.h
OBJ = main.o dll.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

leaks:
	valgrind --leak-check=yes ./go

clean:
	rm *.o go
