/*
 * Day 13 - bus arrival time
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define ull unsigned long long

#if 1
#define INPUT_LEN 62
#define LARGEST_INDEX 44
const ull input[62] = 
{
13,
0,
0,
0,
0,
0,
0,
37,
0,
0,
0,
0,
0,
449,
0,
29,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
19,
0,
0,
0,
23,
0,
0,
0,
0,
0,
0,
0,
773,
0,
0,
0,
0,
0,
0,
0,
0,
0,
41,
0,
0,
0,
0,
0,
0,
17
};
#endif

#if 0
#define INPUT_LEN 4
#define LARGEST_INDEX 3
const ull input[4] = 
{
    17, 0, 13, 19
};
#endif

#if 0
#define INPUT_LEN 4
#define LARGEST_INDEX 3
const ull input[4] = 
{
    1789,37,47,1889
};
#endif

#if 0
#define INPUT_LEN 5
#define LARGEST_INDEX 0
const ull input[5] = 
{
67,7,0,59,61
};
#endif

#if 0
#define INPUT_LEN 5
#define LARGEST_INDEX 0
const ull input[5] = 
{
67,0,7,59,61
};
#endif

#if 0
#define INPUT_LEN 4
#define LARGEST_INDEX 0
const ull input[5] = 
{
67,7,59,61
};
#endif

static ull vals[INPUT_LEN];
static ull diffs[INPUT_LEN];
static ull actualLen = 0;

static void getValsAndDiffs()
{
    size_t i;
    size_t lastI = 0;
    size_t actualIndex = 0;
    for (i = 0; i < INPUT_LEN; i++)
    {
        if (input[i] != 0)
        {
            vals[actualIndex] = input[i];
            diffs[actualIndex] = i - lastI;
            lastI = i;
            actualIndex++;
        }
    }
    actualLen = actualIndex;
}

static inline ull lcm(const ull a,
                      const ull b)
{
    ull max = (a > b) ? a : b;
    ull val = max;
    while (!(val % a == 0 && val % b == 0))
    {
        val += max;
    }
    printf("lcm %llu, %llu: %llu\n", a, b, val);
    return val;
}

static bool timeIsValid(ull startTime)
{
    ull i;
    //printf("Checking time %llu\n", startTime);
    for (i = 0; i < INPUT_LEN; i++, startTime++)
    {
        if (input[i] == 0)
        {
            continue; // 'x'
        }
        if (startTime % input[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    size_t i;
    ull time;
    ull timeIncr = 1;
    ull curVal;
    ull valIndex = 0;
    ull baseDiff = 0;
    bool foundTime = false;

    getValsAndDiffs();
    printf("Actual len: %llu\n", actualLen);
    for (i = 0; i < actualLen; i++)
    {
        printf("Val, diff: %llu, %llu\n", vals[i], diffs[i]);
    }

    curVal = vals[0];
    for (time = 2; !foundTime; time += timeIncr)
    {
        if (timeIsValid(time))
        {
            printf("Valid time: %llu\n", time);
            return 0;
        }
        if (valIndex < actualLen - 1)
        {
            if (((time + baseDiff) % curVal == 0) &&
                ((time + baseDiff + diffs[valIndex+1]) % vals[valIndex+1] == 0))
            {
                printf("Found change, time: %llu\n", time);
                timeIncr = lcm(timeIncr, vals[valIndex+1]);
                curVal = vals[valIndex+1];
                baseDiff += diffs[valIndex+1];
                valIndex++;
                printf("Timeincr changed to %llu\n", timeIncr);
                //printf("Base diff changed to %llu\n", baseDiff);
                if (valIndex >= actualLen)
                {
                    printf("WARNING - REACHED END!\n");
                }
            }
        }
    }

    return 0;
}

