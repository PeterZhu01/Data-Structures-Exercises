//�ļ���:exp10-1.cpp
//#include "seqlist.cpp"				//��������˳���Ļ��������㷨
#include <stdio.h>
#include "malloc.h"
#include"math.h"
#define MAXL 100		//��󳤶�
typedef float KeyType;	//����ؼ�������Ϊint
typedef int InfoType;
typedef struct
{
	KeyType key;		//�ؼ�����
	InfoType ID;		//�������������ΪInfoType
	float Item1;
	float Item2;
	float Item3;
} RecType;				//����Ԫ�ص�����
typedef struct NDLNode
{
	KeyType key;		//�ؼ�����
	InfoType ID;		//�������������ΪInfoType
	float Item1;
	float Item2;
	float Item3;
	struct NDLNode* next;		//ָ���̽��
} NDLinkNode;

typedef struct nodebst               		//��¼����
{
	KeyType key;                  		//�ؼ�����
	InfoType ID;		//�������������ΪInfoType
	float Item1;
	float Item2;
	float Item3; 
	//InfoType data;               		//����������
	struct nodebst * lchild, * rchild;		//���Һ���ָ��
} BSTNode;


void swap(RecType& x, RecType& y);//x��y����
void CreateList(RecType R[], KeyType keys[], int n);	//����˳���
void DispList(RecType R[], int n,int nFlag);	//���˳���
void CreateList1(RecType R[], KeyType keys[], int n);	//����˳���
void DispList1(RecType R[], int n);	//���˳���
/*����*/
#define MAXE 20			//���Ա������Ԫ�ظ���
#define MAXR 10			//���������ȡֵ
typedef struct node
{
	int key;			//��¼�Ĺؼ���
	struct node* next;
} NodeType;


void CreateLink(NodeType*& p, KeyType a[], int n);	//����β�巨����������
void DispLink(NDLinkNode* p);	//���������
void DestroyLink(NodeType* p);	//���ٵ�����



void InsertSort(RecType R[], int n);	//��R[0..n-1]�������������ֱ�Ӳ�������
void BinInsertSort(RecType R[], int n);//��R[0..n-1]��������������۰��������
void ShellSort(RecType R[], int n);	//��R[0..n-1]�������������ϣ������
void BubbleSort(RecType R[], int n);	//��R[0..n-1]�������������ð������
void disppart(RecType R[], int s, int t);//��ʾһ�˻��ֺ�Ľ��
int partition(RecType R[], int s, int t);	//һ�˻���
void QuickSort(RecType R[], int s, int t); //��R[s..t]��Ԫ�ؽ��е�����������
void SelectSort(RecType R[], int n);//��ѡ�������㷨
void DispHeap(RecType R[], int i, int n);//�����ű�ʾ����������Ķ�
void Sift(RecType R[], int low, int high);		//R[loww..high}��ɸѡ�㷨
void HeapSort(RecType R[], int n);	//��R[1]��R[n]Ԫ��ʵ�ֶ�����
/*��·�鲢����*/
void Merge(RecType R[], int low, int mid, int high);
void MergePass(RecType R[], int length, int n);	//ʵ��һ�˹鲢
void MergeSort(RecType R[], int n);  //��·�鲢�����㷨;

/*��������*/

int keyi(int s, int i);	//������ֵs���ӵ͵���λ��ȡ��iλ������
void RadixSort(NDLinkNode *& p, int r, int d); //ʵ�ֻ�������:pָ��������׽ڵ�,rΪ����,dΪ�ؼ���λ��
/*ND����*/
 			//������������
void NDInitList(NDLinkNode*& L);		//��ʼ�����Ա�
void NDDestroyList(NDLinkNode*& L);	//�������Ա�
bool NDListEmpty(NDLinkNode* L);		//�����Ա��Ƿ�Ϊ�ձ�
int NDListLength(NDLinkNode* L);		//�����Ա�ĳ���
void NDDispList(NDLinkNode* L);	//������Ա�
bool NDListAppend(NDLinkNode*& L, KeyType e[], InfoType ID,int nFlag,KeyType Key);//�����i��Ԫ��
bool NDListInsert(NDLinkNode*& L, int i, KeyType e[],InfoType ID);	//�����i��Ԫ��
//void ReadNDSignalFromFile(RecType* signal, int* nNum);
RecType* ReadNDSignalFromFile(const char* FileName,int* nNum,int nFlag);
void WriteNDSignalToFile(const char* FileName, RecType s[], int n, int nFlag);//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������)
RecType* CloneArr(RecType* s, int nNum, int nFlag);//nFlag=1���ڶ���������=0;Ҫע������free
void  CreateLinkFromArr(NDLinkNode*& p, RecType a[], int n);
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p, int nFlag);//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������
/*���²�����غ���*/
#define MaxSize 100
int SeqSearch(RecType R[], int n, KeyType k);	//˳������㷨
int BinSearch(RecType R[], int n, KeyType k);	//�۰�����㷨
void DispBST(BSTNode* b,int nFlag);				//����˵��
bool InsertBST(BSTNode*& bt, KeyType k);
BSTNode* CreateBST(KeyType A[], int n);
void Delete1(BSTNode* p, BSTNode*& r); //��ɾ�ڵ�p������������rָ��������
void Delete(BSTNode*& p);		//�Ӷ�����������ɾ��p�ڵ�
bool DeleteBST(BSTNode*& bt, KeyType k);
void SearchBST1(BSTNode* bt, KeyType k, KeyType path[], int i);
BSTNode* DuplicateSearchBSTND(BSTNode* bt, KeyType k, KeyType path[], int i);
//�Էǵݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
int SearchBST2(BSTNode* bt, KeyType k);
bool JudgeBST(BSTNode* bt);	//�ж�bt�Ƿ�ΪBST;
void DestroyBST(BSTNode* bt);	//����һ��BST
bool InsertBSTND(BSTNode*& bt, RecType rec);	//����btΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
BSTNode* CreateBSTND(RecType A[], int n);

#define MaxSize 100			//��������ϣ����
#define NULLKEY -1			//����չؼ���ֵ
#define DELKEY	-2			//���屻ɾ�ؼ���ֵ
typedef struct
{
	KeyType key;			//�ؼ�����
	InfoType ID;		//�������������ΪInfoType
	float Item1;
	float Item2;
	float Item3;
	//InfoType data;			//����������
	int count;				//̽�������
} HashTable;				//��ϣ��Ԫ������
void InsertHT(HashTable ha[], int& n, int m, int p, KeyType k);
void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p);
int SearchHT(HashTable ha[], int m, int p, KeyType k);
int DeleteHT(HashTable ha[], int m, int p, int& n, int k);
void DispHT(HashTable ha[], int n, int m);
void CreateHTND(HashTable ha[], RecType x[], int n, int m, int p);  //������ϣ��
void InsertHTND(HashTable ha[], int& n, int m, int p, RecType rec);
int* DuplicateSearchHT(HashTable ha[], int m, int p, KeyType k);