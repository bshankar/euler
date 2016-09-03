import math as mth

def angle(p1, p2):
    dot = p1[0]*p2[0] + p1[1]*p2[1]
    norm = mth.sqrt(p1[0]**2 + p1[1]**2)*mth.sqrt(p2[0]**2 + p2[1]**2)
    return mth.acos(dot/norm)

def has_origin(coords, eps=1e-6):
    p1 = coords[0], coords[1]
    p2 = coords[2], coords[3]
    p3 = coords[4], coords[5]
    
    t1 = angle(p1, p2)
    t2 = angle(p2, p3)
    t3 = angle(p3, p1)
    
    if abs(t1 + t2 + t3 - 2*mth.pi) < eps:
        return True
    return False


with open('102.txt', 'r') as file:
    lines = file.readlines()

ans = 0
for line in lines:
    coords = [int(i) for i in line.split(',')]
    if has_origin(coords):
        ans += 1
        
print ans
