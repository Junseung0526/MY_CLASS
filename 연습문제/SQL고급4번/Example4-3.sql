--highorders뷰를변경하고자한다. 판매가격속성을삭제하는명령을 수행하시오. 삭제후(2)번SQL 문을다시수행하시오

CREATE OR REPLACE VIEW highorders
AS SELECT   B.BOOKID,  
            B.BOOKNAME,
            C.NAME,
            B.PUBLUSHER
    FROM BOOK B, ORDERS O, CUSTOMER C
    WHERE B.BOOKID = O.BOOKID
    AND 0.CUSTID = C.CUSTID
    AND SALEPRICE >= 20000