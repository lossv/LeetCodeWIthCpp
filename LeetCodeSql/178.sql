select Score, dense_rank() over(order by Score desc) as 'Rank' FROM Scores;

SELECT Score,
       (SELECT count(DISTINCT score) FROM Scores WHERE score >= s.score) AS 'Rank'
FROM Scores s
ORDER BY Score DESC;