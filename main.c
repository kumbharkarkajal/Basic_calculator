#include<stdio.h>
#include<string.h>
#include<limits.h>
#include "prototype.h"

int main() {
	char ch;
	Integer x, y;
	var *v;
	initVar(&v);
	int count = 0;
	while(1) {
		initInteger(&x);
		initInteger(&y);
		count++;
		char ch, op[10] = "", str[50] = "", s[200] = "", str2[50]; 
		int i =1, j = 0, k = 0, l = 0, sp = 0, c = 0, w = 0, d = 0;
		//read character by character till enter or ctrl + D
		while((ch = getchar()) != '\n' && ch != EOF) { 
			s[l++] = ch;
			if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z')){				d++;
				c = ch;
				if(k == -1)
					str2[++k] = ch;
				else
					str[k++] = ch;
			}
		        else if(ch == '+' || ch == '-'|| ch == '/'|| ch == '*'||
                        ch == '='|| ch == '>'|| ch == '!' || ch == '<' || ch == 			'&'|| ch == '|'|| ch == '^' || ch == '@' || ch == '~' ||
			 ch == '?' || ch == '%' || ch == '$' || ch == '#') {
				op[j++] = ch;
				i = 0;	
				k = -1;
			}
			else if(ch == ' ' || ch == '\t')
				sp++;		
			else if(i)
				addDigit(&x, ch);
			else
				addDigit(&y, ch);
		}
		s[l] = '\0';
		op[j] = '\0';
		w = error(count, op); // prints error if any
		if(w == 1)
			continue;
		switch(op[0]) {
			case '+':
				if(op[1] == '+' && d) {
					if(k == -1)
						x = unaryPlus(s, str, &v);
					else
						x = unaryPlus(s, str2, &v);	
					printInteger(x);
				}
				else if(!x.head || !y.head || op[1] == '\0'){  
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					x = addIntegers(x, y);
					printInteger(x);
				}
				else {  
					w = infixeval(s);
					if(w == INT_MIN)
						printf("ERROR\n");
				}
				break;
			case '-':
				if(op[1] == '-') {
					if(k == -1)
						x = unaryMinus(s, str, &v);
					else
						x = unaryMinus(s, str2, &v);
					printInteger(x);
				}
				else if(y.head == NULL && s[0] == '-') {

					x = negation(str2, &v);
					printInteger(x);
				}
				else if(!x.head || !y.head || op[1] == '\0'){ 
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					x = subtractIntegers(x, y);
					printInteger(x);
				}
				else {	
					w = infixeval(s);
					if(w == INT_MIN)
						printf("ERROR\n");
				}
				break;
			case '*':
				if(!x.head || !y.head || op[1] == '\0') {
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					x = multiplyIntegers(x, y);
					printInteger(x);
				}
				else {
					w = infixeval(s);
					if(w == INT_MIN)
						printf("ERROR\n");
				}
				break;
			case '/':
				if(!x.head || !y.head || op[1] == '\0'){
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					if(y.head->val == 0) {
						printf("\nRuntime error :divide by zero\n");
						break;
					}
					x = divideIntegers(x, y);
					printInteger(x);
				}
				else {
					w = infixeval(s);
					if(w == INT_MIN)
						printf("ERROR\n");
				}
				break;
			case '=':
				if(op[1] == '=') {
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					c = isEqualto(x, y);
					printf("%d\n", c);
				}
				else 
					setVariable(str, y, &v);
				break;
			case '>':
				if(!(x.head)) 
					x = element(str, &v);
				if(!(y.head))
					y = element(str2, &v);
				if(op[1] == '=') 
					c = greaterThanEqualTo(x, y);
				else 
					c = greaterThan(x,y);
				printf("%d\n", c);
				break;
			case '<':
				if(!(x.head)) 
					x = element(str, &v);
				if(!(y.head))
					y = element(str2, &v);
				if(op[1] == '=') 
					c = lessThanEqualTo(x, y);
				else 
					c = lessThan(x , y);
				printf("%d\n", c);
				break;
			case '!':
				if(!(x.head)) 
					x = element(str, &v);
				if(!(y.head))
					y = element(str2, &v);
				if(op[1] == '=') 
					c = notEqualTo(x, y);
				else 
					c = logicalNot(y);
				printf("%d\n", c);
				break;
			case '&':
				if(op[1] == '&') {
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					if(op[1] == '&')
						c = logicalAnd(x, y);
					printf("%d\n", c);
				}				
				else
					printf("%d: syntax error\n", count);
				break;
					
			case '|':
				if(op[1] == '|') {
					if(!(x.head)) 
						x = element(str, &v);
					if(!(y.head))
						y = element(str2, &v);
					if(op[1] == '|')
						c = logicalOr(x, y);
					printf("%d\n", c);
				}
				else
					printf("%d: syntax error\n", count);
				break;
			default:
				//printf("inside default");
				if(ch == EOF)
					return 0;				
				y = element(str, &v);
				if(x.head)
					printInteger(x);
				else if(y.head)
					printInteger(y);
				else 
					printf("0\n");
				break;
		}
	}
	return 0;
}

