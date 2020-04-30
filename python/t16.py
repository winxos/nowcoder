while True:
    try:
        s = input()
        i = 0
        ans = ""
        while i < len(s):
            j = i + 1
            while j < len(s) and s[j] == s[i]:
                j += 1
            if j == i + 1:
                ans += s[i]
            else:
                ans += str(j - i) + s[i]
            i = j
        print(ans)
    except Exception:
        break
