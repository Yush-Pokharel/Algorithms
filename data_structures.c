#include<stdio.h>
#include<ctype.h>
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

char peek(stack *s){
    return (s->array[s->top]);
}

int precedence(char n){
    if (n == '(')
        return 5;
    else if(n == "^")
        return 4;
    else if(n == "/" || n =="*")
        return 3;
    else if(n == "+" || n =="-")
        return 2;
    else
        return 0;
}

int main(){
    char array[MAX], operands[MAX], top_value;
    stack st;
    int j;
    printf("enter the infix: \n");
    gets(array);
    clear(&st);
    for( int i = 0, j ; i < MAX; i++){
        if(isalnum(array[i]) == 1){
            operands[j] = array[i];
            j++;
        }
        else{
            if(array[i] == '('){
                push(&st,array[i]);
            }
            else{
                top_value = peek(&st);
                if(isalnum(top_value)==0){

                }
            }
            while( precedence(st.array[st.top]) > precedence(array[i])){
                c = pop(&st);
                operands[j] = c;
                j++;
            }
        }
    }
}