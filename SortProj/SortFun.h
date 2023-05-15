//文件名:exp10-1.cpp
//#include "seqlist.cpp"				//包含排序顺序表的基本运算算法
//typedef int arrs[5];
//typedef arrs* p_arr5;
//typedef p_arr5 arrp10[10];
//arr5 togs;       // togs是具有5个元素的int数组
//p_arr5 p2;      // p2是一个指针，指向具有元素的数组
//arrp10  ap;    // ap是具有十个元素的指针数组，每个指针指向具有5个元素的int数组

#include <stdio.h>
#include "malloc.h"
#include"math.h"
#define MAXL 100		//最大长度
typedef float KeyType;	//定义关键字类型为int
typedef int InfoType;
typedef struct
{
	KeyType key;		//关键字项
	InfoType ID;		//其他数据项，类型为InfoType
	float Item1;
	float Item2;
	float Item3;
} RecType;				//查找元素的类型
typedef struct NDLNode
{
	KeyType key;		//关键字项
	InfoType ID;		//其他数据项，类型为InfoType
	float Item1;
	float Item2;
	float Item3;
	struct NDLNode* next;		//指向后继结点
} NDLinkNode;

void swap(RecType& x, RecType& y);//x和y交换
void CreateList(RecType R[], KeyType keys[], int n);	//创建顺序表
void DispList(RecType R[], int n,int nFlag);	//输出顺序表
void CreateList1(RecType R[], KeyType keys[], int n);	//创建顺序表
void DispList1(RecType R[], int n);	//输出顺序表
/*链表*/
#define MAXE 20			//线性表中最多元素个数
#define MAXR 10			//基数的最大取值
typedef struct node
{
	int key;			//记录的关键字
	struct node* next;
} NodeType;


void CreateLink(NodeType*& p, KeyType a[], int n);	//采用尾插法创建单链表
void DispLink(NDLinkNode* p);	//输出单链表
void DestroyLink(NodeType* p);	//销毁单链表



void InsertSort(RecType R[], int n);	//对R[0..n-1]按递增有序进行直接插入排序
void BinInsertSort(RecType R[], int n);//对R[0..n-1]按递增有序进行折半插入排序
void ShellSort(RecType R[], int n);	//对R[0..n-1]按递增有序进行希尔排序
void BubbleSort(RecType R[], int n);	//对R[0..n-1]按递增有序进行冒泡排序
void disppart(RecType R[], int s, int t);//显示一趟划分后的结果
int partition(RecType R[], int s, int t);	//一趟划分
void QuickSort(RecType R[], int s, int t); //对R[s..t]的元素进行递增快速排序
void SelectSort(RecType R[], int n);//简单选择排序算法
void DispHeap(RecType R[], int i, int n);//以括号表示法输出建立的堆
void Sift(RecType R[], int low, int high);		//R[loww..high}堆筛选算法
void HeapSort(RecType R[], int n);	//对R[1]到R[n]元素实现堆排序
/*两路归并排序*/
void Merge(RecType R[], int low, int mid, int high);
void MergePass(RecType R[], int length, int n);	//实现一趟归并
void MergeSort(RecType R[], int n);  //二路归并排序算法;

/*基数排序*/

int keyi(int s, int i);	//对于数值s，从低到高位，取第i位的数字
void RadixSort(NDLinkNode *& p, int r, int d); //实现基数排序:p指向单链表的首节点,r为基数,d为关键字位数
/*ND数据*/
 			//单链表结点类型
void NDInitList(NDLinkNode*& L);		//初始化线性表
void NDDestroyList(NDLinkNode*& L);	//销毁线性表
bool NDListEmpty(NDLinkNode* L);		//判线性表是否为空表
int NDListLength(NDLinkNode* L);		//求线性表的长度
void NDDispList(NDLinkNode* L);	//输出线性表
bool NDListAppend(NDLinkNode*& L, KeyType e[], InfoType ID,int nFlag,KeyType Key);//插入第i个元素
bool NDListInsert(NDLinkNode*& L, int i, KeyType e[],InfoType ID);	//插入第i个元素
//void ReadNDSignalFromFile(RecType* signal, int* nNum);
RecType* ReadNDSignalFromFile(const char* FileName,int* nNum,int nFlag);
void WriteNDSignalToFile(const char* FileName, RecType s[],int n,int nFlag);//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找)
RecType* CloneArr(RecType* s, int nNum, int nFlag);//nFlag=1用于堆排序，其他=0;要注意用完free
void  CreateLinkFromArr(NDLinkNode*& p, RecType a[], int n);
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p, int nFlag);//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找