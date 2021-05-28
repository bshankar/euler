with open('42.txt', 'r') as file:
    lines = file.readlines()

words = lines[0].rstrip().split('","')
words[0] = words[0].replace('"', '')
words[-1] = words[-1].replace('"', '')

def value(word):
    value = 0
    for letter in word:    
        value += ord(letter) - ord('A') + 1
    return value

max_ = 26*20  # assume as largest word value
is_tri = [False]*max_

k = 1
tn = 0
while tn < max_:
    is_tri[tn] = True
    tn += k
    k += 1

ans = 0
for word in words:
    if is_tri[value(word)]:
        ans += 1

print ans
