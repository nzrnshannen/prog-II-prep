#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1, *head2, *newNode, *temp1, *temp2, *temp;

void createList(struct node **head, struct node **temp, int n)
{
	int i=1;
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(*head==NULL)
		{
			*head=*temp=newNode;
		}
		else
		{
			(*temp)->next=newNode;
			(*temp)=newNode;
		}
	}
	
	printf("\nLinked list: ");
	*temp=*head;
	while(*temp!=NULL)
	{
		printf("%d ", (*temp)->data);
		(*temp)=(*temp)->next;
	}
}

int main()
{
	head1=head2=NULL;
	int n1, n2, i, j;
	
	printf ("Input the number of nodes for your first linked list: ");
	scanf("%d", &n1);
	
	i=1;
	printf ("Input %d data:\n", n1);
	createList(&head1, &temp1, n1);
	
	printf ("\n\nInput the number of nodes for your second linked list: ");
	scanf("%d", &n2);
	
	if(n2>n1)
	{
		printf("\n\nThe second LL is not a subset of the first LL.");
	}
	else
	{
		createList(&head2, &temp2, n2);
		i=1;
		
		int flag=0, count=0;
		
		for(temp1=head2; temp1!=NULL; temp1=temp1->next)
		{
			for(temp2=head1; temp2!=NULL; temp2=temp2->next)
			{
				if(temp1->data == temp2->data)
				{
					flag=1;
				}
			}
			
			if(flag==0)
				break;
			else
			{
				count++;
				flag=0;
				continue;
			}
		}
		
		if(count==n2)
		{
			printf("\nThe second LL is a subset of the first linked list.\n");
		}
		else
		{
			printf("\nThe second LL is not a subset of the first LL.\n");
		}
	}
	
	free(head1);
	free(head2);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head1=head2=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}