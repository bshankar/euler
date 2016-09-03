
primes = [7, 11, 13, 17, 19, 23, 29, 31, 37, 39,  \
     41, 43, 47, 51, 53, 57, 59, 61, 67, 71, \
     73, 79, 83, 89, 97]

ans = 0

for p in primes:
    t, r, n = 0, 1, 0
    started = False
    while (r != 1 or not started) and t < p:
        t += 1
        x = 10*r
        d = x/p
        r = x % p
        n = 10*n + d
        started = True
        
    if t == p - 1:
        nr = [n,]
        for k in range(len(str(n))-1):
            n = int(str(n)[-1] + str(n)[:-1])
            nr.append(n)
        
        for i in range(len(nr)-1):
            if nr[i+1] % nr[i] == 0:
                ans += nr[i]
        
        
print ans
