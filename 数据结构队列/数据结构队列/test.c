#include"QUEQUE.h"//��������ʵ��
int main()
{
	Queptr q;
	Queinit(&q);
	Quepush(&q, 1);
	Quepush(&q, 2);
	Quepush(&q, 3);

	printf("%d ", QueFront(&q));
	//Quepop(&q);
	//printf("%d ", QueFront(&q));
	//printf("%d ", QueBack(&q));
	Quedestory(&q);
}