CREATE OR REPLACE TRIGGER AfterInsertBook
AFTER INSERT ON Book
FOR EACH ROW
BEGIN
    INSERT INTO Book_log (BOOKID_L, BOOKNAME_L, PUBLISHER_L, PRICE_L)
    VALUES (:NEW.bookid, :NEW.bookname, :NEW.publisher, :NEW.price);

    DBMS_OUTPUT.PUT_LINE('삽입 투플을 Book_log 테이블에 백업..');
END;
/

INSERT INTO Book VALUES(14,'스포츠 과학 1','이상미디어',25000);
SELECT * FROM Book WHERE BOOKID = '14';
SELECT * FROM Book_log WHERE BOOKID_L = '14';