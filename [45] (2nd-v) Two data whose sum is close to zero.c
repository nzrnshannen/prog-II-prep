#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *ptr;
}*head, *temp, *temp1, *temp2, *newNode;


int main()
{
	head==NULL;
	int i=1, sum=0, flag=0, n, num1, num2;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input data for each %d nodes:\n", n);
	for(i; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->ptr=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->ptr=newNode;
			temp=newNode;
		}
	}
	
	printf("\nThe given linked list: ");
	for(temp=head; temp!=NULL; temp=temp->ptr)
	{
		printf("%d ", temp->data);
	}
	
	for(temp1=head; temp1!=NULL; temp1=temp1->ptr)
	{
		for(temp2=head; temp2!=NULL; temp2=temp2->ptr)
		{
			sum = temp1->data + temp2->data;
			if(sum < 0 && sum > -5 || sum <5 && sum > 0)
			{
				num1= temp1->data;
				num2 = temp2->data;
				flag=1;
			}
			
			if(flag==1)
				break;
		}
		
		if(flag==1)
			break;
	}
	
	printf("\nChecking list whose sum is close to zero...\nPress any key to continue- ");
	getch();
	
	if(flag==1)
	{
		printf("\n\nThe pair of elements whose sum is minimum and closest zero: [%d, %d]\n", num1, num2);
	}
	else
	{
		printf("\n\nNo such pair whose sum is close to zero.\n");
	}
	
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;

	return 0;
}
