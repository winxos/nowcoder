# 华为机试题资料

wvv20200430

题目为网上收集

代码为自己python实现，未进行多案例测试

### 题目1 数据分类

 https://www.nowcoder.com/questionTerminal/9a763ed59c7243bd8ab706b2da52b7fd 

题目描述
信息社会，有海量的数据需要分析处理，比如公安局分析身份证号码、 QQ 用户、手机号码、银行帐号等信息及活动记录。  

采集输入大数据和分类规则，通过大数据分类处理程序，将大数据分类输出。

输入描述:
﻿一组输入整数序列I和一组规则整数序列R，I和R序列的第一个整数为序列的个数（个数不包含第一个整数）；整数范围为0~0xFFFFFFFF，序列个数不限

输出描述:
﻿从R依次中取出R<i>，对I进行处理，找到满足条件的I<j>： I<j>整数对应的数字需要连续包含R<i>对应的数字。比如R<i>为23，I<j>为231，那么I<j>包含了R<i>，条件满足 。 

按R<i>从小到大的顺序:

(1)先输出R<i>； 

(2)再输出满足条件的I<j>的个数； 

(3)然后输出满足条件的I<j>在I序列中的位置索引(从0开始)； 

(4)最后再输出I<j>。 

附加条件： 

(1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I<j>，索引大的需要过滤掉 

(2)如果没有满足条件的I<j>，对应的R<i>不用输出 

(3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(不包含“个数”本身)

 

序列I：15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123（第一个15表明后续有15个整数） 

序列R：5,6,3,6,3,0（第一个5表明后续有5个整数） 

输出：30, 3,6,0,123,3,453,7,3,9,453456,13,453,14,123,6,7,1,456,2,786,4,46,8,665,9,453456,11,456,12,786

说明：

30----后续有30个整数

3----从小到大排序，第一个R<i>为0，但没有满足条件的I<j>，不输出0，而下一个R<i>是3

6--- 存在6个包含3的I<j> 

0--- 123所在的原序号为0 

123--- 123包含3，满足条件

输入：

15 123 456 786 453 46 7 5 3 665 453456 745 456 786 453 123
5 6 3 6 3 0

输出：

30 3 6 0 123 3 453 7 3 9 453456 13 453 14 123 6 7 1 456 2 786 4 46 8 665 9 453456 11 456 12 786

```c
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
```



```python
while True:
    try:
        si = [int(i) for i in input().split()[1:]]
        sr = [int(i) for i in input().split()[1:]]
        sr1 = list(set(sr))
        sr1.sort()
        ans = []
        for i, d1 in enumerate(sr1):
            t = []
            for j, d2 in enumerate(si):
                if str(d1) in str(d2):
                    t.append(j)
                    t.append(d2)
            if len(t) > 0:
                ans.append(d1)
                ans.append(len(t) // 2)
                for d in t:
                    ans.append(d)
        ans.insert(0, len(ans))
        print(' '.join([str(i) for i in ans]))
    except Exception:
        break
```



### 题目2 数字排列

C:数字排列
(输入文件: C.in 输出文件: estdout. pc2)
小明最近对数字的排列产生了强烈的兴趣，他想将任意6个连续一位整数按照每行3个
的方式排列成两行，使得这些数据满足条件: 6个数字各不相同，并且上面的数据比下面的
大、左边的数据比右边的大。请你设计程字帮助小明解决这个数字排列问题，求出数字排列
的具体排列方式。

输入数据:
第一行输入一个整数n表示测试案例的个数。此后的每行输入一个数据表示本测试案例
6个连续一位整数的起始数据，当输入的起始数据不能保证连续的6个数据都是1位数时，
显示出Out of data Space!的提示信息。

输出数据:
对应每个测试的起始数据，输出以其为首的连续六个数据的排列方式 和排列种数

样例输入:
2
7
-3

数样例输出:
Out of data space!
2 0 -2
1 -1 -3
2 1 -2
0 -1 -3
2 0 -1
1 -2 -3
2 1 -1
0 -2 -3
2 1 0
-1 -2 -3

```python
while True:
    try:
        l = int(input())
        for i in range(l):
            d = int(input())
            if d > 4 or d < -9:
                print("Out of data Space!")
            else:
                print("%d %d %d\n%d %d %d" % (d + 5, d + 3, d + 1, d + 4, d + 2, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 1, d + 3, d + 2, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 3, d + 2, d + 4, d + 1, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 2, d + 3, d + 1, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 3, d + 2, d + 1, d))

    except Exception as e:
        print(e)

```

此题输出情况是固定的，很坑。

### 题目3 简单四则运算

题目：简单四则运算
问题描述： 输入一个只包含个位数字的简单四则运算表达式字符串，计算该表达式的值
注：
1、表达式只含 +, -, 乘, / 四则运算符，不含括号
2、表达式数值只包含个位整数(0-9)，且不会出现0作为除数的情况
3、要考虑加减乘除按通常四则运算规定的计算优先级
4、除法用整数除法，即仅保留除法运算结果的整数部分。比如8/3=2。输入表达式保证无0作为除数情况发生
5、输入字符串一定是符合题意合法的表达式，其中只包括数字字符和四则运算符字符，除此之外不含其它任何字符，不会出现计算溢出情况
要求实现函数：
int calculate(int len,char expStr)
【输入】 int len: 字符串长度；
char expStr: 表达式字符串；
【输出】 无
【返回】 计算结果

示例
1） 输入：char expStr = “1+45-8/3”
函数返回：19
2） 输入：char expStr = “8/33”
函数返回：6

题目分析：
①这道题输入字符串中有可能有五种字符，数字、+、-、*、/。
②这道题还需要注意的是我们要按照运算法则来进行计算，所以我们要选择用栈来解决这道题
算法思路：
①用字符串数组当做符号+-/的栈；用int数组作为数字的栈
②入栈过程：
数字栈：检测如果为数字，我们直接-‘0’放入number中；
符号栈：
1）+ - :因为它们运算优先级比较低，所以我们需要入栈出栈
检测为+-时候，我们直接放入sign中
2）* / :因为运算优先级别比较高，所以哦我们可以直接运算
这里需要注意索引，这个时候数字索引应该-1,但是字符串的索引应该加1,之后还需要+1（因为已经运算完了）
/需要多注意一个地方，就是分母不能为0，为0时候，直接返回-1;
③出栈过程
1）首先第一步我们需要把两个栈的索引都减去1
2）之后用符号索引进行for循环，如果检测为加号，因为我们需要把数字都放入数字的前一个索引里面，数字索引需要减去1先，之后再运算
3）最后出栈结束返回number[0]就可以了

```python
def cc(op, t1, t2):
    if op == "*": return t1 * t2
    if op == "/": return t1 // t2
    if op == "+": return t1 + t2
    if op == "-": return t1 - t2


def calc(n):
    op = []
    num = []

    n = n.replace('+', ' + ')
    n = n.replace('-', ' - ')
    n = n.replace('*', ' * ')
    n = n.replace('/', ' / ')
    n = n.split()
    i = 0
    while i < len(n):
        if n[i].isdigit():
            num.append(int(n[i]))
        elif n[i] == '/' or n[i] == '*':
            t1 = num.pop()
            t2 = int(n[i + 1])
            r = cc(n[i], t1, t2)
            num.append(r)
            i += 1
        elif n[i] == '+' or n[i] == '-':
            op.append(n[i])
        i += 1
    while op:
        c = op.pop()
        t2 = num.pop()
        t1 = num.pop()
        num.append(cc(c, t1, t2))
    return num[0]


while True:
    try:
        s = input()
        print(calc(s))
    except Exception:
        break
```



### 题目4 文本逐词反转

 https://blog.csdn.net/qj15223080209/article/details/83037877 

 将字符串按单词反转输出，如输入：hello sir 输出：olleh ris 。 

```python
while True:
    try:
        s = input().split()
        print([i[::-1] for i in s])
    except Exception:
        break
```



```c
#include <string.h>
#include <stdio.h>
void split(char *src, const char *sep, char **dest, int *num)
{
    if (src == NULL || strlen(src) == 0 || sep == NULL || strlen(sep) == 0)
    {
        return;
    }
    char *pNext;
    int count = 0;
    pNext = strtok(src, sep);
    while(pNext != NULL)
    {
        *dest++ = pNext;
        ++count;
        pNext = strtok(NULL, sep);
    }
    *num = count;
}
void str_rev(char *s)
{
    if(s == NULL)
        return;
    char *start = s;
    char *end   = s + strlen(s) - 1;
    char t;
    while(start < end)
    {
        t = *start;
        *start = *end;
        *end = t;
        ++ start;
        -- end;
    }
}
void t4()
{
    char buf[100];
    char *a;
    gets(buf);
    char *b[10];
    int num = 0;
    split(buf," ",b,&num);
    for(int i=num-1;i>=0;i--)
    {
        printf("%s ",b[i]);
    }
}
```



### 题目5 检测链表中的循环

 https://blog.csdn.net/ccmlove123/article/details/104052556 

 https://blog.csdn.net/lqy971966/article/details/89818680 

```python
def chk(n):
    low = 0
    fast = 0
    while True:
        if fast >= len(n):
            print("no")
            break
        low = n[low]
        fast = n[fast]
        if fast >= len(n):
            print("no")
            break
        fast = n[fast]
        if low == fast:
            print(low)
            print("loop")
            ct = 0
            while True:
                low = n[low]
                fast = n[n[fast]]
                ct += 1
                if low == fast:
                    break
            print(ct)
            break


while True:
    try:
        s = input().split()
        s = [int(i) for i in s]
        print(chk(s))
    except Exception:
        break
```



### 题目6 打印任务排序

 https://blog.csdn.net/Aoulun/article/details/79960147 

一台打印机有若干个任务，但是打印机每次只能打印一个任务，每个任务是有优先级的，从1到9。打印的时候从序列的第一个开始，如果第一个的优先级不是最大的，则将其出队，并加入队尾。若其优先级是最大的，则直接打印该任务。设计算法实现如下功能：
输入：
（1）第一行：输入测试案例的个数，第二行：第一个数字是打印任务个数，第二个数据是目标任务在当前任务序列的位置
输出：

（2）目前任务打印完成需要的时间（假设打印一个任务需要1个单位时间，转移、判断任务不需要时间）
（3）所有任务的打印顺序

例如：

1（只有一个测试用例）

2 1（一共两个任务，目标任务的位置是1--任务是从0开始的）
2 3（序列）

输出：
2 1 0
 https://blog.csdn.net/fzuim/article/details/75647542 

某个打印机根据打印队列执行打印任务。打印任务分为九个优先级，分别采用数字1~9表示，数字越大优先级越高。打印机每次从队列头部取出第一个任务A，然后检查队列余下任务中有没有比A优先级更高的任务，如果有比A优先级高的任务，则将任务A放到队列尾部，否则执行任务A的打印。请编写一个程序，根据输入的打印队列，输出实际打印顺序。
函数原型：
void printOrder(const int input[], int len, int output[])
参数input表示打印队列，为1~9（优先级）组成的数组，数组索引0代表头部。对于C/C++参数len代表input数组长度，假定参数合法有效；

```python
def prt(n):
    li = list(n)
    ans = []
    while len(li) > 1:
        if li[0] < max(li[1:]):
            li.append(li[0])
            li = li[1:]
        else:
            ans.append(li[0])
            li = li[1:]
    ans.append(li[0])
    return ans


while True:
    try:
        s = input().split()
        print(prt(s))
    except Exception:
        break
```



### 题目7 jam计数法

 https://blog.csdn.net/heisetiantang/article/details/50793621 

题目描述
Jam是个喜欢标新立异的科学怪人。他不使用阿拉伯数字计数，而是使用小写英文字母计数，他觉得这样做，会使世界更加丰富多彩。在他的计数法中，每个数字的位数都是相同的（使用相同个数的字母），英文字母按原先的顺序，**排在前面的字母小于排在它后面的字母**。我们把这样的“数字”称为Jam数字。在Jam数字中，每个字母互不相同，而且从左到右是严格递增的。每次，Jam还指定使用字母的范围，例如，从2到10，表示只能使用{b,c,d,e,f,g,h,i,j}这些字母。如果再规定位数为5，那么，紧接在Jam数字“bdfij”之后的数字应该是“bdghi”。（如果我们用U、V依次表示Jam数字“bdfij”与“bdghi”，则U<V< span>，且不存在Jam数字P，使U<P<V< span>）。你的任务是：对于从文件读入的一个Jam数字，按顺序输出紧接在后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。



输入
输入文件counting.in 有2行，第1行为3个正整数，用一个空格隔开：

s t w

（其中s为所使用的最小的字母的序号，t为所使用的最大的字母的序号。w为数字的位数，这3个数满足：1≤s<T< span>≤26, 2≤w≤t-s ）

第2行为具有w个小写字母的字符串，为一个符合要求的Jam数字。

所给的数据都是正确的，不必验证。

输出
输出文件counting.out 最多为5行，为紧接在输入的Jam数字后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。每行只输出一个Jam数字，是由w个小写字母组成的字符串，不要有多余的空格。

样例输入
2 10 5
bdfij
样例输出
bdghi
bdghj
bdgij
bdhij
befgh

 https://www.cnblogs.com/SJum/p/7383662.html 

```python
def pp(s, e, w, ss):
    t = ss[-1] + 1
    if t >= e - (w - len(ss)):
        r = pp(s, e, w, ss[:-1])
        r.extend([i for i in range(r[-1] + 1, r[-1] + w - len(r) + 1)])
        return r
    ss[-1] += 1
    return list(ss)


while True:
    try:
        s = input().split()
        ss = [ord(i) - ord('a') for i in input()]
        for j in range(5):
            ss = pp(int(s[0]), int(s[1]), int(s[2]), ss)
            print([chr(ord('a') + i) for i in ss])
    except Exception as e:
        print(e)
```

仅仅通过案例测试

### 题目8 单词排序输出

 https://blog.csdn.net/karute/article/details/79459805 

题目描述
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子
输出描述:
输出句子的逆序

```python
while True:
    try:
        s = input().split()
        s.reverse()
        print(' '.join(s))
    except Exception:
        break
```



### 题目9 ***德州扑克

 https://blog.csdn.net/wojiushi3344/article/details/8967735 

 https://blog.csdn.net/biubiuibiu/article/details/80410346 

 https://blog.csdn.net/a375849201893857/article/details/46492363 

 项目简介：依据德州扑克规则，使用C++编写牌手程序，参加扑克比赛。
程序语言:C++ 通讯方式:TCP socket通讯
开发工具:g++ 开发环境:Linux操作系统Ubuntu 

2015年华为精英编程赛题目，几乎不可能用在招聘机试环节



### 题目10 电报内容为空字符串

 https://blog.csdn.net/u010724874/article/details/82354495 

假设电报中用点（.）表示1，用中划线（-）表示0，点与中划线的序列，能够翻译成一个二进制数（可以看做无符号数）。将此二进制转换为整数后，通过一个映射表，可以将整数映射成一个英文字母。多个点、中划线序列间，用#隔开（多个连续的#号，算作一个#号），表示多个英文字母。
当电报中没有点、中划线，只有#时，电报内容为空字符串。
每个点、中划线序列，可以看做是无符号数。如果有点、中划线序列的二进制值超出如下映射表的范围，则输出”ERROR”。
映射表：

请将输入的点、中划线序列集合，转换为英文字母集合。
输入描述:
由点（.）、中划线（-）、#集合构成的原始报文。输出描述:
经过转换后生成的英文字符序列（英文区分大小写）

二进制值超出如下映射表的范围，则输出”ERROR”
示例1
输入
复制
--.#.#-.-
输出
复制
GGR

```python
def code_to_int(ss:str):
    n=0
    for i in ss:
        if i=='.':
            n=n*2+1
        if i=='-':
            n=n*2
    return n
while True:
    try:
        s = input().split('#')
        for i in s:
            if len(i)>0:
                print(code_to_int(i))
    except Exception:
        break
```



### 题目11 华为机试 仿LISP字符串运算

 [https://blog.csdn.net/liuxinyang666/article/details/79048639?utm_source=copy%C2%A0](https://blog.csdn.net/liuxinyang666/article/details/79048639?utm_source=copy ) 

 题目描述
LISP语言唯一的语法就是括号要配对。
形如 (OP P1 P2 …)，括号内元素由单个空格分割。
其中第一个元素OP为操作符，后续元素均为其参数，参数个数取决于操作符类型
注意：参数 P1, P2 也有可能是另外一个嵌套的 (OP P1 P2 …)
当前OP类型为add/sub/mul/div(全小写)，分别代表整数的加减乘除法。简单起见，所以OP参数个数为2
举例
-输入：(mul 3 -7)输出：-21
输入：(add 1 2) 输出：3
输入：(sub (mul 2 4) (div 9 3)) 输出 ：5
输入：(div 1 0) 输出：error
常规方法是用两个栈分别存放操作数和操作符，本文用一个栈来实现，首先从后往前提取操作数和操作符存放在vector，然后判断。

```python
def lisp(p):
    st = []
    add = lambda x, y: x + y
    sub = lambda x, y: x - y
    mul = lambda x, y: x * y
    div = lambda x, y: x // y
    for i in p:
        if i == ')':
            t2 = st.pop()
            t1 = st.pop()
            op = st.pop()
            st.pop()
            try:
                ans = eval(op)(int(t1), int(t2))
                st.append(ans)
            except ZeroDivisionError:
                return "error"
        else:
            st.append(i)
    return st.pop()


while True:
    try:
        s = input()
        s = s.replace('(', '( ')
        s = s.replace(')', ' )')
        print(lisp(s.split()))
    except Exception:
        break
```

### 题目12 华为集五福机试题

 https://blog.csdn.net/yy417168602/article/details/104999354 

集五福作为近年来大家喜闻乐见迎新春活动，集合爱国福、富强福、和谐福、友善福、敬业福即可分享超大红包

以0和1组成的长度为5的字符串代表每个人所得到的福卡，每一位代表一种福卡，1表示已经获得该福卡，单类型福卡不超过1张，随机抽取一个小于10人团队，求该团队最多可以集齐多少套五福？

输入描述:
输入若干个"11010"、”00110"的由0、1组成的长度等于5位字符串,代表的指定团队中每个人福卡获得情况
注意1：1人也可以是一个团队
注意2：1人可以有0到5张福卡，但福卡不能重复

输出描述:
输出该团队能凑齐多少套五福

示例1
输入
11001，11101
输出
0

示例2
输入
11101，10111
输出
1

```python
def cc(n):
    buf = [0 for i in range(5)]
    for s in n:
        for j, d in enumerate(s.strip()):
            if d == "1":
                buf[j] += 1
    return min(buf)


while True:
    try:
        s = input()
        s = s.split(',')
        print(cc(s))
    except Exception:
        break
```



### 题目13 python3 算法题：七进制加法

 https://blog.csdn.net/hzfq1443754157/article/details/82564104 

**题目描述：**

输入一个由空格隔开的两个七进制整数组成的字符串，七进制数只包含字符[0~6]，输入的数长度不超过11位，计算两个七进制数的和，并输出结果，输出结果也是七进制数（题目为大概描述，所有条件已经覆盖，表述可能略有差异）

**样例输入**

15 12

**样例输出**

30

```python
def to_dec(n):
    ans = 0
    for i in n:
        ans = ans * 7 + int(i)
    return ans


def to_7(n):
    s = ""
    while n:
        s +=str( n % 7)
        n //= 7
    return s[::-1]


while True:
    try:
        s = input()
        s = s.split()
        print(to_7(to_dec(s[0]) + to_dec(s[1])))
    except Exception:
        break
```



### 题目14 *** 清一色胡牌问题

 https://blog.csdn.net/sps900608/article/details/87278911 

题目描述：
清一色是麻将番种之一，指由一种花色的序数牌组成的和牌.
数字1-9，每个数字最多有4张牌
我们不考虑具体花色，我们只看数字组合。
刻子：三张一样的牌；如: 111, 222, 333, …, 999
顺子：三张连续的牌；如: 123, 234, 345, …, 789
对子：两张相同的牌；如: 11, 22, 33, …, 99
需要实现一个程序，判断给定牌，是否可以和牌（胡牌）。
和牌要求：

麻将牌张数只能是 2, 5, 8, 11, 14
给定牌可以组合成，除1个对子以外其他都是刻子或顺子
举例： - “11” -> “11”, 1对子，可以和牌
“11122233” -> “111”+“222”+“33”, 2刻子，1对子，可以
“11223344567” -> “11”+“234”+“234”+“567”, 1对子，3顺子，可以
-> “123”+“123”+“44”+“567”, 另一种组合，也可以
输入描述:
合法C字符串，只包含’1’-‘9’，且已经按从小到大顺序排好；字符串长度不超过15。同一个数字最多出现4次，与实际相符。
输出描述:
C字符串，“yes"或者"no”
示例1
输入
2244
输出
no

```python
def majong(n: list):
    ans = []
    for i, c in enumerate(n[:-2]):
        if n[i] == n[i + 2]:
            t = n[:i] + n[i + 3:]
            ans += majong(t)
    for i, c in enumerate(n[:-2]):
        if (chr(ord(c) + 1) in n) and (chr(ord(c) + 2) in n):
            t = list(n)
            t.remove(c)
            t.remove(chr(ord(c) + 1))
            t.remove(chr(ord(c) + 2))
            ans += majong(t)
    if len(n) > 2:
        ans.append(False)
    elif n[0] == n[1]:
        ans.append(True)
    return ans


while True:
    try:
        s = input()
        print(True in majong(list(s)))
    except Exception as e:
        print(e)

```

代码未多案例测试

### 题目15 华为机试题目：删除重复字符串
题目标题：

删除重复字符
给定一个字符串，将字符串中所有和前面重复多余的字符删除，其余字符保留，输出处理后的字符串。需要保证字符出现的先后顺序，并且区分大小写。
详细描述：

接口说明
原型：
int GetResult(const char *input, char *output)
输入参数：
     input     输入的字符串
输出参数（需考虑指针指向的内存区域是否有效）：
    output    输出的字符串
返回值：
        0         成功
         -1        失败及异常
举例：
输入: abadcbad，那么该单词中红色部分的字符在前面已经出现过。
则：输出abdc，返回0。

```python
while True:
    try:
        s = input()
        i = 0
        ans = ""
        while i < len(s):
            j = i + 1
            while j < len(s) and s[j] == s[i]:
                j += 1
            if j == i + 1:
                ans += s[i]
            else:
                ans += str(j - i) + s[i]
            i = j
        print(ans)
    except Exception:
        break
```



### 题目16 字符串压缩 华为

通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串压缩程序，将字符串中连续出席的重复字母进行压缩，并输出压缩后的字符串。
压缩规则：
    1、仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，压缩后的字符串还是"abcbc"。
    2、压缩字段的格式为"字符重复的次数+字符"。例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"。
要求实现函数： 
     void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
    输入pInputStr：  输入字符串lInputLen：  输入字符串长度
    输出 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
注意：只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例 
    输入：“cccddecc”   输出：“3c2de2c”
    输入：“adef”     输出：“adef”
    输入：“pppppppp” 输出：“8p”

```python
while True:
    try:
        s = input()
        i = 0
        ans = ""
        while i < len(s):
            j = i + 1
            while j < len(s) and s[j] == s[i]:
                j += 1
            if j == i + 1:
                ans += s[i]
            else:
                ans += str(j - i) + s[i]
            i = j
        print(ans)
    except Exception:
        break
```



### 题目17 第一个只出现一次的字符

 https://blog.csdn.net/u013132035/article/details/81474654 

**题目：**

在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。

```python
while True:
    try:
        s = input()
        buf = [0 for i in range(26)]
        for i in s:
            buf[ord(i) - ord('a')] += 1
        for i, d in enumerate(buf):
            if d == 1:
                print(chr(buf[i]+ord('a')))
                break
    except Exception as e:
        print(e)
        break
```



### 题目18 寻找字符串中出现次数最多的字符

 https://www.jianshu.com/p/a45dbcb3f71d 

 题目：找出字符串中出现次数最多的字符和次数。
例如：“abbcdaaca”中出现次数最多的字符就是a，出现次数是4 

```python
while True:
    try:
        s = input()
        buf = [0 for i in range(26)]
        for i in s:
            buf[ord(i) - ord('a')] += 1
        m=0
        id=0
        for i, d in enumerate(buf):
            if d>m:
                m=d
                id=i
        print(chr(id+ord('a')))
    except Exception as e:
        print(e)
        break
```



### 题目19 掷骰子游戏

 https://www.cnblogs.com/bhlsheji/p/5272387.html 

在掷骰子游戏中。会依据所掷数字在地图中前进几步。前进完毕后须要依据当前地图位置所看到的的障碍进行对应操作，当中障碍表示：
1）9：无障碍
2）1：停掷一轮，即下轮所掷数字无效。
3）2：后退两步，假设已经到起点不再后退。
4）3：奖励前进一步

假设在游戏过程中，已经走到地图终点，则游戏结束。依据输入的地图数组，和5个骰子数的数组，返回终于玩家前进了多少步。

演示样例
1）输入：map_len = 15, map = {9,1,9,9,9,2,9,9,9,9,9,9,9,9,9}。dice_val = {1,2,1,3,1}，
返回：4
2）输入：map_len = 16, map = {9,9,9,9,9,1,9,3,9,9,2,9,9,9,9,9}，dice_val = {2,1,4,1,6}，
返回：15

```python
while True:
    try:
        m = input().split(',')
        d = input().split(',')
        loc = 0
        id = 0
        while id < len(d):
            loc = loc + int(d[id])
            if m[loc] == '1':
                id += 1
            elif m[loc] == '2':
                loc -= 2
                if loc < 0:
                    loc = 0
            elif m[loc] == '3':
                loc += 1
            if loc >= len(m):
                break
            id += 1
        print(loc)
    except Exception as e:
        print(e)
        break
```

### 题目20 字符串全排列

 https://blog.csdn.net/weixin_39087263/article/details/82861384 

题目：实现字符串的全排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

 https://www.jb51.cc/c/499686.html 

```python
def perm(n: list):
    if len(n) == 1:
        return n[0]
    ans = []
    for i in n:
        rest = list(n)
        rest.remove(i)
        for j in perm(rest):
            t = [i]
            t.extend(j)
            ans.append(t)
    return ans


while True:
    try:
        s = input()
        ans = perm(list(s))
        for i in ans:
            print("".join(i), end=' ')
    except Exception as e:
        print(e)

```

全排列法

