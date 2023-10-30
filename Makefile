CC = gcc
CFLAGS = -Wall -Wextra -g -O2
OBJS = algorithms.o main.o

# Targets
a.out: $(OBJS)
	$(CC) -o $@ $^

algorithms.o: algorithms.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o a.out

.PHONY: clean