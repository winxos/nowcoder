//
// Created by winxo on 2020/5/3.
//
#include "strlib.h"
#include <stdio.h>
void t8()
{
  char buf[100];
  gets(buf);
  char *b[10];
  int num = 0;
  split(buf," ",b,&num);
  for(int i=0;i<num;i++)
  {
    str_rev(b[i]);
    printf("%s\n",b[i]);
  }
}
