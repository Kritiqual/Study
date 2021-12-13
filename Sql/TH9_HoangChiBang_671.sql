CREATE DATABASE TOURCTRL
USE TOURCTRL
----------------------------------------------------------------------------------------------------
-- -- TINH
CREATE TABLE TINH
(
    MaTinh CHAR(10) PRIMARY KEY,
    TenTinh NVARCHAR(30) NOT NULL,
    Mien NVARCHAR(30) NOT NULL
)
--<~>--
CREATE TABLE DIEMDL
(
    MaDDL CHAR(10) PRIMARY KEY,
    TenDDL NVARCHAR(30) NOT NULL,
    DacTrung NVARCHAR(20) NOT NULL,
    MaTinh CHAR(10) FOREIGN KEY REFERENCES TINH(MaTinh) ON UPDATE CASCADE ON DELETE CASCADE
)
--<~>--
CREATE TABLE TOURDL
(
    MaTour CHAR(10) PRIMARY KEY,
    TenTour NVARCHAR(30) NOT NULL,
    SoNgay INT NOT NULL,
    SoDem INT NOT NULL,
    PhuongTienDi VARCHAR(10),
    PhuongTienVe VARCHAR(10),
    GiaVeLe MONEY,
    GiaVeNhom MONEY
)
--<~>--
CREATE TABLE CTTOUR
(
    MaDDL CHAR(10) FOREIGN KEY REFERENCES DIEMDL(MaDDL) ON UPDATE CASCADE ON DELETE CASCADE,
    MaTour CHAR(10) FOREIGN KEY REFERENCES TOURDL(MaTour) ON UPDATE CASCADE ON DELETE CASCADE,
    PRIMARY KEY(MaDDL, MaTour),
    NGAY INT,
    DEM INT
)
--------------------------------------------------
INSERT INTO TINH
    (MaTinh,TenTinh,Mien)
VALUES
    ('204', N'Bắc Giang', 'Bắc'),
    ('211', N'Hà Giang', 'Bắc'),
    ('252', N'Bình Thuận', 'Trung'),
    ('290', N'Cà Mau', 'Nam'),
    ('291', N'Bạc Liêu', 'Nam');
--<~>--
INSERT DIEMDL
    (MaDDL, TenDDL, DacTrung, MaTinh)
VALUES
    ('DDLa', N'Làng Thổ Hà', N'Văn hóa', '204'),
    ('DDLb', N'Thành Cổ Xương Giang', N'Thành cổ', '204'),
    ('DDLc', N'Con Đường Hạnh Phúc', N'Đường đi', '211'),
    ('DDLd', N'Đèo Mã Pì Lèng', N'Đường đèo', '211'),
    ('DDLe', N'Đảo Phú Quý', N'Tắm biển', '252'),
    ('DDLf', N'Đồi Cát Mũi Né', N'Đồi cát', '252'),
    ('DDLg', N'Chợ Nổi Cà Mau', N'Chợ nổi', '290'),
    ('DDLh', N'Tháp Cổ Vĩnh Hưng', N'Tháp cổ', '291');
--<~>--   
INSERT TOURDL
    (MaTour, TenTour, SoNgay, SoDem, PhuongTienDi, PhuongTienVe, GiaVeLe, GiaVeNhom)
VALUES
    ('TDLm', N'Tour 77', 6, 2, N'Ô tô', N'Ô tô', 1000000, 2450000),
    ('TDLn', N'Tour 54', 6, 3, N'Ô tô', N'Máy bay', 2400000, 2790000),
    ('TDLp', N'Tour 32', 6, 3, N'Máy bay', N'Máy bay', 1400000, 1350000),
    ('TDLq', N'Tour 14^2', 5, 4, N'Máy bay', N'Ô tô', 1700000, 1900000),
    ('TDLx', N'Tour square(7)', 5, 2, N'Máy bay', N'Máy bay', 1300000, 1600000),
    ('TDLy', N'Tour 1413', 6, 5, N'Ô tô', N'Ô tô', 2200000, 2650000);
