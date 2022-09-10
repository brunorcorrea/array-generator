#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void setup() {
    srand(time(NULL));
}

int main(int argc, char *argv[]) {
    setup();

    if(argc < 3) {
        printf("not enough arguments\n");
        return 1;
    }

    int selectedArrayType = getArrayType(argv[1]);

    if(selectedArrayType == -1) {
        printf("array type not supported\n");
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
                generateFloatValues(&p, size);
                printFloatArray(p, size);
                break;
            }
        case 3:
            {
                char *p;
                generateCharValues(&p, size);
                printCharArray(p, size);
                break;
            }
        case 4:
            {
                char **p;
                generateStringValues(&p, size);
                printStringArray(p, size);
                break;
            }
    }

    return 0;
}