from itertools import permutations as prms

count = 0
for p in prms('0123456789'):
    if count == 999999:
        print ''.join(j for j in p)
        break
    count += 1    