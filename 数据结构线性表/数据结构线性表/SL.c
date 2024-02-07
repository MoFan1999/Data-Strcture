#include "SL.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl->size = 0;
	psl->capcity = 4;
	psl->ptr = (ELEM*)malloc(sizeof(ELEM) * 4);
	if (psl->ptr == NULL)
	{
		printf("¿ª±Ù´íÎó");
		exit(-1);
	}
}

void SLDestory(SL* psl)
{
	assert(psl);
	free(psl->ptr);
	psl->ptr = NULL;
	psl->size = 0;
	psl->capcity = 0;
}

void SLPrint(const SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ",psl->ptr[i]);
	}
	printf("\n");
}

void SLPushBack(SL* psl, ELEM x)
{
	assert(psl);
	SLCheckCapacity(psl);
	psl->ptr[psl->size] = x;
	psl->size++;
}

void SLPushFront(SL* psl, ELEM x)
{
	assert(psl);
	SLCheckCapacity(psl);
	for (int i = psl->size - 1; i >= 0; i--)
	{
		psl->ptr[i + 1] = psl->ptr[i];
	}
	psl->ptr[0] = x;
	psl->size++;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	for (int i = 0; i < psl->size-1; i++)
	{
		psl->ptr[i] = psl->ptr[i+1];
	}
	psl->size--;
}

void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}

int SLFind(SL* psl, ELEM x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->ptr[i] == x)
			return i+1;
	}
	return -1;
}

void SLInsert(SL* psl, size_t pos, ELEM x)
{
	assert(psl);
	SLCheckCapacity(psl);
	for (int i = psl->size - 1; i >= pos - 1; i--)
	{
		psl->ptr[i + 1] = psl->ptr[i];
	}
	psl->ptr[pos - 1] = x;
	psl->size++;
}

void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	for (int i = pos-1; i < psl->size; i++)
	{
		psl->ptr[i] = psl->ptr[i + 1];
	}
	psl->size--;
}

void SLModify(SL* psl, size_t pos, ELEM x)
{
	assert(psl);
	psl->ptr[pos - 1] = x;
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size >= psl->capcity)
	{
		int newcapcity = psl->capcity == 0 ? 4 : psl->capcity * 2;
		ELEM*tmp = (ELEM*)realloc(psl->ptr, newcapcity*sizeof(ELEM));
		if (tmp == NULL)
		{
			printf("error ¿ª±Ù");
			return;
		}
		psl->ptr = tmp;
		psl->capcity = newcapcity;
	}
}
