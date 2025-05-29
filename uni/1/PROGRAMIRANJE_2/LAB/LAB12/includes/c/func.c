#include "../func.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFile(FILE** file, char* mode){
    printf("Unesi ime datoteke: ");
    char* nameFile = createHeapString();
    if(!nameFile){
        return ERR_ALLOC_FAIL;
    }

    FILE *tmpFile = fopen(nameFile, mode);

    if(!tmpFile){
        return ERR_FILE_ALLOC_FAIL;
    }

    *file = tmpFile;

    free(nameFile);
    return OK;
}

int copyFileContent(FILE* src, FILE* dst){
    if(!src || !dst){
        return ERR_FUNC_ARG_BAD;
    }

    char ch = 0;

    while(1){
        ch = fgetc(src);

        if(ch == EOF){
            break;
        }

        //printf("%c", ch);
        fprintf(dst, "%c", ch);
    }

    return OK;
}

int readData(FILE* stream, int* data){
    if(!stream){
        return ERR_FUNC_ARG_BAD;
    }

    char ch = 0;
    int i = 0;

    int size = 16;
    char* numString = malloc(size * sizeof(char));
    

    while(1){
        ch = fgetc(stream);

        if(ch == EOF){
            break;
        }

        if(isdigit(ch)){
            if(size - 1 <= i){
                size += 1;
                char* temp = realloc(numString, size);
                if(!temp){
                    free(numString);
                    return ERR_ALLOC_FAIL;
                }
            }

            numString[i++] = ch;
        } else {
            break;
        }
    }

    numString[i] = '\0';
    *data = atoi(numString);

    return OK;
}

int printParsedNumber(FILE* stream){
    int res;
    int num;
    res = readData(stream, &num);
    
    if(res){
        return res;
    }

    printf("%d\n", num);

    return OK;
}

int readDataFromFile(FILE *stream, Person ***persons, int* peopleCnt){
    if(!stream || !persons){
        return ERR_FUNC_ARG_BAD;
    }

    int pCnt = 0;
    int size = 1;

    Person** tmpPersons = malloc(size * sizeof(Person*));
    if(!tmpPersons){
        return ERR_ALLOC_FAIL;
    }

    size_t sizeLine = 0;
    char *line = NULL;

    while(getline(&line, &sizeLine, stream) != -1){
        Person* tmpPerson = malloc(sizeof(Person));
        if(!tmpPerson){
            return ERR_ALLOC_FAIL;
        }

        char *name;
        char *surname;

        name = strtok(line, " ");
        surname = strtok(NULL, "\n");

        tmpPerson -> name = strdup(name);
        tmpPerson -> surname = strdup(surname);

        if(size - 1 <= pCnt){
            size += 1;
            Person** tmp = realloc(tmpPersons, size * sizeof(Person*));
            if(!tmp){
                return ERR_ALLOC_FAIL;
            }
            tmpPersons = tmp;
        }

        tmpPersons[pCnt++] = tmpPerson;

        //size_t nameLen = spacePtr - line;
        //size_t surnameLen = strlen(spacePtr + 1);
    }

    *persons = tmpPersons;
    *peopleCnt = pCnt;

    free(line);
    return OK;
}




int countPeopleWithFirstName(Person** persons,char* name, int pCnt,int* count){
    if(!persons || !count){
        return ERR_FUNC_ARG_BAD;
    }

    int cnt = 0;
    for(int i = 0; i < pCnt; i++){
        if (!strcasecmp(name, persons[i]->name)) {
            cnt++;
        }
    }

    *count = cnt;

    return OK;
}

int printLineByLineWordByWord(FILE* stream){
    if(!stream){
        return ERR_FUNC_ARG_BAD;
    }

    size_t sizeLine = 0;
    char *line = NULL;

    while(getline(&line, &sizeLine, stream) != -1){
        char* token = strtok(line, " ");
        while(token != NULL){
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }

    return OK;
}