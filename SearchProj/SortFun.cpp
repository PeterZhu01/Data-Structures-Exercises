//�ļ���:exp10-1.cpp
#include "SortFun.h"				//��������˳���Ļ��������㷨
void swap(RecType& x, RecType& y)	//x��y����
{
	RecType tmp = x;
	x = y; y = tmp;
}

void CreateList(RecType R[], KeyType keys[], int n)	//����˳���,��Ҫ���ڵ�����ֵ�Ƚϣ�IDֵĬ��Ϊ��ţ������Ϊkeyֵ
{
	for (int i = 0; i < n; i++)			//R[0..n-1]��������¼
	{
		R[i].key = keys[i];
		R[i].ID = i;
		R[i].Item1 = keys[i]; R[i].Item2 = 0; R[i].Item3 = 0;
	}
}
void DispList(RecType R[], int n,int nFlag)	//���˳���
{
	for (int i = 0; i < n; i++)
		printf("Key=%f��ID=%d,Item1=%f,Item2=%f,Item3=%f \n",R[i+nFlag].key,R[i + nFlag].ID,  R[i + nFlag].Item1, R[i + nFlag].Item2, R[i + nFlag].Item3);
	printf("\n");
}
//----����������Զ�����ĳ���
void CreateList1(RecType R[], KeyType keys[], int n)	//����˳���
{
	for (int i = 1; i <= n; i++)			//R[1..n]��������¼
		R[i].key = keys[i - 1];
}
void DispList1(RecType R[], int n)	//���˳���
{
	for (int i = 1; i <= n; i++)
	printf("Key=%f��ID=%d,Item1=%f,Item2=%f,Item3=%f \n", R[i].key, R[i].ID, R[i].Item1, R[i].Item2, R[i].Item3);
	//printf("\n");

}

