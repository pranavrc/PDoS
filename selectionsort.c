#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200

int *selectionSort(int list[], int length, float lengthOfBeat)
{
	int i, j, temp, min;

	for (i = 0; i < length; i++) {
		min = i;
		for (j = i + 1; j < length; j++) {
			playNote(list[j] * SCALING_FACTOR, lengthOfBeat);
			if (list[j] < list[min]) {
				min = j;
			}
		}

		if (min != j) {
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
			playNote(list[i] * SCALING_FACTOR, lengthOfBeat);
			playNote(list[min] * SCALING_FACTOR, lengthOfBeat);
		}
	}

	int *listptr;

	listptr = &list[0];

	return listptr;
}

int main()
{
	populateArray(selectionSort);
	return 0;
}


