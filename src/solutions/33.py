from fractions import Fraction as fr, gcd

def cancel_digits(num, den):
    is_cancelled = False
    numstr, denstr = str(num), str(den)
    for i in range(len(numstr)):
        for j in range(len(denstr)):
            if numstr[i] == denstr[j] and numstr[i] != '0':
                is_cancelled = True
                numstr = numstr.replace(numstr[i], 'a', 1)
                denstr = denstr.replace(denstr[j], 'b', 1)
    numstr = numstr.replace('a', '')
    denstr = denstr.replace('b', '')

    if is_cancelled == False:
        return -1

    try:
        return fr(int(numstr), int(denstr))
    except:
        return -1


ans = 1
for den in range(10, 100):
    for num in range(10, den):
        frac = fr(num, den)
        frac2 = cancel_digits(num, den)
        if frac == frac2:
            ans *= frac

print ans.denominator
