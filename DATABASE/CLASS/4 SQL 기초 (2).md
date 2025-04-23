# 4. SQL 기초 (2)

날짜: 2025년 4월 2일
학습 상태: 완료
중요도: 중
복습 필요: No

## 🛠️ 데이터 정의어 (DDL)

### **🔹 CREATE TABLE** (테이블 생성)

새로운 테이블을 만들고 속성을 정의함.

```sql
CREATE TABLE NewBook (
    bookid NUMBER PRIMARY KEY,
    bookname VARCHAR2(20),
    publisher VARCHAR2(20),
    price NUMBER
);
```

### **🔹 ALTER TABLE** (테이블 수정)

기존 테이블에 속성을 추가/삭제/변경함.

```sql
ALTER TABLE NewBook ADD isbn VARCHAR2(13); -- 새로운 열 추가
ALTER TABLE NewBook MODIFY isbn NUMBER; -- 데이터 타입 변경
```

### **🔹 DROP TABLE** (테이블 삭제)

테이블과 데이터를 완전히 삭제함.

```sql
DROP TABLE NewBook;
```

##

## ⚡ 데이터 조작어 (DML)

### **🔹 INSERT** (데이터 삽입)

새로운 데이터를 테이블에 추가함.

```sql
INSERT INTO Book VALUES (1, '스포츠 의학', '한솔의학서적', 90000);
```

### **🔹 UPDATE** (데이터 수정)

기존 데이터의 값을 변경함.

```sql
UPDATE Customer SET address = '대한민국 부산' WHERE custid = 5;
```

### **🔹 DELETE** (데이터 삭제)

특정 조건을 만족하는 데이터를 삭제함.

```sql
DELETE FROM Customer WHERE custid = 5;
```

##

## 🔐 제약 조건 (Constraints)

- **PRIMARY KEY**: 기본키 설정 (중복 불가, NULL 불가)
- **FOREIGN KEY**: 외래키 설정 (다른 테이블의 키 참조)
- **NOT NULL**: NULL 값을 허용하지 않음
- **ON DELETE CASCADE**: 부모 테이블 삭제 시 자식 테이블도 함께 삭제

##

## 🔄 기타 핵심 SQL

### **🔹 자동 증가 값 (IDENTITY & SEQUENCE)**

### ✅ **IDENTITY** (Oracle 12c 이상)

```sql
CREATE TABLE Book (
    bookid NUMBER GENERATED AS IDENTITY PRIMARY KEY,
    bookname VARCHAR2(50),
    price NUMBER
);
```

### ✅ **SEQUENCE** (구버전에서 사용)

```sql
CREATE SEQUENCE bookid_seq START WITH 20 INCREMENT BY 1;
INSERT INTO Book VALUES (bookid_seq.NEXTVAL, '책 제목', '출판사', 123000);
```

### **🔹 TRUNCATE TABLE** (테이블 초기화)

테이블의 모든 데이터를 삭제하지만, 구조는 유지함.

```sql
TRUNCATE TABLE Book;
```

##

## 📝 **핵심 요약**

- **DDL (데이터 정의)**: `CREATE`, `ALTER`, `DROP`
- **DML (데이터 조작)**: `INSERT`, `UPDATE`, `DELETE`
- **제약 조건**: `PRIMARY KEY`, `FOREIGN KEY`, `NOT NULL`
- **자동 증가 값**: `IDENTITY`, `SEQUENCE`
- **삭제 관련 주의**: `DROP`(구조 포함 삭제) vs `TRUNCATE`(데이터만 삭제)
