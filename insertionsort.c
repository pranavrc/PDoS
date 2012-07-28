#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200

int *insertionSort(int list[], int length, float lengthOfBeat)
{
	int i, j, temp;

	for (i = 0; i < length; i++) {
		j = i;
		while ((j > 0) && (list[j] < list[j-1])) {
			temp = list[j];
			list[j] = list[j-1];
			list[j-1] = temp;
			playNote(list[j] * SCALING_FACTOR, lengthOfBeat);
			playNote(list[j - 1] * SCALING_FACTOR, lengthOfBeat);
			j = j - 1;
		}
	}

	int *listptr;

	listptr = &list[0];

	return listptr;
}

int main()
{
	populateArray(insertionSort);
	return 0;
}

