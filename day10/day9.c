/*
 * Day 9 - Joltage adapters
 */

#include <stdio.h>
#include <stdlib.h>

int input[] = 
{
107,
13,
116,
132,
24,
44,
56,
69,
28,
135,
152,
109,
42,
112,
10,
43,
122,
87,
49,
155,
175,
71,
39,
173,
50,
156,
120,
145,
176,
45,
149,
148,
15,
1,
68,
9,
168,
131,
150,
59,
83,
167,
3,
169,
6,
123,
174,
81,
138,
72,
157,
144,
65,
75,
33,
19,
140,
160,
16,
57,
93,
90,
8,
58,
98,
130,
141,
114,
84,
29,
22,
94,
113,
129,
108,
36,
14,
115,
102,
151,
78,
139,
170,
82,
2,
70,
126,
101,
25,
62,
95,
104,
23,
163,
32,
103,
121,
119,
48,
166,
7,
53
};

int testInput1[] = 
{
16,
10,
15,
5,
1,
11,
7,
19,
6,
12,
4
};

int testInput2[] = 
{
28,
33,
18,
42,
31,
14,
46,
20,
48,
47,
24,
23,
49,
45,
19,
38,
39,
11,
1,
32,
25,
35,
8,
17,
7,
9,
4,
2,
34,
10,
3
};

int sortFunc(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}

static void countDiffs(const int* sortedInput,
                       const size_t sortedInputLen,
                       size_t* resDiff1,
                       size_t* resDiff3)
{
    size_t i;
    *resDiff1 = 1;
    *resDiff3 = 1;
    for (i = 1; i < sortedInputLen; i++)
    {
        int diff = sortedInput[i] - sortedInput[i-1];
        switch (diff)
        {
            case 1: (*resDiff1)++; break;
            case 3: (*resDiff3)++; break;
            default:
                printf("ERROR - unhandled difference: %d\n", diff);
                return;
        }
    }
}

int main(void)
{
    size_t i;
    size_t diffs1;
    size_t diffs3;
    size_t inputLen = sizeof(testInput1)/sizeof(int);
    qsort(testInput1,
          inputLen,   // nitems
          sizeof(int),  // each element size
          sortFunc);

    //printf("Sorted input:\n");
    //for (i = 0; i < inputLen; i++)
    //{
    //    printf("%d\n", testInput1[i]);
    //}

    countDiffs(testInput1, inputLen, &diffs1, &diffs3);
    printf("Diffs1, 3, times: %d, %d, %d\n", diffs1, diffs3, diffs1*diffs3);

    inputLen = sizeof(testInput2)/sizeof(int);
    qsort(testInput2,
          inputLen,   // nitems
          sizeof(int),  // each element size
          sortFunc);

    countDiffs(testInput2, inputLen, &diffs1, &diffs3);
    printf("Diffs1, 3, times: %d, %d, %d\n", diffs1, diffs3, diffs1*diffs3);

    inputLen = sizeof(input)/sizeof(int);
    qsort(input,
          inputLen,   // nitems
          sizeof(int),  // each element size
          sortFunc);

    countDiffs(input, inputLen, &diffs1, &diffs3);
    printf("Diffs1, 3, times: %d, %d, %d\n", diffs1, diffs3, diffs1*diffs3);
    
    return 0;
}


