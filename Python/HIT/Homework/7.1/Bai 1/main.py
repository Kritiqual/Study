from PhuongTrinhBac2 import PTB2

object1 = PTB2(0, 0, 0)
print("Object 1: ", end="")
object1.Solve()
# ------------------
print("Object 2: ")
object2 = PTB2()
object2.Ipt()
object2.Solve()
# ------------------
del object1, object2
