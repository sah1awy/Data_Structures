#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdlib.h>

struct node{
    struct node *lchild;
    struct node *rchild;
    int data;
};
struct Queue{
    int f;
    int r;
    int size;
    struct node **Q;
};
void createq(struct Queue *q,int size){
    q->size = size;
    q->f = q->r = 0;
    q->Q = (struct node **)malloc(q->size * sizeof(node *));
}
void enqueue(struct Queue *q,struct node *x){
    if((q->r+1)%q->size == q->f)
        printf("Queue is full\n");
    else{
        q->r = (q->r+1)%q->size;
        q->Q[q->r] = x;
    }
}
struct node * dequeue(struct Queue *q){
    struct node *x;
    if(q->r == q->f)
        printf("Queue is empty\n");
    else{
        q->f = (q->f+1)%q->size;
        x = q->Q[q->f];
    }
    return x;
};
int isEmpty(struct Queue q){
    return q.f == q.r;
}
#endif
