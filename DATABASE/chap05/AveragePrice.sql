CREATE OR REPLACE PROCEDURE AveragePrice(
    AverageVal OUT NUMBER
)
AS
BEGIN
    SELECT AVG(price) INTO AverageVal 
    FROM Book 
    WHERE price IS NOT NULL;
END;
/


SET SERVEROUTPUT ON;

DECLARE
    Average NUMBER;
BEGIN
    AveragePrice(Average);
    DBMS_OUTPUT.PUT_LINE('책값 평균: ' || Average);
END;
/
