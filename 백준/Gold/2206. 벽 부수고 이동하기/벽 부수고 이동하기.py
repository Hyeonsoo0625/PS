import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())
graph = [[0] * m for _ in range(n)]
for i in range(n):
    s = input()
    for j in range(m):
        graph[i][j] = int(s[j])

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]


def bfs():
    q = deque()
    q.append([0, 0, 0])
    visited[0][0][0] = 1

    while q:
        x, y, w = q.popleft()


        if x == n - 1 and y == m - 1:
            return visited[x][y][w]

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:

                if graph[nx][ny] == 0 and visited[nx][ny][w] == 0:
                    visited[nx][ny][w] = visited[x][y][w] + 1
                    q.append([nx, ny, w])

                elif graph[nx][ny] == 1 and w == 0:
                    visited[nx][ny][w + 1] = visited[x][y][w] + 1
                    q.append([nx, ny, w + 1])

    return -1


print(bfs())