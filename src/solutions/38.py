max_ = 0

for n in range(1, 10000):
    nstr = ''
    mult = 1
    while len(nstr + str(mult*n)) < 10:
        nstr += str(mult*n)
        mult += 1
    
    if int(nstr) > int(max_) and len(set(str(nstr))) == 9 and \
        '0' not in nstr:
        max_ = nstr

print max_
