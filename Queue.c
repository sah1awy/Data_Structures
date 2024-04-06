#include<stdlib.h>
#include<stdio.h>

struct Queue{
    int s;
    int f;
    int r;
    int *q;
};
void create(struct Queue *q,int size){
    q->s = size;
    q->f = q->r = 0;
    q->q = (int *)malloc(q->s*sizeof(int ));
}
void enqueue(struct Queue *q,int x){
    if((q->r+1)%q->s == q->f)
        printf("Queue is full\n");
    else{
        q->r = (q->r+1)%q->s;
        q->q[q->r] = x;
    }
}
int dequeue(struct Queue *q){
    int x = -1;
    if(q->f == q->r)
        printf("Queue is empty\n");
    else{
        q->f = (q->f+1)%q->s;
        x = q->q[q->f];
    }
    return x;
}
void display(struct Queue q){
    int i = (q.f+1)%q.s;
    do{
        printf("%d ",q.q[i]);
        i = (i+1)%q.s;
    }while(i != (q.r+1)%q.s);
    printf("\n");
}

int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    display(q);
    printf("%d ",dequeue(&q));
    return 0;
}

//____________________________________________________________________

#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*f=NULL,*r=NULL;

void enqueue(int x){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
        printf("queue is full\n");
    else{
        t->data = x;
        t->next = NULL;
        if(f == NULL)
            f = r = t;
        else{
            r->next = t;
            r = t;
        }
    }
}
int dequeue(){
    int x = -1;
    struct node *p;
    if(f == r)
        printf("queue is empty\n");
    else{
        p = f;
        f = f->next;
        x = p->data;
        free(p);
    }
    return x;
}
void display(){
    struct node *p = f;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("%d\n",dequeue());
    return 0;
}

//_______________________________________________________________________________________
#include<stdlib.h>
#include<stdio.h>
struct queue{
    int f;
    int r;
    int *a;
    int s;
};
void create(struct queue*q,int size){;
    q->s = size;
    q->a = (int *)malloc(q->s*sizeof(int));
    q->r = q->f = -1;
}
void enqueuefront(struct queue *q,int x){
    if(q->f == -1)
        printf("DEqueue overflow\n");
    else{
        q->a[q->f] = x;
        q->f--;
    }
}
void enqueuerear(struct queue *q,int x){
    if(q->r == q->s-1)
        printf("DEqueue overflow\n");
    else{
        q->r++;
        q->a[q->r] = x;
    }
}
int dequeuefront(struct queue *q){
    int x = -1;
    if(q->r == q->f)
        printf("queue underflow\n");
    else{
        q->f++;
        x = q->a[q->f];
    }
    return x;
}
int dequeuerear(struct queue *q){
    int x;
    if(q->r == -1)
        printf("queue is underflow\n");
    else{
        x = q->a[q->r];
        q->r--;
    }
    return x;
}
void display(struct queue *q)
{
    int i;
    for(i=q->f+1;i<=q->r;i++){
        printf("%d ",q->a[i]);
    }
    printf("\n");
}
int main(){
    struct queue s;
    create(&s,10);
    enqueuerear(&s,10);
    enqueuerear(&s,20);
    enqueuerear(&s,30);
    enqueuerear(&s,40);
    enqueuerear(&s,50);
    dequeuerear(&s);
    dequeuefront(&s);
    display(&s);
    enqueuefront(&s,100);
    display(&s);
    return 0;
}
