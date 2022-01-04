


#include<stdlib.h>
#include<stdio.h>

#include"LinkedList.h"

void createLinkedList(LinkedList* list, size_t initialSize){
    list->size = initialSize;
    if(initialSize == 0){
        list->head = NULL;
        list->tail = NULL;
    }else if(initialSize > 0){
        list->head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        LinkedListNode* curNode = list->head;
        for(int i = 1; i < initialSize; i++){
            curNode->next = (LinkedListNode*)malloc(sizeof(LinkedListNode));
            curNode = curNode->next;
        }
        curNode->next = NULL;
        list->tail = curNode;
    }
}

size_t size(const LinkedList* list){
    return list->size;
}

void set(LinkedList* list, size_t index, int element){
    LinkedListNode* desiredNode = list->head;
    for(int i = 0; i < index; i++)
        desiredNode = desiredNode->next;
    desiredNode->data = element;
}

int get(const LinkedList* list, size_t index){
    LinkedListNode* desiredNode = list->head;
    for(int i = 0; i < index; i++)
        desiredNode = desiredNode->next;
    return desiredNode->data;
}

void add(LinkedList* list, int element){
    if(list->tail == NULL){
        list->head = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        list->head->next = NULL;
        list->head->data = element;
        list->tail = list->head;
    }else{
        list->tail->next = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        list->tail->next->next = NULL;
        list->tail->next->data = element;
        list->tail = list->tail->next;
    }
    list->size++;
}

void deleteLinkedList(LinkedList* list){
    LinkedListNode* cur = list->head;
    LinkedListNode* next;
    while(cur != NULL){
        next = cur->next;
        free(cur);
        cur = next;
    }
}

