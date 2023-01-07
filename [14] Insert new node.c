#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *prev, *end;
int n;

void displayList()
{
    struct node *traverse;
    traverse=head;
    while(traverse!=NULL)
    {
        printf ("%d ", traverse->data);
        traverse=traverse->next;
    }
    
    printf ("\n");

    traverse=NULL;
    free(traverse);
}

void warningMessage()
{
	printf ("\n\nInput not applicable for this program. Please try a different one.\n\n");
}
int main()
{
	head=NULL;
	int i=1, pos;

inputAgain:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		warningMessage();
		goto inputAgain;
	}
	
    printf ("\nInput %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		
		printf("Data %d: ", i++);
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
	
	}
	
	printf ("\nLinked list before insertion: ");
	displayList();
	
	newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf ("\nInput data to be inserted: ");
	scanf("%d", &newNode->data);
	newNode->next=NULL;

inputPos:
	printf ("Insert at what position? (starting from 1): ");
	scanf("%d", &pos);
	
	if(pos<=0)
	{
		warningMessage();
		goto inputPos;
	}
	
	i=0;
	prev=NULL;
	temp=head;
	
	if(pos>n)
	{
		end=head;
		while(end->next!=NULL)
		{
			end=end->next;
		}
		end->next=newNode;
		displayList();
		exit(1);
	}
	
	while(i<pos-1)
	{
		prev=temp;
		temp=temp->next;
		i++;
	}
	
	
	if(i==pos-1 && i==0)
	{
		newNode->next=temp;
		head=newNode;
	}	
	else
	{
		newNode->next=prev->next;
		prev->next=newNode;
	}
	
	printf ("\nLinked list after insertion: ");
	displayList();
	

    head=temp=newNode=prev=NULL;
    free(head);
    free(temp);
    free(newNode);
    free(prev);
	return 0;
}