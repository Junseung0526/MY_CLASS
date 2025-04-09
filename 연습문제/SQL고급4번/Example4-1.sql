--판매가격이20,000원이상인도서의도서번호, 도서이름, 고객이름, 출판사, 판매가격을보여주는highorders뷰를생성하시오

 CREATE VIEW highorders
 AS SELECT  B.BOOKID,
            B.BOOKNAME,
            C.NAME,
            B.PUBLISHER,
            O.SALEPRICE
    FROM BOOK B,ORDERS O,CUSTOMER C
    WHERE B.BOOKID = O.BOOKID 
    AND O.CUSTID = C.CUSTID
    AND SALEPRICE >=20000
