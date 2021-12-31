

#include<stdio.h>

#include"genericArrayList1.h"



void intTest(){
    ArrayList list;
    //create the array
    createArrayList(&list, sizeof(int), 0);
    //populate the array
    for(int i = 0; i < 10; i++)
        add(&list, (void*)&i);
    //modify the array
    int j = 6;
    set(&list, 3, (void*)&j);
    j = 5;
    set(&list, 7, (void*)&j);
    //print the array
    for(int i = 0; i < size(&list); i++)
        printf("%d, ", *(int*)get(&list, i));
    deleteArrayList(&list);
}
void floatTest(){
    ArrayList list;
    //create the array
    createArrayList(&list, sizeof(float), 0);
    //populate the array
    for(float i = 0; i < 10; i++){
        i *= 1.1;
        add(&list, (void*)&i);
        i /= 1.1;
    }
    //modify the array
    float j = 6.0;
    set(&list, 3, (void*)&j);
    j = 5.0;
    set(&list, 7, (void*)&j);
    //print the array
    for(int i = 0; i < size(&list); i++)
        printf("%f, ", *(float*)get(&list, i));
    deleteArrayList(&list);
}


int main(){
    intTest();
    printf("\n");
    floatTest();
    return 0;
}