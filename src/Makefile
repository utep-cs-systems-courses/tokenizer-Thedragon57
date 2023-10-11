CFLAGS =-g -O3

all: tokenizer

tokenizer.o: history.h
history.o: tokenizer.h history.h

tokenizer: tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
