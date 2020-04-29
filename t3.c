//
// Created by zx on 2020/4/29.
// 简单四则运算
#include <stdio.h>
int cal(int c1, char op, int c2)
{
    switch(op)
    {
        case '+':
            return c1+c2;
            break;
        case '-':
            return c1-c2;
            break;
        case '*':
            return c1*c2;
            break;
        case '/':
            return c1/c2;
            break;
        default: ;
    }
    return 0;
}

int calculate(int len, char *expStr)
{
    if (len < 3) return -1;
    char *p = expStr;
    int c1 = p[0]-'0';
    char op = p[1];
    int c2 = p[2]-'0';
    p += 3;
    while(*p) {
        if (*p=='*' || *p=='/') {
            c2 = cal(c2, *p, p[1]-'0');
        } else {
            c1 = cal(c1, op, c2);
            op = *p;
            c2 = p[1]-'0';
        }
        p += 2;
    }
    return cal(c1, op, c2);
}
void t3()
{
    printf("%d",calculate(9,"1+4*5-8/3"));
}