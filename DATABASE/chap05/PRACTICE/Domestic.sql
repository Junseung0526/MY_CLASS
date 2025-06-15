--고객의 주소를 이용하여 국내에 거주하면 ‘국내거주’, 해외에 거주하면
--‘국외거주’를 반환하는 함수 Domestic()을 작성하시오
--Domestic()을 호출하여 고객의 이름과 국내/국외 거주 여부를 출력

CREATE OR REPLACE FUNCTION Domestic(p_custid IN NUMBER)
RETURN VARCHAR2
AS
    v_address VARCHAR2(200);
BEGIN
    SELECT address INTO v_address
    FROM Customer
    WHERE custid = p_custid;

    IF v_address LIKE '%한국%' OR v_address LIKE '%서울%' OR v_address LIKE '%부산%' OR v_address LIKE '%대한민국%' THEN
        RETURN '국내거주';
    ELSE
        RETURN '국외거주';
    END IF;
END;
/

--Demestic()을 호출하여 국내 거주 고객의 판매 총액과 국외거주
--고객의 판매 총액을 출력하는 SQL 문을 작성하시오

SELECT 
    d.거주지구분,
    SUM(o.saleprice) AS 총판매액
FROM (
    SELECT c.custid, Domestic(c.custid) AS 거주지구분
    FROM Customer c
) d
JOIN Orders o ON d.custid = o.custid
GROUP BY d.거주지구분;