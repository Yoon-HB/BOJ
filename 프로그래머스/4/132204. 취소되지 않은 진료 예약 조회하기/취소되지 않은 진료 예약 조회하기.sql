--  2022년 4월 13일 취소되지 않은 흉부외과(CS) 진료 예약 내역을 조회하는 SQL문을 작성
-- 진료예약번호, 환자이름, 환자번호, 진료과코드, 의사이름, 진료예약일시 항목이 출력되도록 작성
-- 진료예약일시를 기준으로 오름차순 정렬
SELECT APNT_NO, PT_NAME, P.PT_NO, A.MCDP_CD, DR_NAME, APNT_YMD
FROM PATIENT P, DOCTOR D, APPOINTMENT A
WHERE P.PT_NO = A.PT_NO  AND D.DR_ID = A.MDDR_ID
AND A.MCDP_CD = "CS" AND APNT_CNCL_YN = "N" AND APNT_YMD LIKE "%2022-04-13%"
ORDER BY APNT_YMD