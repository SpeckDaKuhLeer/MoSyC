/*
 * PortAudio Licence
 *
 * This program uses the PortAudio Portable Audio Library.
 * For more information see: http://www.portaudio.com
 * Copyright (c) 1999-2000 Ross Bencina and Phil Burk
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "portaudio.h"


#define _SAMPLERATE 44100
#define _VOLUME_RATIO 25801 // ratio between the bit depth 8 and 16 (0..100..127), (100 * 100% / 127) * 32768 / 100%
#define _NUMBER_PI 3.14159265358979323846
#define _NUMBER_PI_DOUBLE 6.2831853071796 // pi * 2, saves calculation time


int main()
{
    int16_t buffer[_SAMPLERATE];
    double frequency = 440;
    
    
    PaError err;
    err = Pa_Initialize();
    if(err != paNoError){
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    }
    err = Pa_Terminate();
    if(err != paNoError){
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    }
    
    
    
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
