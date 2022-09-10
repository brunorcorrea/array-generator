#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void allocMemoryFloat(float **p, int size)
{
    *p = (float *)malloc(size * sizeof(float));
}

void allocMemoryDouble(double **p, int size)
{
    *p = (double *)malloc(size * sizeof(double));
}

void allocMemoryChar(char **p, int size)
{
    *p = (char *)malloc(size * sizeof(char));
}

void allocMemoryString(char ***p, int size)
{
    *p = (char **)malloc(size * sizeof(char*));
    for(int i = 0; i < size; i++)
    {
        (*p)[i] = (char *)malloc(100 * sizeof(char));
    }
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("not enough arguments");
        return 1;
    }

    int selectedArrayType = getArrayType(argv[1]);

    if(selectedArrayType == -1) {
        printf("array type not supported");
        return 1;
    }

    int size = atoi(argv[2]);

    switch(selectedArrayType) {
        case 0:
            {
                int *p;
                generateIntValues(&p, size);
                printIntArray(p, size);
                break;
            }
        case 1:
            {
                float *p;
                allocMemoryFloat(&p, size);
                break;
            }
        case 2:
            {
                double *p;
                allocMemoryDouble(&p, size);
                break;
            }
        case 3:
            {
                char *p;
                allocMemoryChar(&p, size);
                break;
            }
        case 4:
            {
                char **p;
                allocMemoryString(&p, size);
                break;
            }
    }

    return 0;
}