void InsertSort(RecType R[],int n)	//��R[0..n-1]�������������ֱ�Ӳ�������
{	int i, j; RecType tmp;
	for (i=1;i<n;i++) 
	{
		printf("  i=%d������%d��������: ",i,R[i].key); 
		if (R[i].key<R[i-1].key)	//����ʱ 
		{	tmp=R[i];
			j=i-1; 
			do						//��R[i]�Ĳ���λ�� 
			{	R[j+1]=R[j];   		//���ؼ��ִ���R[i].key�ļ�¼����
				j--;
			}  while  (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;      		//��j+1������R[i]
		}
		DispList(R,n,0);
	}
}
void BinInsertSort(RecType R[], int n) //��R[0..n-1]��������������۰��������
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)		//����ʱ 
		{
			//printf("  i=%d������%d��������: ", i, R[i].key);
			tmp = R[i];		  			//��R[i]���浽tmp��
			low = 0;  high = i - 1;
			while (low <= high)	  		//��R[low..high]�в��Ҳ����λ��
			{
				mid = (low + high) / 2;		//ȡ�м�λ��
				if (tmp.key < R[mid].key)
					high = mid - 1;			//������������
				else
					low = mid + 1;			//��������Ұ���
			}                          	//��λ��high
			for (j = i - 1; j >= high + 1; j--)	//���н���Ԫ�غ���
				R[j + 1] = R[j];
			R[high + 1] = tmp;				//����tmp 
		}
		//DispList(R, n,0);
	}
}
void ShellSort(RecType R[], int n)	//��R[0..n-1]�������������ϣ������
{
	int i, j, d;
	RecType tmp;
	d = n / 2;					//�����ó�ֵ
	while (d > 0)
	{
		for (i = d; i < n; i++) 		//�����������ֱ�Ӳ�������
		{
			tmp = R[i];			//�����d��λ��һ�����ֱ�Ӳ�������
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		printf("  d=%d: ", d); DispList(R, n,0);
		d = d / 2;				//��С����
	}
}
void BubbleSort(RecType R[], int n)		//��R[0..n-1]�������������ð������
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;					//һ��ǰexchange��Ϊ��
		for (j = n - 1; j > i; j--)				//��λR[i],ѭ��n-i-1��
			if (R[j].key < R[j - 1].key)	//��������Ԫ�ط���ʱ
			{
				swap(R[j], R[j - 1]);		//��������Ԫ�ؽ���
				exchange = true;			//һ���н�����exchange��Ϊ��
			}
		printf("  i=%d: ��λԪ��%f����������", i, R[i].key);
		DispList(R, n,0);
		if (!exchange)					//����û�з�����������;�����㷨
			return;
	}
}
void disppart(RecType R[], int s, int t)	//��ʾһ�˻��ֺ�Ľ��
{
	static int i = 1;
	int j;
	printf("��%d�λ���:", i);
	for (j = 0; j < s; j++)
		printf("   ");
	for (j = s; j <= t; j++)
		printf("%.1f,", R[j].key);//ֻ��ӡһλС��
	printf("\n");
	i++;
}
int partition(RecType R[], int s, int t)	//һ�˻���
{
	int i = s, j = t;
	RecType tmp = R[i];			//��R[i]Ϊ��׼
	while (i < j)  				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{
		while (j > i&& R[j].key >= tmp.key)
			j--;				//��������ɨ��,��һ��С��tmp.key��R[j]
		R[i] = R[j];				//�ҵ�������R[j],����R[i]��
		while (i < j && R[i].key <= tmp.key)
			i++;				//��������ɨ��,��һ������tmp.key��R[i]
		R[j] = R[i];				//�ҵ�������R[i],����R[j]��
	}
	R[i] = tmp;
	disppart(R, s, t);
	return i;
}
void QuickSort(RecType R[], int s, int t) //��R[s..t]��Ԫ�ؽ��е�����������
{
	int i;
	if (s < t) 					//���������ٴ�������Ԫ�ص����
	{
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);		//��������ݹ�����
		QuickSort(R, i + 1, t);		//��������ݹ�����
	}
}
void SelectSort(RecType R[], int n)	//��ѡ�������㷨
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)    	 	//����i������
	{
		k = i;
		for (j = i + 1; j < n; j++)  	//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k] 
			if (R[j].key < R[k].key)
				k = j;           	//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k != i)          		//����R[i]��R[k] 
			swap(R[i], R[k]);
		printf(" i=%d,ѡ��ؼ���:%d,������Ϊ:", i, R[i].key);
		DispList(R, n,0);			//���ÿһ�˵�������
	}
}
/*������*/
int count = 1;							//ȫ�ֱ���
void DispHeap(RecType R[], int i, int n)	//�����ű�ʾ����������Ķ�
{
	if (i <= n)
		printf("%.1f", R[i].key);			//������ڵ�
	if (2 * i <= n || 2 * i + 1 < n)
	{
		printf("(");
		if (2 * i <= n)
			DispHeap(R, 2 * i, n);			//�ݹ�������������
		printf(",");
		if (2 * i + 1 <= n)
			DispHeap(R, 2 * i + 1, n);		//�ݹ�������������
		printf(")");
	}
}
void Sift(RecType R[], int low, int high)		//R[loww..high}��ɸѡ�㷨
{
	int i = low, j = 2 * i;     					//R[j]��R[i]������
	RecType temp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    						//��Ϊ2i+1
		if (temp.key < R[j].key)
		{
			R[i] = R[j];              		//��R[j]������˫�׽ڵ�λ����
			i = j;                    		//�޸�i��jֵ,�Ա��������ɸѡ
			j = 2 * i;
		}
		else break;                 		//ɸѡ����
	}
	R[i] = temp;                      		//��ɸѡ�ڵ��ֵ��������λ��
}
void HeapSort(RecType R[], int n)	//��R[1]��R[n]Ԫ��ʵ�ֶ�����
{
	RecType temp;
	int i, j;
	for (i = n / 2; i >= 1; i--)  		//ѭ��������ʼ��
		Sift(R, i, n);
	printf("��ʼ��:"); DispHeap(R, 1, n); printf("\n");	//�����ʼ��
	for (i = n; i >= 2; i--)   	//����n-1��ѭ��,���������
	{
		printf("��%d������:", count++);
		printf(" ����%.1f��%.1f,���%.1f ", R[i].key, R[1].key, R[1].key);
		temp = R[1];       //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
		R[1] = R[i];
		R[i] = temp;

		//swap(R[0], R[i]);        //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
		printf(" ������:");	//���ÿһ�˵�������
		for (j = 1; j <n; j++)
			printf("%.1f,", R[j].key);
		printf("%.1f\n", R[n].key);
		//printf("\n");
		Sift(R, 1, i - 1);     		//ɸѡR[1]�ڵ�,�õ�i-1���ڵ�Ķ�
		printf("ɸѡ�����õ���:"); DispHeap(R, 1, i - 1); printf("\n");
	}
}

