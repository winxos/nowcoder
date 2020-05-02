def chk(n):
    low = 0
    fast = 0
    while True:
        if fast >= len(n):
            print("no")
            break
        low = n[low]
        fast = n[fast]
        if fast >= len(n):
            print("no")
            break
        fast = n[fast]
        if low == fast:
            print(low)
            print("loop")
            ct = 0
            while True:
                low = n[low]
                fast = n[n[fast]]
                ct += 1
                if low == fast:
                    break
            print(ct)
            break


while True:
    try:
        s = input().split()
        s = [int(i) for i in s]
        print(chk(s))
    except Exception:
        break
