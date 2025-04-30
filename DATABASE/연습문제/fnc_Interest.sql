CREATE OR REPLACE FUNCTION fnc_Interest(
  Price NUMBER
) RETURN INT
IS
  myInterest NUMBER;
BEGIN
  /* 가격이 30,000원 이상이면 10%, 미만이면 5% */
  IF Price >= 30000 THEN
    myInterest := Price * 0.1;
  ELSE
    myInterest := Price * 0.05;
  END IF;

  RETURN myInterest;
END;
/

SELECT custid, orderid, saleprice, fnc_Interest(saleprice) AS interest
FROM Orders;