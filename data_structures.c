#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct stack(){
    int top;
    char array[MAX];
}

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

void clear(stack *s){
    s->top = -1;
}

int precedence(char n){
    if (n == '(')
        return 1;
    else if(n == "^")
        return 2;
    else if(n == "/" || n =="*")
        return 3;
    else if(n == "+" || n =="-")
        return 4;
    else
        return 0;
}

int main(){
    char array[MAX], operands[MAX];
    stack st;
    printf("enter the infix: \n");
    gets(array);
    clear(&st);
    for( int i = 1; i < MAX; i++){
        if(array[i] == '('){
            push(&st,array[i]);
        }

    }
}