from mpmath import mp
mp.dps = 7

with open('99.txt', 'r') as file:
    lines = file.readlines()

be = [i.rstrip().split(',') for i in lines]

max_ = 0
max_ans = 0

for index in range(len(be)):
    n, p = (int(i) for i in be[index])
    if p*mp.log(n) > max_:
        max_ans = index + 1
        max_ = p*mp.log(n)
        
print max_ans
        
