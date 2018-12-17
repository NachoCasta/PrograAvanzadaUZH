from findif import findIf, Matcher

import time

vector = []
with open("../../tmp/iterator.txt") as file:
    for line in file:
        vector.append(int(line.strip()))
iterator = iter(vector)

start = time.time()
findIf(iterator, Matcher)
end = time.time()
print(end - start)
