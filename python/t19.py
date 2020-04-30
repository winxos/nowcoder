while True:
    try:
        m = input().split(',')
        d = input().split(',')
        loc = 0
        id = 0
        while id < len(d):
            loc = loc + int(d[id])
            if m[loc] == '1':
                id += 1
            elif m[loc] == '2':
                loc -= 2
                if loc < 0:
                    loc = 0
            elif m[loc] == '3':
                loc += 1
            if loc >= len(m):
                break
            id += 1
        print(loc)
    except Exception as e:
        print(e)
        break
