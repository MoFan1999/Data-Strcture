#include "SL.h"//包含头结点

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		assert(phead);
		return 1;
	}
	phead->data = 0;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListDestory(LTNode** phead)
{
	assert(phead);
	LTNode* cur = (*phead)->next;
	while (cur!=*phead)
	{
		LTNode*p=cur;
		cur = cur->next;
		free(p);
	}
	free(*phead);
	*phead = NULL;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = BuyListNode(x);
	LTNode* cur = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	cur->prev = newnode;
	newnode->next = cur;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LTNode* cur = phead->next;
	LTNode* curnext = cur->next;
	phead->next = curnext;
	curnext->prev = phead;
	free(cur);
	cur = NULL;
}

bool ListEmpty(LTNode* phead)
{
	assert(phead);
	if (phead->next = phead)
		return true;
	else
	    return false;
}

int ListSize(LTNode* phead)
{
	int cnt=0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data = x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)//在pos前插入
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	pos->prev = newnode;
	newnode->next =pos;
	newnode->prev = prev;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
