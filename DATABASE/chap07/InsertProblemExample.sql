//삽입이상

-- 자바 강좌를 Summer 테이블에 삽입 (sid는 자동 생성되거나 NULL로 삽입됨)
INSERT INTO Summer VALUES (NULL, 'JAVA', 25000);

-- Summer 테이블 전체 조회 (삽입 결과 확인용)
SELECT *
FROM Summer;

-- 삽입 이상 예시: NULL이 포함되어 있어 실제 수강 학생 수와 COUNT 결과가 다를 수 있음

-- 1) COUNT(*)는 모든 행(투플)을 센다 → NULL 포함해서 총 5개 투플이므로 5가 출력됨
SELECT COUNT(*) AS "수강인원"
FROM Summer;

-- 2) COUNT(sid)는 sid가 NULL이 아닌 경우만 센다 → NULL인 sid는 제외됨 (예: 실제 수강 학생 수는 4명)
SELECT COUNT(sid) AS "수강인원"
FROM Summer;

-- 3) 동일한 COUNT(*) 사용 → NULL 여부와 관계없이 전체 행 수를 반환
SELECT COUNT(*) AS "수강인원"
FROM Summer;

-- 4) WHERE 절로 sid가 NULL이 아닌 투플만 센다 → 수강 학생이 확실히 존재하는 경우만 집계
SELECT COUNT(*) AS "수강인원"
FROM Summer
WHERE sid IS NOT NULL;