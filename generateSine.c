#include "generateSine.h"

typedef struct
{
    uint32_t total_count;
    uint32_t up_count;

    uint32_t counter;
    uint32_t prev_freq;
    uint32_t freq;
} paTestData;

//volatile int freq = 0;

/* This routine will be called by the PortAudio engine when audio is needed.
** It may called at interrupt level on some machines so don't do anything
** that could mess up the system like calling malloc() or free().
*/
static int patestCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
    paTestData *data = (paTestData*)userData;
    uint8_t *out = (uint8_t*)outputBuffer;
    unsigned long i;
    uint32_t freq = data->freq;

    (void) timeInfo; /* Prevent unused variable warnings. */
    (void) statusFlags;
    (void) inputBuffer;

    for( i=0; i<framesPerBuffer; i++ )
    {
        if(data->up_count > 0 && data->total_count == data->up_count) {
            *out++ = 0x00;
            continue;
        }
        data->total_count++;

        if(freq != data->prev_freq) {
            data->counter = 0;
        }

        if(freq) {
            int overflow_max = SAMPLE_RATE / freq;
            uint32_t data_cnt = data->counter % overflow_max;
            if(data_cnt > overflow_max/2)
                *out++ = 0xff;
            else {
                *out++ = 0x00;
            }
            data->counter++;
        }
        else {
            data->counter = 0;
            *out++ = 0;
        }
        data->prev_freq = freq;
    }

    return paContinue;
}

static PaStream *stream;
static paTestData data;


void buzzer_set_freq(int frequency)
{
    data.up_count = 0; // do not stop!
    data.freq = frequency;
}

void buzzer_beep(int frequency, int msecs)
{
    data.total_count = 0;
    data.up_count = SAMPLE_RATE * msecs / 1000;
    data.freq = frequency;
}

int buzzer_start(void)
{
    PaStreamParameters outputParameters;

    PaError err;
    int i;

    err = Pa_Initialize();
    if( err != paNoError ) goto error;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    outputParameters.channelCount = 1;       /* stereo output */
    outputParameters.sampleFormat = paUInt8; /* 32 bit floating point output */
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(
        &stream,
        NULL, /* no input */
        &outputParameters,
        SAMPLE_RATE,
        FRAMES_PER_BUFFER,
        paClipOff,      /* we won't output out of range samples so don't bother clipping them */
        patestCallback,
        &data );
    if( err != paNoError ) goto error;

    err = Pa_StartStream( stream );
    if( err != paNoError ) goto error;

    return err;
error:
    Pa_Terminate();
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
    return err;

}

int buzzer_stop() 
{
    PaError err = 0;
    err = Pa_StopStream( stream );
    if( err != paNoError ) goto error;

    err = Pa_CloseStream( stream );
    if( err != paNoError ) goto error;

    Pa_Terminate();

    return err;
error:
    Pa_Terminate();
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
    return err;
}

void fillNotes(int *notePitch, int notePitchSize)
{
    int counter;
    int eachNote;
    int numberofBars;
    srand(time(NULL));
    int barLength = 2 * (rand() % 4 + 1);
    int halfBar = barLength / 2;
    int noteCount = notePitchSize / sizeof(int);
    float beat[noteCount];

    for (eachNote = 0; eachNote < noteCount; eachNote += 2) {
	    beat[eachNote] = (float)rand() / ((float)RAND_MAX/halfBar);
	    beat[eachNote + 1] = halfBar - beat[eachNote];
    }
    
    buzzer_start();
    for (numberofBars = 1; numberofBars <= 1; numberofBars++) {
	    for (counter = 0; counter < noteCount; counter++) {
		    buzzer_set_freq(*(notePitch + counter));
		    usleep(beat[counter] * 1000000);
	    }
    }
    buzzer_stop();
}

void playNote(int note, float time)
{
	buzzer_start();
	buzzer_set_freq(note);
	usleep(time * 1000000);
	buzzer_stop();
}

void populateArray(int* (*function)(int *, int, float))
{
	int j;
	float lengthOfBeat;
	printf("Number of notes: ");
	scanf("%d", &j);
	printf("\nLength of each beat(in seconds): ");
	scanf("%f", &lengthOfBeat);
	int unorderedList[j];
	int k = j;
	while (j > 0) {
		//srand(time(NULL));
		//unorderedList[k - j] = rand() % j;
		unorderedList[j] = k - j;
		j--;
	}
	int *orderedListPtr;
        orderedListPtr = (*function)(unorderedList, sizeof(unorderedList)/sizeof(int), lengthOfBeat);
	int i;
	for (i = 0; i < sizeof(unorderedList)/sizeof(int); i++) {
		printf("%d\t", *(orderedListPtr + i));
	}
	printf("\n");
}

void dumpToFile(int noteList[], int arraySize, float lengthOfBeat, char *filename)
{
	SNDFILE *file;
	SF_INFO sfinfo;
	int SAMPLE_COUNT = SAMPLE_RATE * lengthOfBeat;
	int j;
	long int k;
	int *buffer;
	int p, q;
	float noteValue[arraySize/sizeof(int)];

	if (! (buffer = malloc (2 * arraySize * SAMPLE_COUNT * sizeof (int))))
	{	
		printf ("Malloc failed.\n");
		exit (0);
	}

	memset (&sfinfo, 0, sizeof (sfinfo));

	sfinfo.samplerate	= SAMPLE_RATE;
	sfinfo.frames		= SAMPLE_COUNT;
	sfinfo.channels		= 1;
	sfinfo.format		= (SF_FORMAT_WAV | SF_FORMAT_PCM_24);

	if (! (file = sf_open (filename, SFM_WRITE, &sfinfo)))
	{	printf ("Error : Not able to open output file.\n");
	}

	for (j = 0; j < arraySize/sizeof(int); j++) {
		printf("\n%d", noteList[j]); 
		noteValue[j] = (float)(noteList[j]/44100.00);
		printf("\n%f", noteValue[j]);
	}

	for (j = 0; j < (arraySize/sizeof(int)); j++)
	{
		p = j * SAMPLE_COUNT;
		q = (j + 1) * SAMPLE_COUNT;

		for (k = p; k < q; k++) {
			buffer [k] = AMPLITUDE * sin(noteValue[j] * 2 * k * M_PI);
		}
	}

	if (sf_write_int (file, buffer, sfinfo.channels * (arraySize/sizeof(int)) * SAMPLE_COUNT) != sfinfo.channels * SAMPLE_COUNT)
		puts (sf_strerror (file));

	sf_close (file);
}

