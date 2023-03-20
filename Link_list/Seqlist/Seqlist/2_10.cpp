#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

int main(){
    SqList L;
    SqList* L_p;
    int n = 0;
    ElemType e = 0;

    if(InitList_Sq(L_p)){
        
        //Size_of_Sqlist(L_p);
        //printf("Please insert the number of Seqlist:\n");
        //scanf("%d",&n);
        int arr[]={1,3,5,1,8,10,9,6,4,1,2,1};
        n = sizeof(arr)/sizeof(arr[0]); 
        CreateList(L_p, n, arr);
        printf_s("List Initialized! \n");
        DispList(L_p);
        //printf_s("Please insert the number to insert into Seqlist:\n");
        printf_s("Please insert the Element you'd like to delete:\n");
        scanf_s("%d",&e);
        /*if (ListDelete_Sq(L_p, e)) {
            printf_s("Elements are deleted successfully\n");
            DispList(L_p);
        }
        else return -1;*/
        ElemDelete_Sq(L_p, e);
        //Insert_in_Seq(L_p,e);
        //ListInsert_Sq(L_p, 7, 11);
        //printf_s("List Inserted! \n");
        DispList(L_p);
    }
    else{
        return -1;
    }
}