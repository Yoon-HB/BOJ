--  리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문
-- 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력
-- 리뷰 작성일을 기준으로 오름차순, 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬
SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE
FROM REST_REVIEW R
JOIN MEMBER_PROFILE M ON M.MEMBER_ID = R.MEMBER_ID
WHERE R.MEMBER_ID IN (
    SELECT MEMBER_ID
    FROM REST_REVIEW
    GROUP BY MEMBER_ID
    HAVING COUNT(*) = (
        SELECT MAX(review_count)
        FROM (
            SELECT COUNT(*) AS review_count
            FROM REST_REVIEW
            GROUP BY MEMBER_ID
        ) AS sub
    )
)
ORDER BY R.REVIEW_DATE ASC, R.REVIEW_TEXT ASC;