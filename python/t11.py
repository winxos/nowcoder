def lisp(p):
    st = []
    add = lambda x, y: x + y
    sub = lambda x, y: x - y
    mul = lambda x, y: x * y
    div = lambda x, y: x // y
    for i in p:
        if i == ')':
            t2 = st.pop()
            t1 = st.pop()
            op = st.pop()
            st.pop()
            try:
                ans = eval(op)(int(t1), int(t2))
                st.append(ans)
            except ZeroDivisionError:
                return "error"
        else:
            st.append(i)
    return st.pop()


while True:
    try:
        s = input()
        s = s.replace('(', '( ')
        s = s.replace(')', ' )')
        print(lisp(s.split()))
    except Exception:
        break
