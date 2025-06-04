-- 분화된 연도(YEAR), 분화된 연도별 대장균 크기의 편차(YEAR_DEV), 대장균 개체의 ID(ID) 를 출력하는 SQL 문을 작성
-- 분화된 연도별 가장 큰 대장균의 크기 - 각 대장균의 크기
select year(DIFFERENTIATION_DATE) AS YEAR, T.MAX - SIZE_OF_COLONY AS YEAR_DEV, ID
from ECOLI_DATA, (select YEAR(DIFFERENTIATION_DATE) as T_YEAR, max(SIZE_OF_COLONY) as MAX from ECOLI_DATA group by T_YEAR) as T
where T_YEAR = year(DIFFERENTIATION_DATE)
order by YEAR, YEAR_DEV;