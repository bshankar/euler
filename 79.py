import copy

with open('79.txt', 'r') as file:
    lines = [i.rstrip() for i in file.readlines()]

lines = set(lines) # remove duplicates

# build a graph
graph = [set(), set(), set(), set(), set(), \
         set(), set(), set(), set(), set()]

for code in lines:
    graph[int(code[0])].add(int(code[1]))
    graph[int(code[0])].add(int(code[2]))
    graph[int(code[1])].add(int(code[2]))
    
graph_len = [len(i) for i in graph]
graph_len_ = sorted(graph_len)

ans = ''
for len_ in range(7, 0, -1):
    for j in range(len(graph_len)):
        if graph_len[j] == len_:
            ans += str(j)

ans += '0'
print ans
            

