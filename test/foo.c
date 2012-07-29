#include <stdio.h>
#include "../generateSine.c"

int main()
{
int j, k;
int noteArray[10];
for (j = 0; j < 10; j++) {
	noteArray[j] = (j + 1) * 100;
}

dumpToFile(noteArray, sizeof(noteArray), 10, "foo.wav");

return 1;
}
