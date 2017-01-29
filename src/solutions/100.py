# generic integer equation solver
# http://www.alpertron.com.ar/QUAD.HTM

b = 15;
n = 21;
min_n = 1000000000000;
 
while n < min_n:
    b, n = 3*b + 2*n - 2, 4*b + 3*n - 3
    
print b
