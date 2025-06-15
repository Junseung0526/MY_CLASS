--BookInsertOrUpdate() 프로시저를 수정하여 삽입 작업을 수행하는
--프로시저를 작성하시오 (삽입하려는 도서와 동일한 도서가 있으면
--삽입하려는 도서의 가격이 높을 때만 새로운 값으로 변경함)

CREATE OR REPLACE PROCEDURE InsertOrUpdateBookByPrice(
    p_bookid     IN NUMBER,
    p_bookname   IN VARCHAR2,
    p_publisher  IN VARCHAR2,
    p_price      IN NUMBER
)
AS
    v_count NUMBER;
    v_old_price NUMBER;
BEGIN
    SELECT COUNT(*) INTO v_count
    FROM Book
    WHERE bookname = p_bookname;

    IF v_count = 0 THEN
        -- 책이 존재하지 않으면 삽입
        INSERT INTO Book (bookid, bookname, publisher, price)
        VALUES (p_bookid, p_bookname, p_publisher, p_price);
    ELSE
        -- 책이 존재하면 가격 비교 후 업데이트 여부 결정
        SELECT price INTO v_old_price
        FROM Book
        WHERE bookname = p_bookname;

        IF p_price > v_old_price THEN
            UPDATE Book
            SET price = p_price
            WHERE bookname = p_bookname;
        ELSE
            DBMS_OUTPUT.PUT_LINE('기존 가격이 더 높거나 같아서 변경하지 않음.');
        END IF;
    END IF;
END;
/
