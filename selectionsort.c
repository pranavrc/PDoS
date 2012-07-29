#include <stdio.h>
#include "generateSine.c"

#define SCALING_FACTOR 200

int *selectionSort(int list[], int length, float lengthOfBeat)
{
	int i, j, temp, min;
	int eachNote = 0;
	int *noteList;
	
	noteList = (int*) malloc(sizeof(int));

	while(!eachNote) {
		for (i = 0; i < length; i++) {
			min = i;
			
			for (j = i + 1; j < length; j++) {
				playNote(list[j] * SCALING_FACTOR, lengthOfBeat);
				
				noteList = realloc(noteList, (eachNote + 1) * sizeof(int));
				noteList[eachNote] = list[j] * SCALING_FACTOR;

				eachNote++;				

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

				noteList = realloc(noteList, (eachNote + 2) * sizeof(int));

				noteList[eachNote] = list[i] * SCALING_FACTOR;
				noteList[eachNote + 1] = list[min] * SCALING_FACTOR;

				eachNote += 2;
			}
		}	
		break;
	}

	int note;

	for (note = 0; note < eachNote; note++) {
		printf("%d\n", noteList[note]);
	}

	dumpToFile(noteList, eachNote * sizeof(int), lengthOfBeat, "sounds/selectionSort.wav");

	int *listptr;

	listptr = &list[0];

	return listptr;
}

int main()
{
	populateArray(selectionSort);
	return 0;
}


