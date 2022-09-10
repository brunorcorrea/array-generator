#define ARRAY_TYPES_SIZE 5

void allocMemoryInt(int **p, int size);
void generateIntValues(int **p, int size);
void printIntArray(int *p, int size);
void allocMemoryFloat(float **p, int size);
void generateFloatValues(float **p, int size);
void printFloatArray(float *p, int size);
void allocMemoryChar(char **p, int size);
void generateCharValues(char **p, int size);
void printCharArray(char *p, int size);
void allocMemoryString(char ***p, int size);
void generateStringValues(char ***p, int size);
void printStringArray(char **p, int size);
int getArrayType(char *arrayType);