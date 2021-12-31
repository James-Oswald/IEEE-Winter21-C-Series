
#include<stdlib.h>
#include<stdio.h>

typedef struct {
    int* array;
    size_t size;
} ArrayList;

void createArrayList(ArrayList* list, size_t initialSize){
    list->size = initialSize;
    list->array = (int*)malloc(sizeof(int) * initialSize);
}

size_t size(const ArrayList* list){
    return list->size;
}

void set(ArrayList* list, size_t index, int element){
    list->array[index] = element;
}

int get(const ArrayList* list, size_t index){
    return list->array[index];
}

void add(ArrayList* list, int element){
    list->size++;
    list->array = (int*)realloc(list->array, list->size * sizeof(int));
    list->array[list->size-1] = element;
}

void deleteArrayList(ArrayList* list){
    free(list->array);
}

int main(){
    ArrayList list;
    //create the array
    createArrayList(&list, 0);
    //populate the array
    for(int i = 0; i < 10; i++)
        add(&list, i);
    //modify the array
    set(&list, 3, 6);
    set(&list, 7, 5);
    //print the array
    for(int i = 0; i < size(&list); i++)
        printf("%d, ", get(&list, i));
    deleteArrayList(&list);
}