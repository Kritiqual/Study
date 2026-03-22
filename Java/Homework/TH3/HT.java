
public class HT { // Khai báo lớp HT
    private double r; // Khai báo biến double bán kính (r)

    public HT() { // Phương thức khỏi tạo không tham số
        r = 0; // Biến r mặc định bằng 0
    }

    public HT(double r) { // Phương thức khỏi tạo có tham số
        this.r = r;
    }

    public double getR() { // Phương thức get giá trị r
        return this.r;
    }

    public void setR(double r) { // Phương thức set giá trị r
        this.r = r;
    }

    public double Chuvi() { // Phương thức tính chu vi
        return 2 * Math.PI * r;
    }

    public double DienTich() { // Phương thức tính diện tích
        return Math.PI * r * r;
    }

    @Override
    public String toString() { // Phương thúc toString
        return "HT[" + "r='" + r + "'" + "]";
    }

}
