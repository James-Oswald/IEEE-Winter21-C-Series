
#include<stdio.h>

#include"LinkedList.h"
#include"Lib.h"

int main(){
    LinkedList list;
    //create the array
    createLinkedList(&list, 0);
    //populate the array
    for(int i = 0; i < 10; i++)
        add(&list, i);
    //modify the array
    set(&list, 3, 6);
    set(&list, 7, 5);
    //print the array
    for(int i = 0; i < size(&list); i++)
        printf("%d, ", get(&list, i));
    deleteLinkedList(&list);
}