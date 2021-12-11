#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *tail;
struct node* create(struct node *head, int n)
{
    struct node *newnode, *temp;
    int i;
    for(i=1;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->next = newnode->prev=NULL;
        if (head == NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    return head;
}
void display(struct node* head)
{
    struct node *temp;
    if(head==NULL)
        printf("\nCreate List First!");
    else
    {   
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf("\t %d ->",temp->data);
        }
        printf("NULL");
    }
}
struct node *reverseList(struct node *head)
{
    struct node *current = head, *temp = NULL;  
    
    while(current != NULL) {  
        temp = current->next;  
        current->next = current->prev;  
        current->prev = temp;  
        current = current->prev;  
    }  
      
    temp = head;  
    head = tail;  
    tail = temp;
    return(head);
}

