-- Tạo Database
CREATE DATABASE QLVT ON (
    NAME = QLVT_data,
    FILENAME='C:\Users\minec\Downloads\DTB\QLVYdata.mdf',
    SIZE = 50MB,
    MAXSIZE = 200MB,
    FILEGROWTH = 10MB
)
LOG ON (
    NAME = QLVT_log,
    FILENAME='C:\Users\minec\Downloads\DTB\QLVTlog.ldf',
    SIZE = 10MB,
    MAXSIZE = UNLIMITED,
    FILEGROWTH = 5MB
)
----------------------------------------------------------------------------------------------------
-- Các lệnh
-- -- SELECT
USE QLVT
SELECT GETDATE()
SELECT *
FROM NhaCC
SELECT *
FROM VatTu
SELECT *
FROM PNhap
SELECT *
FROM CTPNhap
SELECT *
FROM DonDH
SELECT *
FROM CTDonDH
SELECT *
FROM PXuat
SELECT *
FROM CTPXuat
SELECT *
FROM TonKho
-- -- DROP
USE master
DROP DATABASE QLVT
DROP TABLE NhaCC
DROP TABLE VatTu
DROP TABLE DonDH
DROP TABLE CTDonDH
DROP TABLE PNhap
DROP TABLE CTPNhap
DROP TABLE PXuat
DROP TABLE CTPXuat
DROP TABLE TonKho
----------------------------------------------------------------------------------------------------
-- Tạo và Insert thông tin vào các table
-- -- VatTu
CREATE TABLE VatTu
(
    MaVT CHAR(4) PRIMARY KEY,
    TenVT NVARCHAR(100) UNIQUE,
    DvTinh NVARCHAR(10) DEFAULT '',
    PhanTram REAL CHECK (PhanTram BETWEEN 0 AND 100)
)
--<~>--
INSERT INTO VatTu
    (MaVT, TenVT, DvTinh, PhanTram)
VALUES
    ('DD01', N'Đầu DVD Hitachi 1 đĩa', N'Bộ', 40),
    ('DD02', N'Đầu DVD Hitachi 3 đĩa', N'Bộ', 40),
    ('TL15', N'Tủ lạnh Sanyo 150 lít', N'Cái', 25),
    ('TL90', N'Tủ lạnh Sanyo 90 lít', N'Cái', 20),
    ('TV14', N'Tivi Sony 14 inches', N'Cái', 15),
    ('TV21', N'Tivi Sony 21 inches', N'Cái', 10),
    ('TV29', N'Tivi Sony 29 inches', N'Cái', 10),
    ('VD01', N'Đầu VCD Sony 1 đĩa', N'Bộ', 30),
    ('VD02', N'Đầu VCD Sony 3 đĩa', N'Bộ', 30);
--------------------------------------------------
-- -- NhaCC
CREATE TABLE NhaCC
(
    MaNCC CHAR(3) PRIMARY KEY,
    TenNCC NVARCHAR(100) UNIQUE,
    DiaChi NVARCHAR(200) UNIQUE,
    DienThoai VARCHAR(20) NOT NULL DEFAULT N'Chưa có'
)
--<~>--
INSERT INTO NhaCC
    (MaNCC, TenNCC, DiaChi, DienThoai)
VALUES
    ('C01', N'Lê Minh Trí', N'54 Hậu Giang Q6 HCM', '87812024'),
    ('C02', N'Trần Minh Thạch', N'145 Hùng Vương Mỹ Tho', '7698154'),
    ('C03', N'Hồng Phương', '154/85 Lê Lai Q1 HCM', '9600125'),
    ('C04', N'Nhật Thắng', N'198/40 Hương Lộ 14 QTB HCM', '8757757'),
    ('C05', N'Lưu Nguyệt Quế', N'178 Nguyễn Văn Luông Đà Lạt', '7964251'),
    ('C06', N'Cao Minh Trung', N'125 Lê Quang Sung Nha Trang', DEFAULT);
