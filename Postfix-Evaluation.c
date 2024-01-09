#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char stack[50];
int tos = -1;
void infixtopostfix(char [],char []);
bool isoperator(char token)
{
    switch(token)
    {
        case '%':
        case '*':
        case '/':
        case '+':
        case '-':return true;
        default:return false;
    }
}
int getpriority(char token)
{
    
    if(token == '%'||token == '*'||token == '/')
            return 2;
       
    else if(token == '+'||token == '-')
            return 1;
            
    else if(token == '(')
            return 0;
            
}
void push(char token)
{
    stack[++tos] = token;
}
char pop()
{
    return  stack[tos--];
}
char peep()
{
    return stack[tos];
}
int main()
{
    char postfix[10];
    printf("Enter infix expression");
    scanf("%s",postfix);
    // process
    infixtopostfix(postfix);
}
void infixtopostfix(char postfix[])
{
    int i,j;
    char x,token;
    int res;
    for(i = 0,j = 0; '\0'!= infix[i];i++)
    {   
        token = infix[i];
        if(token == isoperator)
        {
            op2 = pop();
            op1 = pop();
            res = compute(op1,token,op2);
            push(res);
        }
        else
            push(token -'0');
    }
    res = pop();
    return res;
    
}

