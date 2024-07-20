import sys


N = int(input())
li = []
for i in range(N):
    a, b = list(map(int, sys.stdin.readline().split()))
    li.append([a - b, i])
    li.append([a + b, i])
li.sort()

res = []
for i in li:
    if res:
        if i[1] == res[-1][1]:
            res.pop()
        else:
            res.append(i)
    else:
        res.append(i)
if res:
    print("NO")
else:
    print("YES")