#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdint.h>

typedef uint8_t         u8;
typedef uint16_t        u16;
typedef uint32_t        u32;

typedef int8_t          s8;
typedef int16_t         s16;
typedef int32_t         s32;

typedef float           f32;
typedef double          f64;
#ifndef NULL
#define NULL ((void*)0)
#endif
#endif /* STD_TYPES_H_ */