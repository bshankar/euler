import datetime as dt
ans = 0
for year in range(1901, 2001):
    for month in range(1, 13):
        if dt.date(year, month, 1).weekday() == 6:
            ans += 1

print ans
