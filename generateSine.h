#ifndef GENERATESINE_H
#define GENERATESINE_H

#include <stdio.h>
#include <math.h>
#include "portaudio.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sndfile.h>
#include <string.h>

#ifndef		M_PI
#define		M_PI		3.14159265358979323846264338
#endif

#define		SAMPLE_RATE			44100
#define		AMPLITUDE			(1.0 * 0x7F000000)
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

void fillNotes(int *notePitch, int notePitchSize);

void playNote(int note, float time);

void populateArray(int* (*function)(int *, int, float));

void dumpToFile(int noteList[], int arraySize, float lengthOfBeat, char *filename);

#endif
