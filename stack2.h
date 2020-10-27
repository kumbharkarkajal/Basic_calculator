typedef struct Node {
	char val;
	struct Node *next, *prev;
}Node;

typedef struct Stack {
	Node *head;
}stack2;
void initchar(stack2 *s);
int isfullchar(stack2 *s);
int isemptychar(stack2 *s);
void pushchar(stack2 *s, char no);
char popchar(stack2 *s);
char peekchar(stack2 *s);
