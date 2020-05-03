//
// Created by zx on 2020/4/29.
// 数字排列
#include <stdio.h>

void t2() {
    int l1;
    while (~scanf("%d", &l1)) {
        for (int i = 0; i < l1; i++) {
            int d;
            scanf("%d", &d);
            if (d > 4 || d < -9) {
                puts("Out of data space!");
            } else {
              printf("%d %d %d\n%d %d %d\n" , d + 5, d + 3, d + 1, d + 4, d + 2, d);
              printf("%d %d %d\n%d %d %d\n" , d + 5, d + 4, d + 1, d + 3, d + 2, d);
              printf("%d %d %d\n%d %d %d\n" , d + 5, d + 3, d + 2, d + 4, d + 1, d);
              printf("%d %d %d\n%d %d %d\n" , d + 5, d + 4, d + 2, d + 3, d + 1, d);
              printf("%d %d %d\n%d %d %d\n" , d + 5, d + 4, d + 3, d + 2, d + 1, d);
            }
        }
    }
}