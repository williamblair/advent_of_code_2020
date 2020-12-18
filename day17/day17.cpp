/*
 * Day 17 - Conway Cubes
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <vector>

#define MINDIM -30
#define MAXDIM 30
#define DIMSIZE ((MAXDIM) - (MINDIM))
bool cubeStates[DIMSIZE+1][DIMSIZE+1][DIMSIZE+1];

#if 1
#define INPUT_LEN 8
#define INPUT_WIDTH 8
const char* input[INPUT_LEN] =
{
"....###.",
"#...####",
"##.#.###",
"..#.#...",
"##.#.#.#",
"#.######",
"..#..#.#",
"######.#"
};
#endif

#if 0
#define INPUT_LEN 4
#define INPUT_WIDTH 4
const char* input[INPUT_LEN] =
{
"....",
"..#.",
"...#",
".###"
};
#endif

typedef struct StateCoord
{
    int x;
    int y;
    int z;
    bool active;
} StateCoord;

static inline long long coord2index(const int coord)
{
    return (long long)(coord - (MINDIM));
}

static inline void initCubeStates()
{
    memset(cubeStates, 0, sizeof(cubeStates));
}

static bool needsToFlip(const int x, const int y, const int z)
{
    long long xIndex = coord2index(x);
    long long yIndex = coord2index(y);
    long long zIndex = coord2index(z);
    if (xIndex < 0 || xIndex > DIMSIZE ||
        yIndex < 0 || yIndex > DIMSIZE ||
        zIndex < 0 || zIndex > DIMSIZE)
    {
        printf("ERROR - INVALID INDEX\n");
        exit(0);
    }
    bool curActive = cubeStates[xIndex][yIndex][zIndex];

    if (curActive)
    {
        size_t neighborActiveCount = 0;
        int xDiff;
        int yDiff;
        int zDiff;
        int testX;
        int testY;
        int testZ;
        for (xDiff = -1; xDiff <= 1; xDiff++)
        {
            for (yDiff = -1; yDiff <= 1; yDiff++)
            {
                for (zDiff = -1; zDiff <= 1; zDiff++)
                {
                    if (xDiff == 0 && yDiff == 0 && zDiff == 0)
                    {
                        continue;
                    }

                    testX = xIndex + xDiff;
                    testY = yIndex + yDiff;
                    testZ = zIndex + zDiff;

                    if (testX < 0 || testX > DIMSIZE ||
                        testY < 0 || testY > DIMSIZE ||
                        testZ < 0 || testZ > DIMSIZE)
                    {
                        continue;
                    }

                    if (cubeStates[testX][testY][testZ])
                    {
                        neighborActiveCount++;
                    }
                }
            }
        }

        if (neighborActiveCount == 2 || neighborActiveCount == 3)
        {
            // does NOT need to turn inactive (stay active)
            return false;
        }
        else
        {
            // needs to become inactive
            return true;
        }
    }
    // space is not currently active
    else
    {
        size_t neighborActiveCount = 0;
        int xDiff;
        int yDiff;
        int zDiff;
        int testX;
        int testY;
        int testZ;
        for (xDiff = -1; xDiff <= 1; xDiff++)
        {
            for (yDiff = -1; yDiff <= 1; yDiff++)
            {
                for (zDiff = -1; zDiff <= 1; zDiff++)
                {
                    if (xDiff == 0 && yDiff == 0 && zDiff == 0)
                    {
                        continue;
                    }

                    testX = xIndex + xDiff;
                    testY = yIndex + yDiff;
                    testZ = zIndex + zDiff;

                    if (testX < 0 || testX > DIMSIZE ||
                        testY < 0 || testY > DIMSIZE ||
                        testZ < 0 || testZ > DIMSIZE)
                    {
                        continue;
                    }

                    if (cubeStates[testX][testY][testZ])
                    {
                        neighborActiveCount++;
                    }
                }
            }
        }

        if (neighborActiveCount == 3)
        {
            // needs to become active (flip)
            return true;
        }
        else
        {
            // remain inactive
            return false;
        }
    }

    printf("ERROR  - we should not reach here!\n");
    exit(0);
    return false;
}

static void runCycle()
{
    int x;
    int y;
    int z;
    std::vector<StateCoord> coordsToUpdate;
    for (x = MINDIM; x <= MAXDIM; x++)
    {
        for (y = MINDIM; y <= MAXDIM; y++)
        {
            for (z = MINDIM; z <= MAXDIM; z++)
            {
                if (needsToFlip(x, y, z))
                {
                    StateCoord coord;
                    coord.x = x;
                    coord.y = y;
                    coord.z = z;
                    coord.active = !cubeStates[coord2index(x)]
                                              [coord2index(y)]
                                              [coord2index(z)];
                    coordsToUpdate.push_back(coord);
                }
            }
        }
    }

    for (const auto& state : coordsToUpdate)
    {
        cubeStates[coord2index(state.x)][coord2index(state.y)][coord2index(state.z)] = state.active;
    }
}

static void loadInput()
{
    int z = 0;
    int x;
    int y;

    for (x = 0; x < INPUT_WIDTH; x++)
    {
        for (y = 0; y < INPUT_LEN; y++)
        {
            int xcoord = x - (INPUT_WIDTH / 2 - 1);
            int ycoord = -y + (INPUT_LEN / 2 - 1);
            int zcoord = 0;
            bool isActive = input[y][x] == '#';

            cubeStates[coord2index(xcoord)][coord2index(ycoord)][coord2index(zcoord)] = isActive;
        }
    }
}

static inline size_t countActive()
{
    size_t count = 0;
    int x;
    int y;
    int z;
    for (x = MINDIM; x <= MAXDIM; x++)
    {
        for (y = MINDIM; y <= MAXDIM; y++)
        {
            for (z = MINDIM; z <= MAXDIM; z++)
            {
                count += (size_t)cubeStates[coord2index(x)]
                    [coord2index(y)]
                [coord2index(z)];
            }
        }
    }

    return count;
}

int main(void)
{
    size_t i;
    initCubeStates();
    loadInput();

    for (i = 0; i < 6; i++)
    {
        runCycle();
    }

    printf("Active count: %lu\n", countActive());

    return 0;
}
