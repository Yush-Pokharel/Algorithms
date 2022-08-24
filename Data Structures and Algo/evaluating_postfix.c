#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct stack {
	int array[20];
	int top = -1;
};

void push(stack *s,char x) {
	s->array[++s->top] = x;
}

int pop(stack *s) {
	return s->array[s->top--];
}

int main() {
	stack st;
	char exp[20];
	char *e;
	int n1,n2,n3,num;
	printf("Enter the expression \n");
	gets(exp);
	e = exp;
	while(*e != '\0') {
		if(isdigit(*e)) {
			num = *e - 48;
			push(&st,num);
		} else {
			n1 = pop(&st);
			n2 = pop(&st);
			switch(*e) {
				case '+': {
					n3 = n1 + n2;
					break;
				}
				case '-': {
					n3 = n2 - n1;
					break;
				}
				case '*': {
					n3 = n1 * n2;
					break;
				}
				case '/': {
					n3 = n2 / n1;
					break;
				}
			}
			push(&st,n3);
		}
		e++;
	}
	printf("\nThe result of expression = %d ",pop(&st));
	return 0;
}