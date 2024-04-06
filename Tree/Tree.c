#include<stdlib.h>
#include<stdio.h>
#include"Queue.h"
#include"stack.h"

struct node *root = NULL;
void create()
{
    struct node *p , *t;
    int x;
    struct Queue q;
    createq(&q,100);
    printf("Enter the root value:\n");
    scanf("%d",&x);
    root = (struct node *)malloc(sizeof(struct node ));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child :\n");
        scanf("%d",&x);
        if(x != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter right child :\n");
        scanf("%d  ",&x);
        if(x != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}
void preorder(struct node *p){
    if(p){
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void ipreorder(struct node *p){
    struct Stack st;
    createst(&st,20);
    while(p || !isEmptyStack(st)){
        if(p){
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        }else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}
void levelorder(struct node *p){
    struct Queue q;
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p= dequeue(&q);
        if(p->lchild){
            printf("%d ", p->lchild->data);
            enqueue(&q,p->lchild);
        }if(p->rchild){
            printf("%d ", p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int main(){
    create();
    levelorder(root);
    return 0;
}
