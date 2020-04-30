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
