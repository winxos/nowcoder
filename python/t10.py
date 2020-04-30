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
