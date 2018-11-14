/*
 * prog1_1.c
 * ==========================
 * Program that prints name
 * and output to the console.
 * ==========================
 * CS320-02
 * 02.04.18
 * Author: Quang Trinh
 */

#include <stdio.h>
#include <string.h>

int main() {
	char yourName[30];

	printf("Assignment #1-1, Quang Trinh, jasontrinh233@gmail.com\n");
	printf("What is your name?\n");
	gets(yourName);
	printf("Hello %s! \n", yourName);

	return 0;
}

