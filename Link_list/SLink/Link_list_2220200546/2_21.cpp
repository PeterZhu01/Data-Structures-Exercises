#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

int main() {
	LinkNode* La;
	LinkNode* Lb;
	LinkNode* Lc;
	InitList(La);
	InitList(Lb);
	InitList(Lc);
	
	int a[] = { -3,-2,-1,4,5,12,17,18,20,23,25 };
	int b[] = { 3,4,4,5,8,9,9 };
	int n_a = sizeof(a) / sizeof(a[0]);
	int n_b = sizeof(b) / sizeof(b[0]);
	
	CreateListR(La, a, n_a);
	CreateListR(Lb, b, n_b);
	printf("This is your elements of list:\n");
	DispList(La);
	DispList(Lb);
	printf("After intersection and delete repeat elements:\n");
	if (Bonus_2_28(La, Lb, Lc)) {
		printf("This is the new list C:\n");
		DispList(Lc);
		printf("This is the new list A:\n");
		DispList(La);
	} 
	else
		printf_s("Fail\n");
	return 0;
}
