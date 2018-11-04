#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <soundio/soundio.h>


#define _SAMPLERATE 44100
#define _VOLUME_RATIO 25801 // ratio between the bit depth 8 and 16 (0..100..127), (100 * 100% / 127) * 32768 / 100%
#define _NUMBER_PI 3.14159265358979323846
#define _NUMBER_PI_DOUBLE 6.2831853071796 // pi * 2, saves calculation time


int main()
{
    int16_t buffer[_SAMPLERATE];
    double frequency = 440;
    
    
    
    
    
    // calculate the sample, simple sin wave
    double piSamplerateFrequency = _NUMBER_PI_DOUBLE / _SAMPLERATE * frequency;
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; currentIteration++){
        //y = y * math.tanh(x * 0.01 / _ATTACK)
        buffer[currentIteration] = sin(currentIteration * piSamplerateFrequency) * _VOLUME_RATIO;
    }
    
    // print the sample to the console
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; currentIteration++){
        //printf("%d\n", buffer[currentIteration]);
    }
    
    return 0;
}
