SELECT COUNT(*) AS Moviesthathasrating10
FROM movies
WHERE id IN(SELECT movie_id FROM ratings WHERE rating = 10)

