add = lambda x, y: x + y
sub = lambda x, y: x - y
mul = lambda x, y: x * y
div = lambda x, y: x // y


def lisp(p):
    st = []
    ret = ""
    for i in s:
        if i == '(':
            st.append('(')
        elif i == ')':
            t2 = st.pop()
            t1 = st.pop()
            op = st.pop()
            st.pop()
            try:
                ans = eval(op)(int(t1), int(t2))
                st.append(ans)
            except ZeroDivisionError:
                ret = "error"
                break
        else:
            st.append(i)
    if ret == "":
        ret = st.pop()
    return ret


while True:
    try:
        s = input()
        s = s.replace('(', '( ')
        s = s.replace(')', ' )')
        s = s.split()
        print(lisp(s))
    except Exception:
        break
