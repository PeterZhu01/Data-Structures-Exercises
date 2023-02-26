#include <stdio.h>
#include <stdlib.h>

int main() {
    int X, Y, Z;

  
    printf("输入三个整数,数与数之间用空格隔开\n");
    scanf("%d%d%d", &X, &Y, &Z);   // 读入三个整数

    // 按照从大到小的顺序输出三个整数的值
    if (X >= Y && Y >= Z) {
        printf("%d %d %d\n", X, Y, Z);
    } else if (X >= Z && Z >= Y) {
        printf("%d %d %d\n", X, Z, Y);
    } else if (Y >= X && X >= Z) {
        printf("%d %d %d\n", Y, X, Z);
    } else if (Y >= Z && Z >= X) {
        printf("%d %d %d\n", Y, Z, X);
    } else if (Z >= X && X >= Y) {
        printf("%d %d %d\n", Z, X, Y);
    } else {
        printf("%d %d %d\n", Z, Y, X);
    }

    system("pause");
    return 0;
}
