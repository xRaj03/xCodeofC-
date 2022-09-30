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
// FUntion to check loop in the linked list by iterating
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while (p&&q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }

}
void Display( struct Node *p){
    while (p!=NULL)
    {
        printf("%d", p->data);
        p=p->next;
    }
    
    
}


int main(){

    struct Node *t1, *t2;
    int A[]={1,2,3,4,5};

    create(A ,5);
    cout<<endl;
    Display(first);

    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    cout<<endl<<endl;
    printf("%d\n", isLoop(first));
    
    return 0;
}
