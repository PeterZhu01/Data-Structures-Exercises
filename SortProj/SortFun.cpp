//文件名:exp10-1.cpp
#include "SortFun.h"				//包含排序顺序表的基本运算算法
void swap(RecType& x, RecType& y)	//x和y交换
{
	RecType tmp = x;
	x = y; y = tmp;
}

void CreateList(RecType R[], KeyType keys[], int n)	//创建顺序表,主要用于单个数值比较，ID值默认为序号，数据项即为key值
{
	for (int i = 0; i < n; i++)			//R[0..n-1]存放排序记录
	{
		R[i].key = keys[i];
		R[i].ID = i;
		R[i].Item1 = keys[i]; R[i].Item2 = 0; R[i].Item3 = 0;
	}
}
void DispList(RecType R[], int n,int nFlag)	//输出顺序表
{
	for (int i = 0; i < n; i++)
		printf("Key=%f，ID=%d,Item1=%f,Item2=%f,Item3=%f \n",R[i+nFlag].key,R[i + nFlag].ID,  R[i + nFlag].Item1, R[i + nFlag].Item2, R[i + nFlag].Item3);
	printf("\n");
}
//----以下运算针对堆排序的程序
void CreateList1(RecType R[], KeyType keys[], int n)	//创建顺序表
{
	for (int i = 1; i <= n; i++)			//R[1..n]存放排序记录
		R[i].key = keys[i - 1];
}
void DispList1(RecType R[], int n)	//输出顺序表
{
	for (int i = 1; i <= n; i++)
	printf("Key=%f，ID=%d,Item1=%f,Item2=%f,Item3=%f \n", R[i].key, R[i].ID, R[i].Item1, R[i].Item2, R[i].Item3);
	//printf("\n");

}


