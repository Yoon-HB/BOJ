-- 코드를 작성해주세요
select t.ITEM_ID, ITEM_NAME
from ITEM_INFO i, ITEM_TREE t
where i.ITEM_ID = t.ITEM_ID and PARENT_ITEM_ID is NULL