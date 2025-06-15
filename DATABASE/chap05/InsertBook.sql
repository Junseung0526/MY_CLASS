-- InsertBook 프로시저 정의 (이미 존재하면 덮어씀)
-- 입력 파라미터: 책 ID, 책 이름, 출판사, 가격
CREATE OR REPLACE PROCEDURE InsertBook(
    myBookID IN NUMBER,
    myBookName IN VARCHAR2,
    myPublisher IN VARCHAR2,
    myPrice IN NUMBER)
AS
BEGIN
    -- 입력 받은 값들을 Book 테이블에 삽입
    INSERT INTO Book(BOOKID, BOOKNAME, PUBLISHER, PRICE)
    VALUES(myBookID, myBookName, myPublisher, myPrice);
END;
/

-- 정의한 InsertBook 프로시저를 실행
-- (BOOKID=13, BOOKNAME='스포츠과학', PUBLISHER='마당과학서적', PRICE=25000)
EXEC InsertBook(13, '스포츠과학', '마당과학서적', 25000);

-- Book 테이블의 모든 데이터를 조회하여 삽입 결과 확인
SELECT * FROM Book;
