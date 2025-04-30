CREATE OR REPLACE TRIGGER AfterInsertBook
AFTER INSERT ON Book
FOR EACH ROW
DECLARE

BEGIN
    INSERT INTO Book_log
    VALUES(:new.bookid, :new.bookname, :new.publisher, :new.price);

    DBMS_OUTPUT.PUT_LINE('삽입 투플을 BOOK_LOG 테이블에 백업..');
END;
/

-- 트리거 테스트: Book 테이블에 삽입
INSERT INTO Book VALUES(14, '스포츠 과학 1', '이상미디어', 25000);

-- Book 테이블 확인
SELECT * FROM Book WHERE bookid = 14;

-- Book_log 테이블 확인
SELECT * FROM Book_log WHERE bookid_l = 14;
