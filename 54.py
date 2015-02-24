import copy

spls = {'J':'11', 'Q':'12', 'K':'13', 'A':'14'}

def normalize(suit):
    for i in range(len(suit)):
        for spl in spls:
            suit[i] = suit[i].replace(spl, spls[spl])
    return suit

def remove_shapes(suit):
    suit = copy.deepcopy(suit)
    for i in range(len(suit)):
        suit[i] = suit[i][:-1] 
    return suit
    
def remove_numbers(suit):
    suit = copy.deepcopy(suit)
    for i in range(len(suit)):
        suit[i] = suit[i][-1]
    return suit

def is_royal_flush(suit_sh):
    if suit_sh == range(10, 15):
        return True
    return False

def is_flush(suit_no):
    if len(set(map(lambda x: int(x) - suit_no.index(x), suit_no))) == 1:
        return True
    return False
        
def ofa_kind(suit_no):
    return len(set(suit_no))

def high_card(suit_no):
    return suit_no[-1]

    


s = normalize(['5H', '5C', '6S', '7S', 'KD'])
print s
print remove_numbers(s)
print remove_shapes(s)
print is_rf(s)
print is_sf(remove_shapes(s))
