-- 더 이상 업그레이드할 수 없는 아이템의 아이템 ID(ITEM_ID), 아이템 명(ITEM_NAME), 아이템의 희귀도(RARITY)를 출력하는 SQL 이때 결과는 아이템 ID를 기준으로 내림차순 정렬

select I.ITEM_ID, I.ITEM_NAME, I.RARITY
from ITEM_INFO I, ITEM_TREE T
where I.ITEM_ID = T.ITEM_ID and T.PARENT_ITEM_ID is not null and I.ITEM_ID not in (select distinct(PARENT_ITEM_ID) from ITEM_TREE where PARENT_ITEM_ID is not null)
order by I.ITEM_ID desc;