/*��·�鲢����*/
void Merge(RecType R[], int low, int mid, int high)
//һ�ι鲢�������������R[low..mid]��R[mid+1..high]�鲢Ϊһ�������R[low..high]��
{
	RecType* R1;
	int i = low, j = mid + 1, k = 0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));  //��̬����ռ�
	while (i <= mid && j <= high)     	//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i].key <= R[j].key)    	//����1���еļ�¼����R1��
		{
			R1[k] = R[i];
			i++; k++;
		}
		else                       	//����2���еļ�¼����R1��
		{
			R1[k] = R[j];
			j++; k++;
		}
	while (i <= mid)          	   	//����1�����²��ָ��Ƶ�R1
	{
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high)                	//����2�����²��ָ��Ƶ�R1
	{
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++) //��R1���ƻ�R��
		R[i] = R1[k];
}
int Mcount = 1;									//ȫ�ֱ���
void MergePass(RecType R[], int length, int n)	//ʵ��һ�˹鲢
{
	int i;
	printf("��%d�˹鲢:", Mcount++);
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) 	//�鲢length�����������ӱ�
	{
		printf("R[%d,%d]��R[%d,%d]�鲢  ", i, i + length - 1, i + length, i + 2 * length - 1);
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length - 1 < n - 1)                		//���������ӱ�,���߳���С��length
	{
		printf("*R[%d,%d]��R[%d,%d]�鲢  ", i, i + length - 1, i + length, n - 1);
		Merge(R, i, i + length - 1, n - 1);  		//�鲢�������ӱ�
	}
	printf("\n�鲢�����"); DispList(R, n,0);		//������˵�������
}
void MergeSort(RecType R[], int n)  //��·�鲢�����㷨
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}

/*����*/

void CreateLink(NodeType*& p, KeyType a[], int n)	//����β�巨����������
{
	NodeType* s = NULL , * t = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (NodeType*)malloc(sizeof(NodeType));
		s->key = a[i];
		if (i == 0)
		{
			p = s; t = s;
		}
		else
		{
			t->next = s; t = s;
		}
	}
	t->next = NULL;
}
void CreateLinkFromArr(NDLinkNode *& p, RecType a[], int n)	//����β�巨����������
{
	NDLinkNode * s = NULL, * t = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (NDLinkNode*)malloc(sizeof(NDLinkNode));
		s->ID = a[i].ID; s->key = a[i].key;
		s->Item1 = a[i].Item1; s->Item2 = a[i].Item2; s->Item3 = a[i].Item3;
		
		if (i == 0)
		{
			p = s; t = s;
		}
		else
		{
			t->next = s; t = s;
		}
	}
	t->next = NULL;
}

void DispLink(NDLinkNode* p)	//���������
{
	while (p != NULL)
	{
		printf("%.1f,%d,%.1f,%.1f,%.1f\n", p->key,p->ID,p->Item1, p->Item2, p->Item3);;
		p = p->next;
	}
	printf("\n");
}
void DestroyLink(NodeType* p)	//���ٵ�����
{
	NodeType* pre = p, * q = pre->next;
	while (q != NULL)
	{
		free(pre);
		pre = q;
		q = q->next;
	}
	free(pre);
}
/*��������*/


