def merge_list(a, b):
    # result = [item for sublist in zip(a,b) for item in sublist]
    res = []
    # n = len(a) if len(a) <= len(b) else len(b)
    for sublist in zip(a, b):
        for items in sublist:
            res.append(items)

    # if len(a) > len(b):
    #     for i in range(len(b)):
    #         res.append(a[i])
    #         res.append(b[i])
    #     for i in a[len(b) :]:
    #         res.append(i)
    # elif len(a) < len(b):
    #     for i in range(len(a)):
    #         res.append(a[i])
    #         res.append(b[i])
    #     for i in b[len(a) :]:
    #         res.append(i)
    # else:
    #     for i in range(len(a)):
    #         res.append(a[i])
    #         res.append(b[i])
    #     for i in b[len(a) :]:
    #         res.append(i)
    return res


a = list(map(int, input("Nhập list: ").split()))
b = list(map(int, input("Nhập list: ").split()))
n, m = len(a), len(b)

print(merge_list(a, b))
