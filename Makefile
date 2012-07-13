CFLAGS = -Wall -g
all:
	cc generate.c -o generate generateSine.h -lportaudio
clean:
	rm -f generate
