#include"STACK.h"
int main()
{
	STACK st;
	STACKInit(&st);
	STACKPush(&st, 1);
	STACKPush(&st, 2);
	STACKPush(&st, 3);
	STACKPush(&st, 4);
	printf("%d ", STACKTop(&st));
	STACKPop(&st);
	printf("%d ", STACKTop(&st));
	

}