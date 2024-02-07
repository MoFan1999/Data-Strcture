#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode ,*Linklist;
int IsEmpty(Linklist LL)
{
	if (LL->next == NULL)
		return 1;
	else
		return 0;
}
void Destory(Lnode** LL)//完全销毁
{
	Lnode* p = *LL;
	while (p)
	{
		Lnode*next=p->next;
		free(p);
		p = next;
	}
	*LL = NULL;
}

int Count(Linklist LL)
{
	int cnt=0;
	Linklist p = NULL;
	p = LL;
	while (p)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}
Linklist Find1(Linklist LL,int e)//按值查找返回地址
{
	Linklist p = LL->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;
}
int Find2(Linklist LL, int e)//按值查找返回位置序号
{
	int i = 0;
	Linklist p = LL->next;
	while (p && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p)return i;
	else return -1;
}
Lnode* BuyNode(int x)
{
	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void Insertafter( Lnode* pos, int i)
{
	Linklist newnode = BuyNode(i);
	newnode->next = pos->next;
	pos->next = newnode;

}
void Insertbefore(Lnode**LL,Lnode* pos, int i)
{
	Linklist newnode = BuyNode(i);
	if (pos == *LL)
	{
		*LL = newnode;
		newnode->next = ((*LL)->next);
	}
	else
	{
		Lnode* prev = *LL;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		Lnode* newnode = BuyNode(i);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void HeadInsert(Lnode** LL,int x)
{
	Linklist newnode = BuyNode(x);
	newnode->next = (*LL);
	(*LL)= newnode;
}
void TailInsert(Lnode** LL, int x)
{
	Linklist newnode = BuyNode(x);
	Linklist cur = *LL;
	if ((*LL) == NULL)
	{
		*LL = newnode;
	}
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}
void Lprint(Linklist pphead)
{
	Linklist cur = pphead;
	while (cur!=NULL)
	{
		printf("%d->",cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}
int main()
{
	Lnode* plist = NULL;
	HeadInsert(&plist, 1);
	HeadInsert(&plist, 2);
	HeadInsert(&plist, 3);
	HeadInsert(&plist, 4);
	TailInsert(&plist, 100);
	Lprint(plist);
	Destory(&plist);
}