#include <stdio.h>
#include <stdlib.h>
#include "DLink.h"


void InitDList(DLinkNode*& L)
{
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    if (L)
        L->next = L->prior = L;
    else
        exit(1);
}

void DestoryDList(DLinkNode*& L)
{
    DLinkNode* q=NULL,*p = L->next;
    while (p != L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
}


void CreateListR(DLinkNode*& L, Elemtype a[], int n)
{
    DLinkNode* s,*p;
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    L->next = NULL; //先指向空自己后面再换
    L->prior = L;
    p = L;
    for (int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->prior = p;
        s->next = L;
        //p->next->prior = s;
        p->next = s;
        p = s;// p points to the last element
    }
    L->prior = p;
}

void DispList(DLinkNode* L)
{
    DLinkNode* p = L->next;

    while (p != L)
    {
        printf("%3d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void change(DLinkNode*& p, DLinkNode*L)
{
    
     DLinkNode* pre,*q;
     q = L->prior;//指向最后一个结点
     pre = p->prior;
     if(p==L->next){ //如果是第一个结点
         p->prior = q->prior;
         p->next->prior = q;
         L->next = q; //需要动8根指针
         q->prior->next = p;
         q->prior = L; //先动的后面不要动
         q->next = p->next;
         L->prior = p;
         p->next = L;
     }
     else{
         p->prior = pre->prior;
         pre->prior->next = p;

         pre->next = p->next;
         p->next->prior = pre;

         pre->prior = p;     // 只需要动6根指针
         p->next = pre;    // 先动的指针后面不要动
     }     
}

bool Dlink_Re_sort(DLinkNode*&L)
{
    DLinkNode *head, *tail, *p;

    if (!L)
        return false;

    head = L->next;		//注意：此时head指向了第一个结点，并不是头结点		
    tail = L->prior;	//tail作为标记，标记最后一个结点			 

    while (head != tail)
    {
        if (head->next != tail)
        {
            p = head->next;		

            p->next->prior = head;
            head->next = p->next;

            p->next = tail->next;
            p->prior = tail;
            tail->next->prior = p;
            tail->next = p;

            head = head->next;
        }
        else
            break;
    }

    return true;
}

DLinkNode* Get_that_pointer(DLinkNode* L, Elemtype e)
{
    DLinkNode* p; int n = 0;
    p = L->next;
    while (p != L&& n< Maxsize) //防止死循环
    {
        if (p->data == e)     //寻找节点
        {
            return p;
        }
        else
        {
            p = p->next;
        }
        n++;
    }
    return NULL; //找不到返回空
}

