#include<stdio.h>

int queue[30];
int head = -1, tail = -1;

enum status{
STATUS_OK,
STATUS_QUEUE_EMPTY,
STATUS_QUEUE_FULL
};

enum status removeh(int* data);

enum status insert(int data)
{
	printf("head and tail are at position %d, %d",head,tail);
	if(head == 29)
		return STATUS_QUEUE_FULL;
	queue[++tail] = data;
	return STATUS_OK;
}

enum status removeh(int* data)
{
	printf("head and tail are at position %d, %d",head,tail);
	if (tail == head)
		return STATUS_QUEUE_EMPTY;
	*data = queue[++head];
	return STATUS_OK;	
}

int main()
{
	int i;
	enum status status;
sos:
	printf("Enter your choice\n 1. for inserting\n 2. for removing\n");
	scanf("%d",&i);
	switch(i){
	case 1:
		printf("Enter the no. which you want to insert in the queue\n");
		scanf("%d",&i);
		status = insert(i);
		break;
	case 2:
		status = removeh(&i);
		printf("removed element from queue:%d\n",i);
		break;
	default:printf("You have inserted wrong choice..please try again\n");
	}
	if(status == STATUS_OK)
	{
		goto sos;
	}
	return 0;
}
