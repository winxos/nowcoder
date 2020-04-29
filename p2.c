//
// Created by winxo on 2020/4/29.
//
#include <stdio.h>
void p2()
{
    char buf[5000];
    gets(buf);
    char ch=getchar();
    char *p=buf;
    int len=0;
    while(*p)
    {
        if(*p==ch || *p==(ch+32) || *p==(ch-32))
        {
            len++;
        }
        p++;
    }
    printf("%d",len);
}
