with open('81.txt', 'r') as f:
    lines = f.readlines()

A = []
for line in lines:
    row = [int(i) for i in line.split(',')]
    A.append(row)

Alen = len(A)

for i in range(Alen):
    for j in range(Alen):
        if i == 0 and j == 0:
            continue
        elif i == 0:
            A[i][j] += A[i][j-1]
        elif j == 0:
            A[i][j] += A[i-1][j]
        else:
            A[i][j] += min(A[i-1][j], A[i][j-1])
            
print A[-1][-1]
