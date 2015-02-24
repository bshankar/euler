f, f0 = 1, 1
n  = 2
N = 1000

while len(str(f)) < N:
    f, f0 = f+f0, f
    n += 1
    
print n