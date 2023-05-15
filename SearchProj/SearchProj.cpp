// SearchProj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"stdio.h"
#include"time.h"
#include"SortFun.h"

int main()
{
	clock_t start, finish;     //定义第一次调用CPU时钟单位的实际，可以理解为定义一个计数器
	double Total_time;        //定义一个double类型的变量，用于存储时间单位
	RecType* signal = NULL;
	int nNum[1];
	int nFlag = 1;
	/*int n = 10;*/
	KeyType k = 3;
	int nKeyPos;
	RecType* R = NULL;
	const char* SourceFileName = "d:\\db.txt";//查找需要排序的结果"d:\\db.txt";
	const char* ResultFileName = "d:\\result.txt";
	signal = ReadNDSignalFromFile(SourceFileName, nNum, nFlag);////文件格式两种，nFlag=1表示key值已有，格式为ID号，Key值，数据项；nFlag=0表示没有key值，需要计算，格式为ID号，数据项；
	int n = *nNum;
	R = CloneArr(signal, n, 0);

	printf("关键字序列:\n"); DispList(R, n, 0);
	printf("查找%f所比较的关键字:\n\t", k);

	/*1:本部分为二分法查找，需要先排序*/
	//printf("排序前: ");	DispList(R, n, 0);
	//BinInsertSort(R, n);//若没有排序的数据，需要调用排序函数排序，可以换成其他排序函数，注意heap和radius稍有不同，具体见后面的示例
	//						/*finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("插入排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n, 0);
	//WriteNDSignalToFile(ResultFileName, R, n, 1); free(R); R = NULL;*/

	//	start = clock();
	//	//nKeyPos = SeqSearch(R, n, k);
	//	nKeyPos =  BinSearch(R, n, k);
	//	//以下为查找重复关键字
	//	int nEnd, nStart;
	//	nEnd = nKeyPos; nStart = nKeyPos;
	//	while (R[nEnd].key == k) nEnd++;
	//	nEnd--;
	//	while (R[nStart].key == k) nStart--;
	//	nStart++;
	//	//查找重复关键字结束
	//	finish = clock();
	//	Total_time = (double)(finish - start) ;
	//	

	//	if (nKeyPos != 0)
	//	{
	//		printf("关键%f的节点信息如下：\n", k);
	//		printf("NO	ID	Item1	Item2	Item3\n");
	//		for (int i = nStart; i <= nEnd; i++)
	//			printf("%d,%d,%.1f,%.1f,%.1f\n",i+1,R[i].ID,R[i].Item1, R[i].Item2, R[i].Item3 );
	//	}
	//	else
	//		printf("元素%f不在表中\n", k);
	//	printf("查找(耗时=%f毫秒):\n", Total_time);
	//二分法查找结束
	/*2:本部分为二叉排序树*/
	//BSTNode* bt;
	//KeyType path[MaxSize];
	//int nNDFlag = 1;
	//printf("(1)创建一棵BST树:");
	//printf("\n");
	//bt = CreateBSTND(R, n);
	//printf("(2)BST:"); DispBST(bt, nNDFlag); printf("\n");
	//start = clock();
	//BSTNode* KeyNodePos = DuplicateSearchBSTND(bt, k, path, -1);//没有重复健也可以用该函数，类似SearchBST1
	//if (KeyNodePos == NULL)
	//	printf("没有要查找%f关键字\n", k);
	//else
	//{
	//	printf("关键%f的节点信息如下：\n", k);
	//	printf("NO	ID	Item1	Item2	Item3\n");
	//	int j = 1;
	//	while ((KeyNodePos != NULL) && (KeyNodePos->key == k))
	//	{
	//		printf("%d,%d,%f,%f,%f\n", j, KeyNodePos->ID, KeyNodePos->Item1, KeyNodePos->Item2, KeyNodePos->Item3);
	//		j = j + 1;
	//		KeyNodePos = DuplicateSearchBSTND(KeyNodePos->rchild, k, path, -1);
	//	}
	//}
	//	
	//}
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("查找(耗时=%f毫秒):\n", Total_time); 


	/*以下部分二叉树的其他操作*/
	/*printf("(3)bt%s\n", (JudgeBST(bt) ? "是一棵BST" : "不是一棵BST"));
	printf("(4)查找%f关键字(递归,顺序):", k); SearchBST1(bt, k, path, -1);
	printf("(5)查找%f关键字(非递归,逆序):", k); SearchBST2(bt, k);
	printf("\n(6)删除操作:\n");
	printf("   原BST:"); DispBST(bt, nNDFlag); printf("\n");
	printf("   删除节点4:");
	DeleteBST(bt, 4); DispBST(bt, nNDFlag); printf("\n");
	printf("   删除节点5:");
	DeleteBST(bt, 5); DispBST(bt, nNDFlag); printf("\n");
	printf("(7)销毁BST\n"); */
	//DestroyBST(bt);
	/*二叉排序树结束*/

	/*3：本部分为哈希表*/
	//哈希表 ha[0..m - 1]
	//存放元素个数 n个
	//哈希函数 H(key) = key % p(p≤m)
	//线性探查法
	int m = n;
	int  p = 13;
	int* KeyPos=NULL;
	//KeyType k = 12;
	HashTable* ha = (HashTable* )malloc(sizeof(HashTable) * m);// [MaxSize * 10] ;
	printf("(1)创建哈希表\n");
	CreateHTND(ha, R, n, m, p);
	printf("(2)输出哈希表:\n"); 
	DispHT(ha, n, m);
	printf("关键%f的节点信息如下：\n", k);
	printf("NO	ID	Item1	Item2	Item3\n");
	start = clock();
	KeyPos = DuplicateSearchHT(ha, m, p, k);
	if (KeyPos[0] > 0)
	{
		for(int i=1;i<= KeyPos[0];i++)
		printf("%d,%d,%.1f,%.1f,%.1f\n",i,ha[KeyPos[i]].ID, ha[KeyPos[i]].Item1, ha[KeyPos[i]].Item2, ha[KeyPos[i]].Item3);
	}
		else
		printf("   提示:未找到%.1f\n", k);
	finish = clock();
	Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("查找(耗时=%f秒):\n", Total_time);
	/*以下是实验教程提供的例子*/
	///*k = 77;
	//printf("(4)删除关键字%.1f\n", k);
	//DeleteHT(ha, m, p, n, k);
	//printf("(5)删除后的哈希表\n"); DispHT(ha, n, m);
	//printf("(6)查找关键字为%.1f的记录位置\n", k);
	//int i = SearchHT(ha, m, p, k);
	//if (i != -1)
	//	printf("   ha[%d].key=%.1f\n", i, k);
	//else
	//	printf("   提示:未找到%.1f\n", k);
	//printf("(7)插入关键字%.1f\n", k);
	//InsertHT(ha, n, m, p, k);
	//printf("(8)插入后的哈希表\n"); DispHT(ha, n, m); */
	//free(ha); ha = NULL;
	//free(KeyPos); KeyPos = NULL;
	/*哈希查找结束*/
	free(R); R = NULL;
	free(signal);
	//RecType R[MAXL];

	//KeyType k = 6;
	//KeyType a[] = { 4,9,0,1,8,6,3,5,2,7,6 };


	/*KeyType k = 9;
	KeyType a[] = { 1,2,3,4,5,6,7,8,9,10 };*/
	
	//CreateList(R, a, n);			//建立顺序表
	//printf("关键字序列:"); DispList(R, n,0);
	//printf("查找%f所比较的关键字:\n\t", k);
	//
	//clock_t start, finish;     //定义第一次调用CPU时钟单位的实际，可以理解为定义一个计数器
	//double Total_time;        //定义一个double类型的变量，用于存储时间单位
	//	 start = clock();
	//nKeyPos = BinSearch(R, n, k);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("折半查找(耗时=%f秒):", Total_time); 
	//	if (nKeyPos != 0)
	//	printf("元素%f的位置是%d\n", k, nKeyPos);
	//else
	//	printf("元素%f不在表中\n", k);

		//BSTNode* bt;
		//KeyType path[MaxSize];
		//
		//printf("(1)创建一棵BST树:");
		//printf("\n");
		//bt = CreateBST(a, n);
		//printf("(2)BST:"); DispBST(bt); printf("\n");
		//printf("(3)bt%s\n", (JudgeBST(bt) ? "是一棵BST" : "不是一棵BST"));
		//printf("(4)查找%f关键字(递归,顺序):", k); SearchBST1(bt, k, path, -1);
		//printf("(5)查找%f关键字(非递归,逆序):", k); SearchBST2(bt, k);
		//printf("\n(6)删除操作:\n");
		//printf("   原BST:"); DispBST(bt); printf("\n");
		//printf("   删除节点4:");
		//DeleteBST(bt, 4); DispBST(bt); printf("\n");
		//printf("   删除节点5:");
		//DeleteBST(bt, 5); DispBST(bt); printf("\n");
		//printf("(7)销毁BST\n"); DestroyBST(bt);

		/*KeyType x[] = { 16,74,60,43,54,90,46,31,29,88,77 };
		n = 11;
		int m = 13, p = 13, i;
		KeyType k = 29;
		HashTable ha[MaxSize];
		printf("(1)创建哈希表\n");
		CreateHT(ha, x, n, m, p);
		printf("(2)输出哈希表:\n"); DispHT(ha, n, m);
		printf("(3)查找关键字为%.1f的记录位置\n", k);
		i = SearchHT(ha, m, p, k);
		if (i != -1)
			printf("   ha[%d].key=%.1f\n", i, k);
		else
			printf("   提示:未找到%.1f\n", k);
		k = 77;
		printf("(4)删除关键字%.1f\n", k);
		DeleteHT(ha, m, p, n, k);
		printf("(5)删除后的哈希表\n"); DispHT(ha, n, m);
		printf("(6)查找关键字为%.1f的记录位置\n", k);
		i = SearchHT(ha, m, p, k);
		if (i != -1)
			printf("   ha[%d].key=%.1f\n", i, k);
		else
			printf("   提示:未找到%.1f\n", k);
		printf("(7)插入关键字%.1f\n", k);
		InsertHT(ha, n, m, p, k);
		printf("(8)插入后的哈希表\n"); DispHT(ha, n, m);*/


	//CreateList(R, a, n);			//建立顺序表
	//printf("关键字序列:"); DispList(R, n,0);
	//printf("查找%d的比较过程如下:\n", k);
	//if ((i = BinSearch(R, n, k)) != -1)
	//	printf("元素%d的位置是%d\n", k, i);
	//else
	//	printf("元素%d不在表中\n", k);
	getchar();
	return 1;
}
