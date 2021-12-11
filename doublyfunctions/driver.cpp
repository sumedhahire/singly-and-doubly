#include<stdio.h>
#include<stdlib.h>
#include "dylistsirpacknew.h"
int main()
{
  int ch,val,i,m,a,pos,sr,d;
  struct node *head=NULL;
  do
  {
    printf("\n MENU\n");
    printf("\n1.Append");
    printf("\n2.Display");
    printf("\n3.Search");
    printf("\n4.Insert");
    printf("\n5.Delete By Value");
    printf("\n6.Delete By Position");
    printf("\n7.Exit\n");
    printf("\nEnter Ur Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter The Value To Append\n");
            scanf("%d",&val);
            head=append(head,val);
            break;
        case 2:
            printf("\n Linked list is :\n");
            display(head);
            break;
        case 3:
            printf("\n Enter data to be search : ");
            scanf("%d",&val);
            search(head,val);
            break;
        case 4:
            printf("\n Enter the value and position to be data added :");
            scanf("%d%d",&val,&pos);
            head=insert(head,val,pos);
            break;
        case 5:
            printf("\n Enter the data to be deleted :");
            scanf("%d",&val);
            head=delete_val(head,val);
            break;
        case 6:
            printf("\n Enter position to be data deleted :");
            scanf("%d",&pos);
            head=delete_pos(head,pos);
            break;
        case 7: exit(0);
            break;
        default :printf("\n Invalid choice ");     
     }
   } while(ch!=7);
}
