#include<stdio.h>
#include "prototype.h"
typedef struct NODE {
	Integer val;
	struct NODE *next, *prev;
}NODE;

typedef struct stack { 
	NODE *head;
}stack1;

void initint(stack1 *s);
int isemptyint(stack1 *s);
int isfullint(stack1 *s);
void pushint(stack1 *s, Integer no);
Integer popint(stack1 *s);
Integer peek(stack1 *s);
