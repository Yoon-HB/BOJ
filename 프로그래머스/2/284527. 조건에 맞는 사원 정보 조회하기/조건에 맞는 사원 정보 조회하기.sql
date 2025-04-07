-- 2022년도 한해 평가 점수가 가장 높은 사원 정보를 조회
-- 2022년도 평가 점수가 가장 높은 사원들의 점수, 사번, 성명, 직책, 이메일을 조회하는 SQL문을 작성
-- 2022년도의 평가 점수는 상,하반기 점수의 합

SELECT S.TOTAL AS SCORE, E.EMP_NO, E.EMP_NAME, E.POSITION, E.EMAIL
FROM 
(SELECT EMP_NO, SUM(SCORE) AS TOTAL
FROM HR_GRADE
GROUP BY EMP_NO
ORDER BY TOTAL DESC
LIMIT 1) S,
HR_EMPLOYEES E
WHERE S.EMP_NO = E. EMP_NO