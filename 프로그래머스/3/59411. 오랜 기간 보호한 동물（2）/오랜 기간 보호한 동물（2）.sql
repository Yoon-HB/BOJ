-- 입양을 간 동물 중, 보호 기간이 가장 길었던 동물 두 마리의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 이때 결과는 보호 기간이 긴 순으로 조회
SELECT A.ANIMAL_ID, A.NAME
from (SELECT O.ANIMAL_ID, O.NAME, (O.DATETIME - I.DATETIME) AS TIME FROM ANIMAL_INS I, ANIMAL_OUTS O WHERE 
      I.ANIMAL_ID = O.ANIMAL_ID
      ORDER BY TIME DESC) A
LIMIT 2;

