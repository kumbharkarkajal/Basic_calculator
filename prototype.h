#include<stdio.h>
typedef struct node	{
	int val;
	struct node *prev;
	struct node *next;
}node;
typedef struct Integer {
	node *head, *tail;
	int sign;
}Integer;
typedef struct var {
	char name[25];
	struct var *next;
}var;
struct token{
	char type;
	union data{
		Integer num;
		char op;
	}data;
};
typedef struct token token;

#define OPERATOR 1
#define OPERAND 2
#define END 3
#define ERR 4
void initInteger(Integer *a); 
void addDigit(Integer *a, char c);
Integer createIntegerFromString(char *str);
Integer addIntegers(Integer a, Integer b);
Integer subtractIntegers(Integer a, Integer b);
Integer multiplyIntegers(Integer a, Integer b);
Integer divideIntegers(Integer a1, Integer b1);
void printInteger(Integer a);
void destroyInteger(Integer *a);
void reverse(Integer *a);
int getlen(Integer a);
int isgreater(Integer a, Integer b);

void setVariable(char *s, Integer x, var **v);
Integer negation(char *s, var **v);
Integer unaryPlus(char *s, char *str, var **v);
Integer unaryMinus(char *s, char *str, var **v);
int position(char *s, var **v);
Integer element(char *str, var **v);
void createVar(char *s, var **v);
void initVar(var **v);
void traverseVar(var **v);

int notEqualTo(Integer x,Integer y);
int lessThanEqualTo(Integer x, Integer y);
int greaterThanEqualTo(Integer x ,Integer y);
int greaterThan(Integer x, Integer y);
int isEqualto(Integer x, Integer y);
int lessThan(Integer x ,Integer y);

int logicalNot(Integer a);
int logicalAnd(Integer x, Integer y);
int logicalOr(Integer x, Integer y);
int error(int count, char *op);


token getnext(char *str);
int prec(char op);
int infixeval(char *infix);
