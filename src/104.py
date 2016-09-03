n = 1
n_ = 1
k = 1
s = set(range(1, 10))
while 1:
    n, n_ = n + n_, n
    k += 1
    nstr = str(n)
    if len(nstr) >= 18:
        set(nstr[:9]) and set(nstr[-9:])
