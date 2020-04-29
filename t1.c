//
// Created by winxo on 2020/4/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int is_include(int *buf,int size,int n)
{
    for(int i=0;i<size;i++)
    {
        if(n==buf[i])
        {
            return 1;
        }
    }
    return 0;
}
int array_to_set(int *buf,int size,int *buf2,int *n)
{
    int len=0;
    for(int i=0;i<size;i++)
    {
        if(is_include(buf2,len,buf[i])==0)
        {
            buf2[len]=buf[i];
            len++;
        }
    }
    *n=len;
}
int num_is_in_num(int n1,int n2)
{
    char buf1[12],buf2[12];
    sprintf(buf1,"%d",n1);
    sprintf(buf2,"%d",n2);
    return strstr(buf2,buf1)!=NULL;
}
void t1()
{
    int l1,l2,l3;
    int buf1[1000],buf2[1000],buf3[1000];
    while(~scanf("%d",&l1))
    {
        for(int i=0;i<l1;i++)
        {
            scanf("%d",&buf1[i]);
        }
        scanf("%d",&l2);
        for(int i=0;i<l2;i++)
        {
            scanf("%d",&buf2[i]);
        }
        array_to_set(buf2,l2,buf3,&l3);
        qsort(buf3,l3,sizeof(int),cmp);
        int ans[1000]={0};
        int ans_id=1;
        for(int i=0;i<l3;i++)
        {
            l2=0;
            for(int j=0;j<l1;j++)
            {
                if(num_is_in_num(buf3[i],buf1[j]))
                {
                    buf2[l2++]=j;
                    buf2[l2++]=buf1[j];
                }
            }
            if(l2>0)
            {
                ans[ans_id++]=buf3[i];
                ans[ans_id++]=l2/2;
                for(int j=0;j<l2;j++)
                {
                    ans[ans_id++]=buf2[j];
                }
            }
        }
        ans[0]=ans_id-1;
        for(int i=0;i<ans_id;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}
