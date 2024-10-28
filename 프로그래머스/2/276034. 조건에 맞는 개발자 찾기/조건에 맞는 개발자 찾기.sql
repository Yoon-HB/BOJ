-- DEVELOPERS 테이블에서 Python이나 C# 스킬을 가진 개발자의 정보
-- 개발자의 ID, 이메일, 이름, 성을 조회하는 SQL 문을 작성
-- ID를 기준으로 오름차순 정렬
select distinct ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS D JOIN SKILLCODES S ON D.SKILL_CODE & S.CODE
where S.NAME in ("C#", "Python")
order by ID