#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1, *head2, *temp1, *temp2, *newNode;

void warningMessage1();
void createList(struct node**, struct node**, int); 
void displayList(struct node**, struct node**);
void sortList(struct node*);
float findMedian(struct node*, struct node*, int);
void merge(struct node *, struct node *, struct node*, struct node*);

void merge(struct node *head1, struct node *head2, struct node *temp1, struct node *temp2)
{
	temp1=head1;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;	
	}
	temp1->next=head2;
	
}

float findMedian(struct node *head, struct node *temp, int n)
{
	float median=0;
	
	if(n%2==1)
	{
		int s=0;
		temp=head;
		while(temp!=NULL)
		{
			if(s==n/2)
			{
				median=(float)temp->data;
			}
			
			temp=temp->next;
			s++;
		}
	}
	else
	{
		int r=0;
		float num1, num2;
		struct node *previous=NULL;
		temp=head;
		while(temp!=NULL)
		{
			if(r==n/2)
			{
				num1=(float)previous->data;
				num2=(float)temp->data;
			}
			
			previous=temp;
			temp=temp->next;
			r++;
		}
		
		median=(float)(num1+num2)/2;
	}
	
	return median;
}

void displayList(struct node **head, struct node **temp)
{
	*temp=*head;
	while(*temp!=NULL)
	{
		printf("%d ", (*temp)->data);
		*temp=(*temp)->next;
	}
}

void createList(struct node **head, struct node **temp, int n)
{
	int i=1;
	printf("\nInput %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(*head==NULL)
		{
			*head=(*temp)=newNode;
		}
		else
		{
			(*temp)->next=newNode;
			*temp=newNode;
		}
	}
}

void sortList(struct node *head)
{
	struct node *temp2, *temp1;
	for(temp1=head; (temp1)->next!=NULL; temp1=(temp1)->next)
	{
		for(temp2=head; (temp2)->next!=NULL; temp2=(temp2)->next)
		{
			int swap;
			if((temp2)->data > (temp2)->next->data)
			{
				swap=(temp2)->data;
				(temp2)->data=(temp2)->next->data;
				(temp2)->next->data=swap;
			}
		}
	}
}

void warningMessage1()
{
	printf("\n\nInput doesn't construct a linked list. Try again.\n\n");
}

int main()
{
	int n1, n2, m1, m2;
	head1=head2=NULL;

input_n1:
	printf("Input the number of nodes for your first linked list: ");
	scanf("%d", &n1);
	
	if(n1<=0)
	{
		warningMessage1();
		goto input_n1;
	}
	createList(&head1, &temp1, n1);
	printf("Linked list: ");
	displayList(&head1, &temp1);
	sortList(head1);
	printf("\nAfter sorting: ");
	displayList(&head1, &temp1);

input_n2:
	printf("\n\nInput the number of nodes for your second linked list: ");
	scanf("%d", &n2);
	
	if(n2<=0)
	{
		warningMessage1();
		goto input_n2;
	}
	
	createList(&head2, &temp2, n2);
	printf("Linked list: ");
	displayList(&head2, &temp2);
	sortList(head2);
	printf("\nAfter sorting: ");
	displayList(&head2, &temp2);
	
	//m1=findMedian(head1, temp1, n1);
	//m2=findMedian(head2, temp2, n2);

	//merging
	merge(head1, head2, temp1, temp2);
	sortList(head1);
	printf("\n");
	//displayList(&head1, &temp1);
	//sortList(head1);
	int n;
	n=n1+n2;
	float median=findMedian(head1, temp1, n);
	printf("\n\n\nMedian: %.3f", median);
	
	head1=head2=temp1=temp2=newNode=NULL;
	free(head1);
	free(head2);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}