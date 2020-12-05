#include <string.h>
#include <stdio.h>

int main(void)
{
    char dummy[50];
    dummy[0] = 'a';
    dummy[1] = 's';
    dummy[2] = 'd';
    dummy[3] = '\0';
    printf("len: %d\n", strlen(dummy));
}
