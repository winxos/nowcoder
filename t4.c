//
// Created by zx on 2020/4/29.
// 文本逐词反转
#include <string.h>
#include <stdio.h>
void split(char *src, const char *sep, char **dest, int *num)
{
    if (src == NULL || strlen(src) == 0 || sep == NULL || strlen(sep) == 0)
    {
        return;
    }
    char *pNext;
    int count = 0;
    pNext = strtok(src, sep);
    while(pNext != NULL)
    {
        *dest++ = pNext;
        ++count;
        pNext = strtok(NULL, sep);
    }
    *num = count;
}
void str_rev(char *s)
{
    if(s == NULL)
        return;
    char *start = s;
    char *end   = s + strlen(s) - 1;
    char t;
    while(start < end)
    {
        t = *start;
        *start = *end;
        *end = t;
        ++ start;
        -- end;
    }
}
void t4()
{
    char buf[100];
    char *a;
    gets(buf);
    char *b[10];
    int num = 0;
    split(buf," ",b,&num);
    for(int i=num-1;i>=0;i--)
    {
        printf("%s ",b[i]);
    }
}
