#ifndef CONFIG_USER_H
#define CONFIG_USER_H


#include "config_common.h"
// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4


#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A \
    {                  \
        B12            \
    }
#define ENCODERS_PAD_B \
    {                  \
        B13            \
    }

#endif