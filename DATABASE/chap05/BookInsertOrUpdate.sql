CREATE OR REPLACE PROCEDURE BookInsertOrUpdate(
    myBookID     IN NUMBER,
    myBookName   IN VARCHAR2,
    myPublisher  IN VARCHAR2,
    myPrice      IN NUMBER
)
AS
    myCount NUMBER;
BEGIN
    SELECT COUNT(*) INTO myCount 
    FROM Book
    WHERE bookname = myBookName;

    IF myCount != 0 THEN
        UPDATE Book 
        SET price = myPrice 
        WHERE bookname = myBookName;
    ELSE
        INSERT INTO Book(BOOKID, BOOKNAME, PUBLISHER, PRICE)
        VALUES (myBookID, myBookName, myPublisher, myPrice);
    END IF;
END;
/
