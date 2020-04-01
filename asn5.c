#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct linkedList
{
        int node,value;
        struct linkedList*next;
};

struct linkedList*getLastNode(struct linkedList*head)
{
	if(head==NULL)
		return NULL;
	while(head->next!=NULL)
		head=head->next;
	return head;
}

struct linkedList * insertElements(struct linkedList *head,int size, int last_index)
{
	srand(time(0));
	struct linkedList *last_node=getLastNode(head);
	for(int i=0; i<size; i++)
	{
		last_index++;
		struct linkedList *node=(struct linkedList *)malloc(sizeof(struct linkedList));
		node->node=last_index;
		node->value=rand()%100+1;
		if(head==NULL)
		{
			head=node;
			last_node=node;
		}
		else
		{
			last_node->next=node;
			last_node=node;
		}
	}
	return head;
}

void printList(struct linkedList *head)
{
	while(head)
	{
		printf("Node: %d Value: %d\n",head->node,head->value);
		head=head->next;
	}
}

struct linkedList * deleteElements(struct linkedList *head,int size)
{
	if(!head)
		return NULL;
	while(1)
	{
		int value;
		printf("\nEnter the value to be removed from the list: ");
		scanf("%d",&value);
		if(value==0)
			break;
		printf("\nSearching for node with value of %d nodes(elements)\n",value);
		struct linkedList *prev=NULL,*temp=head;
		while(temp && temp->value!=value)
		{
			prev=temp;
			temp=temp->next;
		}
		if(!temp)
			printf("\nValue: %d not in this list\n",value);
		else
		{
			size--;
			printf("\nFound Value: %d at Node: %d\n",temp->value,temp->node);
			if(!prev)
			{
				head=head->next;
			}
			else
			{
				prev->next=temp->next;
			}
			printf("\nSORTED link list after adding members now with %d nodes (elements)\n\n",size);
			printList(head);
		}
	}
	return head;
}

void sort_list(struct linkedList *head)
{
	struct linkedList *temp1=head;
	while(temp1)
	{
		struct linkedList *temp2=temp1->next;
		while(temp2)
		{
			if(temp1->value>temp2->value)
			{
				int node=temp1->node;
				temp1->node=temp2->node;
				temp2->node=node;
				int value=temp1->value;
				temp1->value=temp2->value;
				temp2->value=value;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}

int getSize(struct linkedList *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

int main()
{
	int size,last_index=0;
	printf("Enter the size of list: ");
	scanf("%d",&size);
	struct linkedList *head=NULL;
	head=insertElements(head,size,0);
	last_index+=size;
	printf("\nOriginal (unsorted) link list with %d nodes (elements)\n\n",size);
	printList(head);
	printf("\nSORTED link list with %d nodes (elements)\n\n",size);
	sort_list(head);
	printList(head);
	head=deleteElements(head,size);
	int new_size;
	printf("\nEnter the number of new nodes: ");
	scanf("%d",&new_size);
	head=insertElements(head,new_size,last_index);
	last_index=+new_size;
	sort_list(head);
	size=getSize(head);
	printf("\nSORTED link list after adding members now with %d nodes (elements)\n\n",size);
	printList(head);
	return 0;
}

