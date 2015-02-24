from fractions import Fraction as fr, gcd
ans = 0
n = 12001

#1/3 < p/q < 1/2
#q < 12001
#p > 1/3*12001  (min value of p)
#p < 1/2*12001 (max value of p) 

for num in xrange(1, n/3+2):
    if num % 100 == 0:
        print 'num =', num
    den = 2*num + 1
    while float(num)/den > fr(1, 3):
        if gcd(num, den) == 1:
            ans += 1
        den += 1
           
print ans
