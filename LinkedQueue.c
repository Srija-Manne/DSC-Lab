#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NodeType
{
	char data;
	struct NodeType *link;
};
typedef struct NodeType Node;

Node *createNode(char data)
{

	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	return newNode;
}

struct QueueADT
{
	Node *rear;
	Node *front;
};
typedef struct QueueADT Queue;

Queue *create(void)
{

	Queue *pthis = (Queue *)malloc(sizeof(Queue));
	pthis->rear = NULL;
	pthis->front = NULL;
	return pthis;	
}

bool enqueue(Queue *pthis, char data)
{

	Node *pNew = createNode(data);
	if(pthis->front == NULL)
	{
		pthis->front = pthis->rear = pNew;
		return true;
	}	

	pthis->rear->link = pNew;
	pthis->rear = pNew;
	return true;
}

bool dequeue(Queue *pthis, char *pData)
{

	if(pthis->front == NULL)
		return false;

	*pData = pthis->front->data;

	Node *pDel = pthis->front;

	pthis->front = pDel->link;
	free(pDel); 
	return true;
}

void destroy(Queue *pthis)
{
	char temp;
	while(pthis->front != NULL) // while list is not empty
		dequeue(pthis, &temp); // delete elements
	free(pthis); // free Queue
}

void display(const Queue *pthis)
{
	// start cursor at front
	Node *cursor = pthis->front;
	while(cursor != NULL) // loop till end of Queue
	{
		printf("%c ", cursor->data);
		cursor = cursor->link; // update cursor
	}
	putchar('\n');
}

void inputElement(char *elem)
{
	printf("Enter element: ");
	scanf("%c", elem);
	getchar(); // get rid of a newline after entering option
}

int main(void)
{
	int option;
	char elem, delElem;
	
	Queue *pq = create();
	
	while(true)
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Select an option: ");
		scanf("%d", &option);
		getchar(); // get rid of a newline after entering option
		printf("\n");
		
		switch(option)
		{
			case 1:
				inputElement(&elem);
				if(!enqueue(pq, elem))
					printf("Enqueue failed: %c\n", elem);
				break;
			case 2:
				if(dequeue(pq, &delElem))
					printf("Dequeued: %c\n", delElem);
				else printf("Dequeue failed\n");
				break;
			case 3:
				display(pq);
				break;
			case 4:
				destroy(pq);
				return 0;
			default:
				printf("Invalid option: %d\n", option);
		}
	}
	
	printf("\n");
	return 0;
}
