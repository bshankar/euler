from fractions import Fraction as fr
from math import log10, floor

ans = 0    
a = fr(1, 2)
for i in xrange(1000-1):
    a = fr(1, 2 + a)
    b = 1 + a
    if floor(log10(b.numerator)) > floor(log10(b.denominator)):
        ans += 1
        
print ans
    

