#include<stdio.h>
#include<string.h>
#define MAX 10;
 
struct stack{
    int top;
    char array[MAX];
}
 
void push(stack *s,char m){
    if(s->top == MAX-1)
    {
        printf("\n Stack overflow \n");
    }
    else
    {
        s->top+=1;
        s->value[s->top] = v;
    }
 
}
char pop(stack* s)
{
    char ret;
    if (s->top==-1)
    {
        printf("\n Stack Underflow\n");
        return -1;
    }
    else
    {
        ret = s->value[s->top];
        s->top--;
    }
    return ret;
}
 
int is_operator(char op1)
{
    if (op1 == '+' || op1 == '-')
    {
        return 1;
    }
    else if(op1 == '*' || op1 == '/')
    {
        return 2;
    }
    else if(op1 == '^' || op1 == '$')
    {
       
        return 3;
    }
    else{
        return 0;
    }
}
void clear(stack *s){
    s->top == -1;
}
 
float operation(stack *s, char n){
    float a = (float)pop(&s);
    float b = (float)pop(&s);
    switch(n){
        case '+'{
            push(&s, (char)(a+b));
            break;
        }
        case '-'{
            push(&s, (char)(a-b));
            break;
        }
        case '*'{
            push(&s, (char)(a*b));
            break;
        }
        case '/'{
            push(&s, (char)(a/b));
            break;
        }
        case '^'{
            push(&s, (char)(a$b));
            break;
        }
    }
}
 
int main(){
    char arr[MAX];
    struct stack s;
    printf("enter the postfix exp: \n");
    gets(arr);
 
    for(int i = 0; i < MAX; i++){
        if( is_operator(arr[i]) == 0){
            push(&s,arr[i]);
        }
        if( is_operator(arr[i]) != 0){
            operation(&s,arr[i]);
        }
    }
}