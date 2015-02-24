ans = set()

for i in range(1, 50):
    for j in range(i, 2000):
        ixj = i*j
        ijixj = str(i)+str(j)+str(ixj)
        if len(ijixj) > 9:
            break
        if len(set(ijixj)) == len(ijixj) == 9 and '0' not in ijixj:
            print i, 'x', j, '=', ixj
            ans.add(ixj)

print "Answer is", sum(ixj for ixj in ans)
