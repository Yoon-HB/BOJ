-- 중고 거래의 총금액이 70만 원 이상인 사람의 회원 ID, 닉네임, 총거래금액을 조회
SELECT USER_ID, NICKNAME, sum(PRICE) as TOTAL_SALES
from USED_GOODS_BOARD, USED_GOODS_USER
where WRITER_ID = USER_ID and STATUS = 'DONE'
group by USER_ID, NICKNAME
having sum(PRICE) >= 700000
order by TOTAL_SALES