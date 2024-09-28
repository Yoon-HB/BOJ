-- FISH_INFO 테이블에서 가장 큰 물고기 10마리의 ID와 길이를 출력하는 SQL 문
-- (길이를 기준으로 내림차순 정렬하고, 길이가 같다면 물고기의 ID에 대해 오름차순 정렬)
select ID, LENGTH
from FISH_INFO
order by LENGTH desc, ID asc
limit 10
