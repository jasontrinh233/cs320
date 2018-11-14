/*
 * prog1_2.h
 * ==========================
 * Header file for prog1_2.c.
 * ==========================
 * CS320-02
 * 02.04.18
 * Author: Quang Trinh
 */

#ifndef PROG1_2_H
#define PROG1_2_H

typedef struct stack
{
	int* data;
	int size;
	int capacity;
} STACK;

#endif /* PROG1_2_H */

STACK* MakeStack(int initialCapacity);

void Push(STACK *stackPtr, int data);

int Pop(STACK *stackPtr);

void Grow(STACK *stackPtr);

void Display(STACK *stackPtr);