void InsertSort(RecType R[],int n)	//对R[0..n-1]按递增有序进行直接插入排序
{	int i, j; RecType tmp;
	for (i=1;i<n;i++) 
	{
		//printf("  i=%d，插入%f，插入结果: \n",i,R[i].key); 
		if (R[i].key<R[i-1].key)	//反序时 
		{	tmp=R[i];
			j=i-1; 
			do						//找R[i]的插入位置 
			{	R[j+1]=R[j];   		//将关键字大于R[i].key的记录后移
				j--;
			}  while  (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;      		//在j+1处插入R[i]
		}
		//DispList(R,n,0);
	}
}
void BinInsertSort(RecType R[], int n) //对R[0..n-1]按递增有序进行折半插入排序
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)		//反序时 
		{
			printf("  i=%d，插入%d，插入结果: ", i, R[i].key);
			tmp = R[i];		  			//将R[i]保存到tmp中
			low = 0;  high = i - 1;
			while (low <= high)	  		//在R[low..high]中查找插入的位置
			{
				mid = (low + high) / 2;		//取中间位置
				if (tmp.key < R[mid].key)
					high = mid - 1;			//插入点在左半区
				else
					low = mid + 1;			//插入点在右半区
			}                          	//找位置high
			for (j = i - 1; j >= high + 1; j--)	//集中进行元素后移
				R[j + 1] = R[j];
			R[high + 1] = tmp;				//插入tmp 
		}
		DispList(R, n,0);
	}
}
void ShellSort(RecType R[], int n)	//对R[0..n-1]按递增有序进行希尔排序
{
	int i, j, d;
	RecType tmp;
	d = n / 2;					//增量置初值
	while (d > 0)
	{
		for (i = d; i < n; i++) 		//对所有组采用直接插入排序
		{
			tmp = R[i];			//对相隔d个位置一组采用直接插入排序
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		printf("  d=%d: ", d); DispList(R, n,0);
		d = d / 2;				//减小增量
	}
}
void BubbleSort(RecType R[], int n)		//对R[0..n-1]按递增有序进行冒泡排序
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;					//一趟前exchange置为假
		for (j = n - 1; j > i; j--)				//归位R[i],循环n-i-1次
			if (R[j].key < R[j - 1].key)	//相邻两个元素反序时
			{
				swap(R[j], R[j - 1]);		//将这两个元素交换
				exchange = true;			//一旦有交换，exchange置为真
			}
		printf("  i=%d: 归位元素%f，排序结果：", i, R[i].key);
		DispList(R, n,0);
		if (!exchange)					//本趟没有发生交换，中途结束算法
			return;
	}
}
void disppart(RecType R[], int s, int t)	//显示一趟划分后的结果
{
	static int i = 1;
	int j;
	printf("第%d次划分:", i);
	for (j = 0; j < s; j++)
		printf("   ");
	for (j = s; j <= t; j++)
		printf("%.1f,", R[j].key);//只打印一位小数
	printf("\n");
	i++;
}
int partition(RecType R[], int s, int t)	//一趟划分
{
	int i = s, j = t;
	RecType tmp = R[i];			//以R[i]为基准
	while (i < j)  				//从两端交替向中间扫描,直至i=j为止
	{
		while (j > i&& R[j].key >= tmp.key)
			j--;				//从右向左扫描,找一个小于tmp.key的R[j]
		R[i] = R[j];				//找到这样的R[j],放入R[i]处
		while (i < j && R[i].key <= tmp.key)
			i++;				//从左向右扫描,找一个大于tmp.key的R[i]
		R[j] = R[i];				//找到这样的R[i],放入R[j]处
	}
	R[i] = tmp;
	disppart(R, s, t);
	return i;
}
void QuickSort(RecType R[], int s, int t) //对R[s..t]的元素进行递增快速排序
{
	int i;
	if (s < t) 					//区间内至少存在两个元素的情况
	{
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);		//对左区间递归排序
		QuickSort(R, i + 1, t);		//对右区间递归排序
	}
}
void SelectSort(RecType R[], int n)	//简单选择排序算法
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)    	 	//做第i趟排序
	{
		k = i;
		for (j = i + 1; j < n; j++)  	//在当前无序区R[i..n-1]中选key最小的R[k] 
			if (R[j].key < R[k].key)
				k = j;           	//k记下目前找到的最小关键字所在的位置
		if (k != i)          		//交换R[i]和R[k] 
			swap(R[i], R[k]);
		printf(" i=%d,选择关键字:%d,排序结果为:", i, R[i].key);
		DispList(R, n,0);			//输出每一趟的排序结果
	}
}
/*堆排序*/
int count = 1;							//全局变量
void DispHeap(RecType R[], int i, int n)	//以括号表示法输出建立的堆
{
	if (i <= n)
		printf("%.1f", R[i].key);			//输出根节点
	if (2 * i <= n || 2 * i + 1 < n)
	{
		printf("(");
		if (2 * i <= n)
			DispHeap(R, 2 * i, n);			//递归调用输出左子树
		printf(",");
		if (2 * i + 1 <= n)
			DispHeap(R, 2 * i + 1, n);		//递归调用输出右子树
		printf(")");
	}
}
void Sift(RecType R[], int low, int high)		//R[loww..high}堆筛选算法
{
	int i = low, j = 2 * i;     					//R[j]是R[i]的左孩子
	RecType temp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key) 	//若右孩子较大,把j指向右孩子
			j++;    						//变为2i+1
		if (temp.key < R[j].key)
		{
			R[i] = R[j];              		//将R[j]调整到双亲节点位置上
			i = j;                    		//修改i和j值,以便继续向下筛选
			j = 2 * i;
		}
		else break;                 		//筛选结束
	}
	R[i] = temp;                      		//被筛选节点的值放入最终位置
}
void HeapSort(RecType R[], int n)	//对R[1]到R[n]元素实现堆排序
{
	RecType temp;
	int i, j;
	for (i = n / 2; i >= 1; i--)  		//循环建立初始堆
		Sift(R, i, n);
	printf("初始堆:"); DispHeap(R, 1, n); printf("\n");	//输出初始堆
	for (i = n; i >= 2; i--)   	//进行n-1次循环,完成推排序
	{
		printf("第%d趟排序:", count++);
		printf(" 交换%.1f与%.1f,输出%.1f ", R[i].key, R[1].key, R[1].key);
		temp = R[1];       //将第一个元素同当前区间内R[1]对换
		R[1] = R[i];
		R[i] = temp;

		//swap(R[0], R[i]);        //将第一个元素同当前区间内R[1]对换
		printf(" 排序结果:");	//输出每一趟的排序结果
		for (j = 1; j <n; j++)
			printf("%.1f,", R[j].key);
		printf("%.1f\n", R[n].key);
		//printf("\n");
		Sift(R, 1, i - 1);     		//筛选R[1]节点,得到i-1个节点的堆
		printf("筛选调整得到堆:"); DispHeap(R, 1, i - 1); printf("\n");
	}
}

