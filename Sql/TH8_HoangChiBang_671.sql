USE QLVT
-- 1,
SELECT TenVT, DvTinh, SLCuoi
FROM VatTu vt INNER JOIN TonKho tk
ON vt.MaVT = tk.MaVT
ORDER BY TenVT DESC
-- 2,
SELECT SoPN, MaVT, SLNhap, DgNhap, SLNhap * DgNhap AS N'Thành tiền'
FROM CTPNhap
-- 3,
SELECT SoDH, TenNCC
FROM DonDH dh RIGHT JOIN NhaCC ncc
ON dh.MaNCC = ncc.MaNCC
-- 4,
SELECT SoDH, NgayDH, TenNCC
FROM DonDH dh INNER JOIN NhaCC ncc
ON dh.MaNCC = ncc.MaNCC
-- 5,
SELECT TenVT, ct.SoDH, SLDat
FROM VatTu vt INNER JOIN CTDonDH ct
ON vt.MaVT = ct.MaVT
-- 6,
SELECT TenVT, SUM(ct.SLDat) AS TongSLDat
FROM VatTu vt INNER JOIN CTDonDH ct
ON vt.MaVT = ct.MaVT
GROUP BY TenVT
-- 7,
SELECT TenVT, SoPN, SLNhap
FROM VatTu vt INNER JOIN CTPNhap ct 
ON vt.MaVT = ct.MaVT
-- 8,
SELECT SoPX, TenVT
FROM CTPXuat ct RIGHT JOIN VatTu vt
ON ct.MaVT = vt.MaVT
-- 9,
SELECT SoPX, SLXuat * DgXuat AS N'Tổng trị giá'
FROM CTPXuat
ORDER BY N'Tổng trị giá' DESC
-- 10,
SELECT *, DATENAME(WEEKDAY, NgayDH) AS N'Ngày trong tuần'
FROM DonDH
-- 11,
SELECT ct.SoPX, MaVT, SLXuat, DgXuat,
    CASE
        WHEN DGXuat < 4 THEN DGXuat
        WHEN DgXuat>=4 AND DgXuat<10 THEN DgXuat*0.95
        WHEN DgXuat>=10 AND DgXuat <=20 THEN DgXuat*0.9
        ELSE DgXuat*0.8
    END AS GiaMoi
FROM CTPXuat ct
INNER JOIN PXuat AS px
ON ct.SoPX = px.SoPX
WHERE MONTH(NgayXuat)=1 AND YEAR(NgayXuat)=2002
-- 12,
SELECT TenVT
FROM VatTu vt INNER JOIN CTPNhap ct
ON vt.MaVT = ct.MaVT
WHERE DgNhap LIKE (
    SELECT MIN(DgNhap)
    FROM CTPNhap
)
-- 13,
SELECT TenVT
FROM VatTu vt INNER JOIN CTDonDH ct
ON vt.MaVT = ct.MaVT
GROUP BY TenVT
HAVING SUM(SLDat) >= 30
-- 14,
SELECT TenKH
FROM PXuat px INNER JOIN CTPXuat ct
ON px.SoPX = ct.SoPX
GROUP BY TenKH
HAVING SUM(SLXuat) >= 3
-- 15,
SELECT SoDH, SUM(SLDat) AS TongSLDat
FROM CTDonDH
GROUP BY SoDH
-- 16,
SELECT SoDH, SUM(SLNhap) AS TongSLNhap
FROM CTDonDH dh INNER JOIN CTPNhap pn
ON dh.MaVT = pn.MaVT
GROUP BY SoDH
-- 17,
SELECT NamThang, TenVT, TongSLN
FROM TonKho tk INNER JOIN VatTu vt
ON tk.MaVt = vt.MaVT
-- 18,
SELECT NamThang, TenVT, TongSLX
FROM TonKho tk INNER JOIN VatTu vt
ON tk.MaVt = vt.MaVT
-- 19,
SELECT dh.SoDH, NgayDH, SLDat, ctdh.MaVT, TenVT, TongSLN
FROM DonDH dh INNER JOIN CTDonDH ctdh
ON dh.SoDH = ctdh.SoDH
INNER JOIN VatTu vt
ON ctdh.MaVT = vt.MaVT
INNER JOIN TonKho tk
ON ctdh.MaVt = tk.MaVT
-- 20,
SELECT DISTINCT dh.SoDH
FROM DonDH dh RIGHT JOIN PNhap pn
ON dh.SoDH NOT IN (
    SELECT SoDH
    FROM PNhap
)
-- 21,
SELECT TenVT
FROM VatTu vt INNER JOIN TonKho tk
ON vt.MaVT = tk.MaVT
WHERE SLCuoi=0 AND NamThang='200202'
-- 22,
SELECT DISTINCT ncc.TenNCC
FROM NhaCC ncc INNER JOIN DonDH dh
ON ncc.MaNCC = dh.MaNCC
-- 24,
SELECT TenVT
FROM VatTu vt INNER JOIN CTPXuat ct
ON vt.MaVT = ct.MaVT
WHERE DgXuat >= 2000000 AND SLXuat >= 3
-- 25,
SELECT TenVT
FROM VatTu vt INNER JOIN CTPNhap ct
ON vt.MaVT = ct.MaVT
WHERE DgNhap < (
    SELECT AVG(DgNhap)
    FROM CTPNhap
)