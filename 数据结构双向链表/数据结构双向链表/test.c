#include"SL.h"
//�ı�ͷָ����Ҫ����ָ��
int main()
{
	LTNode* plist = ListInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);
	ListDestory(&plist);
}