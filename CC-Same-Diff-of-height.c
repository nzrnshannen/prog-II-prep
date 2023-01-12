//program was based on our previous CodeChum examination (2022). This serves as a review only. (from array to LL conversion)


#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

int main()
{
	int diff, n, i=1, count=0;
	scanf("%d", &n);
	scanf("%d", &diff);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		i++;
	}
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2!=NULL; temp2=temp2->next)
		{
			if((temp1->data - temp2->data)==diff)
			{
				count++;
			}
		}
	}
	
	printf("%d", count);
	
	head=temp=temp1=temp2=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}