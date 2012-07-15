#include "generateSine.c"

int main(void)
{
    int notePitch[4] = {100, 150, 75, 125};
    int noteLength[4] = {1, 1, 1, 2};
    int noteCount = sizeof(notePitch) / sizeof(int);
    fillNotes(&notePitch[0], &noteLength[0], noteCount);
    return 0;
}

