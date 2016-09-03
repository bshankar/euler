def spell(n):
    # spell a number < 10000 without spaces
    digits = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    tens   = ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', \
              'seventeen', 'eighteen', 'nineteen']
    tens_ = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
    others = ['hundred', 'thousand']

    name = ''
    if n == 10:
        return 'ten'

    if n/1000:
        name += digits[n/1000 - 1] + others[1]
        n %= 1000
        if n < 100 and n:
            name += 'and'
        if n == 10:
            return name + 'ten'
    if n/100:
        name += digits[n/100 - 1] + others[0]
        n %= 100
        if n:
            name += 'and'
        if n == 10:
            return name + 'ten'
    if n/10 > 1:
        name += tens_[n/10-2]
        if n % 10:
            name += digits[n%10 - 1]
    elif n/10 == 1:
        name += tens[n - 11]
    elif n:
        name +=  digits[n%10 - 1]

    return name

print sum(len(spell(n)) for n in range(1, 1001))
    
