//삭제 이상

//C 강좌 수강료 조회
SELECT price "C 수강료"
FROM Summer
WHERE CLASS = "C";

//200번 학생의 수강 신청 취소
DELETE FROM Summer
WHERE sid = 200;

//C 강좌 수강료 다시 조회
SELECT price "C 수강료"
FROM Summer
WHERE CLASS = "C";

//다음 실습을 위해 200번 학생 자료 다시 입력
INSERT INTO Summer VALUES (200,'C',10000);