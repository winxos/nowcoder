//
// Created by winxo on 2020/5/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void str_r(char *s);
int to26(const char *input,char *out)
{
  if(strlen(input)>6)
  {
    strcpy(out,"ERROR\n");
    return 0;
  }
  unsigned long ans=0;
  const char *p=input;
  while(*p)
  {
    if(*p>='a' && *p<='z')
    {
      ans=ans*26+((*p)-'a'+1);
      p++;
    } else{
      strcpy(out,"ERROR\n");
      return 0;
    }
  }
  sprintf(out,"%lld\n",ans);
  return 1;
}
void to26r(const char *input,char *out)
{
  int n=  atoi(input);
  char *p=out;
  while (n)
  {
    *p=(n-1)%26+'a';
    p++;
    n/=26;
  }
  str_r(out);
  *p='\n';
}
void w1()
{
  char buf[10];
  while(~scanf("%s",buf))
  {
    char out[12]={0};
    if(buf[0]<='9' && buf[0]>='0')
    {
      to26r(buf,out);
    } else{
      to26(buf,out);
    }

    printf("%s",out);
  }
}
