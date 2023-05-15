// SortProj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"stdio.h"
#include "SortFun.h"		
#include <math.h>
#include"time.h"
int main()
{

	clock_t start, finish;     //定义第一次调用CPU时钟单位的实际，可以理解为定义一个计数器
	double Total_time;        //定义一个double类型的变量，用于存储时间单位
	RecType* signal=NULL;
	int nNum[1] ;
	int nFlag=2;//1表示直接读取key，2表示通过计算得到，如实验示例。
	const char* SourceFileName = "d:\\db.txt";
	const char* ResultFileName = "d:\\result.txt";
	signal=ReadNDSignalFromFile(SourceFileName,nNum, nFlag);//文件格式两种，nFlag=1表示key值已有，格式为ID号，Key值，数据项；nFlag=0表示没有key值，需要计算，格式为ID号，数据项；
	
	int n = *nNum;
	RecType* R=NULL;
	R= CloneArr(signal,n,0);
	printf("排序前: \n");	DispList(R, n,0);
	start = clock();
	InsertSort(R, n);//可以换成其他排序函数，注意heap和radius稍有不同，具体见后面的示例
	finish = clock();
	Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("插入排序后(耗时=%f秒):\n", Total_time); DispList(R, n,0);
	WriteNDSignalToFile(ResultFileName, R, n,1); free(R);R=NULL;
	//R = CloneArr(signal, n, 0);
	//BinInsertSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("折半查找排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//free(R);R=NULL;
	//R = CloneArr(signal, n, 0);
	//start = clock();
	//ShellSort(R, n);	//对R[0..n-1]按递增有序进行希尔排序
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("希尔排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//free(R);R=NULL;
	//R = CloneArr(signal, n, 0);
	//start = clock();
	//BubbleSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("冒泡排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0); 
	//free(R);R=NULL;
	//R = CloneArr(signal, n, 0);
	//start = clock();
	//QuickSort(R, 0, n - 1);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("快速排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//free(R);R=NULL;
	//R = CloneArr(signal, n, 0);
	// start = clock();
	//SelectSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("简单选择排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	////数组的存储位于data[1]------ - data[n]
	//free(R);R=NULL;
	//R = CloneArr(signal, n, 1);
	//
	//start = clock();
	//HeapSort(R, n);

	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("堆排序后(耗时=%f毫秒):\n", Total_time); 
	//DispList(R, n,1);
	//free(R); R = NULL;
	//R = CloneArr(signal, n, 0);

	//start = clock();
	//MergeSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("两路归并排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//free(R);R=NULL;

	/*NDLinkNode* p=NULL;	
	CreateLinkFromArr(p, signal, n);
	 DispLink(p); 
	 start = clock();
	RadixSort(p, 10, 3);
	finish = clock();
	Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("基数排序后(耗时=%f毫秒):\n", Total_time); 
	DispLink(p); 
	WriteNDSignalLinkToFile(ResultFileName, p,1);
	NDDestroyList(p);*/



	free(signal);
	getchar();
	return 1;
	//下面这部分程序是在程序赋值的例子，和实验书提供的例程类似

	//int n = 10;
	//KeyType a[] = { 6,8,7,9,0,1,3,2,4,5 };// { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//KeyType a[] =  { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//KeyType a[] = { 6,8,7,9,0,1,3,2,4,5 }; 
	//RecType R[MAXL];
	//CreateList(R, a, n);
	//printf("排序前: ");	DispList(R, n,0);
	//start = clock();
	//InsertSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("插入排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);

	//CreateList(R, a, n);
	//printf("排序前: ");	DispList(R, n,0); start = clock();
	//BinInsertSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("折半查找排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//CreateList(R, a, n);
	//printf("排序前: ");	DispList(R, n,0);
	//start = clock();
	//ShellSort(R, n);	//对R[0..n-1]按递增有序进行希尔排序
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("希尔排序后(耗时=%f毫秒):\n",Total_time); DispList(R, n,0);
	//CreateList(R, a, n);
	//printf("排序前:"); DispList(R, n,0); start = clock();
	//BubbleSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("冒泡排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	// 	CreateList(R, a, n);
	//printf("排序前:"); DispList(R, n,0); start = clock();
	//QuickSort(R, 0, n - 1);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("快速排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	//CreateList(R, a, n);
	//printf("排序前:"); DispList(R, n,0); start = clock();
	//SelectSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("简单选择排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
	////数组的存储位于data[1]------ - data[n]
	//CreateList1(R, a, n);
	//printf("排序前:"); DispList(R, n,0); start = clock();
	//HeapSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("堆排序后(耗时=%f毫秒):\n", Total_time); DispList1(R, n);

	//CreateList(R, a, n);
	//printf("排序前:"); DispList(R, n,0); start = clock();
	//MergeSort(R, n);
	//finish = clock();
	//Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("两路归并排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);

////	NodeType* p;
////	int a[] = { 75,223,98,44,157,2,29,164,38,82 };
//	CreateLink(p, a, n);
//	/*printf("   排序前:"); DispLink(p); start = clock();
//	RadixSort(p, 10, 3);*/
//	finish = clock();
//	Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
//	printf("基数排序后(耗时=%f毫秒):\n", Total_time); DispList(R, n,0);
//	DestroyLink(p);
	return 1;
}
