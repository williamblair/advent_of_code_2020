/*
 * Day 15 - rambunctious recitation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <vector>
#include <algorithm>

#if 1
#define INPUT_LEN 6
uint64_t input[6] = 
{
18,11,9,0,5,1
};
#endif

#if 0
#define INPUT_LEN 3
uint64_t input[3] = 
{
0,3,6
};
#endif

static bool findLast(const std::vector<uint64_t>& arr, const uint64_t val, uint64_t* resPos)
{
    ssize_t i;
    //printf("Arr size: %llu\n", arr.size());
    for (i = arr.size()-2; i >= 0; i--)
    {
        //printf("i: %llu\n", i);
        if (arr[i] == val)
        {
            printf("Found %llu at pos %lu\n", val, i);
            *resPos = i;
            return true;
        }
    }

    return false;
}

int main(void)
{
    uint64_t lastPos = 0;
    uint64_t lastSpoken = 0;
    size_t i;
    std::vector<uint64_t> spoken(input, input+INPUT_LEN);
    spoken.push_back(0);
    for (i = INPUT_LEN+1; i < 2020; i++)
    {
        lastSpoken = *spoken.rbegin();
        if (findLast(spoken, lastSpoken, &lastPos))
        {
            // has been said before
            //printf("%llu Said before\n", lastSpoken);
            uint64_t diff = (uint64_t)(spoken.size()-1 - lastPos);
            spoken.push_back(diff);
            lastSpoken = diff;
            printf("Turn %lu says %llu\n", i+1, diff);
        }
        else
        {
            // first time being said
            spoken.push_back(0);
            lastSpoken = 0;
            printf("Turn %lu says %llu\n", i+1, 0);
        }
    }
    return 0;
}

