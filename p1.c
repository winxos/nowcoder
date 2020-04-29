//
// Created by winxo on 2020/4/29.
//
#include <stdio.h>
void p1()
{
    char buf[5000];
    gets(buf);
    char *p=buf;
    char *end=0;
    while(*p)
    {
        if(*p==' ')
        {
            end=p;
        }
        p++;
    }
    int len=0;
    if(end==0)
    {
        len=p-buf;
    }
    else
    {
        len=p-end-1;
    }
    printf("%d",len);
}