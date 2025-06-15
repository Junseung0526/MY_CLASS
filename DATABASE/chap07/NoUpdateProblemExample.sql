//수정이상 없음

-- FORTRAN 강좌의 수강료를 15000으로 수정
-- SummerPrice 테이블에는 과목별로 수강료가 한 번만 저장되어 있음
-- → FORTRAN 수강료를 단 한 곳에서만 수정하면 됨 → 수정 이상 없음
UPDATE SummerPrice
SET price = 15000
WHERE class = 'FORTRAN';

-- 수정된 FORTRAN 강좌 수강료를 확인
SELECT price AS "FORTRAN 수강료"
FROM SummerPrice
WHERE class = 'FORTRAN';