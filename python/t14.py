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
