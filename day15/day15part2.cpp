/*
 * Day 15 - rambunctious recitation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <vector>
#include <algorithm>
#include <map>

#if 1
#define INPUT_LEN 6
int64_t input[6] = 
{
18,11,9,0,5,1
};
#endif

#if 0
#define INPUT_LEN 3
int64_t input[3] = 
{
0,3,6
};
#endif

class MapEntry
{
public:
    int64_t first;
    int64_t second;

    MapEntry()
    {
        first = -1;
        second = -1;
    }

    MapEntry(int64_t first, int64_t second)
    {
        this->first = first;
        this->second = second;
    }

    MapEntry(const MapEntry& other)
    {
        first = other.first;
        second = other.second;
    }

    MapEntry& operator=(MapEntry& other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }
};

// key = the spoken number,
// val = the last 2 indices it was spoken
std::map<int64_t, MapEntry> spoken;

static inline void setVal(const int64_t val, const int64_t index)
{
    if (spoken.count(val) == 0)
    {
        MapEntry dummy(-1,-1);
        spoken[val] = dummy;
        spoken[val].first = -1;
        spoken[val].second = index;
    }
    else if (spoken[val].first == -1)
    {
        spoken[val].first = index;
    }
    else
    {
        spoken[val].second = spoken[val].first;
        spoken[val].first = index;
    }
}

int main(void)
{
    int64_t lastSpoken;
    size_t i;
    MapEntry dummy(-1,-1);
    spoken[0] = dummy;
    for (i = 0; i < INPUT_LEN; i++)
    {
        //spoken[input[i]] = dummy;
        setVal(input[i], i+1);
    }
    lastSpoken = input[INPUT_LEN-1];

    //for (i = INPUT_LEN+1; i <= 2020; i++)
    for (i = INPUT_LEN+1; i <= 30000000; i++)
    {
        if (spoken.count(lastSpoken) == 0 ||
            spoken[lastSpoken].first == -1)
        {
            //spoken[0].first = i;
            setVal(0, i);
            lastSpoken = 0;
        }
        else
        {
            int64_t newVal = spoken[lastSpoken].first - 
                             spoken[lastSpoken].second;
            setVal(newVal, i);
            lastSpoken = newVal;
            printf("Turn %lu says %ld\n", i, newVal);
        }
    }

    return 0;
}

