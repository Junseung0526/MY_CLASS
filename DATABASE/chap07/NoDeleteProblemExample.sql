//삭제이상 없음

-- C 강좌의 수강료를 SummerPrice 테이블에서 조회
-- 수강 학생 정보와는 독립적으로 존재하기 때문에 언제든지 조회 가능
SELECT price AS "C 수강료"
FROM SummerPrice
WHERE class = 'C';

-- 200번 학생의 수강 신청 취소 (SummerEnroll 테이블에서만 삭제됨)
DELETE FROM SummerEnroll
WHERE SID = 200;

-- 현재 SummerEnroll 테이블 상태 확인 (200번 학생의 정보만 삭제됨)
SELECT *
FROM SummerEnroll;

-- 다시 C 강좌의 수강료 조회
-- 수강 신청 정보가 삭제되어도, 강좌 수강료 정보는 유지됨 → 삭제 이상이 발생하지 않음
SELECT price AS "C 수강료"
FROM SummerPrice
WHERE class = 'C';
