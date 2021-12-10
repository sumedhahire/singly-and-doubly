#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};
int count=0;

struct node *create(struct node *head,int n)
{
	struct node *temp,*newnode;
	int i;
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n enter node %d:",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(struct node));
			head->next=newnode;
		}
		else
		{
			temp=head->next;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
	return head;
}

struct node *display(struct node *head)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\n create list first!");
	}
	else
	{
		for(temp=head->next;temp!=NULL;temp=temp->next)
		{
			printf("\t %d->",temp->data);
		}
		printf("NULL");
	}
}

struct node *reverselist(struct node *head)
{
	struct node *prevnode,*currnode,*nextnode;
	
	if(head!=NULL)
	{
		prevnode=NULL;
		currnode=head->next;
		nextnode=NULL;
		while(currnode!=NULL)
		{
			nextnode=currnode->next;
			currnode->next=prevnode;
			prevnode=currnode;
			currnode=nextnode;
		}
		head->next=prevnode;
		printf("your linked list is now reversed\n");		
	}
	return head;
}
