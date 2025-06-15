//삽입이상 없음

-- JAVA 강좌에 대한 수강료 정보를 SummerPrice 테이블에 삽입
-- 수강 학생이 아직 없어도 강좌 정보만 독립적으로 저장 가능 → 삽입 이상 없음
INSERT INTO SummerPrice VALUES ('JAVA', 25000);

-- SummerPrice 테이블 조회 → JAVA 강좌가 정상적으로 삽입되었는지 확인
SELECT *
FROM SummerPrice;

-- SummerEnroll 테이블 조회 → JAVA 과목 수강 학생은 아직 없음
-- 강좌 정보 삽입 시 수강 정보가 없어도 문제가 되지 않음 → 삽입 이상 없음
SELECT *
FROM SummerEnroll;