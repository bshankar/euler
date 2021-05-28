from mpmath import mp
import math as m
mp.dps = 105
def sd(n):
    ss = str(mp.sqrt(n))
    ss = ss.replace('.', '')[:100]
    if len(ss) < 100:
        return 0
    return sum(int(i) for i in ss)


ans = 0
for n in range(101):
    ans += sd(n)

print ans