int keyi(int s, int i)	//������ֵs���ӵ͵���λ��ȡ��iλ������
{
	for (int j = 0; j < i; j++)
		s = s / 10;
	return s % 10;

}
void RadixSort(NDLinkNode *& p, int r, int d) //ʵ�ֻ�������:pָ��������׽ڵ�,rΪ����,dΪ�ؼ���λ��
{
	NDLinkNode * head[MAXR], * tail[MAXR], * t=NULL;	//��������ӵ���βָ��
	int i, j, k;
	for (i = 0; i < d; i++)           		//�ӵ�λ����λѭ��
	{
		for (j = 0; j < r; j++) 				//��ʼ���������ס�βָ��
			head[j] = tail[j] = NULL;
		while (p != NULL)          		//����ԭ������ÿ���ڵ�ѭ��
		{
			k = keyi(p->key, i);   		//��p�ڵ�ؼ��ֵĵ�iλk
			if (head[k] == NULL)   		//��p�ڵ���䵽��k������
			{
				head[k] = p;
				tail[k] = p;
			}
			else
			{
				tail[k]->next = p;
				tail[k] = p;
			}
			p = p->next;             		//����ɨ����һ���ڵ�
		}
		p = NULL;
		for (j = 0; j < r; j++)        		//����ÿһ������ѭ��
			if (head[j] != NULL)         	//�����ռ�
			{
				if (p == NULL)
				{
					p = head[j];
					t = tail[j];
				}
				else
				{
					t->next = head[j];
					t = tail[j];
				}
			}
		t->next = NULL;					//���һ���ڵ��next����NULL
		printf("��%dλ����:", i + 1); DispLink(p);
	}
}
/*ND����*/
void NDInitList(NDLinkNode*& L)		//��ʼ�����Ա�
{
	L = (NDLinkNode*)malloc(sizeof(NDLinkNode));  //����ͷ���
	L->next = NULL;				//��������Ϊ�ձ�
}
void NDDestroyList(NDLinkNode*& L)	//�������Ա�
{
	NDLinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;					//pre��pͬ������һ�����					
		p = pre->next;
	}
	free(pre);					//��ʱpΪNULL,preָ��β���,�ͷ���
}
bool NDListEmpty(NDLinkNode* L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next == NULL);
}
int NDListLength(NDLinkNode* L)		//�����Ա�ĳ���
{
	int i = 0;
	NDLinkNode* p = L;				//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return(i);					//ѭ������,pָ��β���,�����iΪ������
}

