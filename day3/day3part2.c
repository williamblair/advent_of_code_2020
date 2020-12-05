/*
 * Day 3
 * Map trajectory/intersection reading
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char testMap[11][11] =
{
"..##.......",
"#...#...#..",
".#....#..#.",
"..#.#...#.#",
".#...##..#.",
"..#.##.....",
".#.#.#....#",
".#........#",
"#.##...#...",
"#...##....#",
".#..#...#.#"
};

char map[323][31] = 
{
".........#..##.##..............",
"#...#.#..#.....................",
".#...#..#...................#..",
"........##..#...#..............",
".#.#.....#..#..##......#.......",
"....#..#...#..##........#..##..",
"...#....##........#.......#.#..",
"....#................#...###..#",
"...#...#.#..#....#.......####.#",
".....#...#..........#...#..#.#.",
"....#..#............#.#.#.#..#.",
"..#....#.###..#............#...",
".....#.............#.#.........",
".#.##............##.........#..",
"...##...#..#....#.##..#.....#..",
"..............#.#.........#.##.",
"...........#.....##....##......",
".......#............#...#......",
"............#.#....#....#..#..#",
"....#................####......",
"...#.........................##",
"..........#........#.#.........",
"....#.#....#...........#......#",
"..#.#..##......##..##..#..#.#..",
"...#.....##......#.#.#.........",
".........#.#....#...#.#.#......",
".......#.......###.#.......#...",
"..#............##..#.......#...",
"...#....#......#...#...#...#...",
"......#..#.#.....##......#.....",
"...........##...##...#....#.##.",
"#.##..#.....##..#.#............",
".#.#.....##......#.##........#.",
"..#...#...#...#..........#...##",
"...##.........................#",
".....#......#.....##....#.....#",
"..#........#...................",
"#......#..#.#..#..#.#..#...#...",
"...............#..........#....",
".....#...........#......#....#.",
"........#..#...............#...",
".........#...#.......#.#..#...#",
"..#..#......#.##..........#....",
".#...#....#.....#.............#",
".##.....#.........#......#..#..",
"........#..##.......#......#...",
".......#.....###......#..#.....",
".......#.#.......#.............",
"...#................##.#.......",
"..##..#...#.#...#.#..#.#.#.##..",
".......#.#............#...#....",
"#...#.....#......#..........##.",
".#.......#......#.......#.#.#..",
".#.##.#.#...........#..........",
".......#.....#....#.#.##......#",
".###..#...#.............##.....",
"......#......#.................",
"##...#.#...##...#.#.....#....#.",
"#.............#....##...#....#.",
"#.#...#....#........#.###..##..",
"......#.........#......#.#.#.#.",
"..#.#.#.....#........#..#...#..",
"#.##....#.#......#...........#.",
".#.#.####.........#..#.##....##",
"......##...............#......#",
".......#.........#........#.#..",
"....#....#..#.##.........#..#..",
".#..........#.##....#.#..#.....",
"#..#.#............#..#....#.#.#",
"..................#..#.........",
"##..##.#....#.................#",
"..................#........#..#",
".....#.........#.......##......",
".....................#.#..#...#",
".....#.........#..........#.#..",
"...#.#..#..#.#.#.......#.......",
".....#.....#.#.........#.....##",
".............##....#....##.#...",
".#......#........##..#...###...",
"........#.......##.##.#......#.",
"..#....................#.##..#.",
"......#.......#..#....##.#.....",
"...#....#.......##...#.......#.",
".#.#..#.#..........##..........",
"....#.......##...........#.....",
"###....#.......#..#...#.....##.",
"...#......#.........#..#.#..#.#",
"#.........#..##.#..............",
".#.....#..##.#..#..###.....##.#",
"..........#..#....##.......#...",
".#..#.#...#...##.#..#.##.#.....",
"#....#...#........#......##....",
"..#.####....#.#........#....#..",
"#......#............#.#........",
"...#..#.......##...........#...",
".........#..#.#..#.###.#...#..#",
"..#....##.......#.............#",
"............#..#......#........",
"........#......#..............#",
"..#.#.#...........#............",
"...........#......##.#.#.......",
".#..........#...........#..#...",
".....#...#..#.........##...#...",
".......#....##....#.#.........#",
"..#.#......#.......#...##.#....",
".....#..........#........#.....",
"#.......#.......#............#.",
"..##.#.....#.##.#.#.#..#.......",
"..#...#.......#.###............",
".#...#..#....#...#...#..#....##",
".....#.....#...................",
".......................#......#",
"......#...##.........#...#..#..",
".....#..#.....#..............#.",
".#.##..#..#....................",
"....#..#...#....#.............#",
"..###..#...#......#.....#......",
"..#......###....#.....#.....###",
"...#.##..#...#.....#........#..",
".#.#...........##....#...#.##..",
".......#...##......#..#..#.....",
"#.............#..#...##.#..#..#",
"..........#......#.......#.....",
"...............#.#.#....#...#..",
"#.......#.#..#.....#........#..",
".#.#.#.......#..#.........##...",
"......#.....#.#....#...........",
"..#.....##.#........##.#......#",
"...###...#..#.........#........",
"....#...................#..#...",
".##........#...................",
"....#..#...........#.#.........",
".....#.......#...#....#.#......",
".........#...#.......#.#...#...",
".......#.#..#....#....#.......#",
"..#.............#..............",
".#...#..#.#.#..#............#..",
"...#.##.##..#..#...........##..",
"...........#...#..#.#........#.",
"....#...#.....#...#.#....#...#.",
".......#.#...##..#.............",
".......................#....#..",
"..#..#.....#...........#....#..",
".#..#...#.##........##....#....",
"#.....##.#.#.......#.....#...#.",
".#....#.......................#",
"#..##..###...#.........#.......",
"..##...#...#..........#....#...",
"......#..##......##.#.........#",
"................#........#..#..",
".....#.#..#.....#.......#..#...",
"..#..#.....#.......#..#..#...#.",
".#....#...#...#......##.....#..",
"....#........#...#......##....#",
"..#..........##......#......#..",
"#.#.....#.....#.......#........",
"...#...#......#....##.#..#...##",
"...#....#...#.#...........##...",
"#....##...#...#....#...........",
"...#.#..#...#..............##..",
"#..#..........##.#.#.....#.....",
"..#...#.........#.#..........#.",
"....#.....#..........#.........",
"........................#......",
".#.....#.#...###...#....#......",
"....##....#....#..#.##........#",
"..#........#.........#.......#.",
".....#.#......#...#...#........",
"........#..#.....#....###....#.",
"...........#..#.#....#.#....##.",
".......#.....##.#............#.",
"...............#........##.##..",
".............#...##......#...#.",
"#...##.#.......#......###.....#",
"..........#...#........#..#....",
"....#....................#...#.",
".#......#...#.......#....#.#...",
"....#.......................#..",
"#...#...#...#.##....##.........",
"..........#.#...##.#...#.......",
"..#...............#....#..#...#",
"#..#..#...#..#.........#...#...",
".....#..#..........#.##.#..##..",
"........#......##.....#........",
".#....#.#.........#...#..#.#...",
"....#..............##..........",
"#...............#..............",
"..###.........#....##.........#",
".........#.#....##........#...#",
"....#.#..#......#...#..........",
"...#.#.....#....#..#....#.#..#.",
"............#..#.....#...##....",
"...........#....#.#.#...#......",
"#...............#....###.......",
".........#.....##.#..#..#......",
"...#...##...###...............#",
".#......#.#.#.................#",
".........##..#............#....",
"..#..#.....#.....#.#...........",
".#......##............#.#....#.",
".#.##..##.##..#.........#.....#",
"...##.##......##.##......#.....",
"##.....#.#...#...#...#..#......",
"....................#......#...",
".....#.................#...###.",
"...........#..#.........#.#....",
"...#........#..#........#....#.",
"#................#......###...#",
".............##.#.....#.#......",
"...#...#.##..#........##.......",
"#..#.##...#....#.#.............",
".#.........#.#..#...........#..",
"....#...#.....#.#..........#...",
".#.#....###.......##.....#.##..",
".##....##......#......#.#....#.",
"..#...#.#........#...#..##.....",
"..............###..........##..",
"#....#..##.....#.....#.....#...",
"...#...#....................#..",
".#....#.#.....#.#..#..##.......",
"#...##..###......#.............",
"..........#.#....##.#........##",
"..#..#.....#...#....#.#.#......",
"#.....#........#..##.#.........",
"....#.....#..........##......#.",
"......#..#.....#........#.....#",
".....#..#....#...........#.##..",
".#....................#....#..#",
"........#..#...........#.......",
"#....#.#.......#........#.#..#.",
"........#.....#...#............",
"..#........#........#....#...#.",
".....##.......#..#..........#..",
"......#.#......###...#....##..#",
".#..#.............#.#..........",
"#.....##.#.#.#.#.#.....#.....#.",
".#..#.....#.......#.#.....#....",
"###....##...#.#...#..#......###",
".#................#.....#.##...",
"....##....#.#........###.#.#...",
"#.#....#........#.....#.......#",
"..........#..........#.##...#..",
"....#....#..##......#..#.......",
".....#..........#.##...........",
"##......#.#......#.##..........",
"##..........##.......##........",
"..#.....#....#.##..#..#..#.....",
"......###...#...........#...###",
"#..#.............##............",
"...#.###.....#..#.........#.#..",
"......#...............#...#.#..",
".....#...##.#...#.....#.#..#...",
"..#..#.#....#.#................",
"...............##.....#........",
"......#.#.....#...#.........#..",
"........#..#...#.#...#......#..",
"#...........#.......#...##...#.",
"........#.#...#..##..#.#...#...",
"..#....#...#......#..........##",
"..#..............##...##.#.....",
"...#....#..#....##.........#.#.",
".#.#....#..........#.......#...",
"...##....#.#....#....#.#...#...",
"..............#..##........#..#",
"..........#.#...##......#..#.#.",
"#...##..#......................",
".......#........##.#.#.#.......",
".........##..#.#.......####....",
"..#.............#..#........##.",
"##..#..#...#....#.....#...#..#.",
"..#.#...#.#.....#..............",
"..#....#....#..##...#.#........",
"##.....#..#...#................",
"#....#.....................#...",
"..............###.....#.#.#....",
"..#......##.#....#.#...##......",
"#...#.#......#...#.#......#....",
"....#...................##.#...",
".........##......#.....#.####..",
"##..#........#.....#......##..#",
"...#..#...#...#.............#..",
"#..#..#.#......###...#.........",
".......#.#..#........#....##..#",
"............#..##.....#.#.#....",
"#..#.....#.....#....##........#",
"......#..........##............",
".....#...#...........#.........",
"...........#....#...#....#.#...",
"....#.........##.##.......#....",
"......#....#...........#.##...#",
".##.#.#..##...#.....##.#...#...",
".......#.#....#...#...#....#...",
".#...##.#.#.....#..#....#......",
".#....###..#.......#......#...#",
"..#.#.........#.........#.....#",
".......#.#.##..#.#.......##..#.",
".##............#.........#....#",
".#...##.###..#........##.#..#..",
"..#........#.#.....##..##.#....",
"...........#...........#.....#.",
".#...######..##...#.....#......",
".#.##.#.......#......#......#..",
".#.....#.....#........#........",
"...#..#...#.##...#...........#.",
".......#.....#.......#.........",
"............#...###...........#",
"...#.......#.......##....#..#..",
"##.......#....#....####........",
".......#.#......#..........#..#",
"#.....##..#..#.....#....#...#..",
"#............#........##.......",
".#.#...#.............#..##.....",
".#....#..#.#......#.##.......##",
"...................##...##..###",
"..#.....#...#................#.",
"..#...#....#...#.#.#...#.....#.",
".....#............#....#...#..#",
".#.....#....#..#......#.#.....#",
"............#.#.....####.##....",
"....#......###....#...#....#...",
"#.....#..#.....#..#...#.......#",
"..#.#...#....#....##..#...##...",
".##..#..#..##....##...#........"
};

static int countWithSlope(char map[][31], 
                          const int numRows, const int numCols,
                          const int rowInc, const int colInc)
{
    int row = 0;
    int col = 0;
    size_t numIntersect = 0;
    for (row = 0; row < numRows; row += rowInc)
    {
        if (map[row][col] == '#')
        {
            numIntersect++;
        }
        col = (col + colInc) % numCols;
    }
    return numIntersect;
}

int main(void)
{
    unsigned long product;
    size_t i;

    // colInc, rowInc
    const int incs[5][2] = {
        { 1, 1 },
        { 3, 1 },
        { 5, 1 },
        { 7, 1 },
        { 1, 2 }
    };
    int results[5];
    for (i = 0; i < 5; i++)
    {
        results[i] = countWithSlope(map, 323, 31, incs[i][1], incs[i][0]);
//        results[i] = countWithSlope(testMap, 11, 11, incs[i][1], incs[i][0]);
        printf("Intersect %d, %d: %d\n", incs[i][0], incs[i][1], results[i]);
    }
    product = results[0] * 
              results[1] * 
              results[2] *
              results[3] *
              results[4];
    printf("Product: %u\n", product);
    return 0;
}
