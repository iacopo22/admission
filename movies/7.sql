SELECT title, rating FROM ratings JOIN movies ON ratings.movie_ID = id WHERE year = 2010
ORDER BY rating DESC, title ASC;
