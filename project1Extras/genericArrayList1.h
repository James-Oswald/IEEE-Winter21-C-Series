

#include<stdlib.h>
#include<string.h>

typedef struct ArrayList{
    void* array;
    size_t length;
    size_t typeSize;
} ArrayList;

void createArrayList(ArrayList* list, size_t typeSize, size_t initialSize){
    list->typeSize = typeSize;
    list->array = malloc(typeSize * initialSize);
    list->length = initialSize;
}

void set(ArrayList* list, int index, void* item){
    memcpy(list->array + (list->typeSize) * index, item, list->typeSize);
}

void* get(ArrayList* list, int index){
    return list->array + (list->typeSize) * index;
}

size_t size(const ArrayList* list){
    return list->length;
}

void add(ArrayList* list, void* item){
    list->length++;
    list->array = (int*)realloc(list->array, list->length * list->typeSize);
    memcpy(list->array + (list->typeSize) * (list->length - 1), item, list->typeSize);
}

void deleteArrayList(ArrayList* list){
    free(list->array);
}