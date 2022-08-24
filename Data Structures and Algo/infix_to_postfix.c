#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 20

struct stack{
    int top;
    char array[MAX];
};

void push(stack *s,char n){
    s->top += 1;
    s->array[s->top] = n;
}

char pop(stack *s){
    char poped;
    poped = s->array[s->top];
    s->top -= 1;
    return poped;
}

void traverse(stack *s){
    for( int i = 0; i  <=s->top; i++){
        printf("%c",s->array[i]);
    }   
}

void clear(stack *s){
    s->top = -1;
}

char peek(stack *s){
    return (s->array[s->top]);
}

bool isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char n){
    if (n == '(')
        return 1;
    else if(n == '^')
        return 4;
    else if(n == '/' || n =='*')
        return 3;
    else if(n == '+' || n =='-')
        return 2;
    else
        return 0;
}

int main(){
    stack post_stack, op_stack;
    clear(&post_stack);
    clear(&op_stack);
    char array[MAX];
    printf("enter the infix expression: \n");
    gets(array);
    for(int i = 0; i < strlen(array); i++){
        if (array[i] == '('){
            push(&op_stack,array[i]);
        }
        else if(isalpha(array[i])){
            push(&post_stack,array[i]);
        }
        else if( precedence(array[i]) > 1){
            char top = peek(&op_stack);
            if(precedence(top)>1 ){
                char top_p = precedence(top);
                char array_p = precedence(array[i]);
                if(top_p < array_p){
                    push(&op_stack,array[i]);
                }
                else if(top_p >= array_p){
                    char receive = pop(&op_stack);
                    push(&post_stack, receive);
                    push(&op_stack,array[i]);
                    if(precedence(op_stack.array[op_stack.top-1]) > 0){
                    	char skip = pop(&op_stack);
                    	i--;                    	
					}
                }
            }
            else{
                push(&op_stack,array[i]);
            }
        }
        else if (array[i] == ')'){
            while(op_stack.array[op_stack.top] != '('){
                char get = pop(&op_stack);
                push(&post_stack,get);
            }
            if(op_stack.array[op_stack.top] == '('){
                char discard = pop(&op_stack);
            }
        }
    }
    while(op_stack.top != -1){
        char obtained = pop(&op_stack);
        push(&post_stack,obtained);
    }
    printf("postfix is: \n");
	traverse(&post_stack);
}