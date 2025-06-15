CREATE OR REPLACE FUNCTION fnc_Interest(
    Price NUMBER) RETURN INT
IS
    myInterset NUMBER;
BEGIN
    IF PRICE >= 30000 THEN myInterest := Price * 0.1;
    ELSE myInterest := Price * 0.05;
    END IF;
    RETURN myInterset;
END;
/

SELECT custid, orderid, saleprice, fnc_Interest(saleprice) interest
FROM Orders;fnc_Interest