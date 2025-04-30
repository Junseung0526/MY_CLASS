CREATE OR REPLACE PROCEDURE BookInsertOrUpdate(
    myBookID NUMBER,
    myBookName VARCHAR2,
    myPublisher VARCHAR2,
    myPrice INT
)
AS
    mycount NUMBER;
BEGIN
    SELECT COUNT(*) INTO mycount FROM Book
    WHERE bookname LIKE myBookName;

    IF mycount != 0 THEN
        UPDATE Book SET price = myPrice
        WHERE bookname LIKE myBookName;
    ELSE
        INSERT INTO Book(bookid, bookname, publisher, price)
        VALUES(myBookID, myBookName, myPublisher, myPrice);
    END IF;
END;
/

-- BookInsertOrUpdate 프로시저를 실행하여 테스트하는 부분
EXEC BookInsertOrUpdate(15, '스포츠 즐거움', '마당과학서적', 25000);
SELECT * FROM Book; -- 15번 투플 삽입 결과 확인

-- BookInsertOrUpdate 프로시저를 다시 실행하여 테스트하는 부분
EXEC BookInsertOrUpdate(15, '스포츠 즐거움', '마당과학서적', 20000);
SELECT * FROM Book; -- 15번 투플 가격 변경 확인