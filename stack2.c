#include<stdio.h>
#include<stdlib.h>
#include "stack2.h"
void initchar(stack2 *s) {
	s->head = NULL;
}
int isfullchar(stack2 *s) {
	return 0;
}
int isemptychar(stack2 *s) {
	return s->head == NULL;
}
void pushchar(stack2 *s, char no) {
	Node *ptr = s->head, *tmp = (Node*)malloc(sizeof(Node));
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
char popchar(stack2 *s) {
	Node *tmp = s->head;
	char val = s->head->val;
	s->head = s->head->prev;
	free(tmp);
	return val;
}
char peekchar(stack2 *s) {
	char ch;
	ch = popchar(s);
	pushchar(s, ch);
	return ch;
}





