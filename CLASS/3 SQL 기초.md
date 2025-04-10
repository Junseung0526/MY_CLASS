# 3. SQL 기초

날짜: 2025년 3월 21일
학습 상태: 완료
중요도: 중
복습 필요: No

![03-01](https://github.com/user-attachments/assets/7c4584b1-4b3f-4610-a636-bbf8119a57c5)
## **1. SQL 개요**

- **SQL(Structured Query Language)**는 관계형 데이터베이스(RDB)에서 데이터를 **조작하고 관리하는 언어**다.

SQL은 순서가 없는 **비절차적 언어**로, 사용자가 원하는 데이터만 명시하면 DBMS가 내부적으로 처리한다.

SQL은 크게 **세 가지 주요 명령어**로 나뉜다.

1. **데이터 정의어(DDL: Data Definition Language)**
    - 테이블과 같은 데이터 구조를 정의 및 변경하는 명령어
    - `CREATE`, `ALTER`, `DROP`
2. **데이터 조작어(DML: Data Manipulation Language)**
    - 데이터를 조회, 삽입, 수정, 삭제하는 명령어
    - `SELECT`, `INSERT`, `UPDATE`, `DELETE`
3. **데이터 제어어(DCL: Data Control Language)**
    - 데이터 접근 권한을 부여하고 관리하는 명령어
    - `GRANT`, `REVOKE` (9장에서 학습 예정)

---

## **2. SQL 학습을 위한 환경 설정**

SQL 실습을 위해 **Oracle 21c XE 버전 및 SQL Developer**를 설치해야 한다.

**또한, 클라우드 기반의 Oracle Live SQL도 사용할 수 있음.**

[Oracle Live SQL 링크](https://livesql.oracle.com/apex/livesql/file/tutorial_M3ADKLLQOUBPGKW703FRHQRLQ.html)

실습 환경에서 사용하는 마당서점 데이터베이스에는 **세 개의 주요 테이블**이 있다.

| 테이블 | 설명 | 주요 속성 |
| --- | --- | --- |
| **Book** | 도서 정보 | `bookid`, `bookname`, `publisher`, `price` |
| **Customer** | 고객 정보 | `custid`, `name`, `address`, `phone` |
| **Orders** | 주문 정보 | `orderid`, `custid`, `bookid`, `saleprice`, `orderdate` |

---

## **3. SELECT 문 – 데이터 조회**

### **기본 SELECT 문법**

```sql
SELECT 열이름1, 열이름2
FROM 테이블이름;
```

모든 데이터를 조회할 경우 `*` 사용

```sql
SELECT * 
FROM Book;
```

### **조건 검색 - WHERE 절**

- 특정 조건에 맞는 데이터만 조회

```sql
SELECT * 
FROM Book 
WHERE price > 20000;
```

- 여러 조건을 조합할 수도 있음

```sql
SELECT * 
FROM Customer 
WHERE address = '서울' AND phone LIKE '010%';
```

- `IN`, `NOT IN`: 특정 값 포함 여부 확인

```sql
SELECT * 
FROM Book 
WHERE publisher IN ('굿스포츠', '대한미디어');
```

- `LIKE`: 패턴 검색

```sql
SELECT * 
FROM Book 
WHERE bookname LIKE '%축구%'; -- '축구' 포함 도서 검색
```

| 기호 | 의미 | 예제 | 설명 |
| --- | --- | --- | --- |
| `%` | **0개 이상의 문자**와 일치 | `'축구%'` | '축구'로 시작하는 모든 문자열 (ex. 축구의 역사, 축구 기술) |
| `_` | **한 글자**와 일치 | `'축구_'` | '축구' 뒤에 정확히 한 글자가 추가된 문자열 (ex. 축구왕, 축구법) |
| `[ ]` | **특정 문자 중 하나**와 일치 | `'축구[왕법]'` | '축구왕' 또는 '축구법' 검색 |
| `[^ ]` 또는 `[! ]` | **특정 문자를 제외** | `'축구[^왕]'` | '축구' 뒤에 '왕'이 아닌 문자 검색 (ex. 축구법, 축구장) |
| `-` | **범위 지정** | `'도서[0-9]'` | '도서0', '도서1' ~ '도서9' 검색 |
| `\` | **이스케이프 문자** (`%, _, [ ]`를 검색할 때 사용) | `'도서\%'` | '도서%'라는 문자열을 검색 |

---

## **4. 검색 결과 정렬 - ORDER BY**

검색 결과의 정렬이 필요할 경우 `ORDER BY` 사용

**ASC**, DESC(오름차순, 내림차순 정렬) 

```sql
SELECT * 
FROM Book 
ORDER BY price DESC;  -- 가격이 높은 순으로 정렬

SELECT * 
FROM Book 
ORDER BY publisher, bookname;  -- 출판사별, 도서명순 정렬
```

---

## **5. 집계 함수(Aggregate Functions) - 그룹별 데이터 처리**

SQL에서 데이터를 집계하는 주요 함수

| 함수 | 설명 |
| --- | --- |
| `SUM()` | 총합 계산 |
| `AVG()` | 평균값 계산 |
| `MIN()` | 최소값 |
| `MAX()` | 최대값 |
| `COUNT()` | 개수 세기 |

```sql
SELECT COUNT(*) 
FROM Orders; -- 전체 주문 건수

SELECT SUM(saleprice) 
FROM Orders; -- 총 판매액

SELECT AVG(price) 
FROM Book; -- 평균 가격
```

### **GROUP BY - 그룹별 데이터 처리**

`GROUP BY`를 사용하면 특정 속성을 기준으로 그룹화하여 집계할 수 있다.

```sql
SELECT publisher, COUNT(*) 
FROM Book 
GROUP BY publisher; -- 출판사별 도서 개수

SELECT custid, SUM(saleprice) 
FROM Orders 
GROUP BY custid; -- 고객별 총 구매액
```

💡 `HAVING` 절을 사용하여 특정 그룹만 필터링 가능

```sql
SELECT publisher, COUNT(*)
FROM Book
GROUP BY publisher
HAVING COUNT(*) > 5; -- 도서가 5권 이상인 출판사만 조회
```

---

## **6. 조인(JOIN) – 여러 테이블을 연결하여 조회**

### **INNER JOIN (동등 조인)**

두 개 이상의 테이블에서 **공통된 값이 있는 행만 결합**

```sql
SELECT Customer.name, Orders.saleprice
FROM Customer
INNER JOIN Orders ON Customer.custid = Orders.custid;
```

### **OUTER JOIN (외부 조인)**

한쪽 테이블에 해당하는 데이터가 없어도 결과에 포함

```sql
SELECT Customer.name, Orders.saleprice
FROM Customer
LEFT JOIN Orders ON Customer.custid = Orders.custid;
```

📌 `LEFT JOIN` → 왼쪽(Customer) 테이블의 모든 데이터 포함

📌 `RIGHT JOIN` → 오른쪽(Orders) 테이블의 모든 데이터 포함

---

## **7. 부속질의(Subquery) – 중첩된 SQL**

**부속질의**는 다른 `SELECT` 문 안에 포함된 `SELECT` 문을 의미한다.

```sql
SELECT bookname, price
FROM Book
WHERE price = (SELECT MAX(price) FROM Book);  -- 가장 비싼 도서 검색
```

📌 **상관 부속질의(Correlated Subquery)**

부속질의가 상위 질의의 각 행과 연관되어 실행됨

```sql
SELECT bookname 
FROM Book b
WHERE price > (SELECT AVG(price) 
FROM Book 
WHERE publisher = b.publisher);
```

---

## **8. SQL 연산 – 집합 연산 및 EXISTS**

| 연산자 | 설명 |
| --- | --- |
| `UNION` | 두 개의 `SELECT` 결과를 합침 (중복 제거) |
| `INTERSECT` | 두 개의 `SELECT` 결과 중 공통 데이터 |
| `MINUS` (`EXCEPT`) | 첫 번째 `SELECT` 결과에서 두 번째 `SELECT` 결과 제거 |

```sql
SELECT name 
FROM Customer MINUS
SELECT name 
FROM Orders 
JOIN Customer ON Orders.custid = Customer.custid;
```

**📌 결과: 주문하지 않은 고객 조회**

### **EXISTS와 NOT EXISTS**

- **EXISTS**: 특정 조건을 만족하는 데이터가 존재하는지 확인

```sql
SELECT name 
FROM Customer c
WHERE EXISTS (SELECT * FROM Orders o WHERE c.custid = o.custid);
```

- **NOT EXISTS**: 특정 조건을 만족하는 데이터가 없을 때

```sql
SELECT name 
FROM Customer c
WHERE NOT EXISTS (SELECT * FROM Orders o WHERE c.custid = o.custid);
```

---
