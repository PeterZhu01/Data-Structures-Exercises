#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#define Maxsize 100
#define Elemtype int
#define Dim 3
typedef struct LinkNode {
    Elemtype data;
    struct LinkNode* next;
} LinkNode;

void InitList(LinkNode*& L);
void DestoryList(LinkNode*& L);
bool GetElem_L(LinkNode* L, int i, Elemtype& e);
Elemtype Getmax(LinkNode* L);
void CreateListR(LinkNode*& L, Elemtype a[], int n);
void DispList(LinkNode* L);
void List_reverse(LinkNode* L);
void MergeList(LinkNode* La, LinkNode* Lb, LinkNode*& Lc);
void MergeList_E(LinkNode* La, LinkNode* Lb, LinkNode*& Lc);
void Intersection(LinkNode*& La, LinkNode* Lb);
unsigned int Diff_Elem(LinkNode*& La, LinkNode* Lb);
unsigned int ListLength(LinkNode* L);
void LinkSplit(LinkNode*& La, LinkNode*& Lb, LinkNode*& Lc);
void Interval_Delete(LinkNode*& L, int mink, int maxk);
bool Bonus_2_28(LinkNode*& La, LinkNode*& Lb,LinkNode*& Lc);
//unsigned int ListLength_1(LinkNode* L);
#endif // LINKLIST_H
