from itertools import combinations as c

pete  = range(1, 5)*9
colin = range(1, 7)*6
pete_probs = dict()
pete_total = 0.0

for pete_roll in c(pete, 9):
    try:
        pete_probs[sum(pete_roll)] += 1
    except:
        pete_probs[sum(pete_roll)] = 1

    pete_total += 1

#pete_probs = {i:pete_probs[i]/pete_total for i in pete_probs}
print pete_probs

colin_probs = dict()
colin_total = 0.0

for colin_roll in c(colin, 6):
    try:
        colin_probs[sum(colin_roll)] += 1
    except:
        colin_probs[sum(colin_roll)] = 1

    colin_total += 1

colin_probs = {i:colin_probs[i]/colin_total for i in colin_probs}

pete_wins = 0.0
for pete_score in pete_probs:
    for colin_score in colin_probs:
        if pete_score > colin_score:
            pete_wins += pete_probs[pete_score]*colin_probs[colin_score]

print pete_wins



