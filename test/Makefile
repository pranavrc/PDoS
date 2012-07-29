CFLAGS = -Wall -g
all:
	cc foo.c -o foo ../generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile

clean:
	rm foo
