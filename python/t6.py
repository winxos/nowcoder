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
