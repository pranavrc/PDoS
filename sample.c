#include "generateSine.c"

int main(void)
{
    int notePitch[7] = {100, 150, 75, 125, 150, 110, 175};
    fillNotes(&notePitch[0], sizeof(notePitch));
  
    return 0;
}