/*两路归并排序*/
void Merge(RecType R[], int low, int mid, int high)
//一次归并：将两个有序表R[low..mid]和R[mid+1..high]归并为一个有序表R[low..high]中
{
	RecType* R1;
	int i = low, j = mid + 1, k = 0; //k是R1的下标,i、j分别为第1、2段的下标
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));  //动态分配空间
	while (i <= mid && j <= high)     	//在第1段和第2段均未扫描完时循环
		if (R[i].key <= R[j].key)    	//将第1段中的记录放入R1中
		{
			R1[k] = R[i];
			i++; k++;
		}
		else                       	//将第2段中的记录放入R1中
		{
			R1[k] = R[j];
			j++; k++;
		}
	while (i <= mid)          	   	//将第1段余下部分复制到R1
	{
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high)                	//将第2段余下部分复制到R1
	{
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++) //将R1复制回R中
		R[i] = R1[k];
}
int Mcount = 1;									//全局变量
void MergePass(RecType R[], int length, int n)	//实现一趟归并
{
	int i;
	printf("第%d趟归并:", Mcount++);
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) 	//归并length长的两相邻子表
	{
		printf("R[%d,%d]和R[%d,%d]归并  ", i, i + length - 1, i + length, i + 2 * length - 1);
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length - 1 < n - 1)                		//余下两个子表,后者长度小于length
	{
		printf("*R[%d,%d]和R[%d,%d]归并  ", i, i + length - 1, i + length, n - 1);
		Merge(R, i, i + length - 1, n - 1);  		//归并这两个子表
	}
	printf("\n归并结果："); DispList(R, n,0);		//输出该趟的排序结果
}
void MergeSort(RecType R[], int n)  //二路归并排序算法
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}

/*链表*/

void CreateLink(NodeType*& p, KeyType a[], int n)	//采用尾插法创建单链表
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
void CreateLinkFromArr(NDLinkNode *& p, RecType a[], int n)	//采用尾插法创建单链表
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

void DispLink(NDLinkNode* p)	//输出单链表
{
	while (p != NULL)
	{
		printf("%.1f,%d,%.1f,%.1f,%.1f\n", p->key,p->ID,p->Item1, p->Item2, p->Item3);;
		p = p->next;
	}
	printf("\n");
}
void DestroyLink(NodeType* p)	//销毁单链表
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
/*基数排序*/


int keyi(int s, int i)	//对于数值s，从低到高位，取第i位的数字
{
	for (int j = 0; j < i; j++)
		s = s / 10;
	return s % 10;

}
void RadixSort(NDLinkNode *& p, int r, int d) //实现基数排序:p指向单链表的首节点,r为基数,d为关键字位数
{
	NDLinkNode * head[MAXR], * tail[MAXR], * t=NULL;	//定义各链队的首尾指针
	int i, j, k;
	for (i = 0; i < d; i++)           		//从低位到高位循环
	{
		for (j = 0; j < r; j++) 				//初始化各链队首、尾指针
			head[j] = tail[j] = NULL;
		while (p != NULL)          		//对于原链表中每个节点循环
		{
			k = keyi(p->key, i);   		//找p节点关键字的第i位k
			if (head[k] == NULL)   		//将p节点分配到第k个链队
			{
				head[k] = p;
				tail[k] = p;
			}
			else
			{
				tail[k]->next = p;
				tail[k] = p;
			}
			p = p->next;             		//继续扫描下一个节点
		}
		p = NULL;
		for (j = 0; j < r; j++)        		//对于每一个链队循环
			if (head[j] != NULL)         	//进行收集
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
		t->next = NULL;					//最后一个节点的next域置NULL
		printf("按%d位排序:", i + 1); DispLink(p);
	}
}
/*ND数据*/
void NDInitList(NDLinkNode*& L)		//初始化线性表
{
	L = (NDLinkNode*)malloc(sizeof(NDLinkNode));  //创建头结点
	L->next = NULL;				//单链表置为空表
}
void NDDestroyList(NDLinkNode*& L)	//销毁线性表
{
	NDLinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;					//pre、p同步后移一个结点					
		p = pre->next;
	}
	free(pre);					//此时p为NULL,pre指向尾结点,释放它
}
bool NDListEmpty(NDLinkNode* L)		//判线性表是否为空表
{
	return(L->next == NULL);
}
int NDListLength(NDLinkNode* L)		//求线性表的长度
{
	int i = 0;
	NDLinkNode* p = L;				//p指向头结点,n置为0(即头结点的序号为0)
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return(i);					//循环结束,p指向尾结点,其序号i为结点个数
}

