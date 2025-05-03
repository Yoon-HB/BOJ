-- 할인율이 적용되는 대여 기간 종류로는 '7일 이상' (대여 기간이 7일 이상 30일 미만인 경우), '30일 이상' (대여 기간이 30일 이상 90일 미만인 경우), '90일 이상' (대여 기간이 90일 이상인 경우) 이 있습니다. 대여 기간이 7일 미만인 경우 할인정책이 없습니다.

-- 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고 30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차에 대해서 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트를 출력하는 SQL문

-- 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 자동차 종류를 기준으로 오름차순 정렬, 자동차 종류까지 같은 경우 자동차 ID를 기준으로 내림차순 정렬
SELECT 
    C.CAR_ID, 
    C.CAR_TYPE, 
    FLOOR(C.DAILY_FEE * 30 * (100 - CAST(REPLACE(P.DISCOUNT_RATE, '%', '') AS UNSIGNED)) / 100) AS FEE
FROM 
    CAR_RENTAL_COMPANY_CAR C, 
    CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
WHERE 
    C.CAR_TYPE = P.CAR_TYPE
    AND P.DURATION_TYPE = '30일 이상'
    AND C.CAR_TYPE IN ('세단', 'SUV')
    AND NOT EXISTS (
        SELECT *
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
        WHERE H.CAR_ID = C.CAR_ID
        AND H.START_DATE <= '2022-11-30'
        AND H.END_DATE >= '2022-11-01'
    )
HAVING 
    FEE >= 500000 AND FEE < 2000000
ORDER BY 
    FEE DESC, CAR_TYPE ASC, CAR_ID DESC;
