#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
int count=0;
struct node *append(struct node *head,int x)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->next=newnode; 
		newnode->prev=head;
		count++;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
		count++;
	}
	return head;
}

void display(struct node *head)
{
	 struct node *temp;
	 if(head==NULL)
	 {
	 	printf("\nCreate List First\n");
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

struct node *insert(struct node *head,int x,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data= x;
	newnode->next=NULL;
	if(pos>=count)
	{
		for(temp=head->next;temp!=NULL;temp=temp->next)
			temp->next=newnode;
			newnode->prev=temp;
		count++;
	}
	else
	{
		if(pos==1)
		{
			newnode->next=head->next;
			head->next->prev=newnode;
			head->next=newnode;
			newnode->prev=head;
			count++;
		}
		else
		{
			for(i=1,temp=head->next;i<pos-1;i++)
			{
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next->prev=newnode;
			temp->next=newnode;
			newnode->prev=temp;
			count++;
		}
	}
	return head;
}

void search(struct node *head,int x)
{
	struct node *temp,*temp1;
	int flag=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(x==temp->data)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nElment is found\n");
	}
	else
	{
		printf("\nelement is not present\n");
	}
}
struct node *delete_pos(struct node *head,int pos)
{
	struct node *temp,*temp1;
	int i;
	if(pos==1)
	{
		temp=head->next;
		head->next=temp->next;
		temp->next->prev=head;
		temp->next=NULL;
		temp->prev=NULL;
		free(temp);
		count--;
	}
	else if(pos==count)
	{
		for(i=1,temp=head->next;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=NULL;
		temp1->prev=NULL;
		free(temp1);
		count--;
	}
	else
	{
	
        for(i=1,temp=head->next;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp1->next=NULL;
		temp1->prev=NULL;
		free(temp1);
		count--;
	}
	
	return head;
}
struct node *delete_val(struct node *head,int x)
{
	struct node *temp,*temp1;
	int i, flag=0;
	i=1;
	temp=head;
	while(temp!=NULL)
	{
		if(x==temp->next->data)
		{
			flag=1;
			temp1=temp->next;
			temp->next=temp1->next;
			if(temp1->next!=NULL)
			{
				temp1->next->prev=temp;
			}
			temp1->next=NULL;
			temp1->prev=NULL;
			free(temp1);
			count--;
			break;
			
		}
		temp=temp->next;
	}
	if(flag==1)
	{
		printf("\nElment has been found and has been deleted\n");
	}
	else
	{
		printf("\nelement not present\n");
	}
	return head;
}
