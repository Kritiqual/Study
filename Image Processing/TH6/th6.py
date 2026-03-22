import cv2
from sklearn.neighbors import NearestNeighbors

test_img = cv2.imread('/home/kritiqual/Projects/Study/Image Processing/Input/TH6/test/t3.jpg')
test_img = cv2.resize(test_img, (300, 300))

data_imgs = []
data_hists = []
for i in range(1, 12):
    data_img = cv2.imread(f'/home/kritiqual/Projects/Study/Image Processing/Input/TH6/data/a{format(i)}.jpg')
    data_img = cv2.resize(data_img, (300, 300))
    hist = cv2.calcHist([data_img], [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
    print(hist)
    hist = cv2.normalize(hist, hist).flatten()
    data_imgs.append(data_img)
    data_hists.append(hist)

for i in range(1, 6):
    data_img = cv2.imread(f'/home/kritiqual/Projects/Study/Image Processing/Input/TH6/data/c{format(i)}.jpg')
    data_img = cv2.resize(data_img, (300, 300))
    hist = cv2.calcHist([data_img], [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
    hist = cv2.normalize(hist, hist).flatten()
    data_imgs.append(data_img)
    data_hists.append(hist)

test_hist = cv2.calcHist([test_img], [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
test_hist = cv2.normalize(test_hist, test_hist).flatten()

neigh = NearestNeighbors(n_neighbors=3)
neigh.fit(data_hists)
distances, indices = neigh.kneighbors([test_hist])

cv2.imshow('Test picture', test_img)
for i in range(3):
    data_img = data_imgs[indices[0][i]]
    cv2.imshow('Data image {}'.format(i + 1), data_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
