#include<stdlib.h>
#include<stdio.h>

struct node{
    int data ;
    struct node *next ;
    struct node * prev;
} *first = NULL;
void create(int a[],int n){
    int i = 0;
    struct node *t, *p;
    first = (struct node*)malloc(sizeof(struct node));
    first->data =a[i];
    first->next = first->prev = NULL;
    p =first;
    for(i=1;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = p->next;
        t->prev = p;
        p->next = t;
        p = t;
    }
}
void display(struct node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int length(struct node *p){
    int l =0;
    while(p){
        l++;
        p = p->next;
    }
    return l;
}
void Insert(int pos,int x){
    struct node *p ,*t;
    p = first ;
    if(pos<0 || pos > length(p))
        return ;
    if(pos == 0){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    }else{
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        for(int i=1;i<pos;i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Delete(struct node *p,int pos){
    int i,x=-1;
    if(pos<0 || pos > length(p))
        return -1;
    if(pos == 1){
        first = first->next;
        x = p->data;
        if(first)
            first->prev = NULL;
        free(p);
    }
    else{
        for(i=0;i<pos-1;i++)
            p = p->next;
        p->prev->next = p->next;
        x = p->data;
        if(p->next)
            p->next->prev = p->prev;
        free(p);
    }
    return x;
}
void Reverse(struct node *p){
    struct node *t;
    while(p!=NULL){
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if(p->next == NULL && p)
            first = p;
    }
}
int main(){
    int a[] = {10,20,30,40,50,60};
    create(a,6);
    Reverse(first);
    display(first);
    return 0;
}
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;
void create(int a[],int n){
    int i = 0;
    struct node *t , *p;
    first = (struct node *)malloc(sizeof(struct node));
    p = first;
    first->data = a[i];
    first->prev = NULL;
    first->next = first;
    for(i = 1;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->prev = p;
        t->next = p->next;
        p->next = t;
        p = t;
        if(t == NULL)
            first->prev = p;
    }
}
void display(struct node *p){
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p != first);
    printf("\n");
}
int length(struct node *p){
    int l = 0;
    do{
        l++;
        p = p->next;
    }while(p->next != first);
    return l;
}
void Insert(int pos, int x){
    struct node *p,*t;
    p = first ;
    if(pos < 0 || pos > length(p))
        return;
    if(pos == 0){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if(p  == NULL){
            t->next = t;
            t->prev = t;
            first = t;
        }else{
            t->next = p;
            t->prev = p->prev;
            first = t;
        }
    }else{
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        for(int i = 0; i< pos-1;i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        if(p->next)
            p->next->prev = t;
    }
}
int main(){
    int a[] = {10,20,40,50};
    create(a,4);
    display(first);
    Insert(2,30);
    display(first);
    return 0;
}
