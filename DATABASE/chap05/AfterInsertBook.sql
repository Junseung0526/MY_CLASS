-- Book 테이블에 행이 삽입된 직후 실행되는 AFTER INSERT 트리거 생성
CREATE OR REPLACE TRIGGER AfterInsertBook
AFTER INSERT ON Book
FOR EACH ROW  -- 삽입된 각 행마다 실행됨
BEGIN
    -- 새로 삽입된 데이터(:NEW)를 Book_log 테이블에 복사(백업)
    INSERT INTO Book_log (BOOKID_L, BOOKNAME_L, PUBLISHER_L, PRICE_L)
    VALUES (:NEW.bookid, :NEW.bookname, :NEW.publisher, :NEW.price);

    -- 삽입 완료 메시지를 서버 출력창에 표시 (SQL*Plus, SQL Developer에서 확인 가능)
    DBMS_OUTPUT.PUT_LINE('삽입 투플을 Book_log 테이블에 백업..');
END;
/

-- Book 테이블에 새 데이터 삽입 (트리거 자동 실행됨)
INSERT INTO Book VALUES(14, '스포츠 과학 1', '이상미디어', 25000);

-- 삽입된 BOOKID = 14 데이터 조회 (원본 테이블)
SELECT * FROM Book WHERE BOOKID = 14;

-- Book_log 테이블에서 삽입 시점의 백업 데이터 조회
SELECT * FROM Book_log WHERE BOOKID_L = 14;
