scores = {chr(i):i - ord('A') + 1 for i in range(ord('A'), ord('Z')+1)}

with open('22.txt', 'r') as f:
    f_ = f.readlines()
s = 0
f_[0] = f_[0].replace('\n', '')
f_ = f_[0].split(" ")
f_ = list(f_)
f_.sort()
ind = 0 ## empty beginning
print(f_[938])
for name in f_:
    s += sum(scores[i] for i in name)*ind
    ind += 1
print(s)
