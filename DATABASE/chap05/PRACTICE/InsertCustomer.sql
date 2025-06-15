--InsertBook() 프로시저를 수정하여 고객을 새로 등록하는
--InsertCustomer() 프로시저를 작성하시오

CREATE OR REPLACE PROCEDURE InsertCustomer(
    p_custid   IN NUMBER,
    p_name     IN VARCHAR2,
    p_address  IN VARCHAR2,
    p_phone    IN VARCHAR2
)
AS
    v_count NUMBER;
BEGIN
    -- 동일한 고객 ID가 이미 존재하는지 확인
    SELECT COUNT(*) INTO v_count
    FROM Customer
    WHERE custid = p_custid;

    IF v_count = 0 THEN
        -- 새로운 고객 등록
        INSERT INTO Customer (custid, name, address, phone)
        VALUES (p_custid, p_name, p_address, p_phone);
    ELSE
        DBMS_OUTPUT.PUT_LINE('이미 존재하는 고객입니다. 등록되지 않았습니다.');
    END IF;
END;
/