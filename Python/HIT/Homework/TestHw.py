def opt(matrix, n):
    for i in range(n[0]):
        for j in range(n[1]):
            print(matrix[i][j], end=" ")
        print()


def rev(matrix, n):
    mx = []
    for i in range(n[0] - 1, 0):
        for j in range(n[1] - 1, 0):
            mx[i][j] = matrix[i][j]


n = list(map(int, input("Nhap so hang va cot: ").split()))[:2]
matrix = []
for i in range(n[0]):
    matrix.append(list(map(int, input().split()))[0 : n[1]])
opt(matrix, n)
rev(matrix, n)
