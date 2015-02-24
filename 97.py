m = 10000000000
def pow(a, b, c):
    # modular exponentiation
    ans = 1
    while b > 0:
        if b&1:
            ans = (ans*a) % c
        b = b >> 1
        a = (a*a) % c
    return ans

print (28433*pow(2, 7830457, m) + 1) % m
