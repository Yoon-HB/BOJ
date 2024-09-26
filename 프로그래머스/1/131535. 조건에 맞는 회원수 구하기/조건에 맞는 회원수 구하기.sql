--  2021년에 가입한 회원 중 나이가 20세 이상 29세 이하인 회원이 몇 명인지 출력하는 SQL문
SELECT COUNT(*) AS USERS
FROM USER_INFO
WHERE AGE <= 29 AND AGE >= 20 AND JOINED LIKE "2021%"