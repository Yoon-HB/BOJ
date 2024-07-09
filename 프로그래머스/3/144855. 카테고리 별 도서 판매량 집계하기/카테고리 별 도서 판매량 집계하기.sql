-- 코드를 입력하세요
SELECT b.CATEGORY, sum(SALES) as TOTAL_SALES
from BOOK b, BOOK_SALES bs
where b.BOOK_ID = bs.BOOK_ID and SALES_DATE LIKE '2022-01%'
group by CATEGORY
order by CATEGORY