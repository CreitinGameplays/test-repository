// tesy is the king the greatest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} int_vector;

void makeVec(int_vector* vec) {
    vec->capacity = 4;
    vec->size = 0;
    vec->data = malloc(vec->capacity * sizeof(int));
    if (vec->data == NULL) {
        fputs("Criminal error", stderr);
        exit(EXIT_FAILURE);
    }
}

void addToVec(int_vector* vec, int value){
    if (vec->capacity == vec->size){
        vec->capacity *= 2;
        int* t = realloc(vec->data, vec->capacity * sizeof(int));
        if (!t){
            fputs("Wild realloc error", stderr);
            exit(EXIT_FAILURE);
        }
        vec->data = t;
    }
    vec->data[vec->size++] = value;
}

// shit collector
void vecFree(int_vector* vec){
    if (vec->data == NULL){
    } else {
        free(vec->data);
        vec->data = NULL;
    }
}

int main() {
    int_vector myVec;
    makeVec(&myVec);

    addToVec(&myVec, 10);
    addToVec(&myVec, 20);

    printf("Value 1: %d \n", myVec.data[0]);
    printf("Value 2: %d \n", myVec.data[1]);

    char** x = malloc(20);
    x[0] = "someone";
    x[1] = "crow";
    printf("%s\n", x[0]);
    printf("%s\n", x[1]);

    // while(-1) _sleep(1024);
    free(x);
    vecFree(&myVec);
    vecFree(&myVec);
    return 0;
}
