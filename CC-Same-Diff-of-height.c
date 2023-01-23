
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *tmp1, *tmp2;

int main()
{
	int n, diff=0, count=0;
	scanf("%d", &n);
	scanf("%d", &diff);
	
	head=NULL;
	int i=1; 
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
	
	for(tmp1=head; tmp1!=NULL; tmp1=tmp1->next)
	{
		for(tmp2=head; tmp2!=NULL; tmp2=tmp2->next)
		{
			if((tmp1->data - tmp2->data)==diff)
				count++;
		}
	}
	
	printf("%d", count);
	
	free(head);
	free(temp);
	free(tmp1);
	free(tmp2);
	free(newNode);

	head=temp=tmp1=tmp2=newNode=NULL;
	
	return 0;
}
