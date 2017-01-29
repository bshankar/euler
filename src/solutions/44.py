def P(n):
    return n*(3*n - 1)/2

N = 20000000
pArray = [False]*N

n = 0
Pn = P(n)
while Pn < N:
    pArray[Pn] = True
    n += 1
    Pn = P(n)

min_ = N*10000
for i in range(1, N):
    if pArray[i] == False:
        continue
    for j in range(i+1, N):
        if pArray[j] == False:
            continue

        if i+j >= N:
            break    
        
        if pArray[i+j] and pArray[j-i] and j - i < min_:
            print i, j
