#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

const char supportedArrayTypes[ARRAY_TYPES_SIZE][10] = {"int", "float", "double", "char", "string"};
char arraySeparator = ',', arrayIndicator = '[';

void allocMemoryInt(int **p, int size)
{
    *p = (int *)malloc(size * sizeof(int));
}

void generateIntValues(int **p, int size)
{
    allocMemoryInt(p, size);    
    for (int i = 0; i < size; i++)
    {
        (*p)[i] = rand() % 100;
    }
}

void printIntArray(int *p, int size)
{
    printf("%c ", arrayIndicator);
    for (int i = 0; i < size-1; i++)
    {
        printf("%d%c ", p[i], arraySeparator);
    }
    printf("%d %c\n", p[size-1], arrayIndicator == '[' ? ']' : '}');
}

int getArrayType(char *arrayType)
{
    int i;
    for (i = 0; i < ARRAY_TYPES_SIZE; i++)
    {
        if (strcmp(arrayType, supportedArrayTypes[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}