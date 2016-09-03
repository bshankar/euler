from fractions import Fraction as f

frs = set()
diff = 100

for i in range(1000000, 999997, -1):
    f27 = f(2, 7) 
    f37 = f(3, 7)
    for j in range(i):
        fji = f(j, i)
        if fji > f37:
            break
        diff_ = f37 - fji
        if diff > diff_ and diff_ != 0:
            diff = diff_
            print "New approximation: ", j, i
            
    if i % 2 == 0:
        print "Reached", i
