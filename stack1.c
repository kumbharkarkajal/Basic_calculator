#include<stdio.h>
#include<stdlib.h>
#include "stack1.h"
void initint(stack1 *s) {
	s->head = NULL;
}
int isfullint(stack1 *s) {
	return 0;
}
int isemptyint(stack1 *s) {
	return s->head == NULL;
}
void pushint(stack1 *s, Integer no) {
	NODE *ptr = s->head, *tmp = (NODE*)malloc(sizeof(NODE));
	if(!tmp)
		return;
	tmp->val = no;
	tmp->next = NULL;
	tmp->prev = NULL;
	if(!ptr) {
		s->head = tmp;
	}
	else {
		ptr->next = tmp;
		tmp->prev = ptr;
		s->head = tmp;
	}
	
}
Integer popint(stack1 *s) {
	NODE *tmp = s->head;
	Integer val = s->head->val;
	if(s->head->prev == NULL)
		s->head = NULL;
	else
		s->head = s->head->prev;
	free(tmp);
	return val;
}
Integer peek(stack1 *s) {
	Integer ch;
	ch = popint(s);
	pushint(s, ch);
	return ch;
}





