def to_dec(n):
    ans = 0
    for i in n:
        ans = ans * 7 + int(i)
    return ans


def to_7(n):
    s = ""
    while n:
        s +=str( n % 7)
        n //= 7
    return s[::-1]


while True:
    try:
        s = input()
        s = s.split()
        print(to_7(to_dec(s[0]) + to_dec(s[1])))
    except Exception:
        break
