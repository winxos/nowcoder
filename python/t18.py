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