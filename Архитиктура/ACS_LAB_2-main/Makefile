prog := dgemv
prog_objs := dgemv.o

CC := gcc
CFLAGS := -Wall -g
LDFLAGS :=

.PHONY: all clean

all: $(prog)

$(prog): $(prog_objs)
	$(CC) -o $@ $^ $(LDFLAGS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

dgemv.o: dgemv.c

clean:
	@rm -rf *.o $(prog)
