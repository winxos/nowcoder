while True:
    try:
        s = input()
        buf = ""
        for c in s:
            if c not in buf:
                buf += c
        print(buf)
    except Exception:
        break
