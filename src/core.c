#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <soundio/soundio.h>


#define _SAMPLERATE 44100
#define _VOLUME_RATIO 25801 // ratio between the bit depth 8 and 16 (0..100..127), (100 * 100% / 127) * 32768 / 100%
#define _NUMBER_PI 3.14159265358979323846
#define _NUMBER_PI_DOUBLE 6.2831853071796 // pi * 2, saves calculation time


/*
const enum SoundIoBackend soundioBackend = SoundIoBackendPulseAudio;

void playSound(){
    struct SoundIo *soundio = soundio_create();
    
    soundio_connect(soundio):soundio_connect_backend(soundio, soundioBackend);
    soundio_flush_events(soundio);
    
    int selected_device_index = -1;
    if (device_id) {
        int device_count = soundio_output_device_count(soundio);
        for (int i = 0; i < device_count; i += 1) {
            struct SoundIoDevice *device = soundio_get_output_device(soundio, i);
            if (strcmp(device->id, device_id) == 0 && device->is_raw == raw) {
                selected_device_index = i;
                break;
            }
        }
    } else {
        selected_device_index = soundio_default_output_device_index(soundio);
    }
    
    struct SoundIoDevice *device = soundio_get_output_device(soundio, selected_device_index);
    if (!device) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    fprintf(stderr, "Output device: %s\n", device->name);
    if (device->probe_error) {
        fprintf(stderr, "Cannot probe device: %s\n", soundio_strerror(device->probe_error));
        return 1;
    }
}
*/

int main(int argumentCount, char **arguments){
    int16_t* buffer = malloc(_SAMPLERATE * 16);
    double frequency = 440;
    
    // calculate the sample, simple sin wave
    double piSamplerateFrequency = _NUMBER_PI_DOUBLE / _SAMPLERATE * frequency;
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; ++currentIteration){
        buffer[currentIteration] = sin(currentIteration * piSamplerateFrequency) * _VOLUME_RATIO;
    }
    
    // print the sample to the console
    for(long currentIteration = 0; currentIteration < _SAMPLERATE; ++currentIteration){
        printf("%d\n", buffer[currentIteration]);
    }
    
    return 0;
}
