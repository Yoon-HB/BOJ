SELECT ROUND(AVG(CASE 
                    WHEN LENGTH is null THEN 10 
                    ELSE LENGTH 
                 END),2) AS AVERAGE_LENGTH
FROM FISH_INFO;