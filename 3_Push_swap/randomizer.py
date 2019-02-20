import random
import sys

l = list(range(-1000, 1000))
random.shuffle(l)
i = 0
r = 0
if len(sys.argv) > 1:
    r = (int)(sys.argv[1])
while i < r:
    print(l[i], end=" ")
    i = i + 1
if r > 0:
    print()