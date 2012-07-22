CFLAGS = -Wall -g
all:
	cc sample.c -o rendered/sample generateSine.h -lportaudio
	cc fib.c -o rendered/fib generateSine.h -lportaudio
clean:
	rm -f rendered/sample rendered/fib
