/*
 * Day 8 - handheld game device emulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char* input[612] =
{
"acc +18",
"nop +222",
"acc -16",
"acc +28",
"jmp +475",
"acc -6",
"jmp +584",
"acc -12",
"acc -8",
"jmp +554",
"acc -9",
"acc +12",
"acc -16",
"acc +27",
"jmp +336",
"acc -4",
"jmp +214",
"acc +38",
"jmp +61",
"acc +3",
"acc +28",
"acc +5",
"acc -19",
"jmp +584",
"nop +206",
"jmp +506",
"acc +36",
"jmp +133",
"acc +20",
"acc +43",
"acc -18",
"jmp +409",
"acc +24",
"jmp +131",
"acc -12",
"acc +7",
"acc +7",
"jmp +454",
"acc +37",
"acc -6",
"nop +558",
"acc +31",
"jmp +124",
"acc -15",
"nop +201",
"acc -7",
"jmp +297",
"acc +3",
"nop +517",
"jmp +221",
"jmp +211",
"acc +28",
"acc +35",
"jmp +5",
"acc +31",
"nop +325",
"acc -15",
"jmp +116",
"jmp +1",
"nop +333",
"acc -2",
"acc -5",
"jmp +138",
"acc +19",
"acc +9",
"jmp +180",
"acc +18",
"jmp +228",
"jmp +495",
"jmp +382",
"acc +20",
"nop +414",
"nop +139",
"acc +33",
"jmp +171",
"acc -10",
"jmp +41",
"acc -2",
"jmp +80",
"acc +20",
"nop +451",
"acc +2",
"acc +24",
"jmp +102",
"acc +1",
"acc -11",
"acc +9",
"acc +38",
"jmp -73",
"acc +17",
"acc +16",
"acc +12",
"acc +43",
"jmp +168",
"jmp +286",
"acc +6",
"acc +6",
"jmp +271",
"acc -17",
"acc -5",
"acc +1",
"jmp -50",
"acc -9",
"acc +6",
"acc -2",
"acc +33",
"jmp +385",
"acc +18",
"acc +24",
"jmp +370",
"acc -5",
"acc +23",
"acc +6",
"jmp +98",
"acc -10",
"acc -16",
"jmp +329",
"nop +41",
"jmp +463",
"nop +224",
"acc +35",
"jmp +345",
"acc +34",
"acc -18",
"acc +5",
"jmp +177",
"nop -57",
"nop -80",
"acc +20",
"jmp -12",
"acc +24",
"acc +39",
"jmp +363",
"jmp +253",
"acc -14",
"acc +0",
"acc +22",
"jmp +118",
"acc +43",
"acc -2",
"jmp +300",
"acc -14",
"acc +8",
"acc +47",
"jmp +271",
"jmp +420",
"acc +33",
"acc +15",
"acc +20",
"acc +25",
"jmp +84",
"acc +41",
"jmp +420",
"acc +25",
"jmp +238",
"jmp +1",
"acc +14",
"jmp +415",
"jmp +68",
"jmp +262",
"acc +34",
"jmp +346",
"acc +39",
"jmp +56",
"jmp +364",
"jmp -133",
"acc +13",
"jmp +1",
"acc +33",
"jmp +408",
"acc +29",
"acc -4",
"jmp +319",
"jmp +106",
"jmp +228",
"acc -8",
"acc +8",
"acc +22",
"jmp -146",
"jmp +223",
"acc +27",
"nop +191",
"acc +49",
"jmp +331",
"jmp +39",
"jmp -170",
"acc +28",
"acc -6",
"acc +50",
"jmp +268",
"acc +41",
"nop +254",
"acc +28",
"jmp +269",
"jmp +140",
"acc +10",
"nop +131",
"acc +3",
"jmp -40",
"jmp +373",
"acc +47",
"jmp -91",
"acc -19",
"jmp +300",
"acc -2",
"jmp +1",
"acc +44",
"acc -11",
"jmp +306",
"acc +33",
"jmp -15",
"acc +9",
"jmp +1",
"jmp +144",
"acc +40",
"nop +184",
"nop -75",
"nop +228",
"jmp +296",
"acc +22",
"nop +364",
"jmp -214",
"jmp +18",
"jmp +375",
"acc +22",
"jmp -67",
"acc +8",
"acc -17",
"jmp +174",
"jmp -99",
"nop -45",
"acc +7",
"jmp -213",
"jmp -218",
"acc +50",
"nop +52",
"nop +98",
"jmp -142",
"acc +18",
"jmp +252",
"acc +36",
"jmp -194",
"acc +1",
"nop -53",
"jmp -127",
"jmp +327",
"acc +7",
"acc -9",
"acc +39",
"nop -127",
"jmp +84",
"jmp -117",
"nop -29",
"acc +43",
"jmp -216",
"acc +25",
"acc +16",
"acc +40",
"nop +122",
"jmp +140",
"jmp +180",
"acc +42",
"acc -5",
"acc -14",
"jmp -84",
"jmp -31",
"acc +37",
"acc -11",
"jmp -217",
"jmp +210",
"jmp +170",
"nop +301",
"jmp +309",
"acc +6",
"jmp +135",
"acc +6",
"nop -123",
"acc +17",
"jmp +315",
"acc -1",
"nop -46",
"nop -58",
"nop -59",
"jmp +202",
"acc +48",
"acc +38",
"jmp +86",
"acc -4",
"acc +33",
"acc +28",
"jmp -50",
"nop +43",
"acc +38",
"acc +13",
"jmp +33",
"acc +4",
"acc +6",
"jmp -78",
"acc +22",
"acc +7",
"acc -9",
"jmp -56",
"acc +30",
"nop +54",
"nop -81",
"nop +198",
"jmp +252",
"jmp +1",
"acc +6",
"acc -10",
"acc +29",
"jmp -242",
"jmp +1",
"acc +42",
"acc +34",
"acc +22",
"jmp +231",
"acc +29",
"acc -10",
"jmp -161",
"acc +37",
"acc +9",
"jmp -77",
"acc -15",
"acc +32",
"acc +32",
"jmp -6",
"acc +0",
"nop -124",
"nop +174",
"jmp +20",
"acc +45",
"acc +24",
"jmp -13",
"acc +6",
"acc -10",
"acc +23",
"acc -15",
"jmp +34",
"acc +5",
"acc +38",
"acc +42",
"jmp -116",
"acc +0",
"acc +8",
"jmp -243",
"acc -18",
"acc +25",
"acc +1",
"jmp +158",
"nop +65",
"jmp +1",
"jmp +151",
"acc +12",
"acc +12",
"jmp +1",
"jmp -305",
"jmp +29",
"jmp -263",
"acc +33",
"jmp +1",
"nop +142",
"jmp +78",
"acc +41",
"nop -141",
"acc -9",
"acc +5",
"jmp -245",
"jmp +41",
"acc +16",
"nop -83",
"jmp -28",
"nop -149",
"acc +38",
"jmp -15",
"acc +7",
"nop -329",
"acc +5",
"acc +21",
"jmp -7",
"acc -19",
"jmp -38",
"acc +5",
"acc +3",
"acc +10",
"jmp -181",
"jmp -240",
"acc +19",
"acc +15",
"acc +31",
"acc -11",
"jmp -340",
"acc +12",
"acc +46",
"jmp +127",
"acc +12",
"acc +31",
"acc +30",
"jmp -158",
"acc -10",
"jmp -374",
"jmp +50",
"acc +43",
"nop +42",
"acc +19",
"jmp -232",
"acc -14",
"acc -4",
"jmp +95",
"acc +23",
"acc +49",
"acc +31",
"nop -139",
"jmp -272",
"jmp -141",
"acc +26",
"acc -8",
"jmp +173",
"nop +145",
"nop +133",
"jmp +164",
"acc +7",
"jmp +23",
"acc -4",
"acc +48",
"jmp -138",
"acc +4",
"jmp -389",
"nop +156",
"acc +44",
"acc +40",
"jmp +146",
"nop -247",
"acc +44",
"jmp +1",
"acc +28",
"jmp +95",
"acc +13",
"acc +2",
"jmp -254",
"acc +24",
"jmp +122",
"acc +39",
"acc +0",
"jmp -12",
"jmp -179",
"nop -44",
"nop +100",
"acc -19",
"nop -47",
"jmp -107",
"acc +32",
"acc +33",
"acc +42",
"acc +6",
"jmp -366",
"jmp -122",
"acc +2",
"nop -443",
"nop +72",
"jmp -381",
"jmp -446",
"jmp -332",
"acc -7",
"acc +45",
"jmp -355",
"acc +27",
"acc -4",
"acc +3",
"jmp +96",
"acc +45",
"jmp -402",
"acc +45",
"acc -3",
"acc +22",
"jmp -141",
"acc +29",
"acc -1",
"jmp +29",
"acc -1",
"acc -10",
"jmp -208",
"acc +6",
"nop -196",
"jmp -218",
"acc -12",
"acc +49",
"nop -137",
"jmp -430",
"acc +21",
"jmp -110",
"nop -287",
"acc -3",
"jmp -42",
"jmp -487",
"acc -16",
"acc -1",
"acc +7",
"acc +39",
"jmp -119",
"jmp +1",
"acc +9",
"jmp -23",
"acc +27",
"jmp -300",
"acc +12",
"jmp -440",
"acc +2",
"acc +38",
"acc +12",
"jmp -84",
"acc +25",
"acc -14",
"jmp -418",
"acc -15",
"acc +48",
"jmp +1",
"nop -383",
"jmp -365",
"acc +47",
"jmp -193",
"acc +23",
"jmp -235",
"jmp +1",
"acc -4",
"acc +35",
"nop -64",
"jmp -87",
"acc +32",
"jmp -339",
"jmp -479",
"acc -4",
"acc +32",
"acc -10",
"jmp -77",
"acc +0",
"acc +47",
"acc +41",
"jmp -308",
"acc -8",
"acc -9",
"jmp -229",
"acc -14",
"acc +24",
"nop -380",
"acc +49",
"jmp -174",
"acc -11",
"nop -69",
"jmp +3",
"acc -14",
"jmp -89",
"jmp -301",
"acc +46",
"acc +8",
"nop -156",
"acc +44",
"jmp +1",
"jmp +26",
"acc +17",
"acc +23",
"acc +6",
"jmp -4",
"jmp -97",
"jmp -324",
"acc +2",
"jmp -27",
"nop -195",
"acc +3",
"acc -13",
"acc +15",
"jmp -19",
"acc +30",
"nop -318",
"jmp +19",
"nop -72",
"jmp -315",
"acc +4",
"nop +6",
"jmp -384",
"jmp -505",
"jmp -512",
"acc +33",
"jmp -168",
"jmp -443",
"nop -519",
"acc +7",
"acc +41",
"acc +15",
"jmp -269",
"nop -539",
"jmp -416",
"jmp -326",
"nop -221",
"acc +14",
"jmp -186",
"acc -1",
"jmp -295",
"acc +29",
"acc +43",
"nop -436",
"nop -421",
"jmp -123",
"acc +13",
"acc -11",
"acc +12",
"jmp -155",
"acc +9",
"acc -16",
"acc -15",
"nop -380",
"jmp +1"
};

const char* testInput[9] = 
{
"nop +0",
"acc +1",
"jmp +4",
"acc +3",
"jmp -3",
"acc -99",
"acc +1",
"jmp -4",
"acc +6"
};

typedef struct CPU
{
    int acc;
    int sp;
} CPU;

static void CPU_Init(CPU* cpu)
{
    cpu->acc = 0;
    cpu->sp = 0;
}

typedef struct Instruction
{
    char name[50];
    int val;
} Instruction;

static inline void parseInstruction(const char* str, Instruction* instr)
{
    char plusMinus;
    sscanf(str, "%s %c%d", instr->name, &plusMinus, &instr->val);
    if (plusMinus != '+' && plusMinus != '-')
    {
        printf("  ERROR - instruction not plus or minus!\n");
    }
    else if (plusMinus == '-')
    {
        instr->val *= -1;
    }
}

static inline void acc(CPU* cpu, Instruction* instr)
{
    cpu->acc += instr->val;
    cpu->sp++;
}

static inline void jmp(CPU* cpu, Instruction* instr)
{
    cpu->sp += instr->val;
}

static inline void nop(CPU* cpu, Instruction* instr)
{
    cpu->sp++;
}

#define INPUT_LEN 612
//#define INPUT_LEN 9

static bool ranInstructions[INPUT_LEN]; 
// returns true if the instruction hasn't already been run
static inline bool registerInstr(int sp)
{
    if (!ranInstructions[sp])
    {
        ranInstructions[sp] = true;
        return true;
    }
    return false;
}

static inline void runInstr(CPU* cpu, Instruction* instr)
{
    if (strcmp(instr->name, "acc") == 0)
    {
        acc(cpu, instr);
    }
    else if (strcmp(instr->name, "jmp") == 0)
    {
        jmp(cpu, instr);
    }
    else if (strcmp(instr->name, "nop") == 0)
    {
        nop(cpu, instr);
    }
    else
    {
        printf("  ERRROR - failed to find matching instructino for %s\n", instr->name);
    }
}

static inline int getNumInstrs(const char* inputArr[INPUT_LEN], const char* instr)
{
    size_t count = 0;
    size_t i;
    char tmpInstr[4] = { 0 };
    for (i = 0; i < INPUT_LEN; i++)
    {
        tmpInstr[0] = inputArr[i][0];
        tmpInstr[1] = inputArr[i][1];
        tmpInstr[2] = inputArr[i][2];
        //printf("TmpStr: %s\n", tmpInstr);
        if (strcmp(tmpInstr, instr) == 0)
        {
            //printf("Match at %d\n", i);
            count++;
        }
    }

    return count;
}

static inline int getInstrLocs(const char* inputArr[INPUT_LEN], const char* instr, int* locs)
{
    size_t i;
    size_t index = 0;
    char tmpInstr[4] = { 0 };
    for (i = 0; i < INPUT_LEN; i++)
    {
        tmpInstr[0] = inputArr[i][0];
        tmpInstr[1] = inputArr[i][1];
        tmpInstr[2] = inputArr[i][2];
        if (strcmp(tmpInstr, instr) == 0)
        {
            printf("Match at %d\n", i);
            locs[index] = i;
            index++;
        }
    }
}

static int* jmpLocations = NULL;
static int* nopLocations = NULL;



int main(void)
{
    size_t i;
    CPU cpu;
    bool programExitSuccess = false;
    int numJmps = getNumInstrs(input, "jmp");
    int numNops = getNumInstrs(input, "nop");
    printf("Num Jmps: %d\n", numJmps);
    printf("Num Nops: %d\n", numNops);

    jmpLocations = (int*)malloc(numJmps * sizeof(int));
    nopLocations = (int*)malloc(numNops * sizeof(int));

    getInstrLocs(input, "jmp", jmpLocations);
    getInstrLocs(input, "nop", nopLocations);

    for (i = 0; i < numJmps; i++)
    {
        CPU_Init(&cpu);

        memset(ranInstructions, 0, sizeof(ranInstructions)); 

        while (cpu.sp < INPUT_LEN)
        {
            Instruction instr;
            parseInstruction(input[cpu.sp], &instr);

            // replace the jmp with a nop
            if (cpu.sp == jmpLocations[i])
            {
                printf("Replacing jmp with nop\n");
                printf("  Before: %s %d\n", instr.name, instr.val);
                memset(instr.name, 0, sizeof(instr.name));
                strcpy(instr.name, "nop");
                printf("  After: %s %d\n", instr.name, instr.val);
            }

            if (!registerInstr(cpu.sp))
            {
                // the line has already been ran
                programExitSuccess = false;
                break;
            }
            runInstr(&cpu, &instr);
        }
        if (cpu.sp >= INPUT_LEN)
        {
            programExitSuccess = true;
            printf("Accum: %d\n", cpu.acc);
            goto endProg;
        }
    }

    for (i = 0; i < numNops; i++)
    {
        CPU_Init(&cpu);

        memset(ranInstructions, 0, sizeof(ranInstructions)); 

        while (cpu.sp < INPUT_LEN)
        {
            Instruction instr;
            parseInstruction(input[cpu.sp], &instr);

            // replace the nop with a jmp
            if (cpu.sp == nopLocations[i])
            {
                printf("Replacing nop with jmp\n");
                printf("  Before: %s %d\n", instr.name, instr.val);
                memset(instr.name, 0, sizeof(instr.name));
                strcpy(instr.name, "jmp");
                printf("  After: %s %d\n", instr.name, instr.val);
            }

            if (!registerInstr(cpu.sp))
            {
                // the line has already been ran
                programExitSuccess = false;
                break;
            }
            runInstr(&cpu, &instr);
        }
        if (cpu.sp >= INPUT_LEN)
        {
            programExitSuccess = true;
            printf("Accum: %d\n", cpu.acc);
            goto endProg;
        }
    }

endProg:
    if (jmpLocations != NULL)
    {
        free(jmpLocations);
    }
    if (nopLocations != NULL)
    {
        free(nopLocations);
    }
    return 0;
}
