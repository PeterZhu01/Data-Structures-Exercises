//文件名:exp10-1.cpp
//#include "seqlist.cpp"				//包含排序顺序表的基本运算算法
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

typedef struct nodebst               		//记录类型
{
	KeyType key;                  		//关键字项
	InfoType ID;		//其他数据项，类型为InfoType
	float Item1;
	float Item2;
	float Item3; 
	//InfoType data;               		//其他数据域
	struct nodebst * lchild, * rchild;		//左右孩子指针
} BSTNode;


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
void WriteNDSignalToFile(const char* FileName, RecType s[], int n, int nFlag);//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找)
RecType* CloneArr(RecType* s, int nNum, int nFlag);//nFlag=1用于堆排序，其他=0;要注意用完free
void  CreateLinkFromArr(NDLinkNode*& p, RecType a[], int n);
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p, int nFlag);//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找
/*以下查找相关函数*/
#define MaxSize 100
int SeqSearch(RecType R[], int n, KeyType k);	//顺序查找算法
int BinSearch(RecType R[], int n, KeyType k);	//折半查找算法
void DispBST(BSTNode* b,int nFlag);				//函数说明
bool InsertBST(BSTNode*& bt, KeyType k);
BSTNode* CreateBST(KeyType A[], int n);
void Delete1(BSTNode* p, BSTNode*& r); //被删节点p有左、右子树，r指向其左孩子
void Delete(BSTNode*& p);		//从二叉排序树中删除p节点
bool DeleteBST(BSTNode*& bt, KeyType k);
void SearchBST1(BSTNode* bt, KeyType k, KeyType path[], int i);
BSTNode* DuplicateSearchBSTND(BSTNode* bt, KeyType k, KeyType path[], int i);
//以非递归方式输出从根节点到查找到的节点的路径
int SearchBST2(BSTNode* bt, KeyType k);
bool JudgeBST(BSTNode* bt);	//判断bt是否为BST;
void DestroyBST(BSTNode* bt);	//销毁一颗BST
bool InsertBSTND(BSTNode*& bt, RecType rec);	//在以bt为根节点的BST中插入一个关键字为k的节点
BSTNode* CreateBSTND(RecType A[], int n);

#define MaxSize 100			//定义最大哈希表长度
#define NULLKEY -1			//定义空关键字值
#define DELKEY	-2			//定义被删关键字值
typedef struct
{
	KeyType key;			//关键字域
	InfoType ID;		//其他数据项，类型为InfoType
	float Item1;
	float Item2;
	float Item3;
	//InfoType data;			//其他数据域
	int count;				//探测次数域
} HashTable;				//哈希表元素类型
void InsertHT(HashTable ha[], int& n, int m, int p, KeyType k);
void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p);
int SearchHT(HashTable ha[], int m, int p, KeyType k);
int DeleteHT(HashTable ha[], int m, int p, int& n, int k);
void DispHT(HashTable ha[], int n, int m);
void CreateHTND(HashTable ha[], RecType x[], int n, int m, int p);  //创建哈希表
void InsertHTND(HashTable ha[], int& n, int m, int p, RecType rec);
int* DuplicateSearchHT(HashTable ha[], int m, int p, KeyType k);