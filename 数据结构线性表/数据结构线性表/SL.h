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

void SLInit(SL* psl);//初始化
void SLDestory(SL* psl);//销毁
void SLPrint(const SL* psl);//打印顺序表

// 尾插头插
void SLPushBack(SL* psl, ELEM x);
void SLPushFront(SL* psl, ELEM x);
//尾删头删
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

// 没有找到就返回-1
int SLFind(SL* psl, ELEM x);

// 顺序表在pos位置插入x
void SLInsert(SL* psl, size_t pos, ELEM x);

// 顺序表删除pos位置的值
void SLErase(SL* psl, size_t pos);
// 顺序表修改pos位置的值
void SLModify(SL* psl, size_t pos, ELEM x);
//检查容量
void SLCheckCapacity(SL* psl);