#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200
float lengthOfBeat;

int *selectionSort(int list[], int length)
{
	int i, j, temp, min;

	for (i = 0; i < length; i++) {
		min = i;
		for (j = i + 1; j < length; j++) {
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
	int j;
	printf("Number of notes: ");
	scanf("%d", &j);
	printf("\nLength of each beat(in seconds): ");
	scanf("%f", &lengthOfBeat);
	int unorderedList[j];
	int k = j;
	while (j > 0) {
		srand(time(NULL));
		//unorderedList[k - j] = rand() % j;
		unorderedList[j] = k - j;
		j--;
	}
	int *orderedListPtr;
        orderedListPtr = selectionSort(unorderedList, sizeof(unorderedList)/sizeof(int));
	int i;
	for (i = 0; i < sizeof(unorderedList)/sizeof(int); i++) {
		printf("%d\t", *(orderedListPtr + i));
	}
	printf("\n");

	return 0;
}


