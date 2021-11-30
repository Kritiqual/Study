USE QLVT
-- -- -- Bài 1
-- -- 1,
SELECT MaVT, SUM(SLDat) AS TongSLDat
FROM CTDonDH
GROUP BY MaVT
-- -- 2,
SELECT SoPX, SUM(SLXuat)
FROM CTPXuat
GROUP BY SoPX
HAVING SUM(SLXuat) >= 3
-- -- 3,
SELECT NgayXuat, COUNT(SoPX) AS SLPXuat
FROM PXuat
GROUP BY NgayXuat
ORDER BY COUNT(SoPX)
-- -- 4,
SELECT MaVT, MAX(SLDat) AS SLDatMAX
FROM CTDonDH
GROUP BY MaVT
-- -- 5,
SELECT MaVT, COUNT(SoPN) AS SLPNhap
FROM CTPNhap
GROUP BY MaVT
-- -- 6,
SELECT NgayNhap
FROM PNhap
GROUP BY NgayNhap
HAVING COUNT(SoDH) >= 5
-- -- 7,
SELECT MaNCC
FROM DonDH
GROUP BY MaNCC
HAVING COUNT(MaNCC) >= 2
-- -- 8,
SELECT SoDH, SUM(SLDat) AS TongSLDat
FROM CTDonDH
GROUP BY SoDH
ORDER BY SUM(SLDat) DESC
-- -- 9,
SELECT MaVT, SUM(SLNhap) AS TongSLNhap
FROM CTPNhap
WHERE DgNhap < 3000000
GROUP BY MaVT
-- -- 10,
SELECT MaVT, SUM(SLCuoi) AS TongSLCuoi
FROM TonKho
GROUP BY MaVT
HAVING SUM(SLCuoi) BETWEEN 10 AND 30

-- -- -- Bài 2
-- -- A,
CREATE DATABASE DeptEmp
USE DeptEmp
-- -- B + C,
-- Department
CREATE TABLE Department
(
    DepartmentNo INT PRIMARY KEY,
    DepartmentName CHAR(25) NOT NULL,
    Location CHAR(25) NOT NULL
)
--<~>--
INSERT INTO Department
    (DepartmentNo, DepartmentName, Location)
VALUES
    (10, 'Accounting', 'Melbourne'),
    (20, 'Research', 'Adealide'),
    (30, 'Sales', 'Sydney'),
    (40, 'Operations', 'Perth');
-- Employee
CREATE TABLE Employee
(
    EmpNo INT PRIMARY KEY,
    Fname VARCHAR(15) NOT NULL,
    Lname VARCHAR(15) NOT NULL,
    Job VARCHAR(25) NOT NULL,
    HireDate DATETIME NOT NULL,
    Salary NUMERIC NOT NULL,
    Commision NUMERIC,
    DepartmentNo INT FOREIGN KEY REFERENCES Department(DepartmentNo)
)
--<~>--
INSERT INTO Employee
    (EmpNo, Fname, Lname, Job, HireDate, Salary, Commision, DepartmentNo)
VALUES
    (1, 'John', 'Smith', 'Clerk', '17-Dec-1980', 800, NULL, 20),
    (2, 'Peter', 'Allen', 'Salesman', '20-Feb-1981', 1600, 300, 30),
    (3, 'Kate', 'Ward', 'Salesman', '22-Feb-1981', 1250, 500, 30),
    (4, 'Jack', 'Jones', 'Manager', '02-Apr-1981', 2975, NULL, 20),
    (5, 'Joe', 'Martin', 'Salesman', '28-Sep-1981', 1250, 1400, 30);
-- -- D,
-- 1,
SELECT *
FROM Department
-- 2,
SELECT *
FROM Employee
-- 3,
SELECT EmpNo, Fname, Lname
FROM Employee
WHERE Fname LIKE 'Kate'
-- 4,
SELECT CONCAT(Fname, ' ', Lname) AS 'Full Name', Salary, 1.1 * Salary AS '10%Salary'
FROM Employee
-- 5,
SELECT Fname, Lname, HireDate
FROM Employee
WHERE YEAR(HireDate) LIKE '1981'
ORDER BY Lname
-- 6,
SELECT AVG(Salary) AS SalaryAVG, MAX(Salary) AS SalaryMAX, MIN(Salary) AS SalaryMIN
FROM Employee
GROUP BY DepartmentNo
-- 7,
SELECT Dpt.DepartmentNo, COUNT(Emp.Fname) AS EmpNum
FROM Department AS Dpt
INNER JOIN Employee AS Emp
ON Dpt.DepartmentNo = Emp.DepartmentNo
GROUP BY Dpt.DepartmentNo
