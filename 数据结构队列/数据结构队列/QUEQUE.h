#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int ELEM;
typedef struct Quenode
{
	ELEM data;
	struct Quenode* next;
}Quenode;
typedef struct Queptr
{
	Quenode* head;
	Quenode* tail;
	int size;
}Queptr;
void Queinit(Queptr*ptr);
void Quedestory(Queptr* ptr);
void Quepush(Queptr* ptr, ELEM x);
void Quepop(Queptr* ptr);
ELEM QueFront(Queptr* pq);
ELEM QueBack(Queptr* pq);
bool QueEmpty(Queptr* pq);
int QueSize(Queptr* pq);