void NDDispList(NDLinkNode* L)	//������Ա�
{
	NDLinkNode* p = L->next;	//pָ���׽��
	int i;

	while (p != NULL)			//p��ΪNULL,���p����data��
	{
		/*for (i = 0; i < p->D - 1; i++)
			printf("%f,", p->data[i]);
		printf("%f\n", p->data[p->D - 1]);*/
		printf("%f,%f,%f\n", p->Item1, p->Item2, p->Item3);
		p = p->next;			//p������һ�����
	}
	printf("\n");
}
bool NDListAppend(NDLinkNode*& L, KeyType e[], InfoType ID,int nFlag, KeyType key)	//׷��Ԫ��
{
	NDLinkNode* p = L, * s;
	int k;
	if (p == NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p,�����½�㲢����true
	{
		while (p->next!=NULL)
			p = p->next;
		s = (NDLinkNode*)malloc(sizeof(NDLinkNode));
		//s->D = D; 
		s->ID = ID;
		s->Item1 = e[0]; s->Item2 = e[1]; s->Item3 = e[2];
		/*for (k = 0; k < s->D; k++)
			s->data[k] = e[k];*/				//�����½��s,��data����Ϊe
		if (nFlag)
			s->key = key;
		s->next = NULL;
		p->next = s;
		return true;
	}
}


bool NDListInsert(NDLinkNode*& L, int i, float e[])	//�����i��Ԫ��
{
	int j = 0;
	if (i <= 0) return false;		//i���󷵻ؼ�
	NDLinkNode* p = L, * s;			//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	int k;
	while (j < i - 1 && p != NULL)	//���ҵ�i-1�����p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p,�����½�㲢����true
	{
		s = (NDLinkNode*)malloc(sizeof(NDLinkNode));
		s->Item1 = e[0]; s->Item2 = e[1]; s->Item3 = e[2];
			
		s->next = p->next;		//�����s���뵽���p֮��
		p->next = s;
		return true;
	}
}
RecType* ReadNDSignalFromFile(const char* FileName,int *nNum,int nFlag)//nFlag=1 ��Ҫ����ؼ�ֵ��0����Ҫֱ�Ӵ��ļ��ж�
{
	RecType* signal;
int D = 3;//����ά��
FILE* fps, * fpr;
//fopen_s(&fps, "D:\\db.txt", "r");
fopen_s(&fps,FileName, "r");

NDLinkNode* h;
NDInitList(h);
int i = 0;
KeyType e[3],key=0;
float ID;
while (!feof(fps))
{
	fscanf_s(fps, "%f,", &ID, sizeof(float));
	if(nFlag)
		fscanf_s(fps, "%f,", &key, sizeof(KeyType));
	fscanf_s(fps, "%f,", &e[0], sizeof(KeyType));
	fscanf_s(fps, "%f,", &e[1], sizeof(KeyType));
	fscanf_s(fps, "%f\n", &e[2], sizeof(KeyType));
	NDListAppend(h,e,ID,nFlag,key);
}
fclose(fps);
//printf("  (3)���������h:\n");
//NDDispList(h);
KeyType AnchorPoint[3];
AnchorPoint[0] = 0; AnchorPoint[1] = 0; AnchorPoint[2] = 0;
int nPointNum = NDListLength(h);
signal = (RecType*)malloc(sizeof(RecType) * nPointNum);
//float* data = (float*)malloc(sizeof(float) * nPointNum);
NDLinkNode* tmpp = h->next;				//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
float tmpD = 0;
int k = 0;
while (tmpp != NULL)
{
	tmpD = 0;
	if (nFlag)
		signal[k].key = tmpp->key;
	else
	{

		//for (i = 0; i < tmpp->D; i++)
			tmpD = (AnchorPoint[0] - tmpp->Item1) * (AnchorPoint[0] - tmpp->Item1)+ (AnchorPoint[1] - tmpp->Item2) * (AnchorPoint[1] - tmpp->Item2)+ (AnchorPoint[2] - tmpp->Item3) * (AnchorPoint[2] - tmpp->Item3);
		signal[k].key = sqrt(tmpD);
	}	
	signal[k].ID = tmpp->ID;
	signal[k].Item1 = tmpp->Item1;
	signal[k].Item2 = tmpp->Item2;
	signal[k].Item3 = tmpp->Item3;
	k++;
	tmpp = tmpp->next;
}

*nNum = k;
NDDestroyList(h);
return signal;

//fopen_s(&fpr, "d:\\result.txt", "w");
//for (int j = 0; j < nPointNum; j = j + 1)
//{
//	fprintf(fpr, "%f\n", data[j]);
//	//fprintf(fpr,"%f,%f,%f\n", data[j], data[j+1], data[j+2]);
//	//i = i + 1;
//}
//fclose(fpr);
//getchar();
//return 1;
}
RecType* CloneArr(RecType* s, int nNum,int nFlag)//nFlag=1���ڶ���������=0;Ҫע������free
{
	int nTotalNum = nNum + nFlag;

	RecType* Out = (RecType*)malloc(sizeof(RecType) * (nTotalNum));
	for (int i = 0; i < nNum; i++)
		Out[i+nFlag] = s[i];
	return Out;

}
void WriteNDSignalToFile(const char* FileName, RecType s[], int n, int nFlag)//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������)
{

	FILE* fpr;
	fopen_s(&fpr, FileName, "w");
	//fopen_s(&fpr, "d:\\result.txt", "w");
	if (nFlag)
	{
		for (int i = 0; i < n; i++)
			fprintf(fpr, "%d,%f,%f,%f,%f\n", s[i].ID, s[i].key, s[i].Item1, s[i].Item2, s[i].Item3);

	}
	else
	{
		for (int i = 0; i < n; i++)
			fprintf(fpr, "Key=%f��ID=%d,Item1=%f,Item2=%f,Item3=%f \n", s[i].key, s[i].ID, s[i].Item1, s[i].Item2, s[i].Item3);

	}

	fclose(fpr);

}
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p, int nFlag)//nFlag=0,���ڹۿ���nFlag=1��ʽͬ�����ļ������ں�������
{

	FILE* fpr = NULL;
	fopen_s(&fpr, FileName, "w");
	//fopen_s(&fpr, "d:\\result.txt", "w");
	if (nFlag)
	{
		while (p != NULL)
		{
			fprintf(fpr, "%d,%f,%f,%f,%f \n", p->ID, p->key, p->Item1, p->Item2, p->Item3);;
			p = p->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			fprintf(fpr, "Key=%f��ID=%d,Item1=%f,Item2=%f,Item3=%f \n", p->key, p->ID, p->Item1, p->Item2, p->Item3);;
			p = p->next;
		}
	}

	fclose(fpr);

}



