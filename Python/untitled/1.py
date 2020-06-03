n = int(input())
k = 1
a = [[0] * n for i in range(n)]
size = range(n)

for i in size:
    for j in size:
        a[i][j] = k
        k += 1
        if a[i][j + 1] != 0 or j + 1 not in range(n):
            temp = i
            i = j
            j = temp

        if a[i + 1][j] != 0 or i + 1 not in range(n):
            temp = i
            i = j
            j = temp
            size = range(n - 1, -1, -1)