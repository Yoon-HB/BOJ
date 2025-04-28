-- 월별 잡은 물고기의 수와 월을 출력하는 SQL문
-- 결과는 월을 기준으로 오름차순 정렬

select count(*) as FISH_COUNT, MONTH(TIME) as MONTH
from FISH_INFO
group by MONTH
order by MONTH