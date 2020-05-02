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
