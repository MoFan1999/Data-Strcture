#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ELEM;
typedef struct STACK
{
	ELEM* _a;
	int top;//TOP在元素后一个位置
	int capicity;
}STACK;
void STACKInit(STACK* ptr);
void STACKDestory(STACK* ptr);
void STACKPush(STACK* ptr,ELEM x);
void STACKPop(STACK* ptr);
ELEM STACKTop(STACK* ptr);
bool STACKEmpty(STACK* ptr);
int STACKSize(STACK* ptr);
