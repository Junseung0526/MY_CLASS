SELECT ORDERID 
FROM ORDERS 
WHERE ORDERDATE
    NOT BETWEEN TO_DATE('2020-07-04', 'YYYY-MM-DD')AND
                TO_DATE('2020-07-07', 'YYYY-MM-DD');