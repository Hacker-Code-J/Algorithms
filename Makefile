CC = gcc
CFLAGS = -Wall -Wextra -g -O2
OBJS = algorithms.o rotation.o measure.o main.o

# Targets
a.out: $(OBJS)
	$(CC) -o $@ $^

measure.o: measure.c
	$(CC) $(CFLAGS) -c -o $@ $<

rotation.o: rotation.c
	$(CC) $(CFLAGS) -c -o $@ $<

algorithms.o: algorithms.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.txt a.out
	(cd Views && rm -f *.txt)

leak:
	valgrind --leak-check=full --show-leak-kinds=all ./a.out

speed-rot:
	@echo "Visualizing ..."
	./a.out > speed.txt
	mv speed.txt Views/
	(cd Views && python3 compare_rotation.py)
	@echo "Completed."

.PHONY: clean