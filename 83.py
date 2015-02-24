with open('81.txt', 'r') as f:
    lines = f.readlines()

A = []
for line in lines:
    row = [int(i) for i in line.split(',')]
    A.append(row)

Alen = len(A)
infty = 1000000
B = [[infty for i in range(Alen)] for j in range(Alen)]

s    = [0, 0]  # source vertex
next = [0, 0]
B[0][0] = 0

if A[0][1] > A[1][0]:
    next = [1, 0]
    B[1][0] = A[0][0] + A[1][0]
else:
    next = [0, 1]
    B[0][1] = A[0][0] + A[0][1]

def findNext(node):
    # find the minimum of these 4 elements
    # and update B
    m, n = node
    c = [(m-1, n), (m, n-1), (m+1, n), (m, n+1)]
    
    min_value = infty
    min_neighbour = 0
    
    for i, j in c:
        if i < 0 or i > Alen-1:
            continue
        if j < 0 or j > Alen-1:
            continue
        if A[i][j] < min_value:
            min_value = A[i][j]
            min_neighbour = (i, j)
    
    i_, j_ = min_neighbour
    B[i_][j_] = B[i][j] + min_value 
    return min_neighbour
        

while next != [Alen-1, Alen-1]:
    next = findNext(c)
