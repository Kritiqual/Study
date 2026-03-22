import java.util.Scanner; // Import thư viện cần thiết

public class NV { // Khai báo lớp Nhânviên
    private String hoDem, Ten; // Khai báo thuộc tính Họ đệm và Tên
    NT ngaySinh, ngayVaoLam; // Khai báo thuộc tính Ngáy sinh và Ngày vào làm

    public NV() { // Phương thức khởi tạo không tham số
        hoDem = "";
        Ten = "";
        ngaySinh = new NT(0, 0, 0);
        ngayVaoLam = new NT(0, 0, 0);
    }

    public NV(String hoDem, String Ten, NT ngaySinh, NT ngayVaoLam) { // Phương thức khởi tạo có tham số
        this.hoDem = hoDem;
        this.Ten = Ten;
        this.ngaySinh = ngaySinh;
        this.ngayVaoLam = ngayVaoLam;
    }

    public void Nhap() { // Phương thức nhập các thuộc tính
        try (Scanner scn = new Scanner(System.in)) {
            System.out.print("Nhap Ho dem: ");
            hoDem = scn.nextLine();
            System.out.print("Nhap Ten: ");
            Ten = scn.nextLine();
        }
        System.out.println("Nhap Ngay Sinh:");
        ngaySinh.Nhap();
        System.out.println("Nhap Ngay Vao Lam:");
        ngayVaoLam.Nhap();
    }

    @Override
    public String toString() { // Phương thức toString để hiển thị thông tin Nhân viên
        return hoDem + "\t\t" + Ten + "\t\t" + ngaySinh + "\t\t\t" + ngayVaoLam;
    }
}
