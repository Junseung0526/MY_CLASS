SELECT BOOKNAME
FROM BOOK
WHERE BOOKID NOT IN (
    SELECT BOOKID
    FROM ORDERS
    WHERE CUSTID = 1
)