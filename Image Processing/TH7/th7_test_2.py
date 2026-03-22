import cv2
import numpy as np
from sklearn.neighbors import NearestNeighbors
import matplotlib.pyplot as plt

new_size = (128, 128)


def get_pixel(img, center, x, y):
    new_value = 0
    try:
        if img[x][y] >= center:
            new_value = 1
    except:
        pass
    return new_value


def lbp_calculated_pixel(img, x, y):
    center = img[x][y]
    val_ar = []
    val_ar.append(get_pixel(img, center, x - 1, y + 1))
    val_ar.append(get_pixel(img, center, x, y + 1))
    val_ar.append(get_pixel(img, center, x + 1, y + 1))
    val_ar.append(get_pixel(img, center, x + 1, y))
    val_ar.append(get_pixel(img, center, x + 1, y - 1))
    val_ar.append(get_pixel(img, center, x, y - 1))
    val_ar.append(get_pixel(img, center, x - 1, y - 1))
    val_ar.append(get_pixel(img, center, x - 1, y))

    power_val = [4, 8, 16, 32, 64, 128, 1, 2]
    val = 0
    for i in range(len(val_ar)):
        val += val_ar[i] * power_val[i]
    return val


def compute_lbp(image, radius=1, neighbors=8):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    height, width = gray.shape
    img_lbp = np.zeros((height, width, 3), np.uint8)
    for i in range(0, height):
        for j in range(0, width):
            img_lbp[i, j] = lbp_calculated_pixel(gray, i, j)

    hist, _ = np.histogram(
        img_lbp.ravel(),
        bins=np.arange(0, 2**neighbors + 1),
        range=(0, 2**neighbors),
    )
    hist = hist.astype("float")
    hist /= hist.sum() + 1e-7
    return hist


# Danh sách các tên file ảnh train và test
folder_train = "/home/kritiqual/Projects/Study/Image Processing/Input/TH7/train/"
train_filenames = [
    "train1.bmp",
    "train2.bmp",
    "train3.bmp",
    "train4.bmp",
    "train5.bmp",
    "train6.bmp",
    "train7.bmp",
    "train8.bmp",
    "train9.bmp",
    "train10.bmp",
    "train11.bmp",
    "train12.bmp",
    "train13.bmp",
    "train14.bmp"
]

folder_test = "/home/kritiqual/Projects/Study/Image Processing/Input/TH7/test/"
test_filenames = ["test1.bmp", "test2.bmp", "test3.bmp"]

train_lbps = []
for filename in train_filenames:
    img = cv2.imread(folder_train + filename)
    img = cv2.resize(img, new_size)
    lbp = compute_lbp(img)
    train_lbps.append(lbp)

test_lbps = []
for filename in test_filenames:
    img = cv2.imread(folder_test + filename)
    img = cv2.resize(img, new_size)
    lbp = compute_lbp(img)
    test_lbps.append(lbp)

test_index = 2
test_lbp = test_lbps[test_index]

k = 5
nbrs = NearestNeighbors(n_neighbors=k).fit(train_lbps)
distances, indices = nbrs.kneighbors([test_lbp])

plt.subplot(3, 3, 1)
plt.imshow(
    cv2.cvtColor(
        cv2.imread(folder_test + test_filenames[test_index]), cv2.COLOR_BGR2RGB
    )
)
plt.title("Test image")

for i in range(k):
    plt.subplot(3, 3, i + 2)
    plt.imshow(
        cv2.cvtColor(
            cv2.imread(folder_train + train_filenames[indices[0][i]]), cv2.COLOR_BGR2RGB
        )
    )
    plt.title("Train image {}".format(i + 1))

plt.show()
