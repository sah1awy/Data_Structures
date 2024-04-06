#include<stdio.h>
#include<stdlib.h>
struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};
void create(struct Sparse *s1){
    int i;
    printf("Enter the Dimensions:\n");
    scanf("%d%d",&s1->m,&s1->n);
    printf("Enter the number of non zero elements:\n");
    scanf("%d",&s1->num);
    s1->e =(struct Element *) malloc(s1->num*sizeof(struct Element));
    printf("Enter the matrix:\n");
    for(i=0;i<s1->num;i++){
        scanf("%d%d%d",&s1->e[i].i,&s1->e[i].j,&s1->e[i].x);
    }
}
void display(struct Sparse *s){
    int i,j,k=0;
    for(i=0;i<s->m;i++){
        for(j=0;j<s->n;j++){
            if(s->e[k].i == i&&s->e[k].j == j)
                printf("%d ",s->e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
struct Sparse *add(struct Sparse*s1,struct Sparse*s2){
    int i,j,k;
    i=j=k=0;
    struct Sparse *sum;
    if(s1->m != s2->m || s1->n != s1->n)
        return 0;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->e = (struct Element *)malloc(s1->num+s2->num * sizeof(struct Element));
    while(i < s1->num && j < s2->num){
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
        else if(s1->e[i].j > s2->e[j].j)
            sum->e[k++] = s2->e[j++];
        else{
            sum->e[k] = s1->e[i];
            sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
        }
      }
   }
   for(;i<s1->num;i++)sum->e[k++] = s1->e[i];
   for(;j<s2->num;j++)sum->e[k++] = s1->e[j];
   sum->m = s1->m;
   sum->n = s1->n;
   sum->num = k;
   return sum;
}
int main(){
    struct Sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);
    printf("Sparse 1:\n");
    display(&s1);
    printf("Sparse 2:\n");
    display(&s2);
    printf("Sum:\n");
    display(s3);
    return 0;
}
