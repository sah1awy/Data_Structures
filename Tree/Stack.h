#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include"Queue.h"
#include<stdlib.h>
struct Stack{
    int top;
    int size;
    struct node **s;
};
void createst(struct Stack *st,int s){
    st->size = s;
    st->top = -1;
    st->s = (struct node **)malloc(st->size * sizeof(struct node *));
}
void push(struct Stack *st,struct node *x){
    if(st->top == st->size-1)
        printf("Stack overflow\n");
    else{
        st->top++;
        st->s[st->top] = x;
    }
}
struct node *pop(struct Stack *st){
    struct node *x ;
    if(st->top == -1)
        printf("Stack is empty\n");
    else{
        x = st->s[st->top--];
    }
    return x;
};
int isEmptyStack(struct Stack st){
    if(st.top == -1)
        return 1;
    return 0;
}
int isFullStack(struct Stack st){
    if(st.top == st.size-1)
        return 1;
    return 0;
}


#endif // STACK_H_INCLUDED