--<~>--
INSERT CTTOUR
    (MaDDL, MaTour, NGAY, DEM)
VALUES
    ('DDLh', 'TDLy', 2, 6),
    ('DDLd', 'TDLx', 0, 1),
    ('DDLb', 'TDLq', 3, 6),
    ('DDLc', 'TDLy', 1, 6),
    ('DDLa', 'TDLx', 3, 6),
    ('DDLb', 'TDLy', 0, 2),
    ('DDLa', 'TDLm', 0, 5),
    ('DDLa', 'TDLp', 2, 2),
    ('DDLd', 'TDLp', 1, 4),
    ('DDLb', 'TDLn', 3, 3);


----------------------------------------------------------------------------------------------------
-- -- 6,
-- a,
SELECT MaTour, TenTour, PhuongTienDi, PhuongTienVe, GiaVeNhom
FROM TOURDL
WHERE SoNgay = 2 AND SoDem = 1
    AND GiaVeNhom < 2000000
-- b,
SELECT t.MaTour, TenTour
FROM TOURDL t
    INNER JOIN CTTOUR ct ON t.MaTour = ct.MaTour
    INNER JOIN DIEMDL d ON ct.MaDDL = d.MaDDL
WHERE 
    PhuongTienDi LIKE N'Máy bay'
    AND PhuongTienVe LIKE N'Ô tô'
    AND DacTrung LIKE N'Tắm biến'
ORDER BY GiaVeLe
-- c,
SELECT TenTinh
FROM TINH t INNER JOIN DIEMDL d
ON t.MaTinh = d.MaTinh
GROUP BY TenTinh
HAVING COUNT(MaDDL) = (
    SELECT MAX(x.SLDDL)
    FROM (
        SELECT COUNT(MaDDL) AS SLDDL
        FROM DIEMDL
        GROUP BY MaTinh
    ) x
)
-- d,
SELECT t.MaTinh, TenTinh
FROM TINH t INNER JOIN (
    SELECT MaTinh
    FROM DIEMDL
    WHERE 
        DacTrung LIKE N'Tắm biển'
        AND MaTinh IN (
            SELECT MaTinh FROM DIEMDL
            WHERE DacTrung LIKE N'Leo núi'
        )
) b
ON t.MaTinh = b.MaTinh
-- -- e,
-- SELECT MaDDL, TenDDL
-- FROM DIEMDL
-- GROUP BY MaDDL, TenDDL
-- HAVING COUNT()
-- f,
SELECT MaTour, TenTour, SoNgay, SoDem, GiaVeLe
FROM TOURDL
WHERE 
    PhuongTienDi LIKE N'Máy bay'
    AND PhuongTienVe LIKE 'Máy bay'
    AND GiaVeLe < 3000000
-- g,
SELECT td.MaTour, TenTour, SoNgay, SoDem, GiaVeLe
FROM TOURDL td
    INNER JOIN CTTOUR ct ON td.MaTour = ct.MaTour
    INNER JOIN DIEMDL dl ON ct.MaDDL = dl.MaDDL
WHERE TenDDL LIKE N'Vịnh Hạ Long'
ORDER BY ct.NGAY DESC
-- h,
SELECT TenTour
FROM TOURDL t INNER JOIn CTTOUR ct
    ON t.MaTour = ct.MaTour
GROUP BY TenTour
HAVING COUNT(MaDDL) = (
    SELECT MAX(x.SLDDL)
    FROM (
        SELECT COUNT(MaDDL) AS SLDDL
        FROM CTTOUR
        GROUP BY MaTour
    ) X
)
-- i,
SELECT t.MaTinh, TenTinh
FROM TINH t INNER JOIN (
    SELECT MaTinh FROM DIEMDL
    WHERE 
        DacTrung LIKE N'Tắm biển'
        AND MaTinh NOT IN (
            SELECT MaTinh FROM DIEMDL
            WHERE DacTrung LIKE N'Leo núi'
        )
) b
ON t.MaTinh = b.MaTinh
-- j,




