//수정이상: 일부만 수정하여 데이터 불일치 문제 발생

//만약 UPDATE 문을 다음과 같이 작성하면 데이터 불일치 문제가 발생
UPDATE SUMMER
SET PRICE = 15000
WHERE CLASS = "FORTRAN" AND SID = 100;

//SUMMER 테이블을 조회해 보면 FORTRAN 강좌의 수강료가 한 건만 수정됨
SELECT *
FROM SUMMER;

//FORTRAN 수강료를 조회하면 두 건이 나옴 (데이터 불일치 문제 발생)
SELECT PRICE "FORTRAN 수강료"
FROM SUMMER
WHERE CLASS = "FORTRAN";

//다음 실습에 의해 FORTRAN 강좌의 수강료를 다시 20,000원으로 복구
UPDATE SUMMER
SET PRICE = 20000
WHERE CLASS = "FORTRAN";

//다음 실습을 위해 SID 가 NULL인 투플 삭제
DELETE
FROM SUMMER
WHERE SID IS NULL;