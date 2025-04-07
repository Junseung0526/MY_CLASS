--도서의 판매액 평균보다 자신의 구매액 평균이 더 높은 고객의 이름
--도서의 판매액 평균: 모든 주문의 평균 판매액
--자신의 구매액 평균: 각 고객이 구매한 주문의 구매액 평균

SELECT C.NAME
FROM CUSTOMER C
JOIN ORDERS O ON C.CUSTID = O.CUSTID
GROUP BY C.CUSTID, C.NAME
HAVING AVG(O.SALEPRICE) > (
    SELECT AVG(SALEPRICE)
    FROM ORDERS
)