#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <soundio/soundio.h>
#include <stdlib.h>

//#define _SAMPLERATE 44100
#define _SAMPLERATE 12
#define _VOLUME_RATIO 25801 // ratio between the bit depth 8 and 16 (0..100..127), (100 * 100% / 127) * 32768 / 100%
#define _NUMBER_PI 3.14159265358979323846
#define _NUMBER_PI_DOUBLE 6.2831853071796 // pi * 2, saves calculation time






int main(int argumentCount, char **arguments){
    //int16_t buffer[_SAMPLERATE];
    int16_t* buffer = malloc(_SAMPLERATE * sizeof(int16_t));
    int16_t* tmp;
    tmp = buffer-1;
    double frequency = 1;
    
    // calculate the sample, simple sin wave
    double piSamplerateFrequency = _NUMBER_PI_DOUBLE / _SAMPLERATE * frequency;
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; ++currentIteration){
        //y = y * math.tanh(x * 0.01 / _ATTACK)
        buffer[currentIteration] = sin(currentIteration * piSamplerateFrequency) * _VOLUME_RATIO;
    }
    
    // print the sample to the console
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; currentIteration++){
        printf("%d %d %d\n", buffer[currentIteration], *(buffer +currentIteration), *(++tmp) );
    }
    
    free(buffer);
    return 0;
}
