max_ = 0

for a in range(100):
    for b in range(100):
        sum_ = sum(int(i) for i in str(a**b))
        if (sum_ > max_):
            max_ = sum_
            print a, b, sum_
            
