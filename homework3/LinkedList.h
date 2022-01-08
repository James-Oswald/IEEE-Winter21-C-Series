
#pragma once

#include<stdint.h>

typedef struct LinkedListNode{
    struct LinkedListNode* next;
    int data;
} LinkedListNode;

typedef struct LinkedList{
    LinkedListNode* head;
    LinkedListNode* tail;
    size_t size;
} LinkedList;

void createLinkedList(LinkedList*, size_t);
size_t size(const LinkedList*);
void set(LinkedList*, size_t, int);
int get(const LinkedList*, size_t);
void add(LinkedList*, int);
void deleteLinkedList(LinkedList*);
