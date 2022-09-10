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
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d%c ", p[i], arraySeparator);
    }
    printf("%d %c\n", p[size - 1], arrayIndicator == '[' ? ']' : '}');
}

void allocMemoryFloat(float **p, int size)
{
    *p = (float *)malloc(size * sizeof(float));
}

void generateFloatValues(float **p, int size)
{
    allocMemoryFloat(p, size);
    for (int i = 0; i < size; i++)
    {
        int randomNum = rand() % 100;
        float randomFloat = (float)randomNum / 7.3 + randomNum;
        (*p)[i] = randomFloat;
    }
}

void printFloatArray(float *p, int size)
{
    printf("%c ", arrayIndicator);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%.2f%c ", p[i], arraySeparator);
    }
    printf("%.2f %c\n", p[size - 1], arrayIndicator == '[' ? ']' : '}');
}

void allocMemoryChar(char **p, int size)
{
    *p = (char *)malloc(size * sizeof(char));
}

void generateCharValues(char **p, int size)
{
    allocMemoryChar(p, size);
    for (int i = 0; i < size; i++)
    {
        int randomNum = rand() % 26;
        (*p)[i] = 'a' + randomNum;
    }
}

void printCharArray(char *p, int size)
{
    printf("%c ", arrayIndicator);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%c%c ", p[i], arraySeparator);
    }
    printf("%c %c\n", p[size - 1], arrayIndicator == '[' ? ']' : '}');
}

void allocMemoryString(char ***p, int size)
{
    *p = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        (*p)[i] = (char *)malloc(100 * sizeof(char));
    }
}

void generateStringValues(char ***p, int size)
{
    FILE *ptr;
    ptr = fopen("englishWords.txt", "r");
    if (NULL == ptr)
    {
        printf("file can't be opened \n");
        return;
    }

    allocMemoryString(p, size);

    char words[200][100];

    int count = 0, c = 0, l = 0;
    for (c = getc(ptr); c != EOF; c = getc(ptr))
    {
        if (c == '\n')
        {
            words[count][l] = '\0';
            count++;
            l = 0;
            continue;
        }
        else {
            words[count][l] = c;
            l++;
        }
    }
    for(int i = 0; i < size; i++) {
        int randomNum = rand() % count - 1;
        strcpy((*p)[i], words[randomNum]);
    }

    fclose(ptr);
}

void printStringArray(char **p, int size)
{
    printf("%c ", arrayIndicator);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%s%c ", p[i], arraySeparator);
    }
    printf("%s %c\n", p[size - 1], arrayIndicator == '[' ? ']' : '}');
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