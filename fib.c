#include <stdio.h>
#include "generateSine.c"

int main()
{
   int counter, termCount = 8, termOne = 0, termTwo = 1, nextTerm, scalingFactor = 50, notePitches[termCount];
 
   for ( counter = 0 ; counter < termCount ; counter++ )
   {
      if ( counter <= 1 )
      {
	 nextTerm = counter;     
      } else {
         nextTerm = termOne + termTwo;
         termOne = termTwo;
         termTwo = nextTerm;
      }
      notePitches[counter] = nextTerm * scalingFactor;
      printf("%d\n", notePitches[counter]); 
   }

   fillNotes(&notePitches[0], sizeof(notePitches));	

   return 0;
}
