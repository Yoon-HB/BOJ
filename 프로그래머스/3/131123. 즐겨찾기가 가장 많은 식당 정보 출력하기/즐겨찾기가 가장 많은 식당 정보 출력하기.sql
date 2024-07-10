-- 코드를 입력하세요
SELECT a.FOOD_TYPE, a.REST_ID, a.REST_NAME, a.FAVORITES
from REST_INFO a
where a.FAVORITES in (select max(FAVORITES) from REST_INFO b where a.FOOD_TYPE = b.FOOD_TYPE group by FOOD_TYPE)
order by a.FOOD_TYPE desc