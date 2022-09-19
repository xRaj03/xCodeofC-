#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
}*first = NULL;

void create(int A[], int n){

    int i;
    struct Node *t, *last;
    first= (struct Node *) malloc (sizeof(struct Node));
    first-> data=A[0];
    first->next =NULL;
    last=first;

    for(i=1; i<n; i++){
        t=(struct Node *) malloc (sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }

}
void Display( struct Node *p){
    while (p!=NULL)
    {
        printf("%d\n", p->data);
        printf("%d\n", p->next);
        p=p->next;
    }
    
    
}
// Funtion to Insert a node sortedly in a sorted linked list
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while (p && p->data<x)
        {
            q=p;
            p=p->next;

        }
        if(p==first){
            t->next=first;
            first=t;

        }
        else{
            t->next=q->next;
            q->next=t;
        }
        
    }

}


int main(){

    int A[]={1,2,3,4,6};

    create(A ,5);
    SortedInsert(first, 5);
    cout<<endl<<endl;
    Display(first);
    cout<<endl<<endl;
    return 0;
}