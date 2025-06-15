--고객의 주문 총액을 계산하여 20,000원 이상이면 ‘우수’,
--20,000원 미만이면 ‘보통’을 반환하는 함수 Grade()를 작성하시오
--Grade()를 호출하여 고객의 이름과 등급을 보이는 SQL 문도 작성

CREATE OR REPLACE FUNCTION Grade(p_custid IN NUMBER)
RETURN VARCHAR2
AS
    v_total NUMBER := 0;
BEGIN
    SELECT NVL(SUM(saleprice), 0) INTO v_total
    FROM Orders
    WHERE custid = p_custid;

    IF v_total >= 20000 THEN
        RETURN '우수';
    ELSE
        RETURN '보통';
    END IF;
END;
/
