-- 코드를 입력하세요
SELECT count(a.NAME)
from (select distinct name from ANIMAL_INS where NAME is not null) a
