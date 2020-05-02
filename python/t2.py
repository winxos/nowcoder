while True:
    try:
        l = int(input())
        for i in range(l):
            d = int(input())
            if d > 4 or d < -9:
                print("Out of data Space!")
            else:
                print("%d %d %d\n%d %d %d" % (d + 5, d + 3, d + 1, d + 4, d + 2, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 1, d + 3, d + 2, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 3, d + 2, d + 4, d + 1, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 2, d + 3, d + 1, d))
                print("%d %d %d\n%d %d %d" % (d + 5, d + 4, d + 3, d + 2, d + 1, d))

    except Exception as e:
        print(e)
