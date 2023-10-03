from collections import deque
n = int(input())

lis = []
d = [[-1, 0], [1, 0], [0, 1], [0, -1]]
def bfs(ay, ax, s):
    queue = deque([(ax, ay)])
    global visited
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + d[i][0]
            ny = y + d[i][1]
            if (0<=nx<n) and (0<=ny<n) and lis[ny][nx] == s and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((nx, ny))


for i in range(n):
    lis.append(list(input()))
cnt = 0
cnt1 = 0
visited = [[False]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j, lis[i][j])
            cnt += 1
for i in range(n):
    for j in range(n):
        if lis[i][j] == 'R':
            lis[i][j] = 'G'
visited = [[False]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j, lis[i][j])
            cnt1 += 1

print(cnt, cnt1)