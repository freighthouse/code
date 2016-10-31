for i in range(1,101):
    s = ''
    if not i % 3:
        s += 'fizz'
    if not i % 5:
        s += 'buzz'
    if not s:
        s = i
    print(s)
