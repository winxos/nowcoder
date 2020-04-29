//
// Created by zx on 2020/4/29.
//
#include <stdio.h>
void p6()
{
    int n;
    while(~scanf("%d",&n))
    {
        char buf[100];
        for(int i=2;n>1;)
        {
            if(n%i==0)
            {
                printf("%d ",i);
                n/=i;
            } else{
                i++;
            }
        }
    }
}