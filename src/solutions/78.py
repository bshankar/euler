import sys
sys.setrecursionlimit(10000)
P = dict()

def p(n, k, dict_=P):
    if n == 0:
        return 1
    if n < 0 or k <= 0:
        return 0
    if (n, k) in dict_:
        return dict_[n, k]
    
    dict_[n, k] = p(n-k, k) + p(n, k-1)    
    return dict_[n, k]


n = 100
while p(n, n) % 1000000:
    n += 1
    if n % 10 == 0:
        print "n = ", n

print n
