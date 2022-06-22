import numpy as np

np.set_printoptions(suppress=True, linewidth=np.inf)


def read(file):
    try:
        with open(file, "r") as f:
            return np.array([line.split() for line in f])
    except:
        print("Không tìm thấy file!")
        return


def distance(src, dst):
    return np.sum(((src - dst) ** 2)) ** 0.5


def distancetoall(test, x_train):
    return np.array([distance(test, i) for i in x_train])


def predict(test, x_train, label):
    return label[np.argmin(distancetoall(test, x_train))]


# [1]
x_train = read("./kddcup.data")
label = x_train[:, -1]
x_train = np.array(x_train[:, 4:-1], dtype=float)

# [2]
x_test = read("./kddcup.test")
label_test = x_test[:, -1]
x_test = np.array(x_test[:, 4:-1], dtype=float)

# [3]
idx_test = np.random.randint(len(x_test))
print(f"Dòng được chọn: {idx_test} -> {x_test[idx_test]}")
print(f"-> Dự đoán: {predict(x_test[idx_test], x_train, label)}")
print(f"-> Đúng: {label_test[idx_test]}")
