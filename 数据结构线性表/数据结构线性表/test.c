#include"SL.h"
int main()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushFront(&s, 66);
	SLPushFront(&s, 99);
	SLInsert(&s, 3, 100);
	SLErase(&s, 1);
	//SLModify(&s, 2, 18);
	SLPrint(&s);
	SLDestory(&s);
}