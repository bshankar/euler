import numpy as np

def f(n):    
    return 1 - n + n**2 - n**3 + n**4 - n**5 + \
            n**6 - n**7 + n**8 - n**9 + n**10
    

def g(n, p):
    value = 0
    for k in xrange(len(p)):
        value += p[-k-1]*n**k
    
    return value
    
X = range(1, 20)    
Y = map(f, X)

ans = 0

for i in range(1, 11):
    p = np.polyfit(X[:i], Y[:i], i-1)
    bop = [g(j, p) for j in X]
    for j in range(len(bop)):
        if abs(bop[j] - Y[j]) > 1e-3:
            ans += bop[j]
            break

print ans
