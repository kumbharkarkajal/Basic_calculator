#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "prototype.h"
void initInteger(Integer *a) {
	a->head = NULL;
	a->tail = NULL; 
	a->sign = 0;
}
void addDigit(Integer *a, char c) {  //Add  digit in a Integer type number
	int e = c - 48;
	node *b = a->tail, *d;
	if(b == NULL) {
		b = (node *)malloc(sizeof(node)*1);
		a->head = b;
		a->tail = b;
		if(c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c =='5'||  				c == '6'||c == '7'||c == '8'||c == '9')	{
			b->val = e;
			b->prev = NULL; 
			b->next = NULL;
		}
	}
	else {
		d = b;
		if(c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||
                  c == '6'||c == '7'||c == '8'||c == '9') {
			b = (node *)malloc(sizeof(node)*1);
			b->val = e;
			b->prev = d; 
			d->next = b;
			b->next = NULL;
			a->tail = b;
		}
	}  
}
Integer createIntegerFromString(char *str) {
	Integer z;
	initInteger(&z);
	node *x, *p;
	p = z.head;
	int j = 0, sum = 0, e;
	char a[100], b[100];
	strcpy(a, str);
	for(j = 0;j < strlen(a);j++) {
		if(a[j] == '0'||a[j] == '1'||a[j] == '2'||a[j] == '3'||a[j] ==
		 '4'||a[j] == '5'||a[j] == '6'||a[j] == '7'||a[j] == '8'||a[j]
		 == '9') {
			addDigit(&z, a[j]);
		}
		else
			break;
	}
	if(j == 0) {
		addDigit(&z, '0');			
		return z;
	}
	return z;
	
}
int getlen(Integer a) {    //returns number of digit in Integer
	int l = 0;
	node *ptr = a.head;
	while(ptr) {
		ptr = ptr->next;
		l++;
	}
	return l;

}
int isgreater(Integer a, Integer b) { //return which number is greater / equal  
	node *p1, *p2;
	p1 = a.head;
	p2 = b.head;
	while(p1) {
		if(p1->val > p2->val) {
			return 1;
		}
		else if(p2->val > p1->val) {
			return 2;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	return 0;
}
		
Integer subtractIntegers(Integer a1, Integer b1) {//substract two integers
	int borrow = 0, diff = 0, j = 0, len1, len2, s = 10, d1, d2;
	char ch;
	Integer n;
	len1 = getlen(a1);
	len2 = getlen(b1);
	node *a = a1.tail, *b = b1.tail;
	initInteger(&n);
	if(len1 == len2) {
		s = isgreater(a1 , b1);
	}
	if(s == 0) {
		ch = '0' + 0;
	//printf("0");
		addDigit(&n, ch);
		return n;
    	}
    	else if(s == 2) {
		n.sign = 1;
		s = 0;
		while(a != NULL || b != NULL) {
			diff = borrow + ((b? b->val : 0) - (a ? a->val : 0));
			borrow = (diff < 0)? -1 : 0;
			if(borrow < 0) 
				diff = diff + 10;	
			if(b) 
				b = b->prev;
			
			if(a) 
				a = a->prev;

			ch = '0' + diff;
			addDigit(&n, ch);
			s = s + diff;
	     	}
		reverse(&n);
		return n;
	}
	else if(s == 1) {
		s = 0;
		while(a != NULL || b != NULL) {
			diff = borrow + ((a? a->val : 0) - (b ? b->val : 0));
			borrow = (diff < 0)? -1 : 0;
			if(borrow < 0) 
				diff = diff + 10;	
			if(b) 
				b = b->prev;	
			if(a) 
				a = a->prev;
			ch = '0' + diff;
			addDigit(&n, ch);
			s = s + diff;
	     	}
		reverse(&n);
		return n;
	}
	else {
		j = 1;
		while(a != NULL || b != NULL) {
			d1 = (a)? a->val : 0;
			d2 = (b)? b->val : 0;
		    	diff = d1 - d2;
			if(len1 < len2) {
			     n.sign = 1;
			     s = 0;
			     while(a != NULL || b != NULL) {
					diff = borrow + ((b? b->val : 0) - (a ? a->val : 0));
					borrow = (diff < 0)? -1 : 0;
					if(borrow < 0) 
						diff = diff + 10;	
					if(b) 
						b = b->prev;	
					if(a) 
						a = a->prev;
					ch = '0' + diff;
					addDigit(&n, ch);
					s = s + diff;
	     		    }
			    reverse(&n);
			    return n;
			}
			else if(1) {
				s = 0;
				while(a != NULL || b != NULL) {
					diff = borrow + ((a? a->val : 0) - (b ? b->val : 0));
					borrow = (diff < 0)? -1 : 0;
					if(borrow < 0) 
						diff = diff + 10;	
					if(b) 
						b = b->prev;	
					if(a) 
						a = a->prev;
					ch = '0' + diff;
					addDigit(&n, ch);
					s = s + diff;
		     		     }
			     reverse(&n);
			     return n;
			}
			else if(diff < 0){
				diff = borrow + (-1) * diff;
				ch = '0' + diff;
				addDigit(&n, ch);
				borrow = diff;
				borrow = -1;
			}
			else{
				ch = '0' + diff;
				addDigit(&n, ch);
				borrow = diff;
				borrow = 0;
			}
			if(a)
				a = a->prev;
			if(b)
				b = b->prev;
			j = 0;
		}
	}
	reverse(&n);
	return n;	
}
		
void printInteger(Integer a)	{ //print number
	node *b;
	b = a.head;
	int j, k = 1;
	char c[100];
	for(j = 0; ;j++)	{
		c[j] = b->val + 48;
		b = b->next;
		if(k) {
			if(c[j] != '0')
				k = 0;
			else if(c[j] == '0')
				j--;
			else
				k = 0;
		}
		
		if(b == NULL)
           		break;
	}
	if(j < 0)
		printf("0");
	c[j+1] = '\0';
	if(a.sign == 1)
		printf("-");
	puts(c);
}

void reverse(Integer *l) { 		//reverse a number
	node  *p1, *p2;
	int temp;
   	p1 = l->head; 
	p2 = l->tail;
        while(p1!=p2 && p2 != p1->prev){
        	temp = p1->val;
        	p1->val = p2->val;
        	p2->val = temp;
        	p1=p1->next;
        	p2=p2->prev;
   	}
	
}

void destroyInteger(Integer *a)	{ // destroys number
	node *c = a->tail, *temp;
	while(c) {
		temp = c;
		c = c->prev;
		free(temp);
	}
}
Integer addIntegers(Integer a2, Integer b2) {  // add two numbers
	int carry = 0, sum = 0;
	char ch;
	Integer new;
	node *a = a2.tail, *b = b2.tail;
	initInteger(&new);
	while(a != NULL || b != NULL) {	
		sum = carry;
		if(a != NULL) {
			sum = sum + a->val;
			a = a-> prev;
		}
		if(b != NULL) {
			sum = sum + b->val;
			b = b-> prev;
		}
		carry = sum / 10;
		sum = sum % 10;
		ch = '0' + sum;
		addDigit(&new, ch);
	}
	if(carry > 0) {
		ch = '0' + carry;
		addDigit(&new, ch);
     	}
     	reverse(&new);
     	return new;
}

Integer multiplyIntegers(Integer a, Integer b) { //multiplies two numbers
	node *first = a.head, *second = b.head, *resptr1, *resptr2;
	Integer result;
	initInteger(&result);
	int len1 = getlen(a), len2 = getlen(b) , i = len1 + len2 + 1;
	int carry, mul;
	while(i--)
		addDigit(&result, '0');
	
	resptr1 = result.head;
	reverse(&a);
	reverse(&b);
	while(second) {
		carry = 0;
		resptr2 = resptr1;
		first = a.head;
		while(first) {
			mul = first->val * second->val + carry; 
			resptr2->val += mul % 10; 
			carry = mul / 10 + resptr2->val / 10;
			resptr2->val = resptr2->val % 10;
			first = first->next;
			resptr2 = resptr2->next;
		}
		if(carry > 0) {
			resptr2->val += carry;
		}
		resptr1 = resptr1->next;
		second = second->next;
	}
	reverse(&a);
	reverse(&b);
	reverse(&result);
	return result;
}
Integer divideIntegers(Integer a1, Integer b1) {  // divides two numbers
	long long unsigned int num1 = 0, num2 = 0, num3;
	node *first = a1.head, *second = b1.head;
	Integer result;
	initInteger(&result);
	char ch;
	while(first || second) {
		if(first){
			num1 = num1 * 10 + first->val;
			first = first->next;
		}
		if(second){
			num2 = num2 * 10 + second->val;
			second = second->next;
		}
	}
	num3 = num1 / num2;
	if(num3 <= 0) {
		addDigit(&result,'0');
		return result; 
	}
	while(num3 > 0) {
		ch = '0' + num3 % 10;
		num3 = num3 / 10;
		addDigit(&result, ch);
	}
	reverse(&result);
	return result;
}
