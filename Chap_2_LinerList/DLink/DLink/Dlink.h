#pragma once
#ifndef DLINKLIST_H
#define DLINKLIST_H
#define Maxsize 1000
#define Elemtype int
typedef struct DNode {
    Elemtype data;
    struct DNode* prior;
    struct DNode* next;
} DLinkNode;

void InitDList(DLinkNode*& L);
void DestoryDList(DLinkNode*& L);
void CreateListR(DLinkNode*& L, Elemtype a[], int n);
void DispList(DLinkNode* L);
void change(DLinkNode*& p, DLinkNode* L);
bool Dlink_Re_sort(DLinkNode*& L);
DLinkNode* Get_that_pointer(DLinkNode* L, Elemtype e);
//unsigned int ListLength_1(LinkNode* L);
#endif // DLINKLIST_H
