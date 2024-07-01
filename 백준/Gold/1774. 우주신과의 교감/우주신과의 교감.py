import sys
input = sys.stdin.readline

def calcuDis(n1, n2):
    x1, y1, x2, y2 = n1[0], n1[1], n2[0], n2[1]
    return ((x1-x2)**2 + (y1-y2)**2)**0.5

def find(parent, x):
    if x != parent[x]:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N, M = map(int, input().split())
parent = list(range(N+1))

edges = [0] * (N+1)
for i in range(1, N+1):
    edges[i] = list(map(int, input().split()))

for _ in range(M):
    a, b = map(int, input().split())
    union(parent, a, b)

dis = []
for i in range(1, N):
    for j in range(i+1, N+1):
        dis.append([calcuDis(edges[i], edges[j]), i, j])

dis.sort()
sum = 0

for i in dis:
    cost, x, y = i[0], i[1], i[2]

    if find(parent, x) != find(parent, y):
        union(parent, x, y)
        sum += cost
print("{:.2f}".format(sum))
