//
// Created by winxo on 2020/4/29.
//
#include <stdio.h>
#include <string.h>
void show(char *s)
{
    int len=strlen(s);
    int i;
    for(i=0;i<len/8;i++)
    {
        for(int j=0;j<8;j++)
        {
            putchar(s[i*8+j]);
        }
        putchar('\n');
    }
    if(len==i*8)
    {
        return;
    }
    for(int j=0;j<len-i*8;j++)
    {
        putchar(s[i*8+j]);
    }
    for(int j=len;j<(i+1)*8;j++)
    {
        putchar('0');
    }
    putchar('\n');
}
void p4()
{
    char l1[100];
    char l2[100];
    gets(l1);
    gets(l2);
    show(l1);
    show(l2);
}