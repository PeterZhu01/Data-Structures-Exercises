#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


void InitList(LinkNode*& L)
{
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void DestoryList(LinkNode*& L)
{
    LinkNode* pre = L, * p = L->next;
    while (p!=NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool GetElem_L(LinkNode * L,int i , Elemtype& e) {
    int j = 0;
    LinkNode* p = L;
    if (i <= 0) return false;
    while (j < i && (p!= NULL))
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p->data;
        return true;
    }
}

Elemtype Getmax(LinkNode* L) {
    LinkNode* L_max, * L_n;
    if (L->next == NULL) return NULL;
    L_max = L->next;
    L_n = L->next->next;

    while (L_n) {
        if (L_n->data > L_max->data) {
            L_max = L_n;
        }
        L_n = L_n->next;
    }

    return L_max->data;
}

void CreateListR(LinkNode*& L, Elemtype a[], int n)
{
    LinkNode* s, * r;
    L = (LinkNode*)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++) {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;  // r points to the last element
    }
    r->next = NULL;
}

void DispList(LinkNode* L)
{
    LinkNode* p = L->next;
   
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void List_reverse(LinkNode* L)
{
    LinkNode* pre, * q; //设置两个指针
    pre = L->next; L->next = NULL; //前指针指向头结点
    while (pre) {
        q = pre->next; //将q设置为后一结点，此时pre指向待操作结点
        pre->next = L->next; //让pre指向现在的头结点
        L->next = pre; //表头指向最后插入的结点
        pre = q;
    }
}

void MergeList(LinkNode* La, LinkNode* Lb, LinkNode* &Lc) {
    LinkNode* pa, * pb, * pc;
    pa = La->next; pb = Lb->next; //
    Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data) {
            if (pc->data != pa->data) {
                pc->next = pa; pc = pa; pa = pa->next;
            }
            else {
                pa = pa->next;
            }
    }
        else {
            if (pc->data != pb->data) {
                pc->next = pb; pc = pb; pb = pb->next;
            }
            else {
                pb = pb->next;
            }
        }
        pc->next = pa ? pa : pb;
    }
    free(Lb);
}

void MergeList_E(LinkNode* La, LinkNode* Lb, LinkNode*& Lc) {
    LinkNode* pa, * pb, * pc;
    pa = La->next; pb = Lb->next; //
    Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data) {
                pc->next = pa; pc = pa; pa = pa->next;
        }
        else { 
                pc->next = pb; pc = pb; pb = pb->next;
        }
        pc->next = pa ? pa : pb; //这种算法保留了重复值
    }
    free(Lb);
}

void Intersection(LinkNode*& La, LinkNode* Lb) {
    LinkNode* pa = La->next;
    LinkNode* pb = Lb->next;
    LinkNode* pc = NULL;
    LinkNode* Lc = NULL; //C的头指针
    LinkNode* u = NULL;
    Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data == pb->data) {
            pc->next = pa; pc = pa;
            u = pb;   
            pa = pa->next; pb = pb->next;
            u->next = NULL; free(u); //边操作边释放
        }
        else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            u->next = NULL; free(u);
        }
        else {
                u = pb;
                pb = pb->next;
                u->next = NULL; free(u);
        }
    }
    while (pa) {                  //链表长度不同，我们需要释放未操作的结点
        u = pa;
        pa = pa->next;             //释放后续结点
        u->next = NULL; free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        u->next = NULL; free(u);
    }
    pc->next = NULL;
    La = Lc;
}

unsigned int Diff_Elem(LinkNode*& La, LinkNode* Lb) {
    LinkNode* pa = La->next;
    LinkNode* pb = Lb->next;
    LinkNode* cur = La;
    LinkNode* pre = La;
    LinkNode* u = NULL;
    unsigned int n_length = 0;

    while (pa && pb)
    {
        if (pa->data < pb->data) {
            cur->next = pa;
            pa = pa->next;
            cur = cur->next;
            pre = pre->next;
        }
        else if (pa->data > pb->data) {
            pb = pb->next;
        }
        else {
            pre->next = pa->next;
            u = pa;
            pa = pa->next;
            free(u);
            pb = pb->next;
        }
        if(!pb) cur->next=pa;
    }
    return ListLength(La);
}

unsigned int ListLength(LinkNode* L)
{
    unsigned int n_cal = 0;
    LinkNode* p = L;
    while (p->next != NULL)
    {
        n_cal++;
        p = p -> next;
    }
    printf("\n");
    return n_cal;
}

//unsigned int ListLength_1(LinkNode* L)
//{
//    unsigned int n_cal = 0; 
//    LinkNode* p = L;
//    while (p != NULL)  // 这种写法出错的根本在于算入了头结点
//    {
//        n_cal++;
//        p = p->next;
//    }
//    printf("\n");
//    return n_cal;
//}

void LinkSplit(LinkNode *&La, LinkNode*& Lb, LinkNode*& Lc)
{
    Lb = (LinkNode*)malloc(sizeof(LinkNode));
    Lb->next = NULL;
    Lc = (LinkNode*)malloc(sizeof(LinkNode));
    Lc->next = NULL;

    LinkNode* p = La->next;
    LinkNode* pre = NULL;
    LinkNode* tail = Lc;  //刚开始的尾指针指向头结点！
    while (p != NULL)
    {
        pre = p->next;
        if (p->data < 0) {
            p->next = Lb->next; Lb->next = p;
        }   //使用头插法插入元素
        else if (p->data >= 0) {
            p->next = NULL;
            tail->next = p; //使用尾插法插入元素
            tail = p;
        }
        p = pre;
    }
}

void Interval_Delete(LinkNode*& L,int mink,int maxk)
{
    LinkNode* pre = L;
    LinkNode* p = L->next;
    LinkNode* u = NULL;
    while (p->data<maxk)
    {
        if ((mink < p->data) && (p->data < maxk)) {
            u = p;
            pre->next = p->next;
            free(u);
            p = pre->next;
        }
        else {
            p = p->next;
            pre = pre->next;
        }
        
    }
}
bool Bonus_2_28(LinkNode*& La, LinkNode*& Lb,LinkNode*& Lc)
{
	LinkNode *pa, *pb, *cur,*pc,*pre=NULL,*u=NULL;

    if (!La || !Lb)
        return false;

	pa = La->next;
	pb = Lb->next;
    pc = Lc;
    pre = La;

	while(pa && pb)
	{
		if(pa->data==pb->data)
		{
			if(pc==Lc || pc->data!=pa->data)
            {
                cur = (LinkNode*)malloc(sizeof(LinkNode));
                if (cur == NULL)
                    return false;

                cur->next = NULL;//将结点插入链表
                cur->data = pa->data;
                
                pc->next = cur;
                pc = pc->next;
			}
            else
            {
                u = pa;
                pre->next = pa->next;
                free(u); //删除重复的元素
                pa = pre->next;
            }
            pre = pre->next;
            pa = pa->next;
            pb = pb->next;
		}
		else if(pa->data<pb->data)
		{
			u = pa;
            pre->next = pa->next;
            free(u);
            pa = pre->next;	
		}
		else
			pb = pb->next;
	}
    while (pa) { //删除没遍历到的元素
            u = pa;
            pre->next = pa->next;
            pa->next = NULL;
            free(u);
            pa = pre->next;
    }
	return true;
}
