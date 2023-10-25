COMMON_OBJECTS = tokenizer.o history.o main.o
CFLAGS = -g -O3 -I../h
CC = cc

all: tokenizer
tokenizer.o: tokenizer.h
history.o: tokenizer.h history.h
main.o: tokenizer.h history.h

tokenizer: ${COMMON_OBJECTS}
	cc -v -o $@ $^ ${CFLAGS}
clean:
	rm -f *.o tokenizer
