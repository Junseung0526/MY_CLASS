-- 책 정보를 삽입하거나(신규 도서) 수정(가격 변경)하는 프로시저 정의
CREATE OR REPLACE PROCEDURE BookInsertOrUpdate(
    myBookID     IN NUMBER,
    myBookName   IN VARCHAR2,
    myPublisher  IN VARCHAR2,
    myPrice      IN NUMBER
)
AS
    myCount NUMBER;  -- 해당 도서명으로 검색한 결과 개수를 저장할 변수
BEGIN
    -- Book 테이블에서 입력받은 도서명이 존재하는지 개수 확인 후 myCount에 저장
    SELECT COUNT(*) INTO myCount 
    FROM Book
    WHERE bookname = myBookName;

    -- 도서명이 이미 존재하면 가격 정보만 업데이트
    IF myCount != 0 THEN
        UPDATE Book 
        SET price = myPrice 
        WHERE bookname = myBookName;
    ELSE
        -- 도서명이 없으면 새 도서 정보를 삽입
        INSERT INTO Book(BOOKID, BOOKNAME, PUBLISHER, PRICE)
        VALUES (myBookID, myBookName, myPublisher, myPrice);
    END IF;
END;
/
