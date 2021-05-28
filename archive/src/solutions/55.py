ans = 0
for i in xrange(10000):
    ly = True
    i_ = i
    for j in xrange(50):
        i = i + int(str(i)[::-1])
        if i == int(str(i)[::-1]):
            ly = False
    i = i_
    if ly: ans += 1
print ans
