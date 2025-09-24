-- 부서별로 부서 ID, 영문 부서명, 평균 연봉을 조회하는 SQL문


select D.DEPT_ID, DEPT_NAME_EN, round(avg(E.SAL)) as AVG_SAL
from HR_DEPARTMENT D, HR_EMPLOYEES E
where D.DEPT_ID = E.DEPT_ID
group by E.DEPT_ID
ORDER BY AVG_SAL DESC;