import cv2
import numpy as np

#> Su dung tich chap va tinh |I* Hx| + |I * Hy| va nguong tu dong

def convolve_nest_loop(img, kernel, n):
    iH, iW = img.shape[0], img.shape[1]
    kH, kW = kernel.shape[0], kernel.shape[1]

    for i in range(1, iH - 1):
        for j in range(1, iW - 1):
            sum = 0
            for m in range(0, kH):
                for n in range(0, kW):
                    iP = img[i]
            img[i][j] = (
                img[i - 1][j - 1] * kernel[0][0]
                + img[i - 1][j] * kernel[0][1]
                + img[i - 1][j + 1] * kernel[0][2]
                + img[i][j - 1] * kernel[1][0]
                + img[i][j] * kernel[1][1]
                + img[i][j + 1] * kernel[1][2]
                + img[i + 1][j - 1] * kernel[2][0]
                + img[i + 1][j] * kernel[2][1]
                + img[i + 1][j + 1] * kernel[2][2]
            )
    return img


img = cv2.imread("/home/kritiqual/Projects/Study/Image Processing/TH4/bottle.png")
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
mx_test = np.array(gray_img)
cv2.imshow("anh cu", mx_test)
# cv2.waitKey()

# mx_test = np.array(
#     [
#         [0, 1, 2, 3, 4, 5],
#         [0, 0, 1, 2, 3, 4],
#         [0, 0, 0, 1, 2, 3],
#         [0, 0, 0, 0, 1, 2],
#         [0, 0, 0, 0, 0, 1],
#     ]
# )
# img =
