-- 기존에 존재하던 테이블을 삭제 (초기화 목적)
DROP TABLE SummerPrice;
DROP TABLE SummerEnroll;

-- 수강 과목별 수강료를 저장하는 테이블 생성
-- CLASS: 과목 이름
-- PRICE: 해당 과목의 수강료
CREATE TABLE SummerPrice(
    CLASS VARCHAR(20),
    PRICE INTEGER
);

-- SummerPrice 테이블에 각 과목별 수강료 데이터 삽입
INSERT INTO SummerPrice VALUES ('FORTRAN', 20000);
INSERT INTO SummerPrice VALUES ('PASCAL', 15000);
INSERT INTO SummerPrice VALUES ('C', 10000);

-- SummerPrice 테이블 내용 조회
SELECT *
FROM SummerPrice;

-- 수강 신청 정보를 저장하는 테이블 생성
-- sid: 학생 ID
-- class: 수강한 과목
CREATE TABLE SummerEnroll(
    sid INTEGER,
    class VARCHAR(20)
);

-- SummerEnroll 테이블에 학생들의 수강 과목 삽입
INSERT INTO SummerEnroll VALUES (100, 'FORTRAN');
INSERT INTO SummerEnroll VALUES (150, 'PASCAL');
INSERT INTO SummerEnroll VALUES (200, 'C');
INSERT INTO SummerEnroll VALUES (250, 'FORTRAN');

-- SummerEnroll 테이블 내용 조회
SELECT *
FROM SummerEnroll;
