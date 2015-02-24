# read grid into file
with open('11.txt', 'r') as file:
    lines = file.readlines()
grid = [[int (j) for j in i.split(' ')] for i in lines]

max_ = 0

for i in range(len(grid)):
    for j in range(len(grid)):
        products = [0, 0, 0, 0]

        if j+3 < len(grid):
            products[0] = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]
        
        if i+3 < len(grid):
            products[1] = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]

        if i+3 < len(grid) and j+3 < len(grid):
            products[2] = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]

        if i+3 < len(grid) and j-3 >= 0:
            products[3] = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]

        local_max = max(products)
        if max_ < local_max:
            max_ = local_max

print max_
