#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last; 
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d\n", p->data);
        printf("%d\n", p->next);
        p=p->next;
    }
}
int main(){
    int z;
    cin>>z;
    int A[z];
    for(int i=0; i<z; i++){
        cin>>A[i];
    }
    create(A, 5);
    display(first);


    return 0;
}