void NDDispList(NDLinkNode* L)	//输出线性表
{
	NDLinkNode* p = L->next;	//p指向首结点
	int i;

	while (p != NULL)			//p不为NULL,输出p结点的data域
	{
		/*for (i = 0; i < p->D - 1; i++)
			printf("%f,", p->data[i]);
		printf("%f\n", p->data[p->D - 1]);*/
		printf("%f,%f,%f\n", p->Item1, p->Item2, p->Item3);
		p = p->next;			//p移向下一个结点
	}
	printf("\n");
}
bool NDListAppend(NDLinkNode*& L, KeyType e[], InfoType ID,int nFlag, KeyType key)	//追加元素
{
	NDLinkNode* p = L, * s;
	int k;
	if (p == NULL)				//未找到第i-1个结点,返回false
		return false;
	else						//找到第i-1个结点p,插入新结点并返回true
	{
		while (p->next!=NULL)
			p = p->next;
		s = (NDLinkNode*)malloc(sizeof(NDLinkNode));
		//s->D = D; 
		s->ID = ID;
		s->Item1 = e[0]; s->Item2 = e[1]; s->Item3 = e[2];
		/*for (k = 0; k < s->D; k++)
			s->data[k] = e[k];*/				//创建新结点s,其data域置为e
		if (nFlag)
			s->key = key;
		s->next = NULL;
		p->next = s;
		return true;
	}
}


bool NDListInsert(NDLinkNode*& L, int i, float e[])	//插入第i个元素
{
	int j = 0;
	if (i <= 0) return false;		//i错误返回假
	NDLinkNode* p = L, * s;			//p指向头结点,j置为0(即头结点的序号为0)
	int k;
	while (j < i - 1 && p != NULL)	//查找第i-1个结点p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//未找到第i-1个结点,返回false
		return false;
	else						//找到第i-1个结点p,插入新结点并返回true
	{
		s = (NDLinkNode*)malloc(sizeof(NDLinkNode));
		s->Item1 = e[0]; s->Item2 = e[1]; s->Item3 = e[2];
			
		s->next = p->next;		//将结点s插入到结点p之后
		p->next = s;
		return true;
	}
}
RecType* ReadNDSignalFromFile(const char* FileName,int *nNum,int nFlag)//nFlag=1 需要计算关键值，0不需要直接从文件中读
{
RecType* signal;
int D = 3;//数据维数
FILE* fps, * fpr;
//fopen_s(&fps, "D:\\db.txt", "r");
fopen_s(&fps,FileName, "r");

NDLinkNode* h;
NDInitList(h);
int i = 0;
KeyType e[3],key=0;
int ID;
while (!feof(fps))
{
	fscanf_s(fps, "%d,", &ID, sizeof(float));
	if(nFlag)
	fscanf_s(fps, "%f,", &key, sizeof(KeyType));
	fscanf_s(fps, "%f,", &e[0], sizeof(KeyType));
	fscanf_s(fps, "%f,", &e[1], sizeof(KeyType));
	fscanf_s(fps, "%f\n", &e[2], sizeof(KeyType));
	NDListAppend(h,e,ID,nFlag,key);
}
fclose(fps);
//printf("  (3)输出单链表h:\n");
//NDDispList(h);
KeyType AnchorPoint[3];
AnchorPoint[0] = 0; AnchorPoint[1] = 0; AnchorPoint[2] = 0;
int nPointNum = NDListLength(h);
signal = (RecType*)malloc(sizeof(RecType) * nPointNum);
//float* data = (float*)malloc(sizeof(float) * nPointNum);
NDLinkNode* tmpp = h->next;				//p指向头结点,n置为0(即头结点的序号为0)
float tmpD = 0;
int k = 0;
while (tmpp != NULL)
{
	tmpD = 0;
	if (nFlag==1)
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
RecType* CloneArr(RecType* s, int nNum,int nFlag)//nFlag=1用于堆排序，其他=0;要注意用完free
{
	int nTotalNum = nNum + nFlag;

	RecType* Out = (RecType*)malloc(sizeof(RecType) * (nTotalNum));
	for (int i = 0; i < nNum; i++)
		Out[i+nFlag] = s[i];
	return Out;

}
void WriteNDSignalToFile(const char* FileName, RecType s[], int n,int nFlag)//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找)
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
		fprintf(fpr, "Key=%f，ID=%d,Item1=%f,Item2=%f,Item3=%f \n", s[i].key, s[i].ID, s[i].Item1, s[i].Item2, s[i].Item3);

	}

	fclose(fpr);
	
}
void WriteNDSignalLinkToFile(const char* FileName, NDLinkNode* p,int nFlag)//nFlag=0,便于观看；nFlag=1格式同输入文件，便于后续查找
{

	FILE* fpr=NULL;
	fopen_s(&fpr, FileName, "w");
	//fopen_s(&fpr, "d:\\result.txt", "w");
	if (nFlag)
	{
		while (p != NULL)
		{
			fprintf(fpr, "%d,%f,%f,%f,%f \n",  p->ID, p->key,p->Item1, p->Item2, p->Item3);;
			p = p->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			fprintf(fpr, "Key=%f，ID=%d,Item1=%f,Item2=%f,Item3=%f \n", p->key, p->ID, p->Item1, p->Item2, p->Item3);;
			p = p->next;
		}
	}
	
		fclose(fpr);

}

