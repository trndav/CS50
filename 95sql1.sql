-- Run Sqlite3 commands in sqlite prompt as: .read 95sql1.sql

-- SELECT title FROM books;
-- SELECT id, title FROM books ORDER BY rating DESC;
-- SELECT id, title FROM books WHERE rating > 8 AND published > 2020-11-11;
-- SELECT AVG(rating) FROM books;
-- SELECT ROUND(AVG(rating), 2) FROM books;
-- SELECT SUM(rating) FROM books;
-- SELECT title FROM books JOIN author on books.id = author.id WHERE author = 'Bob';
-- SELECT author FROM author WHERE id = (SELECT id FROM books WHERE title = 'Teske boje');
-- SELECT books.title, rating, author.author FROM books JOIN author ON author.id = books.id WHERE author.author = "Bomb";
-- SELECT AVG(rating) FROM books JOIN author ON author.id = books.id WHERE author.author = 'Bob';
-- SELECT author FROM author WHERE author LIKE '%&%'; -- % Match any character
UPDATE books SET title = 'Bila jednom dva zmaja' WHERE title = 'Bio jednom jedan zmaj';