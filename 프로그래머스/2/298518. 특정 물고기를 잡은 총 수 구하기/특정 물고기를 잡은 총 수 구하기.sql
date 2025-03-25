-- FISH_INFO 테이블에서 잡은 BASS와 SNAPPER의 수를 출력하는 SQL 문
-- FISH_COUNT

select count(*) as FISH_COUNT
from FISH_INFO I, FISH_NAME_INFO N
where I.FISH_TYPE = N.FISH_TYPE and N.FISH_NAME in ("BASS", "SNAPPER")