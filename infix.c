#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>
#include"stack1.h"
#include"stack2.h"
int i = 0;
token getnext(char *str){ // return next token
	Integer x;
	initInteger(&x);
	int j;
	token t;
	char ch;
	while(str[i] == ' '|| str[i] == ','|| str[i] == '\t') {
		i++;
	}
	if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || 
          str[i] == '4'|| str[i] == '5' || str[i] == '6' || str[i] == '7' || 
          str[i] == '8' || str[i] == '9'){
			for(j = 0; isdigit(str[i]); j++) {
				addDigit(&x, str[i]);
				i++;
			}
			t.type = OPERAND;       //returns operand
			t.data.num = x;
			return t;
	}
	else if(str[i] == '\0') {
		t.type = END;
		return t;
	}
	else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] ==
		'/') {
			t.type = OPERATOR;	//return operator
			t.data.op = str[i];
			i++;
			return t;
	}
	else {
		t.type = ERR;			//return error token
		return t;
	}
	return t;
}

int prec(char op){ // returns precedence of operator
	switch(op) {
		case '+': case '-':
			return 1;
		case '/': case '*':
			return 2;
		default:
			return 0;

	}
}
int infixeval(char *infix){ // infix evaluation of given string
	stack1 s1;
	stack2 s2;
	i = 0;
	Integer x, y, z;
	initInteger(&x);
	initInteger(&y);
	initInteger(&z);
	char d, e;
	initint(&s1);
	initchar(&s2);
	token t;
	while(1){
		t = getnext(infix);
		if(t.type == OPERAND){
			if(!isfullint(&s1))
				pushint(&s1, t.data.num);//push operand in stack
			else{
				printf("INTMIN 1\n");
				return INT_MIN;
			}
		}
		else if(t.type == OPERATOR){
			if(!isemptychar(&s2)){
				d = peekchar(&s2);
				if(prec(d) >= prec(t.data.op)) { 
					if(!isemptyint(&s1))
						x = popint(&s1);
					else{
						printf("INTMIN 2\n");
						return INT_MIN;
					}
					if(!isemptyint(&s1))
						y = popint(&s1);
					else{
						printf("INTMIN 3\n");
						return INT_MIN;
					}
					if(!isemptychar(&s2))
						e = popchar(&s2);
					else{
						printf("INTMIN 4\n");
						return INT_MIN;
					}
				  	switch(e) {
				   		case '+':
						    	z = addIntegers(y, x);
							break;
				   		case '*':
							z = multiplyIntegers(y, x);							break;
				   		case '-':
							z = subtractIntegers(y, x);							break;
				  		case '/':
							z = divideIntegers(y, x);							break;
				   		default:
							break;
			          	}
				  	if(!isfullint(&s1))
						pushint(&s1, z);
				  	else{
						printf("INTMIN 4\n");
						return INT_MIN;
				  	}
				  	if(!isfullchar(&s2))
						pushchar(&s2, t.data.op);
				  	else{
						printf("INTMIN 5\n");
						return INT_MIN;
				 	 }
				}
			        else{
			     		if(!isfullchar(&s2))
						pushchar(&s2, t.data.op);
					else{
						printf("INTMIN 6\n");
						return INT_MIN;
					}
			    	}
			}
		        else{
				if(!isfullchar(&s2))
					pushchar(&s2, t.data.op);
				else{
					printf("INTMIN 7\n");
					return INT_MIN;
				}
		 	}
		}
		else if(t.type == END){
	   		while(1) {
				if(!isemptyint(&s1))
					x = popint(&s1);
				else
					break;
				if(!isemptyint(&s1))
					y = popint(&s1);
				else
					break;
				if(!isemptychar(&s2))
					e = popchar(&s2);
				else
					break;
				switch(e) {
					case '+':
						z = addIntegers(y, x);
						break;
					case '*':
						z = multiplyIntegers(y, x); 
						break;
					case '-':
						z = subtractIntegers(y, x);
						break;
					case '/':
						z = divideIntegers(y, x);
						break;
					default:
						break;
				}
				if(!isfullint(&s1))
					pushint(&s1, z);
				else{
					printf("INTMIN 8\n");
					return INT_MIN;
				}
	    		}
			printInteger(z);		
			return 1;
		}
		else if(t.type == ERR){
			printf("INTMIN 9\n");
			return INT_MIN;
		}
	}	
	
}

