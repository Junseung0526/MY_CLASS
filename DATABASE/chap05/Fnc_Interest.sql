-- 이자 계산 함수 정의: 3만 원 이상이면 10%, 아니면 5%
CREATE OR REPLACE FUNCTION fnc_Interest(
    Price NUMBER
) RETURN NUMBER -- INT 대신 NUMBER가 오라클에서 일반적으로 사용됨
IS
    myInterest NUMBER;
BEGIN
    IF Price >= 30000 THEN
        myInterest := Price * 0.1;
    ELSE
        myInterest := Price * 0.05;
    END IF;
    RETURN myInterest; -- 변수명 오타 수정: myInterset → myInterest
END;
/

-- Orders 테이블에서 saleprice별로 이자 계산 결과를 함께 조회
SELECT 
    custid, 
    orderid, 
    saleprice, 
    fnc_Interest(saleprice) AS interest
FROM Orders;
