--  사원별 성과금 정보를 조회
-- 사번, 성명, 평가 등급, 성과금을 조회하는 SQL문
-- 결과는 사번 기준으로 오름차순 정렬



WITH TBL AS  (
    SELECT EMP_NO,
    CASE
        WHEN SUM(SCORE)/2 >= 96 THEN "S"
        WHEN SUM(SCORE)/2 >= 90 AND SUM(SCORE)/2 < 96 THEN "A"
        WHEN SUM(SCORE)/2 >= 80 AND SUM(SCORE)/2 < 90 THEN "B"
        ELSE "C"
    END AS GRADE
    FROM HR_GRADE
    GROUP BY EMP_NO
)

select E.EMP_NO,
        E.EMP_NAME, GRADE,
        CASE 
            WHEN GRADE = "S" THEN SAL*0.2
            WHEN GRADE = "A" THEN SAL*0.15
            WHEN GRADE = "B" THEN SAL*0.1
            ELSE SAL*0
        END AS BONUS
FROM HR_EMPLOYEES E, TBL T
WHERE E.EMP_NO = T.EMP_NO
ORDER BY E.EMP_NO;


