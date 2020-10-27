#include<stdio.h>
#include "prototype.h"
/* All functions in this file performs Relational Operations */
int isEqualto(Integer x, Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 != len2)
		return 0;
	while(a) {
		if(a->val == b->val)
			count++;
		else
			return 0;
		a = a->next;
		b = b->next;
	}
	return 1;
}
int greaterThan(Integer x, Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 > len2)
		return 1;
	else if(len1 == len2) {
		if(a) {
			if(a->val > b->val)
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}
int greaterThanEqualTo(Integer x ,Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 > len2)
		return 1;
	else if(len1 == len2) {
		while(a) {
			if(a->val == b->val || a->val > b->val)
				count++;
			else
				return 0;
			a = a->next;
			b = b->next;
		}
		return 1;
	}
	return 0;
}
int lessThanEqualTo(Integer x, Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 < len2)
		return 1;
	else if(len1 == len2) {
		while(a) {
			if(a->val == b->val || a->val < b->val)
				count++;
			else
				return 0;
			a = a->next;
			b = b->next;
		}
		return 1;
	}
	return 0;

}
int lessThan(Integer x ,Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 < len2)
		return 1;
	else if(len1 == len2) {
		if(a) {
			if(a->val < b->val)
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}
int notEqualTo(Integer x,Integer y) {
	node *a = x.head, *b = y.head;
	int len1 = getlen(x), len2 = getlen(y), count = 0;
	if(len1 < len2 || len1 > len2)
		return 1;
	else if(len1 == len2) {
		while(a) {
			if(a->val == b->val)
				count++;
			else
				return 0;
			a = a->next;
			b = b->next;
		}
		return 0;
	}
	else 
		return 0;
}
