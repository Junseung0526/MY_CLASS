--주문 금액의 총액과 주문의 평균 금액

SELECT  SUM(saleprice) AS TOTAL_PRICE,
        AVG(SALEPRICE) AS AVG_PRICE
FROM ORDERS