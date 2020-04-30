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
