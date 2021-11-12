CC=gcc
CFLAGS=-Wall


%.out: %.c
	$(CC) $(CFLAGS) $< -o $@


run: randomchar.out
	./randomchar.out

clean:
	rm -f *.out