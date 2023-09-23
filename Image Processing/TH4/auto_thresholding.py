import cv2
import numpy as np

img = cv2.imread("/home/kritiqual/Projects/Study/Image Processing/TH4/bottle.png")
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
mx_test = np.array(gray_img)
cv2.imshow("anh cu", mx_test)

# mx_test = np.array(
#     [
#         [0, 1, 2, 3, 4, 5],
#         [0, 0, 1, 2, 3, 4],
#         [0, 0, 0, 1, 2, 3],
#         [0, 0, 0, 0, 1, 2],
#         [0, 0, 0, 0, 0, 1],
#     ]
# )

g, hg = np.unique(mx_test, return_counts=True)
# for i in range(len(g)):
#     print(g[i], " -> ", hg[i])

tg = [hg[0]]
for i in range(len(g) - 1):
    tg.append(tg[i] + hg[i + 1])
# for i in range(len(g)):
#     print(g[i], " -> ", hg[i], " -> ", tg[i])

ghg = []
for i in range(len(g)):
    ghg.append(g[i] * hg[i])
# for i in range(len(g)):
#     print(g[i], " -> ", hg[i], " -> ", tg[i], " -> ", ghg[i])


sigma = [ghg[0]]
for i in range(len(g) - 1):
    sigma.append(sigma[i] + ghg[i + 1])
# for i in range(len(g)):
#     print(g[i], " -> ", hg[i], " -> ", tg[i], " -> ", ghg[i], " -> ", sigma[i])

mg = []
for i in range(len(g)):
    mg.append(sigma[i] / tg[i])
# for i in range(len(g)):
#     print(
#         g[i],
#         " -> ",
#         hg[i],
#         " -> ",
#         tg[i],
#         " -> ",
#         ghg[i],
#         " -> ",
#         sigma[i],
#         " -> ",
#         mg[i],
#     )

fg = []
for i in range(len(g) - 1):
    fg.append(
        tg[i]
        * (mg[i] - mg[len(g) - 1]) ** 2
        / (mx_test.shape[0] * mx_test.shape[1] - tg[i])
    )
# for i in range(len(g) - 1):
#     print(
#         g[i],
#         " -> ",
#         hg[i],
#         " -> ",
#         tg[i],
#         " -> ",
#         ghg[i],
#         " -> ",
#         sigma[i],
#         " -> ",
#         mg[i],
#         " -> ",
#         fg[i],
#     )

fphi = max(fg)
for i in range(len(fg)):
    if fg[i] == fphi:
        index = i
print(f"phi = {index} -> f(phi) = {fphi}")


for i in range(mx_test.shape[0]):
    for j in range(mx_test.shape[1]):
        if mx_test[i][j] > index:
            mx_test[i][j] = 255
        else:
            mx_test[i][j] = 0
print(mx_test)
cv2.imshow("anh phan nguong", mx_test)
cv2.waitKey()
