#define _LC 130
#define _LCS 137
#define _LD 145
#define _LDS 155
#define _LE 166
#define _LF 175
#define _LFS 185
#define _LG 195
#define _LGS 207
#define _LA 220
#define _LAS 235
#define _LB 245

#define _MC 260
#define _MCS 275
#define _MD 290
#define _MDS 311
#define _ME 333
#define _MF 350
#define _MFS 370
#define _MG 390
#define _MGS 415
#define _MA 440
#define _MAS 470
#define _MB 490

#define _HC 520

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dos.h>

int main() {
    int notes[14] = {_MC, _MD, _MA, _ME, _MF, _MG, _LA, _LB, _LA, _LG, _LF, _LE, _LD, _LC};
    int x;
    for(x = 0; x < 14; x ++) {
        sound(notes[x]);
        delay(100); /* NOTE! THIS CRASHES WINDOWS 98 SOMETIMES */
    }
    sound(0);
    return 0;
}
