# 개인 정리 파일

학습 상태: 학습중
복습 필요: No

### 1. **DDL (Data Definition Language)** - "건물 설계"

**DDL**은 **데이터베이스의 구조를 정의하는 명령어들**입니다.

**건물 설계**처럼 **데이터베이스 구조를 정의하거나 변경**하는 작업입니다.

### 주요 명령어:

- **CREATE**: 건물을 짓기 위한 **설계도**를 만드는 것처럼, 새로운 테이블, 데이터베이스 등을 생성하는 명령어입니다.
    
    ```sql
    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype
    );
    ```
    
- **ALTER**: 이미 지어진 건물에 **수정 작업**을 하는 것처럼, 테이블의 구조를 변경하는 명령어입니다. 예를 들어, 컬럼을 추가하거나 삭제하는 작업입니다.
    
    ```sql
    ALTER TABLE table_name ADD column_name datatype;
    ```
    
- **DROP**: 건물을 **철거**하는 것과 비슷합니다. 더 이상 필요 없는 테이블이나 데이터베이스를 삭제합니다.
    
    ```sql
    DROP TABLE table_name;
    ```
    
- **TRUNCATE**: 건물 안의 모든 물건을 **빼내는 것**처럼, 테이블의 모든 데이터를 삭제하지만 테이블 자체는 유지합니다.
    
    ```sql
    TRUNCATE TABLE table_name;
    ```
    

---

### 2. **DML (Data Manipulation Language)** - "건물 내부 작업"

**DML**은 **데이터베이스에 저장된 데이터를 수정, 조회, 삭제하는 명령어들**입니다.

**건물 내부의 가구나 물건을 수정, 배치, 추가하는 작업**과 비슷합니다.

### 주요 명령어:

- **SELECT**: 건물 안의 방을 **조사**하는 것처럼, 데이터를 조회하는 명령어입니다.
    
    ```sql
    SELECT column1, column2 FROM table_name;
    ```
    
- **INSERT**: 건물에 **새로운 가구**나 물건을 추가하는 것처럼, 새로운 데이터를 테이블에 삽입합니다.
    
    ```sql
    INSERT INTO table_name (column1, column2) VALUES (value1, value2);
    ```
    
- **UPDATE**: 이미 있는 가구를 **다시 배치**하는 것처럼, 데이터를 수정합니다.
    
    ```sql
    UPDATE table_name SET column1 = value1 WHERE condition;
    ```
    
- **DELETE**: 불필요한 물건을 **버리는** 것처럼, 데이터를 삭제합니다.
    
    ```sql
    DELETE FROM table_name WHERE condition;
    ```
    

---

### 3. **DCL (Data Control Language)** - "건물 관리자의 권한 부여"

**DCL**은 **데이터베이스 사용 권한을 관리하는 명령어들**입니다.

**건물 관리자**가 **입주자에게 권한을 부여**하거나 **권한을 취소**하는 것과 같습니다.

### 주요 명령어:

- **GRANT**: 건물의 **관리자**가 특정 사람에게 건물에 들어갈 수 있는 권한을 주는 것과 같아요. 사용자에게 특정 권한을 부여할 때 사용됩니다.
    
    ```sql
    GRANT SELECT, INSERT ON table_name TO user_name;
    ```
    
- **REVOKE**: 관리자 권한을 취소하는 것처럼, 사용자의 권한을 취소할 때 사용됩니다.
    
    ```sql
    REVOKE SELECT, INSERT ON table_name FROM user_name;
    ```
    

---

### 요약

| 구분 | 명령어 예시 | 비유 |
| --- | --- | --- |
| **DDL** | CREATE, ALTER, DROP, TRUNCATE | 건물 설계 및 수정, 철거 |
| **DML** | SELECT, INSERT, UPDATE, DELETE | 건물 내부 작업 (가구 추가/수정/삭제) |
| **DCL** | GRANT, REVOKE | 건물 관리자 권한 부여/취소 |

---

## ✅ **뷰(View)**

### 📌 **뷰(View)란?**

- 뷰(View)는 **테이블의 가상 테이블**로, 실제 데이터를 저장하지 않고 **쿼리의 결과를 테이블처럼** 사용할 수 있게 해주는 SQL 객체입니다.

즉, 복잡한 쿼리 결과를 저장해놓고 **조회**만 하는 용도로 사용됩니다.

### 비유:

- **뷰**는 마치 **미리 준비된 보고서**와 같아요. 이 보고서는 실제 데이터를 저장하지 않고, 필요한 순간마다 **동적으로 생성**됩니다.

### 📋 **뷰 생성**

```sql
CREATE VIEW view_name AS
SELECT column1, column2 FROM table_name WHERE condition;
```

### 📋 **뷰 조회**

```sql
SELECT * FROM view_name;
```

### 📋 **뷰 삭제**

```sql
DROP VIEW view_name;
```

### 📋 **뷰 사용 예시**

```sql
CREATE VIEW employee_view AS
SELECT employee_id, first_name, last_name FROM employees WHERE department_id = 10;
```

### ✅ **뷰 사용 이유**

- **복잡한 쿼리**를 한 번만 작성하고, 그 결과를 **반복 사용**할 수 있음
- **보안**: 민감한 데이터를 숨기고, 필요한 데이터만 제공
- **데이터 분석**: 특정 데이터를 자주 조회하는 경우 성능을 높일 수 있음

---

## ✅ **인덱스(Index)**

### 📌 **인덱스(Index)란?**

- *인덱스(Index)**는 테이블 내에서 **데이터 검색 속도를 향상**시키기 위한 데이터 구조입니다.

일반적으로 **검색 속도**를 높이기 위해 사용되며, 책의 **목차**와 같은 역할을 합니다.

### 비유:

- **인덱스**는 마치 **책의 목차**와 같습니다. 책의 내용이 어디에 있는지 빠르게 찾아주는 역할을 하죠. 책 내용을 직접 읽지 않고 목차만 보고 바로 원하는 부분을 찾을 수 있습니다.

### 📋 **인덱스 생성**

```sql
CREATE INDEX index_name ON table_name (column_name);
```

### 📋 **인덱스 삭제**

```sql
DROP INDEX index_name;
```

### 📋 **인덱스 사용 예시**

```sql
CREATE INDEX idx_employee_name ON employees (last_name);
```

### 📋 **복합 인덱스**

여러 개의 컬럼을 기준으로 인덱스를 생성할 수도 있습니다.

```sql
CREATE INDEX idx_employee_name_dept ON employees (last_name, department_id);
```

### ✅ **인덱스 사용 이유**

- **검색 속도 향상**: 특히 **WHERE 절**에서 자주 사용되는 컬럼에 인덱스를 추가하면 성능이 향상됨
- **정렬 속도 향상**: **ORDER BY** 절에 사용되는 컬럼에도 인덱스를 추가하면 정렬 성능이 빨라짐
- **유니크 제약 조건**: **PRIMARY KEY**나 **UNIQUE** 제약 조건을 사용할 때 인덱스가 자동으로 생성됨

### 📌 **인덱스의 단점**

- **성능 저하**: 인덱스는 데이터를 **삽입, 삭제, 수정할 때** 오버헤드를 발생시킴
- **디스크 공간 사용**: 인덱스를 추가하면 추가적인 **디스크 공간**이 필요함

---