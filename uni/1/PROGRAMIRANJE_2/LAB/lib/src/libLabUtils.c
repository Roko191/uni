#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#define ENTER 0x0d
#endif

#ifdef __linux__
#define ENTER '\n'
#endif

// Array functons


// Matrix functions
int** createMatrix(int row, int col){

    int** matrix = NULL;

    matrix = malloc(row * sizeof(int));

    if(!matrix){
        return NULL;
    }

    for(int i = 0; i < row; i++){
        matrix[i] = malloc(col * sizeof(int));

        if(!matrix[i]){
            return NULL;
        }
    }

    return matrix;
}


// String functons

char* createHeapString(){



    int size = 1;
    int index = 0;

    char ch = 0;

    char *sPoint = malloc(size);

    while(1){
        ch = getc(stdin);

        // printf("\n ch: %c", ch);

        if(ch == ENTER || ch == EOF){
            break;
        }

        if(size - 1 <= index){
            size += 1;

            char *temp;

            temp = (char *)realloc(sPoint, size);
            if(!temp){
                free(sPoint);
                return NULL;
            }

            sPoint = temp;
        }

        sPoint[index++] = ch;

    }
    
    sPoint[index] = '\0';

    return sPoint;
}
