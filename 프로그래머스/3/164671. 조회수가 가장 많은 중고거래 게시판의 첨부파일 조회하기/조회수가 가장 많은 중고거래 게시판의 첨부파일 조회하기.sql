-- 조회수가 가장 높은 중고거래 게시물에 대한 첨부파일 경로를 조회하는 SQL문
-- FILE ID를 기준으로 내림차순 정렬
-- 게시글 ID를 기준으로 디렉토리가 구분되고, 파일이름은 파일 ID, 파일 이름, 파일 확장자로 구성되도록 출력

SELECT concat("/home/grep/src/", B.BOARD_ID, "/", F.FILE_ID, F.FILE_NAME, F.FILE_EXT ) AS FILE_PATH
FROM USED_GOODS_BOARD B, USED_GOODS_FILE F
WHERE B.BOARD_ID = F.BOARD_ID AND B.VIEWS = (SELECT MAX(VIEWS) FROM USED_GOODS_BOARD)
ORDER BY F.FILE_ID DESC;

