#include<stdio.h>
#include "prototype.h"
/* All functions in this file performs Logical Operations */
int logicalNot(Integer a) {
	if(a.head->val == 0)
		return 1;
	else
		return 0;

}
int logicalAnd(Integer x, Integer y) {
	if((x.head->val != 0) && (y.head->val != 0) )
		return 1;
	else
		return 0;
}
int logicalOr(Integer x, Integer y) {
	if((x.head->val != 0) || (y.head->val != 0))
		return 1;
	else
		return 0;

}
int error(int count, char *op) { //Displays error if any
	if(op[0] == '^' || op[0] == '@' || op[0] == '~' || op[0] == '?' || op[0]
	 == '%' || op[0] == '$' || op[0] == '#' ) {
		printf("%d: syntax error\n", count);
		return 1;
	}
	else if(op[1] == '^' || op[1] == '@' || op[1] == '~' || op[1] == '?' || 
		op[1] == '%' || op[1] == '$' || op[1] == '#' ) {
		printf("%d: syntax error\n", count);
		return 1;
	}
	else	
		return 0;
	
}
