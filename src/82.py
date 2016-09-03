with open('81_test.txt', 'r') as f:
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
            A[i][j] += min(A[i][j-1], A[i+1][j])
        elif j == 0 and i != Alen - 1:
            A[i][j] += min(A[i-1][j], A[i+1][j])
        elif j == 0 and i == Alen - 1:
            A[i][j] = A[i-1][j]
        elif i == Alen - 1:
            A[i][j] += min(A[i-1][j], A[i][j-1])
        else:
            A[i][j] += min(min(A[i-1][j], A[i][j-1]), A[i+1][j])
            
#print min(A[i][Alen-1] for i in range(Alen))
print A
