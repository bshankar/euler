from math import sqrt
N = 1000
solns = [0]*N

for x in range(1, N):
    for y in range(x, N):
        z = sqrt(x*x + y*y)
        if x + y + z >= 1000:
            break

        if int(z) == z:
            solns[x + y + int(z)] += 1

print solns.index(max(solns))
