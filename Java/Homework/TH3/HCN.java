
public class HCN { // Khởi tạo lớp HCN

    private float dai, rong; // Khai báo 2 biến float dài và rộng

    public HCN() { // Phương thức khởi tạo của lớp không tham số
        dai = 0;
        rong = 0;
    }

    public HCN(float dai, float rong) { // Phươmg thức khởi tạo có tham số
        this.dai = dai;
        this.rong = rong;
    }

    public float getDai() { // Phương thức get chiều dài
        return this.dai;
    }

    public void setDai(float dai) { // Phường thức set chiều dài
        this.dai = dai;
    }

    public float getRong() { // Phường thức get chiều rộng
        return this.rong;
    }

    public void setRong(float rong) { // Phương thức set chiều rộng
        this.rong = rong;
    }

    public float ChuVi() { // Phương thức tính chu vi
        return 2 * (dai + rong);
    }

    public float DienTich() { // Phương thức tính diện tích
        return dai * rong;
    }

    @Override
    public String toString() { // Phương thức toString
        return "HCN[" + " dai='" + dai + "'" + ", rong='" + rong + "'" + "]";
    }
}
