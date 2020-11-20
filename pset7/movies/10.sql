SELECT name FROM people 
WHERE id IN (SELECT person_id FROM directors
WHERE movie_id IN (SELECT movies.id FROM movies
JOIN ratings ON ratings.movie_id = movies.id 
WHERE ratings.rating >= 9.0));
