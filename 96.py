with open('96.txt', 'r+') as file:
    lines = file.readlines()

puzzles = []
puzzle = ''
for line in lines:
    if len(line) < 9:
        continue
    puzzle += line.rstrip()
    if len(puzzle) == 81:
        puzzles.append(puzzle)
        puzzle = ''

sum_ = 0

def same_row(i,j): return (i/9 == j/9)
def same_col(i,j): return (i-j) % 9 == 0
def same_block(i,j): return (i/27 == j/27 and i%9/3 == j%9/3)

def r(a):
    i = a.find('0')
    if i == -1:
        global sum_
        sum_ += int(a[:3])
        return

    excluded_numbers = set()
    for j in range(81):
        if same_row(i,j) or same_col(i,j) or same_block(i,j):
            excluded_numbers.add(a[j])

    for m in '123456789':
        if m not in excluded_numbers:
            r(a[:i]+m+a[i+1:])


for p in puzzles:
    r(p)

print sum_
