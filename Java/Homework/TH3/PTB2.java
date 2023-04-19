
public class PTB2 { // Khai báo lớp PTB2
    private int a, b, c; // Khai báo 3 biến int a, b, c
    public PTB2() { // Phương thức khởi tạo không tham số
        a = 0;
        b = 0;
        c = 0;
    }
    public PTB2(int a, int b, int c) { // Phương thức khởi tạo có tham số
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public int getA() { // Phương thức get giá trị a
        return this.a;
    }
    public void setA(int a) { // Phương thức set giá trị a
        this.a = a;
    }
    public int getB() { // Phương thức get giá trị b
        return this.b;
    }
    public void setB(int b) { // Phương thức set giá trị b
        this.b = b;
    }
    public int getC() { // Phương thức get giá trị c
        return this.c;
    }
    public void setC(int c) { // Phương thức set giá trị c
        this.c = c;
    }
    public void Solve() { // Phương thức giải PTB2
        if (a == 0) {
            System.out.println("Khong phai PTB2!");
        } else {
            float delta = b * 2 - 4 * a * c;
            if (delta == 0) {
                System.out.printf("PT co nghiem kep: x = %.2d", -b / (2 * a));
            }
            if (delta > 0) {
                System.out.println("PT co 2 nghiem: ");
                System.out.printf("\tx1 = %.2f", (-b + Math.sqrt(delta)) / (2 * a));
                System.out.printf("\tx2 = %.2f", (-b - Math.sqrt(delta)) / (2 * a));
            }
            if (delta < 0) {
                System.out.println("PT co 2 nghiem phuc: ");
                System.out.printf("\tx1 = (%.2d + i*%.2f) / %.2d\n", -b, Math.sqrt(-delta), 2 * a);
                System.out.printf("\tx2 = (%.2d - i*%.2f) / %.2d\n", -b, Math.sqrt(-delta), 2 * a);
            }
        }
    }
    @Override
    public String toString() { // Phương thức toString
        return a + "x2 + " + b + "x + " + c + " = 0";
    }
}
