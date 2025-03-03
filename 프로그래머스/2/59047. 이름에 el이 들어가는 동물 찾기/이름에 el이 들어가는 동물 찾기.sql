-- 이름에 "EL"이 들어가는 개의 아이디와 이름을 조회하는 SQL문
-- 이름 순
SELECT ANIMAL_ID, NAME
FROM   ANIMAL_INS
where NAME LIKE "%EL%" and ANIMAL_TYPE = "Dog"
ORDER BY NAME