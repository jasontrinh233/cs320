/*
 * prog1_3.c
 * ==========================
 * Driver program that takes
 * single command line arg as
 * a program input.
 * ==========================
 * CS320-02
 * 02.04.18
 * Author: Quang Trinh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog1_2.h"

int main(int argc, char *argv[])
{
    printf("Assignment #1-3, Quang Trinh, jasontrinh233@gmail.com\n");

    /* if not single command line argument, exit the program */
    if(argc != 2) {
        printf("\n");
        printf("This program expects a single command line argument.\n"); /* Error */
        return 0;
    } else {
        STACK* s = MakeStack(3);
        char in[256];	/* user input */

        /* user pass in the number of argument lines */
        for(int argCount = 0; argCount < atoi(argv[1]); ++argCount){
            printf("> ");
            fgets(in, sizeof(in), stdin);

            char *p = strtok(in, " \n");
            char *token[10];
            int i = 0;
            int wordCount = 0;

            /* store each word into an array token[] */
            while(p != NULL){
            	token[i] = p;
            	p = strtok(NULL, " \n");
            	wordCount++;
            	i++;
            }
            if( (wordCount == 1) && strcmp(token[0], "pop") == 0){
                printf("%d\n", Pop(s));
            } else if(wordCount == 2 && strcmp(token[0], "push") == 0){
                Push(s, atoi(token[1]));
            }
        }
    }
    return 0;
}
