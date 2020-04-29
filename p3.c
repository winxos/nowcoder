//
// Created by winxo on 2020/4/29.
//
#include <stdlib.h>
#include <stdio.h>
static int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

void p3()
{
    int n,t;
    int buf[1001]={0};
    while(~scanf("%d",&n))
    {
        int id=0;
        int hash[1001]={0};
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(hash[t]==0)
            {
                buf[id]=t;
                id++;
                hash[t]=1;
            }
        }
        qsort(buf,id,sizeof(int),cmp);
        for(int i=0;i<id;i++)
        {
            printf("%d\n",buf[i]);
        }
    }
}