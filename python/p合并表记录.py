while True:
    try:
        s = int(input())
        d={}
        for i in range(s):
            t=input().split()
            if int(t[0]) not in d:
                d[int(t[0])]=int(t[1])
            else:
                d[int(t[0])]+=int(t[1])
        li=sorted(d.items(),key=lambda d:d[0])
        for j in li:
            print("%s %d"%(j[0],j[1]))
    except Exception as e:
        break