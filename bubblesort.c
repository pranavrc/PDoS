#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200

int *bubbleSort(int list[], int length, float lengthOfBeat)
{
	int i, j, temp;
	int eachNote = 0;
	int *noteList;

	noteList = (int*) malloc(sizeof(int));

	while(!eachNote) {
		for (j = 0; j < length - 1; j++) {
			for (i = 0; i < length - j - 1; i++) {
				if (list[i] > list[i + 1]) {
					temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
					
					noteList = realloc(noteList, (eachNote + 1) * sizeof(int));
					
					noteList[eachNote] = list[i] * SCALING_FACTOR;
					noteList[eachNote + 1] = list[i + 1] * SCALING_FACTOR;

					eachNote = eachNote + 2;
	
					playNote(list[i] * SCALING_FACTOR, lengthOfBeat);
					playNote(list[i + 1] * SCALING_FACTOR, lengthOfBeat);
				}
			}
		}

		break;
	}

	int note;

	for (note = 0; note < eachNote; note++) {
		printf("%d\n", noteList[note]);
	}

	dumpToFile(noteList, eachNote * sizeof(int), lengthOfBeat, "sounds/bubbleSort.wav");

	int *listptr;

	listptr = &list[0];

	return listptr;
}

int main()
{
	populateArray(bubbleSort);
	return 0;
}

