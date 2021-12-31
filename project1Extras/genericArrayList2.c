
#include<stdio.h>

#define TYPE int
#include"genericArrayList2.h"
#define TYPE float
#include"genericArrayList2.h"

void intTest(){
    ArrayList_int list;
    //create the array
    createArrayList_int(&list, 0);
    //populate the array
    for(int i = 0; i < 10; i++)
        add_int(&list, i);
    //modify the array
    set_int(&list, 3, 6);
    set_int(&list, 7, 5);
    //print the array
    for(int i = 0; i < size_int(&list); i++)
        printf("%d, ", get_int(&list, i));
    deleteArrayList_int(&list);
}

void floatTest(){
    ArrayList_float list;
    //create the array
    createArrayList_float(&list, 0);
    //populate the array
    for(int i = 0; i < 10; i++)
        add_float(&list, i * 1.1);
    //modify the array
    set_float(&list, 3, 6.0);
    set_float(&list, 7, 5.0);
    //print the array
    for(int i = 0; i < size_float(&list); i++)
        printf("%f, ", get_float(&list, i));
    deleteArrayList_float(&list);
}

int main(){
    intTest();
    printf("\n");
    floatTest();
    return 0;
}