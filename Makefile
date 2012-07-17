CFLAGS = -Wall -g
all:
	cc sample.c -o sample generateSine.h -lportaudio
	cc fib.c -o fib generateSine.h -lportaudio
clean:
	rm -f sample fib