/*�˺�Ϊ���Һ���*/
int SeqSearch(RecType R[], int n, KeyType k)	//˳������㷨
{
	int i = 0;
	while (i < n && R[i].key != k)
	{
		printf("%.1f ", R[i].key);
		i++;					//�ӱ�ͷ������
	}
	if (i >= n)
		return 0;
	else
	{
		printf("%.1f", R[i].key);
		return i + 1;
	}
}
int BinSearch(RecType R[], int n, KeyType k)	//�۰�����㷨
{
	int low = 0, high = n - 1, mid, count = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%.1f\n", ++count, low, high, mid, R[mid].key);
		if (R[mid].key == k)   	//���ҳɹ�����
			return mid ;
		if (R[mid].key > k)     		//������R[low..mid-1]�в���
			high = mid - 1;
		else
			low = mid + 1;       		//������R[mid+1..high]�в���
	}
	return 0;
}
bool InsertBST(BSTNode*& bt, KeyType k)	//����btΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
{
	if (bt == NULL)						//ԭ��Ϊ��, �²���ļ�¼Ϊ���ڵ�
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)
		return false;
	else if (k < bt->key)
		return InsertBST(bt->lchild, k);	//���뵽bt�ڵ����������
	else
		return InsertBST(bt->rchild, k);  //���뵽bt�ڵ����������
}
BSTNode* CreateBST(KeyType A[], int n)
//������A�еĹؼ��ֽ���һ�ö���������
{
	BSTNode* bt = NULL;         			//��ʼʱbtΪ����
	int i = 0;
	while (i < n)
		if (InsertBST(bt, A[i]) == 1)		//��A[i]�������������T��
		{
			printf("    ��%d��,����%d:", i + 1, A[i]);
			DispBST(bt,0); printf("\n");
			i++;
		}
	return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}

bool InsertBSTND(BSTNode*& bt, RecType rec)	//����btΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
{
	if (bt == NULL)						//ԭ��Ϊ��, �²���ļ�¼Ϊ���ڵ�
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = rec.key;
		bt->ID = rec.ID;
		bt->Item1 = rec.Item1; bt->Item2 = rec.Item2; bt->Item3 = rec.Item3;

		bt->lchild = bt->rchild = NULL;
		return true;
	}
	/*else if (rec.key == bt->key)
		return false;*/
	else if (rec.key < bt->key)
		return InsertBSTND(bt->lchild, rec);	//���뵽bt�ڵ����������
	else
		return InsertBSTND(bt->rchild, rec);  //���뵽bt�ڵ����������
}
BSTNode* CreateBSTND(RecType A[], int n)
//������A�еĹؼ��ֽ���һ�ö���������
{
	BSTNode* bt = NULL;         			//��ʼʱbtΪ����
	int i = 0;
	while (i < n)
		if (InsertBSTND(bt, A[i]) == 1)		//��A[i]�������������T��
		{
			printf("    ��%d��,����%.1f:", i + 1, A[i].key);
			DispBST(bt,1); printf("\n");
			i++;
		}
	return bt;               			//���ؽ����Ķ����������ĸ�ָ��
}


