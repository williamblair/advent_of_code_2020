/*
 * Day 13 - bus arrival time
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define INPUT_LEN 62
static const size_t baseTime = 1002576;
const char* input[62] = 
{
"13","x","x","x","x","x","x","37","x","x","x","x","x","449","x","29","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","19","x","x","x","23","x","x","x","x","x","x","x","773","x","x","x","x","x","x","x","x","x","41","x","x","x","x","x","x","17"
};

static bool parseNumber(const char* str, size_t* res)
{
    if (str[0] == 'x')
    {
        return false;
    }

    sscanf(str, "%lu", res);
    return true;
}

static size_t getMinArrival(size_t val)
{
    size_t actualTime = baseTime / val;
    actualTime = actualTime * val;
    if (baseTime % val != 0)
    {
        actualTime += val;
    }

    return actualTime;
}

int main(void)
{
    size_t i;
    size_t minTime = SIZE_MAX;
    size_t minId = 0;
    size_t val = 0;
    size_t time;
    for (i = 0; i < INPUT_LEN; i++)
    {
        if (!parseNumber(input[i], &val))
        {
            continue; // 'x'
        }

        time = getMinArrival(val);
        if (time < minTime)
        {
            minTime = time;
            minId = val;
        }
    }
    printf("Min time, id, diff*id: %lu, %lu, %lu\n", 
            minTime, 
            minId,
            (minTime - baseTime)*minId);
    return 0;
}

