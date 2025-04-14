# STL 함수 정리표

학습 상태: 학습중
복습 필요: No

## ✅ STL 함수 정리표

| 카테고리 | 함수 | 설명 | 헤더 |
| --- | --- | --- | --- |
| 🔢 숫자 관련 | `std::max(a, b)` | 둘 중 큰 값 반환 | `<algorithm>` |
|  | `std::min(a, b)` | 둘 중 작은 값 반환 | `<algorithm>` |
|  | `std::swap(a, b)` | 두 변수의 값을 교환 | `<algorithm>` |
| 📊 배열/벡터 | `std::sort()` | 오름차순 정렬 | `<algorithm>` |
|  | `std::reverse()` | 순서 뒤집기 | `<algorithm>` |
|  | `std::max_element()` | 최댓값 요소 반복자 반환 | `<algorithm>` |
|  | `std::min_element()` | 최솟값 요소 반복자 반환 | `<algorithm>` |
|  | `std::accumulate()` | 요소 전체 합계 구하기 | `<numeric>` |
| 🔍 탐색 | `std::find()` | 특정 값 찾기 | `<algorithm>` |
|  | `std::count()` | 특정 값 등장 횟수 세기 | `<algorithm>` |
| 🔠 문자열 | `std::getline()` | 한 줄 전체 입력 | `<string>` |
|  | `s.length()` | 문자열 길이 | `<string>` |
|  | `s.substr(pos, len)` | 문자열 자르기 | `<string>` |
|  | `s.find("text")` | 문자열 내 위치 찾기 | `<string>` |

## ✅ STL 컨테이너 5대장 요약

| 이름 | 구조 | 특징 | 헤더 |
| --- | --- | --- | --- |
| `vector` | 동적 배열 | 배열처럼 쓰되, 크기 자동 증가 | `<vector>` |
| `list` | 이중 연결 리스트 | 삽입/삭제 빠름, 랜덤 접근 느림 | `<list>` |
| `deque` | 양방향 큐 | 앞뒤 삽입/삭제 빠름 | `<deque>` |
| `stack` | 후입선출(LIFO) | `push`, `pop`, `top` | `<stack>` |
| `queue` | 선입선출(FIFO) | `push`, `pop`, `front` | `<queue>` |

## 📌 컨테이너 + 예제들

### 1. 🔹 `vector<T>`

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    v.push_back(4);   // [1, 2, 3, 4]
    v.pop_back();     // [1, 2, 3]

    for (int x : v) {
        cout << x << " ";
    }
}
```

- 동적 배열처럼 크기 조절 가능
- `v.size()`, `v[i]`, `v.clear()`, `v.empty()` 등 사용 가능

---

### 2. 🔹 `list<T>`

```cpp
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> lst = {10, 20, 30};

    lst.push_front(5); // [5, 10, 20, 30]
    lst.push_back(40); // [5, 10, 20, 30, 40]

    for (int x : lst) {
        cout << x << " ";
    }
}
```

- `push_front()`, `push_back()` 모두 지원
- 삽입/삭제가 빠름 (중간도 가능)

---

### 3. 🔹 `deque<T>`

```cpp
#include <deque>
#include <iostream>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);  // [1, 2]
    dq.pop_front();   // [2]

    for (int x : dq) {
        cout << x << " ";
    }
}
```

- 앞뒤 삽입/삭제 모두 빠름
- 큐와 스택 역할 둘 다 가능

---

### 4. 🔹 `stack<T>`

```cpp
#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;  // 3
    s.pop();                  // [1, 2]
}
```

- LIFO 구조 (마지막에 넣은 게 먼저 나감)

---

### 5. 🔹 `queue<T>`

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;  // 1
    q.pop();                    // [2, 3]
}
```

- FIFO 구조 (먼저 넣은 게 먼저 나감)

---

### 6. 🔹 `priority_queue<T>` (우선순위 큐)

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(3);
    pq.push(1);
    pq.push(5);

    cout << pq.top() << endl;  // 5 (최댓값이 먼저)
}
```

- 자동으로 정렬됨 (기본: 큰 값이 먼저)
- `priority_queue<int, vector<int>, greater<int>>` 하면 최소 힙도 가능

---

### 7. 🔹 `set<T>`

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> s = {3, 1, 4, 1, 5};  // 중복 제거됨, 자동 정렬

    for (int x : s) {
        cout << x << " ";  // 1 3 4 5
    }
}
```

- 중복 없는 데이터 저장
- 자동 정렬

---

## 💡 STL 선택 기준 요약

| 원하는 기능 | 추천 STL |
| --- | --- |
| 동적 배열 | `vector` |
| 빠른 중간 삽입/삭제 | `list` |
| 양쪽 삽입/삭제 | `deque` |
| 후입선출 스택 | `stack` |
| 선입선출 큐 | `queue` |
| 정렬 + 중복X | `set` |
| 키-값 저장 | `map` |
