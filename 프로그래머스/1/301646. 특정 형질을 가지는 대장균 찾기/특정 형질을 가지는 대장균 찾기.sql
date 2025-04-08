-- 2번 형질이 보유하지 않으면서 1번이나 3번 형질을 보유하고 있는 대장균 개체의 수(COUNT)를 출력하는 SQL 문
SELECT COUNT(*) AS COUNT
FROM ECOLI_DATA
WHERE (GENOTYPE & (1 << 1)) = 0         -- 2번 형질을 가지고 있지 않음
  AND (
        (GENOTYPE & (1 << 0)) > 0       -- 1번 형질을 가지고 있음
        OR
        (GENOTYPE & (1 << 2)) > 0       -- 3번 형질을 가지고 있음
      );