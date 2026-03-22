import java.util.Scanner; // Import thư viện cần thiết

public class NT { // Khai báo lớp Ngày tháng
    private int d, m, y; // Khai báo các thuộc tính ngày, tháng, năm

    private int checkDay(int dC) { // Phương thức kiểm tra ngày
        int D[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && dC == 29) {
            if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
                return dC;
        } else if (dC > 0 && dC <= D[m])
            return dC;
        return 1;
    }

    public NT() {
    }

    public NT(int d, int m, int y) { // Phương thức khởi tạo có tham số
        this.y = y;

        if (m > 0 && m <= 12)
            this.m = m;
        else
            this.m = 1;

        this.d = checkDay(d);
    }

    public int getD() {
        return this.d;
    }

    public int getM() {
        return this.m;
    }

    public int getY() {
        return this.y;
    }

    public void Nhap() { // Phương thức nhập ngày, tháng, năm
        try (Scanner scn = new Scanner(System.in)) {
			System.out.print("\tNhap ngay: ");
			d = scn.nextInt();
			System.out.print("\tNhap thang: ");
			m = scn.nextInt();
			System.out.print("\tNhap nam: ");
			y = scn.nextInt();
			scn.nextLine();
		}
    }

    @Override
    public String toString() { // Phương thức toString để hiện thị ngày tháng
        return d + "/" + m + "/" + y;
    }
}