void Delete1(BSTNode* p, BSTNode*& r) //��ɾ�ڵ�p������������rָ��������
{
	BSTNode* q;
	if (r->rchild != NULL)		//�ݹ��ҽڵ�r�������½ڵ�
		Delete1(p, r->rchild);
	else						//�ҵ��������½ڵ�r����û����������
	{
		p->key = r->key;			//���ڵ�r��ֵ��ŵ��ڵ�p�У��ڵ�ֵ�����
		p->Item1 = r->Item1; p->Item2 = r->Item2; p->Item3 = r->Item3;
		q = r;					//ɾ���ڵ�r
		r = r->lchild;			//���ýڵ�r�����������
		free(q);				//�ͷŽڵ�r�Ŀռ�
	}
}
void Delete(BSTNode*& p)		//�Ӷ�����������ɾ��p�ڵ�
{
	BSTNode* q;
	if (p->rchild == NULL)		//p�ڵ�û�������������
	{
		q = p; p = p->lchild; free(q);
	}
	else if (p->lchild == NULL)	//p�ڵ�û�������������
	{
		q = p; p = p->rchild; free(q);
	}
	else Delete1(p, p->lchild);	//p�ڵ�������������������������
}
bool DeleteBST(BSTNode*& bt, KeyType k)
//��bt��ɾ���ؼ���Ϊk�Ľڵ�
{
	if (bt == NULL) return false;		//����ɾ��ʧ��
	else
	{
		if (k < bt->key)
			return DeleteBST(bt->lchild, k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k);		//�ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
		else									//k=bt->key�����
		{
			Delete(bt);							//����Delete(bt)����ɾ��bt�ڵ�
			return true;
		}
	}
}
void SearchBST1(BSTNode* bt, KeyType k, KeyType path[], int i)
//�Էǵݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{
	int j;
	if (bt == NULL)
		return;
	else if (k == bt->key)	//�ҵ��˽ڵ�
	{
		path[i + 1] = bt->key;	//�����·��
		for (j = 0; j < i + 1; j++)
			printf("%.1f,", path[j]);
		printf("%.1f\n", path[i+1]); 
		
	}
	else
	{
		path[i + 1] = bt->key;
		if (k < bt->key)
			SearchBST1(bt->lchild, k, path, i + 1);  //���������еݹ����
		else
			SearchBST1(bt->rchild, k, path, i + 1);  //���������еݹ����
	}
}
BSTNode*  DuplicateSearchBSTND(BSTNode* bt, KeyType k, KeyType path[], int i)
//�Էǵݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{
	int j;
	if (bt == NULL)
		return NULL;
	else if (k == bt->key)	//�ҵ��˽ڵ�
	{
		path[i + 1] = bt->key;	//�����·��
		for (j = 0; j < i + 1; j++)
			printf("%.1f,", path[j]);
		printf("%.1f\n", path[i + 1]);
		return bt;

	}
	else
	{
		path[i + 1] = bt->key;
		if (k < bt->key)
			DuplicateSearchBSTND(bt->lchild, k, path, i + 1);  //���������еݹ����
		else
			DuplicateSearchBSTND(bt->rchild, k, path, i + 1);  //���������еݹ����
	}
}

int SearchBST2(BSTNode* bt, KeyType k)
//�Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
{
	if (bt == NULL)
		return 0;
	else if (k == bt->key)
	{
		printf("%.1f,", bt->key);
		return 1;
	}
	else if (k < bt->key)
		SearchBST2(bt->lchild, k);  //���������еݹ����
	else
		SearchBST2(bt->rchild, k);  //���������еݹ����
	printf("%.1f,", bt->key);
}

void DispBST(BSTNode* bt,int nFlag)
//�����ű�ʾ���������������bt
{
	if (bt != NULL)
	{
		if (nFlag)
			printf("%d:%.1f",bt->ID,bt->key);
		else
			printf("%.1f", bt->key);
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			DispBST(bt->lchild,nFlag);
			if (bt->rchild != NULL) printf(",");
			DispBST(bt->rchild, nFlag);
			printf(")");
		}
	}
}
KeyType predt = -32767;		//predtΪȫ�ֱ���,���浱ǰ�ڵ�����ǰ����ֵ,��ֵΪ-��
bool JudgeBST(BSTNode* bt)	//�ж�bt�Ƿ�ΪBST
{
	bool b1, b2;
	if (bt == NULL)
		return true;
	else
	{
		b1 = JudgeBST(bt->lchild);
		if (b1 == false || predt >= bt->key)
			return false;
		predt = bt->key;
		b2 = JudgeBST(bt->rchild);
		return b2;
	}
}
void DestroyBST(BSTNode* bt)	//����һ��BST
{
	if (bt != NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}

void InsertHT(HashTable ha[], int& n, int m, int p, KeyType k)  //���ؼ���Ϊk�ļ�¼���뵽��ϣ����
{
	int i, adr;
	adr = (int)k % p;
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY) //x[j]����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key = k;
		ha[adr].count = 1;
	}
	else					//������ͻʱ��������̽�ⷨ�����ͻ
	{
		i = 1;				//i��¼x[j]������ͻ�Ĵ���
		do
		{
			adr = (adr + 1) % m;
			i++;
		} while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = k;
		ha[adr].count = i;
	}
	n++;
}
void InsertHTND(HashTable ha[], int& n, int m, int p, RecType rec)  //���ؼ���Ϊk�ļ�¼���뵽��ϣ����
{
	int i, adr;
	adr = (int)(rec.key) % p;
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY) //x[j]����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key = rec.key;
		ha[adr].ID = rec.ID;
		ha[adr].Item1 = rec.Item1; ha[adr].Item2 = rec.Item2; ha[adr].Item3 = rec.Item3;
		ha[adr].count = 1;
	}
	else					//������ͻʱ��������̽�ⷨ�����ͻ
	{
		i = 1;				//i��¼x[j]������ͻ�Ĵ���
		do
		{
			adr = (adr + 1) % m;
			i++;
		} while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = rec.key;
		ha[adr].ID = rec.ID;
		ha[adr].Item1 = rec.Item1; ha[adr].Item2 = rec.Item2; ha[adr].Item3 = rec.Item3;
		ha[adr].count = i;
	}
	n++;
}


