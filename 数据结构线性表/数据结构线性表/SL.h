#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ELEM;
#define N 10

typedef struct SqList
{
	ELEM size;
	ELEM capcity;
	ELEM* ptr;
}SL;

void SLInit(SL* psl);//��ʼ��
void SLDestory(SL* psl);//����
void SLPrint(const SL* psl);//��ӡ˳���

// β��ͷ��
void SLPushBack(SL* psl, ELEM x);
void SLPushFront(SL* psl, ELEM x);
//βɾͷɾ
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

// û���ҵ��ͷ���-1
int SLFind(SL* psl, ELEM x);

// ˳�����posλ�ò���x
void SLInsert(SL* psl, size_t pos, ELEM x);

// ˳���ɾ��posλ�õ�ֵ
void SLErase(SL* psl, size_t pos);
// ˳����޸�posλ�õ�ֵ
void SLModify(SL* psl, size_t pos, ELEM x);
//�������
void SLCheckCapacity(SL* psl);