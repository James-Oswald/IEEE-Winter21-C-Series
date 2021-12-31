

#ifdef TYPE
#define TCI(A,B) A ## B
#define TC(A,B) TCI(A,B)
#define TYPEDNAME(NAME) TC(NAME, TYPE)
#include<stdlib.h>

typedef struct TYPEDNAME(ArrayList_){
    TYPE* array;
    size_t length;
} TYPEDNAME(ArrayList_);

void TYPEDNAME(createArrayList_)(TYPEDNAME(ArrayList_)* list, size_t initialSize){
    list->array = (TYPE*)malloc(sizeof(TYPE) * initialSize);
    list->length = initialSize;
}

void TYPEDNAME(set_)(TYPEDNAME(ArrayList_)* list, size_t index, TYPE item){
    list->array[index] = item;
}

TYPE TYPEDNAME(get_)(TYPEDNAME(ArrayList_)* list, size_t index){
    return list->array[index];
}

size_t TYPEDNAME(size_)(TYPEDNAME(ArrayList_)* list){
    return list->length;
}

void TYPEDNAME(add_)(TYPEDNAME(ArrayList_)* list, TYPE element){
    list->length++;
    list->array = (TYPE*)realloc(list->array, list->length * sizeof(TYPE));
    list->array[list->length-1] = element;
}

void TYPEDNAME(deleteArrayList_)(TYPEDNAME(ArrayList_)* list){
    free(list->array);
}

#else
#error Type not specified for generic ArrayList header __FILE__
#endif
#undef TYPE