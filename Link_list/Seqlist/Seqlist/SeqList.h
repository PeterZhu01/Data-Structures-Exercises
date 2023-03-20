#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H
#define ElemType int
#define MaxSize 100

typedef struct 
{
    ElemType data[MaxSize];
    int length;
    int listsize;

} SqList;
void ElemDelete_Sq(SqList*& L, ElemType e);
bool InitList_Sq(SqList*& L);
void CreateList(SqList*& L, int n, ElemType* arr);
void DestroyList_Sq(SqList*& L);
bool GetElem(SqList* L, int i, ElemType& e);
bool ListEmpty(SqList* L);
int ListLength(SqList* L);
void DispList(SqList* L);
bool ListInsert_Sq(SqList*& L, int i, ElemType e);
bool Insert_in_Seq(SqList* L, ElemType e);
void Size_of_Sqlist(SqList* L);
bool ListDelete_Sq(SqList*& L, int i);
int LocateElem_Sq(SqList* L, ElemType e);

#endif // !SEQLIST_H