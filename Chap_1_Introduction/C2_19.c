#include <stdio.h>
#include <limits.h>
//#include <stdlib.h>

#define ARR_SIZE 20   //定义数组大小

// 计算 i! * 2^i 的函数
 unsigned long long calc(int i) {
    unsigned long long result_1 = 1ULL;
    unsigned long long result = 1ULL;
    for (int j = 1; j <= i; j++) {
        result_1 *= j;
        if (result_1 >= (ULLONG_MAX >> j)) { // 如果a！太大就没有必要计算2^i
            // 数组已满或溢出
            return -1;
        }
        //result += result_1 << 1ULL; //使用左移代替乘法，避免出错
    }
    unsigned long long left_mov(unsigned long long ,int );
    result = left_mov(result_1,i);
    return result;
}

// 存储计算结果到函数的数组
int push(unsigned long long *a, int i, unsigned long long value) {
    if (i >= ARR_SIZE)  // 如果实际计算的i超出数组大小，返回0
        return 0;
    a[i-1] = value;
    return 1;
}

// 此函数可以通过左移数据达到乘法的效果
unsigned long long left_mov(unsigned long long result_1,int i_mov){
    unsigned long long result_2 = result_1 << i_mov;
    return result_2;
}
int main() {
    int n = ARR_SIZE;
    int max_index = 0;
    unsigned long long a[ARR_SIZE] = {0};
    for (int i = 1; i <= n; i++) {
        unsigned long long value;
        value = calc(i);
        if (value == -1) {
            printf("数值过大,在i=%d处,即第%d个元素无法正常存储\n", (i-1),i);
            break;
        }
        
        if (!push(a, i, value)) {
            printf("数组已满,值并未溢出i=%d\n", i);
            break;
        }
        max_index = i-1;  //找到最大值对应索引
    }
    for (int i = 0; i < (ARR_SIZE-1); i++) {
        printf("%llu ", a[i]);
    }
    printf("\n");
    printf("最大值为：\n%llu",a[max_index]);
    // system("pause");
    return 0;
}