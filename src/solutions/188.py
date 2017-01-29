def hyperpower(n, k):
    n_ = n
    for i in range(k-1):
        n_ = n**n_ % 100
        
    return n_
    
print hyperpower(1777, 1855)
