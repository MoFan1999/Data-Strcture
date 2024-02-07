#include "QUEQUE.h"

void Queinit(Queptr* ptr)
{
	assert(ptr);
	ptr->head = ptr->tail = NULL;
	ptr->size = 0;
}

void Quedestory(Queptr* ptr)
{
	Quenode* tmp=ptr->head;
	while (tmp)
	{
		Quenode* del = tmp;
		tmp = tmp->next;
		free(del);

	}
	ptr->head = ptr->tail = NULL;

}

void Quepush(Queptr* ptr, ELEM x)
{
	assert(ptr);
	Quenode* newnode = (Quenode*)malloc(sizeof(Quenode));
	if (newnode == NULL)
	{
		printf("error");
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (ptr->tail == NULL)
	{
		ptr->tail = ptr->head = newnode;
	}
	else
	{
		ptr->tail->next = newnode;
		ptr->tail = newnode;
	}
	ptr->size++;
}

void Quepop(Queptr* ptr)
{
	assert(ptr->head);
	Quenode* tmp = ptr->head->next;
	free(ptr->head);
	ptr->head = tmp;
	if (ptr->head == NULL)
		ptr->tail = NULL;
}
ELEM QueFront(Queptr* pq)
{
	assert(pq);
	return pq->head->data;
}

ELEM QueBack(Queptr* pq)
{
	assert(pq);
	return pq->tail->data;
}

bool QueEmpty(Queptr* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

int QueSize(Queptr* pq)
{
	assert(pq);
	return pq->size;
}
