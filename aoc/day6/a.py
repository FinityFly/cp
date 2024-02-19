with open('ewpython/sample.txt', 'r') as f:
    data = f.readlines()
    f.close()

answer = 1
queries = [[51926890, 222203111261225]]

for q in queries:
    print(q)
    temp = 0
    hasPassed = False
    for j in range(q[0]):
        dist = j * (q[0] - j)
        if dist > q[1]:
            temp += 1
            hasPassed = True
        elif hasPassed:
            break
    answer *= temp

print(answer)