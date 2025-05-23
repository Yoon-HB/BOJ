-- 서울에 위치한 식당들의 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를 조회하는 SQL문
-- 리뷰 평균점수는 소수점 세 번째 자리에서 반올림 해주시고 결과는 평균점수를 기준으로 내림차순 정렬해주시고, 평균점수가 같다면 즐겨찾기수를 기준으로 내림차순 정렬
SELECT I.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, SCORE
FROM REST_INFO I,
(SELECT REST_ID, ROUND(AVG(REVIEW_SCORE), 2) AS SCORE
FROM REST_REVIEW
GROUP BY REST_ID) R 
WHERE I.REST_ID = R.REST_ID AND ADDRESS LIKE "서울%"
ORDER BY SCORE DESC, FAVORITES DESC;