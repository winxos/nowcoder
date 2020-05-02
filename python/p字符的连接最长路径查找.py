while True:
    try:
        l = int(input())
        a = []
        for i in range(l):
            a.append(input())
        a = sorted(a)
        print('\n'.join(a))
    except Exception as e:
        print(e)
        break
