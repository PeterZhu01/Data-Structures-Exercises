//�ļ���:exp10-1.cpp
//#include "seqlist.cpp"				//��������˳���Ļ��������㷨
//typedef int arrs[5];
//typedef arrs* p_arr5;
//typedef p_arr5 arrp10[10];
//arr5 togs;       // togs�Ǿ���5��Ԫ�ص�int����
//p_arr5 p2;      // p2��һ��ָ�룬ָ�����Ԫ�ص�����
//arrp10  ap;    // ap�Ǿ���ʮ��Ԫ�ص�ָ�����飬ÿ��ָ��ָ�����5��Ԫ�ص�int����

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
void WriteNDSignalToFile(const char* FileName, RecType s[],int n,int nFlag);//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������)
RecType* CloneArr(RecType* s, int nNum, int nFlag);//nFlag=1���ڶ���������=0;Ҫע������free
void  CreateLinkFromArr(NDLinkNode*& p, RecType a[], int n);
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p, int nFlag);//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������