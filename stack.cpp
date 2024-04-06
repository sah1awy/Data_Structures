#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct stac{
    int data;
    struct stac *next;
}*top = NULL;

void push(int x){
        struct stac *p;
        p = (struct stac*)malloc(sizeof(struct stac));
        if(p == NULL)
            printf("stack is full\n");
        else{
            p->data = x;
            p->next = top;
            top = p;
    }
}
int pop(){
    int x = -1;
    struct stac *p;
    if(top == NULL)
        printf("stack is empty");
    else{
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}
void display(){
    struct stac *p;
    p = top;
    while(p){
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}
char stacktop(){
    if(top)
        return top->data;
    return -1;
}
int isbalanced(char *exp){
    int i =0;
    while(exp[i] != '\0')
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
            {
                if(top == NULL)
                    return 0;
                pop();
            }
            i++;
        }
        if(top == NULL)
            return 1;
        return 0;
}
int outpre(char x){
     if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
            return 0;
}
int inpre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 100;
}
int isop(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'|| x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}
char * InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    long len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(isop(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(outpre(infix[i])>inpre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
        }
    }
 }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}
int eval(char *postfix)
{
    int i =0;
    int x1,x2,r=0;
    for(i=0;postfix[i] !='\0';i++){
        if(isop(postfix[i]))
            push(postfix[i]-'0');
        else{
            x2 = pop();x1= pop();
            switch(postfix[i]){
                case'+': r = x1+ x2;break;
                case'-': r = x1- x2;break;
                case'*': r = x1* x2;break;
                case'/': r = x1/ x2;break;
            }
            push(r);
        }
    }
    return top->data;
}
int main(){
    char *infix = "35+2*";
    printf("Result is:%d",eval(infix));
    return 0;
}
