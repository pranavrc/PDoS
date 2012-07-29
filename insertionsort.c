#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200

int *insertionSort(int list[], int length, float lengthOfBeat)
{
	int i, j, temp;
	int eachNote = 0;
	int *noteList;

	noteList = (int*) malloc(sizeof(int));

	while(!eachNote) {
		for (i = 0; i < length; i++) {
			j = i;
			while ((j > 0) && (list[j] < list[j-1])) {
				temp = list[j];
				list[j] = list[j-1];
				list[j-1] = temp;

				noteList = realloc(noteList, (eachNote + 1) * sizeof(int));

				noteList[eachNote] = list[j] * SCALING_FACTOR;
				noteList[eachNote + 1] = list[j - 1] * SCALING_FACTOR;

				eachNote = eachNote + 2;

				playNote(list[j] * SCALING_FACTOR, lengthOfBeat);
				playNote(list[j - 1] * SCALING_FACTOR, lengthOfBeat);

				j = j - 1;
	        	}
		}
		break;
	}
	
	int note;

	for (note = 0; note < eachNote; note++) {
		printf("%d\n", noteList[note]);
	}

	dumpToFile(noteList, eachNote * sizeof(int), lengthOfBeat, "sounds/insertionSort.wav");

	int *listptr;

	listptr = &list[0];

	return listptr;
}

int main()
{
	populateArray(insertionSort);
	return 0;
}