--------------------------------------------------
-- -- DonDH
CREATE TABLE DonDH
(
    SoDH CHAR(4) PRIMARY KEY,
    NgayDH DATE DEFAULT GETDATE(),
    MaNCC CHAR(3) FOREIGN KEY REFERENCES NhaCC(MaNCC) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
INSERT INTO DonDH
    (SoDH, NgayDH, MaNCC)
VALUES
    ('D001', '01/15/2002', 'C03'),
    ('D002', '01/30/2002', 'C01'),
    ('D003', '02/10/2002', 'C02'),
    ('D004', '02/17/2002', 'C05'),
    ('D005', '03/01/2002', 'C02'),
    ('D006', '03/12/2002', 'C05');
-- -- -- CTDonDH
CREATE TABLE CTDonDH
(
    SoDH CHAR(4),
    MaVT CHAR(4),
    PRIMARY KEY(SoDH, MaVT),
    SLDat INT NOT NULL CHECK(SLDat > 0),
    CONSTRAINT fk_SoDHCT FOREIGN KEY(SoDH) REFERENCES DonDH(SoDH) ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_MaVTDH FOREIGN KEY(MaVT) REFERENCES VatTu(MaVT) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
INSERT INTO CTDonDH
    (SoDH, MaVT, SLDat)
VALUES
    ('D001', 'DD01', 10),
    ('D001', 'DD02', 15),
    ('D002', 'VD02', 30),
    ('D003', 'TV14', 10),
    ('D003', 'TV29', 20),
    ('D004', 'TL90', 10),
    ('D005', 'TV14', 10),
    ('D005', 'TV29', 20),
    ('D006', 'TV14', 10),
    ('D006', 'TV29', 20),
    ('D006', 'VD01', 20);
--------------------------------------------------
-- -- PNhap
CREATE TABLE PNhap
(
    SoPN CHAR(4) PRIMARY KEY,
    NgayNhap DATE NOT NULL,
    SoDH CHAR(4) FOREIGN KEY REFERENCES DonDH(SoDH) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
INSERT INTO PNhap
    (SoPN, NgayNhap, SoDH)
VALUES
    ('N001', '01/07/2002', 'D001'),
    ('N002', '01/20/2002', 'D001'),
    ('N003', '01/31/2002', 'D002'),
    ('N004', '02/15/2002', 'D003');
-- -- -- CTPNhap
CREATE TABLE CTPNhap
(
    SoPN CHAR(4),
    MaVT CHAR(4),
    PRIMARY KEY(SoPN, MaVT),
    SLNhap INT NOT NULL CHECK (SLNhap > 0),
    DgNhap MONEY NOT NULL CHECK (DgNhap > 0),
    CONSTRAINT fk_SoPNCT FOREIGN KEY(SoPN) REFERENCES PNhap(SoPN) ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_MaVTPN FOREIGN KEY(MaVT) REFERENCES VatTu(MaVT) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
INSERT INTO CTPNhap
    (SoPN, MaVT, SLNhap, DgNhap)
VALUES
    ('N001', 'DD01', 8, 2500000),
    ('N001', 'DD02', 10, 3500000),
    ('N002', 'DD01', 2, 2500000),
    ('N002', 'DD02', 5, 3500000),
    ('N003', 'VD02', 30, 2500000),
    ('N004', 'TV14', 5, 2500000),
    ('N004', 'TV29', 12, 3500000);
--------------------------------------------------
-- -- PXuat
CREATE TABLE PXuat
(
    SoPX CHAR(4) PRIMARY KEY,
    NgayXuat DATE NOT NULL,
    TenKH NVARCHAR(100) NOT NULL
)
--<~>--
INSERT INTO PXuat
    (SoPX, NgayXuat, TenKH)
VALUES
    ('X001', '01/17/2002', 'Nguyễn Ngọc Phương Nhi'),
    ('X002', '01/25/2002', 'Nguyễn Hồng Phong'),
    ('X003', '01/31/2002', N'Nguyễn Tuấn Tú');
-- -- -- CTPXuat
CREATE TABLE CTPXuat
(
    SoPX CHAR(4),
    MaVT CHAR(4),
    PRIMARY KEY(SoPX, MaVT),
    SLXuat INT NOT NULL CHECK (SLXuat > 0),
    DgXuat MONEY NOT NULL CHECK (DgXuat > 0),
    CONSTRAINT fk_SoPXCT FOREIGN KEY(SoPX) REFERENCES PXuat(SoPX) ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_MaVTPX FOREIGN KEY(MaVT) REFERENCES VatTu(MaVT) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
INSERT INTO CTPXuat
    (SoPX, MaVT, SLXuat, DgXuat)
VALUES
    ('X001', 'DD01', 2, 3500000),
    ('X002', 'DD01', 1, 3500000),
    ('X002', 'DD02', 5, 4900000),
    ('X003', 'DD01', 3, 3500000),
    ('X003', 'DD02', 2, 4900000),
    ('X003', 'VD02', 10, 3250000);
--------------------------------------------------
-- -- TonKho
CREATE TABLE TonKho
(
    NamThang CHAR(6),
    MaVT CHAR(4),
    PRIMARY KEY(NamThang, MaVT),
    CONSTRAINT fk_MaVTTK FOREIGN KEY(MaVT) REFERENCES VatTu(MaVT) ON UPDATE CASCADE ON DELETE CASCADE,
    SLDau INT NOT NULL DEFAULT 0 CHECK (SLDau >= 0),
    TongSLN INT NOT NULL DEFAULT 0 CHECK (TongSLN >= 0),
    TongSLX INT NOT NULL DEFAULT 0 CHECK (TongSLX >= 0),
    SLCuoi INT
)
--<~>--
INSERT INTO TonKho
    (NamThang, MaVT, SLDau, TongSLN, TongSLX, SLCuoi)
VALUES
    ('200201', 'DD01', 0, 10, 6, 4),
    ('200201', 'DD02', 0, 15, 7, 8),
    ('200201', 'VD02', 0, 30, 10, 20),
    ('200202', 'DD01', 4, 0, 0, 4),
    ('200202', 'DD02', 8, 0, 0, 8),
    ('200202', 'VD02', 20, 0, 0, 20),
    ('200202', 'TV14', 5, 0, 0, 5),
    ('200202', 'TV29', 12, 0, 0, 12);
----------------------------------------------------------------------------------------------------
-- UPDATE & DELETE
UPDATE NhaCC
SET DienThoai='098473645'
WHERE MaNCC LIKE 'C01'
--<~>--
DELETE FROM NhaCC
WHERE DienThoai LIKE 'Chưa có'
--<~>--
UPDATE CTPXuat
SET DgXuat = DgXuat - 1000000
WHERE SLXuat >= 3