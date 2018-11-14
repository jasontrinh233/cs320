/*
 * prog1_2.c
 * =================================
 * Program create a Stack, Push, Pop
 * and Grow functions.
 * =================================
 * CS320-02
 * 02.04.18
 * Author: Quang Trinh
 */

#include <stdio.h>
#include <stdlib.h>
#include "prog1_2.h"

STACK* MakeStack(int initialCapacity) 
{
    STACK* s;
    s = (STACK*)malloc(sizeof(STACK));
    (*s).size = 0;
    (*s).data = (int*)malloc(initialCapacity * sizeof(int));
    (*s).capacity = initialCapacity;
    return s;
}

void Push(STACK* stackPtr, int data) 
{
    /* Stack is full */
    if((*stackPtr).size == (*stackPtr).capacity) {
        Grow(stackPtr);
        (*stackPtr).data[(*stackPtr).size] = data;
        (*stackPtr).size += 1;
        return;
    }
    (*stackPtr).data[(*stackPtr).size] = data;
    (*stackPtr).size += 1;
    return;
}

int Pop(STACK* stackPtr) 
{
    int num;    
    if((*stackPtr).size <= 0) {
        return -1;
    } else {
        num = (*stackPtr).data[(*stackPtr).size - 1];
        (*stackPtr).size -= 1;
        return (num);
    }
}

void Grow(STACK* stackPtr) 
{
    (*stackPtr).capacity *= 2;
    return;
}

void Display(STACK* stackPtr) 
{
    int i = 0;
    printf("Capacity: %d\n", (*stackPtr).capacity);
    printf("Size: %d\n", (*stackPtr).size);
    for (i = 0; i < (*stackPtr).size; ++i) {
        printf("Data[%d]: %d\n", i, (*stackPtr).data[i]);
    }
    return;
}

