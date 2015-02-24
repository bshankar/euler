from __future__ import division
from math import ceil, floor
from itertools import permutations as p, combinations as c

def safe_eval(expr):
    try:
        return eval(expr)
    except ZeroDivisionError:
        return 0


max_cons, max_abcd = 0, 0
operators = ['+', '-', '*', '/']*3
nos_set = [str(i) for i in xrange(1, 10)]

for nos_ in c(nos_set, 4):
    ans = set()
    for nos in p(nos_):
        for op in p(operators, 3):
            # ((a*b)*c)*d (a*(b*c))*d a*((b*c)*d) (a*b)*(c*d) a*(b*(c*d))
            a, b, c, d = nos
            w, t, h = op
            subs = (a, w, b, t, c, h, d)
            exprs = ["((%s%s%s)%s%s)%s%s"%subs, "(%s%s(%s%s%s))%s%s"%subs, \
                    "%s%s((%s%s%s)%s%s)"%subs, "(%s%s%s)%s(%s%s%s)"%subs, \
                    "%s%s(%s%s(%s%s%s))"%subs]
            for no in map(safe_eval, exprs):
                if ceil(no) == floor(no) and no > 0:
                    ans.add(no)

    # Find maximum consecutive nos
    k = 1
    while k in ans:
        k += 1

    if k > max_cons:
        max_cons = k-1
        max_abcd = ''.join(nos_)


print max_abcd, max_cons
