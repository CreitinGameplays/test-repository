// learning C ahh language
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// array
typedef struct {
    char** data;
    size_t size;
    size_t capacity;
} strArray;

void makeArray(strArray* array){
    array->size = 0;
    array->capacity = 4;
    array->data = malloc(array->capacity * sizeof(char*));
    if (!array->data){
        fputs("Criminal malloc error\n", stderr);
        exit(EXIT_FAILURE);
    }
}

void addBack(strArray* array, char* value){
    if (array->capacity == array->size){
        array->capacity *= 2;
        char** tmp = realloc(array->data, array->capacity * sizeof(char*));
        if (!array->data){
            fputs("Wild realloc error happened.\n", stderr);
            exit(EXIT_FAILURE);
        };
        array->data = tmp;
    }
    array->data[array->size++] = value;
}

// death
int main() {
    strArray myArray;
    makeArray(&myArray);
    addBack(&myArray, "test one");
    addBack(&myArray, "test two");
    printf("%s\n", myArray.data[1]);

    // end
    // while (1) _sleep(5LL * 1024); // ignore this :skull:
    free(myArray.data);
    return 0; 
}
