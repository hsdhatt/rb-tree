CC=cc
CFLAGS= -Wall -c

all: rbt 

rbt: pretty_print rotate height main rules
	$(CC) height.o pretty_print.o rotate.o main.o rules.o -o rbt -lm

main: main.o
	$(CC) $(CFLAGS) main.c

height: height.o
	$(CC) $(CFLAGS) height.c

pretty_print: pretty_print.o
	$(CC) $(CFLAGS) pretty_print.c

rotate: rotate.o
	$(CC) $(CFLAGS) rotate.c

rules: rules.o
	$(CC) $(CFLAGS) rules.c

clean:
	rm *.o rbt
