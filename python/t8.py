while True:
    try:
        s = input().split()
        s.reverse()
        print(' '.join(s))
    except Exception:
        break
