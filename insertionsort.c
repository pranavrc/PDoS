#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200
float lengthOfBeat;

int *insertionSort(int list[], int length)
{
	int i, j, temp;

	for (i = 0; i < length; i++) {
		j = i;
		while ((j > 0) && (list[j] < list[j-1])) {
			temp = list[j];
			list[j] = list[j-1];
			list[j-1] = temp;
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
	int j;
	printf("Number of notes: ");
	scanf("%d", &j);
	printf("\nLength of each beat(in seconds): ");
	scanf("%f", &lengthOfBeat);
	int unorderedList[j];
	int k = j;
	while (j > 0) {
		srand(time(NULL));
		unorderedList[k - j] = rand() % j;
		j--;
	}
	int *orderedListPtr;
        orderedListPtr = insertionSort(unorderedList, sizeof(unorderedList)/sizeof(int));
	int i;
	for (i = 0; i < sizeof(unorderedList)/sizeof(int); i++) {
		printf("%d\t", *(orderedListPtr + i));
	}
	printf("\n");

	return 0;
}

