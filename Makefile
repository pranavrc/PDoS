CFLAGS = -Wall -g
all:
	cc sample.c -o rendered/sample generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile
	cc fib.c -o rendered/fib generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile
	cc insertionsort.c -o rendered/insertionsort generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile
	cc selectionsort.c -o rendered/selectionsort generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile
	cc bubblesort.c -o rendered/bubblesort generateSine.h /lib64/libm.so.6 -lportaudio -lsndfile
clean:
	rm -f rendered/sample rendered/fib rendered/factorial rendered/insertionsort rendered/selectionsort
