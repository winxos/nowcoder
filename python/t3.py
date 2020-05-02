def cc(op, t1, t2):
    if op == "*": return t1 * t2
    if op == "/": return t1 // t2
    if op == "+": return t1 + t2
    if op == "-": return t1 - t2


def calc(n):
    op = []
    num = []

    n = n.replace('+', ' + ')
    n = n.replace('-', ' - ')
    n = n.replace('*', ' * ')
    n = n.replace('/', ' / ')
    n = n.split()
    i = 0
    while i < len(n):
        if n[i].isdigit():
            num.append(int(n[i]))
        elif n[i] == '/' or n[i] == '*':
            t1 = num.pop()
            t2 = int(n[i + 1])
            r = cc(n[i], t1, t2)
            num.append(r)
            i += 1
        elif n[i] == '+' or n[i] == '-':
            op.append(n[i])
        i += 1
    while op:
        c = op.pop()
        t2 = num.pop()
        t1 = num.pop()
        num.append(cc(c, t1, t2))
    return num[0]


while True:
    try:
        s = input()
        print(calc(s))
    except Exception:
        break
