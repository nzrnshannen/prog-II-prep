#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *next_addr;
}*head1, *head2, *temp, *temp1, *temp2, *newNode;

int n;

void createList(struct node **, struct node**, int);
void displayList(struct node**, struct node**);
void sortList(struct node*);
int findMedian(struct node*, struct node*);

int main()
{
	head1=head2=NULL;

inputNo:
	printf("Enter the number of nodes for your two linked lists: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInput doesn't create a linked list. Try a different one.\n\n");
		goto inputNo;
	}
	
	printf("\nInput %d data for the first list:\n", n);
	createList(&head1, &temp1, n);
	printf("First linked list: ");
	displayList(&head1, &temp1);
	printf("After sort: ");
	sortList(head1);
	displayList(&head1, &temp1);
	
	printf("Input %d data for the second list:\n", n);
	createList(&head2, &temp2, n);
	printf("Second linked list: ");
	displayList(&head2, &temp2);
	printf("After sort: ");
	sortList(head2);
	displayList(&head2, &temp2);
	
	//finding median of the first one:
	int m1=findMedian(head1, temp1);
	printf("Median of the first LL: %d\n", m1);
	int m2=findMedian(head2, temp2);
	printf("Median of the second LL: %d\n", m2);
	
	printf("\n\t\t\tPrinting the median of the 2 linked lists...\n\t\t\tPress any key to continue- ");
	getch();
	
	printf("\n\n========================\nMedian of the two lists with the same number of nodes: %d\n\n", (m1+m2)/2);
	
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

int findMedian(struct node *head, struct node *temp)
{
	int i=1, pos, median;
	
	if(n%2==1)
	{
		pos = (n+1)/2;
		
		temp=head;
		while(i<pos)
		{
			temp=temp->next_addr;
			i++;
		}
		median=temp->num;
	}
	else
	{
		pos = (n/2)+1;
		temp=head;
		while(i<pos)
		{
			temp=temp->next_addr;
			i++;
		}
		median=temp->num;
	}
	
	head=temp=NULL;
	free(head);
	free(temp);
	return median;
}