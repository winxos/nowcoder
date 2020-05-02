while True:
    try:
        s = input().split()
        print([i[::-1] for i in s])
    except Exception:
        break