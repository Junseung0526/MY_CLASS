SELECT SUM(B.price) AS 총구매액
FROM Orders O
JOIN Book B
ON O.bookid = B.bookid
WHERE O.custid = 1;