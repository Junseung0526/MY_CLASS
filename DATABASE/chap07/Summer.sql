//Summer 테이블을 생성하고 데이터를 삽입하는 SQL 문

-- 기존에 Summer 테이블이 존재하면 삭제 (테이블 재생성을 위해)
DROP TABLE Summer;

-- Summer 테이블 생성
-- sid: 학생 ID (숫자)
-- class: 수강 과목 (최대 20자 문자열)
-- price: 수강료 (숫자)
CREATE TABLE Summer (
    sid NUMBER,
    class VARCHAR2(20),
    price NUMBER
);

-- 수강 정보 삽입 (학생 ID, 수강 과목, 수강료)
INSERT INTO Summer VALUES (100, 'FORTRAN', 20000);
INSERT INTO Summer VALUES (150, 'PASCAL', 15000);
INSERT INTO Summer VALUES (200, 'C', 10000);
INSERT INTO Summer VALUES (250, 'FORTRAN', 20000);

-- Summer 테이블의 전체 데이터 조회 (삽입 확인)
SELECT *
FROM Summer;