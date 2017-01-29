import pt
import numpy as np

N = 1500
a = dict()

for triple in pt.gen_all_pyth_trips(N):
    sum_ = np.sum(triple[0])
    if sum_ > N:
        continue
    if sum_ in a:
        a[sum_] += 1
    else:
        a[sum_] = 1

print a[120]
