CC=g++
CPPFLAGS=-g
SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)

all: main

$(OBJS): %.o:%.c
	$(CC) $(CPPFLAGS) -c -o $@ $^

main: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm main *.o
