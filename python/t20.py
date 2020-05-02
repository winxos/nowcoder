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
