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
