-- 책 가격의 평균을 계산해 OUT 파라미터로 반환하는 프로시저 정의
CREATE OR REPLACE PROCEDURE AveragePrice(
    AverageVal OUT NUMBER  -- 계산된 평균값을 반환할 출력 파라미터
)
AS
BEGIN
    -- Book 테이블에서 price 컬럼의 평균값 계산 후 AverageVal에 저장
    -- NULL 값은 제외됨 (WHERE price IS NOT NULL)
    SELECT AVG(price) INTO AverageVal 
    FROM Book 
    WHERE price IS NOT NULL;
END;
/

-- DBMS_OUTPUT의 결과 출력을 위해 서버 출력 옵션 활성화
SET SERVEROUTPUT ON;

-- 익명 PL/SQL 블록 시작
DECLARE
    Average NUMBER;  -- 프로시저가 반환할 평균값을 받을 변수 선언
BEGIN
    -- AveragePrice 프로시저 호출하여 평균값을 Average 변수에 저장
    AveragePrice(Average);

    -- DBMS_OUTPUT.PUT_LINE으로 평균값을 화면에 출력
    DBMS_OUTPUT.PUT_LINE('책값 평균: ' || Average);
END;
/
