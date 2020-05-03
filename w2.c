//
// Created by winxo on 2020/5/3.
//
#include <stdio.h>
#include <string.h>
void str_r(char *s)
{
  if(s==NULL)
  {
    return;
  }
  char *start=s;
  char *end=s+ strlen(s)-1;
  char t;
  while(start<end)
  {
    t=*start;
    *start=*end;
    *end=t;
    start++;
    end--;
  }
}
unsigned long to_dec(char *s)
{
  unsigned long ans=0;
  char *p=s;
  while(*p)
  {
    ans=ans*7+((*p)-'0');
    p++;
  }
  return ans;
}
void to_7(unsigned long num,char *out)
{
  char *p=out;
  while(num)
  {
    *p=num%7+'0';
    p++;
    num/=7;
  }
  str_r(out);
}
void w2()
{
  char buf1[12],buf2[12];
  while(~scanf("%s %s",buf1,buf2))
  {
    unsigned long t1=to_dec(buf1);
    unsigned long t2=to_dec(buf2);
    char buf[12];
    to_7(t1+t2,buf);
    printf("%s",buf);
  }
}