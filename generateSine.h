#ifndef GENERATESINE_H
#define GENERATESINE_H

#include <stdio.h>
#include <math.h>
#include "portaudio.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)

static int patestCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData );

void buzzer_set_freq(int frequency);

void buzzer_beep(int frequency, int msecs);

int buzzer_start(void);

int buzzer_stop();

void fillNotes(int *notePitch);

#endif
