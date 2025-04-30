# 5. SQL 고급

날짜: 2025년 4월 2일
학습 상태: 완료
중요도: 상
복습 필요: No

## 🔍 고급 SQL 개념

- 기본 SQL을 확장하여 **복잡한 쿼리, 최적화, 고급 함수** 등을 활용하는 방법
- 데이터 분석, 성능 향상, 트랜잭션 관리 등의 기능 포함

##

## 🏗️ 고급 SQL 기능

### **🔹 서브쿼리 (Subquery)**

쿼리 안에 또 다른 쿼리를 포함하여 데이터를 조회

```sql
SELECT bookname, price
FROM Book
WHERE price > (SELECT AVG(price) FROM Book);
```

### **🔹 JOIN (조인) - 테이블 결합**

여러 테이블에서 데이터를 가져와 연결

### ✅ **INNER JOIN** (공통 데이터만)

```sql
SELECT A.bookname, B.publisher
FROM Book A
INNER JOIN Publisher B ON A.publisher_id = B.publisher_id;
```

### ✅ **LEFT JOIN** (왼쪽 테이블 모든 데이터 + 오른쪽 일치하는 값)

```sql
SELECT A.bookname, B.publisher
FROM Book A
LEFT JOIN Publisher B ON A.publisher_id = B.publisher_id;
```

### ✅ **RIGHT JOIN** (오른쪽 테이블 모든 데이터 + 왼쪽 일치하는 값)

```sql
SELECT A.bookname, B.publisher
FROM Book A
RIGHT JOIN Publisher B ON A.publisher_id = B.publisher_id;
```

##

## 📊 집계 및 분석 함수

### **🔹 GROUP BY** (데이터 그룹화)

특정 컬럼을 기준으로 데이터를 그룹화

```sql
SELECT publisher, COUNT(*) AS book_count
FROM Book
GROUP BY publisher;
```

### **🔹 HAVING** (그룹 조건 설정)

`WHERE`와 유사하지만, `GROUP BY` 이후 필터링

```sql
SELECT publisher, COUNT(*) AS book_count
FROM Book
GROUP BY publisher
HAVING COUNT(*) > 5;
```

### **🔹 윈도우 함수 (Window Function)**

행 단위가 아닌 **그룹 내에서 순위 및 집계 연산** 수행

### ✅ **RANK()** (순위 부여)

```sql
SELECT bookname, price, RANK() OVER (ORDER BY price DESC) AS rank
FROM Book;
```

### ✅ **ROW_NUMBER()** (각 행 고유 번호)

```sql
SELECT bookname, price, ROW_NUMBER() OVER (PARTITION BY publisher ORDER BY price DESC) AS row_num
FROM Book;
```

##

## 🔄 트랜잭션 & 무결성

### **🔹 트랜잭션 (Transaction)**

데이터의 **일관성을 유지**하기 위한 작업 단위

- `COMMIT`: 변경 사항 저장
- `ROLLBACK`: 변경 사항 취소

```sql
BEGIN;
UPDATE Account SET balance = balance - 500 WHERE account_id = 1;
UPDATE Account SET balance = balance + 500 WHERE account_id = 2;
COMMIT;
```

### **🔹 INDEX (인덱스) - 조회 성능 향상**

데이터 검색 속도를 높이기 위해 컬럼에 인덱스 생성

```sql
CREATE INDEX idx_bookname ON Book(bookname);
```

##

## 📝 **핵심 요약**

- **서브쿼리**: 쿼리 안에 또 다른 쿼리 포함
- **JOIN**: 여러 테이블을 연결 (`INNER JOIN`, `LEFT JOIN`,`RIGHT JOIN`)
- **GROUP BY & HAVING**: 데이터 그룹화 및 조건 설정
- **윈도우 함수**: 순위(RANK), 행 번호(ROW_NUMBER) 계산
- **트랜잭션**: `COMMIT` (저장), `ROLLBACK` (취소)
- **인덱스**: 검색 속도 최적화
