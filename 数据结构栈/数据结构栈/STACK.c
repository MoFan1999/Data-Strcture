#include "STACK.h"

void STACKInit(STACK* ptr)
{
	ptr->_a = (ELEM*)malloc(sizeof(ELEM) * 4);
	ptr->top = 0;
	ptr->capicity = 4;
}

void STACKDestory(STACK* ptr)
{
	ptr->top = 0;
	ptr->capicity = 0;
	free(ptr->_a);
	ptr->_a = NULL;
}

void STACKPop(STACK* ptr)
{
	assert(!STACKEmpty(ptr));
	ptr->top--;
}

ELEM STACKTop(STACK* ptr)
{
	assert(ptr);
	assert(!STACKEmpty(ptr));

	return ptr->_a[ptr->top - 1];

}

bool STACKEmpty(STACK* ptr)
{
	if(ptr->top==0)
	  return 1;
	return 0;
}

int STACKSize(STACK* ptr)
{
	return ptr->top;
}

void STACKPush(STACK* ptr,ELEM x)
{
	if (ptr->top >= ptr->capicity)
	{
		int newcapicity = ptr->capicity * 2;
		ELEM*tmp = (ELEM*)realloc(ptr->_a, newcapicity);
		assert(tmp);
		ptr->capicity = newcapicity;
		ptr->_a = tmp;
	}
	ptr->_a[ptr->top] = x;
	ptr->top++;
}
