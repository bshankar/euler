from itertools import permutations as P
from copy import deepcopy

with open('59.txt') as file:
    lines = file.readlines()

text = [int(i) for i in lines[0].split(",")]

# try four extremely common words
common = [' the ', ' be ', ' to ']
words = [[ord(j) for j in i] for i in common]
lower = range(97, 97+26)

def cipher(text, key):
    # apply key repeatedly 
    # and encrypt/decrypt using xor
    i, j = 0, 0
    while i < len(text):
        text[i] = text[i]^key[j]
        i += 1
        j += 1
        if j == len(key):
            j = 0
            
    return text

def find_text(text, words):
    matches = 0
    for i in range(len(text)):
        match = True
        if text[i] == words[0] and \
        len(text) - i >= len(words):
            for j in range(1, len(words) - 1):
                if text[i+j] != words[j]:
                    match = False
            if match:
                matches += 1
    return matches

ans = 0
max_score = 0

for key in P(lower, 3):
    text_ = deepcopy(text)
    cipher(text, key)
    score = 0
    for word in words:
        if find_text(text, word):
            score += 1
            
    if score > max_score:
        print "key is: ", ''.join(chr(i) for i in key), "score is: ", score
        print ''.join(chr(i) for i in text)
        max_score = score
        ans = sum(i for i in text)
    text = deepcopy(text_)
    
print ans