void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p)  //������ϣ��
{
	int i, n1 = 0;
	for (i = 0; i < m; i++)			//��ϣ���ó�ֵ
	{
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for (i = 0; i < n; i++)
		InsertHT(ha, n1, m, p, x[i]);
}
void CreateHTND(HashTable ha[], RecType x[], int n, int m, int p)  //������ϣ��
{

	int i, n1 = 0;
	for (i = 0; i < m; i++)			//��ϣ���ó�ֵ
	{
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for (i = 0; i < n; i++)
	{
		InsertHTND(ha, n1, m, p, x[i]);
	}
		

}

int SearchHT(HashTable ha[], int m, int p, KeyType k)		//�ڹ�ϣ���в��ҹؼ���k
{
	int i = 0, adr;
	adr = (int)k % p;
	while (ha[adr].key != NULLKEY && ha[adr].key != k &&i<m)
	{
		i++;				//��������̽�ⷨ����һ����ַ
		adr = (adr + 1) % m;
	}
	if (ha[adr].key == k)		//���ҳɹ�
		return adr;
	else					//����ʧ��
		return -1;
}
int * DuplicateSearchHT(HashTable ha[], int m, int p, KeyType k)		//�ڹ�ϣ���в��ҹؼ���k
{
	int i = 1, adr;
	adr = (int)k % p;
	int* adrArr =(int *) malloc(sizeof(int) * m);

	adrArr[0] = 0; 
	int j = adr;
	while (ha[adr].key != NULLKEY && j<m)
	{
		if (ha[adr].key == k)
		{
			adrArr[0]++;
			adrArr[i] = adr;
			i++;	

		}
		j++;
				//��������̽�ⷨ����һ����ַ
		adr = (adr + 1) % m;
	}
	return adrArr;
}

int DeleteHT(HashTable ha[], int m, int p, int& n, int k)	  //ɾ����ϣ���йؼ���k
{
	int adr;
	adr = SearchHT(ha, m, p, k);
	if (adr != -1)		//�ڹ�ϣ�����ҵ��ùؼ���
	{
		ha[adr].key = DELKEY;
		n--;			//��ϣ���ȼ�1
		return 1;
	}
	else				//�ڹ�ϣ����δ�ҵ��ùؼ���
		return 0;
}
void DispHT(HashTable ha[], int n, int m)    //�����ϣ��
{
	float avg = 0;
	int i;
	printf("    ��ϣ���ַ:   ");
	for (i = 0; i < m; i++)
		printf("%-4d", i);
	printf(" \n");
	printf("    ��ϣ��ؼ���: ");
	for (i = 0; i < m; i++)
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d", (int)ha[i].key);
	printf("\n");
	printf("    ̽�����:     ");
	for (i = 0; i < m; i++)
		if (ha[i].key == NULLKEY || ha[i].key == DELKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d", ha[i].count);
	printf(" \n");
	for (i = 0; i < m; i++)
		if (ha[i].key != NULLKEY && ha[i].key != DELKEY)
			avg = avg + ha[i].count;
	avg = avg / n;
	printf("    ƽ�����ҳ���ASL(%d)=%g\n", n, avg);
}