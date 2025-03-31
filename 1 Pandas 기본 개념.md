# 1. Pandas 기본 개념

학습 상태: 학습중
복습 필요: No

### **1. Pandas 기본 개념**

### ✅ **1.1 Pandas 소개 및 설치**

Pandas는 **데이터 분석과 조작을 위한 파이썬 라이브러리**입니다.

- **주요 기능**: 데이터 로드, 정리, 변환, 분석
- **주요 객체**: `Series`(1차원), `DataFrame`(2차원)

📌 **설치하기**

```bash
pip install pandas
```

📌 **라이브러리 불러오기**

```python
import pandas as pd
```

---

### ✅ **1.2 데이터프레임(DataFrame)과 시리즈(Series) 개념**

📌 **Series (1차원 데이터)**

```python
data = pd.Series([10, 20, 30, 40])
print(data)
```

출력:

```
0    10
1    20
2    30
3    40
dtype: int64
```

- **인덱스(index)** 와 **값(value)** 으로 구성됨

📌 **DataFrame (2차원 데이터)**

```python
data = {
    '이름': ['철수', '영희', '민수'],
    '나이': [25, 24, 23],
    '점수': [90, 85, 88]
}
df = pd.DataFrame(data)
print(df)
```

출력:

```
   이름  나이  점수
0  철수  25  90
1  영희  24  85
2  민수  23  88
```

- 여러 개의 **Series가 모여서** DataFrame을 만듦

---

### ✅ **1.3 데이터프레임 생성 및 기본 정보 확인**

📌 **데이터프레임 기본 정보 확인**

```python
print(df.info())  # 데이터 타입 및 결측치 확인
print(df.describe())  # 기본 통계 정보
print(df.head(2))  # 상위 2개 행 출력
print(df.tail(2))  # 하위 2개 행 출력
```

📌 **데이터프레임 크기 확인**

```python
print(df.shape)  # (행 개수, 열 개수)
print(df.columns)  # 컬럼 이름 확인
print(df.index)  # 인덱스 확인
```