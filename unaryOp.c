#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "prototype.h"
/* All functions in this file performs Unary Operations */

static int count = 0;
Integer a[50], b, d;
void initVar(var **v) {
	*v = NULL;
}
void createVar(char *s, var **v) { // Create variable and initialize it
	var *ptr = *v;
	var *new = (var *)malloc(sizeof(var));
	if(!new)
		return;
	strcpy(new->name, s);
	new->next = NULL;
	if(ptr == NULL) 
		*v = new;
		
	else {
		while(ptr->next != NULL) 
			ptr = ptr->next;
		ptr->next = new;	
	}
	
}
void setVariable(char *s, Integer x, var **v) {  //update value of variable
	static int index = 0;
	int i = position(s, v);
	if(i != -1) {
		a[i] = x;
	}		
	createVar(s, v);
	a[index] = x;
	index++;
	count++;
}
Integer negation(char *s, var **v) {
	int i = 0;
	i = position(s, v);
	if(i == -1) {
		initInteger(&b);
		addDigit(&b, '0');
		//printf("0");
		return b;
	}
	b = a[i];		
	b.sign = 1;	
	reverse(&b);
	return b;
}
Integer unaryPlus(char *s, char *str, var **v) {
	int i = 0, j;
	while(s[i] == ' '|| s[i] == '\t') {
		i++;
	}
	j = position(str, v);
	if(j == -1) {
		initInteger(&b);
		addDigit(&b, '1');
		setVariable(str, b, v);
		if(s[i] == '+')
			return b;
		else {
			initInteger(&b);
			addDigit(&b, '0');
			//printf("0");
			return b; 
		}
	}
	if(s[i] == '+') {
		initInteger(&b);
		addDigit(&b, '1');
		a[j] = addIntegers(a[j], b);
		return a[j];
	}
	else {
		initInteger(&b);
		initInteger(&d);
		addDigit(&b, '1');
		d = a[j];
		a[j] = addIntegers(a[j], b);
		return d;
	}

}

Integer unaryMinus(char *s, char *str, var **v) {
	int i = 0, j;
	while(s[i] == ' '|| s[i] == '\t') {
		i++;
	}
	j = position(str, v);
	if(j == -1) {
		initInteger(&b);
		addDigit(&b, '1');
		b.sign = 1;
		setVariable(str, b, v);
		if(s[i] == '-')
			return b;
		else {
			initInteger(&b);
			addDigit(&b, '0');
			//printf("0");
			return b;
		}
	}
	if(s[i] == '-') {
		initInteger(&b);
		addDigit(&b, '1');
		a[i] = subtractIntegers(a[i], b);
		return a[i];
	}
	else {
		initInteger(&b);
		initInteger(&d);
		addDigit(&b, '1');
		d = a[i];
		a[i] = subtractIntegers(a[i], b);
		return d;
	}

}
int position(char *s, var **v) {
	int i = 0;
	var *ptr = *v;
	while(ptr){
		if(strcmp(s , ptr->name) == 0)	
			return i;
		ptr = ptr->next;
		i++;
	}
	return -1;
	
}
Integer element(char *str, var **v) { //return Integer number associated with
	int i;			      //specific variable
	i = position(str, v);
	if(i != -1) 
		return a[i];
	initInteger(&b);
	addDigit(&b, '0');
	return b;
}
