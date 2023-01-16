#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *next_addr;
}*head1, *head2, *temp, *temp1, *temp2, *newNode, *link;

int n1, n2, n;

void createList(struct node **, struct node**, int);
void displayList(struct node**, struct node**);
void sortList(struct node*);
float findMedian(struct node*, struct node*);

int main()
{
	head1=head2=NULL;

inputNo1:
	printf("Enter the number of nodes for your first linked list: ");
	scanf("%d", &n1);
	
	if(n1<=0)
	{
		printf("\n\nInput doesn't create a linked list. Try a different one.\n\n");
		goto inputNo1;
	}
	
	printf("\nInput %d data for the first list:\n", n1);
	createList(&head1, &temp1, n1);
	printf("First linked list: ");
	displayList(&head1, &temp1);
	
	printf("Enter the number of nodes for your second linked list: ");
	scanf("%d", &n2);	

inputNo2:		
	if(n2<=0)
	{
		printf("\n\nInput doesn't create a linked list. Try a different one.\n\n");
		goto inputNo2;
	}
	
	printf("Input %d data for the second list:\n", n2);
	createList(&head2, &temp2, n2);
	printf("Second linked list: ");
	displayList(&head2, &temp2);
	
	n=n1+n2;
	//linking 
	link=head1;
	while(link->next_addr!=NULL)
	{
		link=link->next_addr;
	}
	link->next_addr=head2;
	
	printf("\nBefore sort: ");
	displayList(&head1, &temp1);
	sortList(head1);
	printf("\nAfter sort: ");
	displayList(&head1, &temp1);
	
	//finding median of the first one:
	float m=findMedian(head1, temp1);
	
	printf("\n\t\t\tPrinting the median of the 2 linked lists...\n\t\t\tPress any key to continue- ");
	getch();
	
	printf("\n\n========================\nMedian of the two lists with the different number of nodes: %.3f\n\n", m);
	
	head1=head2=temp=temp1=temp2=newNode=NULL;
	free(head1);
	free(head2);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}


void createList(struct node **hd, struct node **tmp, int n)
{
	int i=1;
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->num);
		newNode->next_addr=NULL;
		
		if(*hd==NULL)
		{
			*hd=*tmp=newNode;
		}
		else
		{
			(*tmp)->next_addr=newNode;
			(*tmp)=newNode;
		}
	}
	
	printf("\n");
	
	hd=tmp=NULL;
	free(hd);
	free(tmp);
}

void displayList(struct node**hd, struct node **tmp)
{
	*tmp=*hd;
	while(*tmp!=NULL)
	{
		printf("%d ", (*tmp)->num);
		(*tmp)=(*tmp)->next_addr;
	}
	
	printf("\n\n");
	
	hd=tmp=NULL;
	free(hd);
	free(tmp);
}

void sortList(struct node *hd)
{
	int tmpNum;
	for(temp1=hd; temp1->next_addr!=NULL; temp1=temp1->next_addr)
	{
		for(temp2=hd; temp2->next_addr!=NULL; temp2=temp2->next_addr)
		{
			if(temp2->num > temp2->next_addr->num)
			{
				//swap
				
				tmpNum=temp2->num;
				temp2->num=temp2->next_addr->num;
				temp2->next_addr->num=tmpNum;
			}
		}
	}
	
	hd=NULL;
	free(hd);
}

float findMedian(struct node *head, struct node *temp)
{
	struct node *prev;
	int i=1, pos;
	float median;
	
	if(n%2==1)
	{
		pos = (n+1)/2;
		
		temp=head;
		while(i<pos)
		{
			temp=temp->next_addr;
			i++;
		}
		median=(float)temp->num;
	}
	else
	{
		pos = (n/2)+1;
		prev=NULL;
		temp=head;
		while(i<pos)
		{
			prev=temp;
			temp=temp->next_addr;
			i++;
		}
		median=(float)(temp->num + prev->num)/2;
	}
	
	head=temp=prev=NULL;
	free(head);
	free(temp);
	free(prev);
	
	return median;
}