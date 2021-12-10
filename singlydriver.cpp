#include<stdio.h>
#include<stdlib.h>
#include"singlereverse.h"
main()
{
  int ch,n;
  struct node *head=NULL;
  do
  {
    printf("\nMENU\n");
    printf("\n1.Create");
    printf("\n2.Display");
    printf("\n3.Reverse");
    printf("\n4.Exit\n");
    printf("\nEnter Ur Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter The Number of Node You Want\n");
            scanf("%d",&n);
            head=create(head,n);
            break;
        case 2:
               printf("\nLinked list is :\n");
            display(head);
            break;
        case 3:
            head=reverselist(head);
            break;
        case 4:
               exit(0);
            break;
        default :printf("\nInvalid choice ");     
     }
   } while(ch!=4);
}

