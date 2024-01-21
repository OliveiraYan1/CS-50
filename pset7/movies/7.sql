SELECT rating, title
FROM ratings
INNER JOIN movies ON movie_id = id
WHERE year = 2010 AND rating > 0
ORDER BY
    rating DESC,
    title
