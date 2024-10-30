-- FISH_NAME_INFO에서 물고기의 종류 별 물고기의 이름과 잡은 수를 출력하는 SQL문
select COUNT(ID) as FISH_COUNT, N.FISH_NAME
from FISH_INFO F, FISH_NAME_INFO N
where F.FISH_TYPE = N.FISH_TYPE
group by N.FISH_NAME
order by FISH_COUNT desc;