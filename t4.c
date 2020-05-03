//
// Created by zx on 2020/4/29.
// 文本逐词反转
#include <string.h>
#include <stdio.h>
#include "strlib.h"
void t4()
{
    char buf[100];
    gets(buf);
    char *b[10];
    int num = 0;
    split(buf," ",b,&num);
    for(int i=num-1;i>=0;i--)
    {
        printf("%s ",b[i]);
    }
}
