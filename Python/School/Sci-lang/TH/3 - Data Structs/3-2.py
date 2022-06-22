def nested_list(l):
    mx = []
    n, m = map(int, input("Nhập số dòng và số cột: ").split())
    if len(l) < n * m:
        return mx
    mx = [l[i * m : i * m + m] for i in range(n)]
    return mx


l = list(map(int, input("Nhập list: ").split()))
print(f"Ma trận tạo được: {nested_list(l)}")
