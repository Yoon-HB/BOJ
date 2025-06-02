-- 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문
-- 결과는 시간대 순으로 정렬

with recursive time
as(
    select 0 as HOUR
    union
    select HOUR +1 
    from time
    where HOUR < 23
)

SELECT t.hour AS HOUR, count(ANIMAL_ID) as count
from time t left join ANIMAL_OUTS A on HOUR(DATETIME) = t.HOUR 
group by HOUR
order by HOUR