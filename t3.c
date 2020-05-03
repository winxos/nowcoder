//
// Created by zx on 2020/4/29.
// 简单四则运算
#include <stdio.h>
#include <string.h>
int cal(char op, int c1,  int c2) {
  if (op == '+') {
    return c1 + c2;
  }
  if (op == '-') {
    return c1 - c2;
  }
  if (op == '*') {
    return c1 * c2;
  }
  if (op == '/') {
    return c1 / c2;
  }
  return 0;
}
#define is_digit(x) (x>='0' && x<='9')
#define N_MAX 100
struct stack{
  int buf[N_MAX];
  int pt;
};
struct stack data;
struct stack op;
void add(struct stack *s, int n)
{
  if(s->pt<N_MAX)
  {
    s->buf[s->pt]=n;
    s->pt++;
  }
}
int get(struct stack *s, int *n)
{
  if(s->pt>0)
  {
    s->pt--;
    *n = s->buf[s->pt];
    return 1;
  }
  return 0;
}
int calc(char *s) {
  if (strlen(s) < 3) return -1;
  char *p = s;
  int t1,t2;
  while (*p) {
    if(is_digit(*p)){
      add(&data,*p-'0');
    }
    else if(*p=='/' || *p=='*')
    {
      get(&data,&t1);
      t2=*(p+1)-'0';
      t1 = cal(*p,t1,t2);
      add(&data,t1);
      p++;
    }
    else if (*p == '+' || *p == '-') {
      add(&op,*p);
    }
    p++;
  }
  while (op.pt>0)
  {
    int c;
    get(&op,&c);
    get(&data,&t2);
    get(&data,&t1);
    add(&data,cal((char)c,t1,t2));
  }
  get(&data,&t1);
  return t1;
}
void t3() {
  char buf[100];
  while (~scanf("%s", buf)) {
    printf("%d\n", calc(buf));
  }
}