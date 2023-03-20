#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

void ElemDelete_Sq(SqList*&L,ElemType e){
    int i = 0,j = 0;
    for (int i = 0;i<L->length;i++){
        if(L->data[i]!=e)
        {
            L -> data[j] = L -> data[i]; 
            j++;
        }
    }
    L -> length = j;
}

bool InitList_Sq (SqList*&L){

    L = (SqList *)malloc(sizeof(SqList));
    L -> length = 0;
    return true;
}

void CreateList(SqList *&L,int n,ElemType* arr)
{
    //ElemType a[n]={0};
    // for (short index = 0; index < n; index++)
    // {
    //     printf("Insert the %d number: ",(index+1));
    //     scanf("%d",&a[index]);
    // } 这是比较笨的写法
    
    int i = 0;
    //L = (SqList*)malloc(sizeof(SqList));
    while (i < n)
    {
        L -> data[i]=arr[i];
        i++;
    }
    L -> length = i;
 
}

void DestroyList_Sq(SqList*&L){
    free(L);
}

bool GetElem(SqList *L,int i,ElemType & e)
{
    if (i<1||i>L->length) return false;
    e = L->data[i-1];
    printf("%d\n",e);
    return true;
}

bool ListEmpty(SqList * L)
{
    return (L -> length == 0);
}

int ListLength(SqList *L)
{
    return (L->length);
}

void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf_s("%d  ",L->data[i]);
    printf_s("\n");
}

bool ListInsert_Sq(SqList*&L,int i,ElemType e){
    int j;
    if(i<1||i>L->length+1) return false;
    i--;
    for (j = L -> length; j > i; j--)
        L -> data[j] = L->data[j-1];
    L -> data[i] = e;
    L -> length++;
    return true;
}

bool Insert_in_Seq(SqList *L,ElemType e)
{
    int i = 0;
    for (i = 0; i < L->length - 1; i++) {
        if (L->data[0] >= e) {
            ListInsert_Sq(L, 1, e);
            return true;
        }
        else if ((L->data[i] <= e) && (L->data[i + 1] > e)) {
            ListInsert_Sq(L, (i + 2), e); 
            return true;
        }
    }
    if (i >= L->length - 1) {
        ListInsert_Sq(L, L->length + 1, e);
        return true;
    }
    else return false;
}

void Size_of_Sqlist(SqList *L)
{
    printf("The size of list:\n");
    printf_s("%llu\n",sizeof(SqList));
}

bool ListDelete_Sq(SqList*&L,int i){
    int j;
    if(i<1||i>L->length)
        return false;
    i--;
    
    for (j = i; j < L -> length-1 ; j++)
        L -> data[j]=L->data[j+1];
    L -> length--;
    return true;
}

int LocateElem_Sq(SqList *L,ElemType e){

    int i=0;
    while (i<L->length && L->data[i]!=e)
        i++;
    if(i>=L->length)
        return 0;
    else
        return i+1;
}
