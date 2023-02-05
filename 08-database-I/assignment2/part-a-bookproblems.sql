-- Exercises 3.11 & 3.12 Uses University Schema
-- Exercise 3.21 Uses Liberary Schema

-- [Exercise 3.11a] 
-- Find the names of all students who have taken at least one Comp.
-- Sci. course; make sure there are no duplicate names in the result.
SELECT DISTINCT name
  FROM student
  JOIN takes USING (ID)
  WHERE dept_name = 'Comp. Sci.'

-- [Exercise 3.11b] 
-- For each department, find the maximum salary of instructors in that department. 
-- You may assume that every department has at least one instructor.
SELECT dept_name, max(salary) AS maximum_salary
  FROM instructor
  JOIN department USING (dept_name)
  GROUP BY dept_name
  ORDER BY maximum_salary

-- [Exercise 3.11d] 
-- For the lowest, across all departments, of the per-department maximum salary computed by the preceding query.
-- You should actually include the query from part c; you can't just pretend it has a name (or use a view, etc.).
SELECT dept_name, max(salary) AS maximum_salary
  FROM instructor
  JOIN department USING (dept_name)
  GROUP BY dept_name
  ORDER BY maximum_salary
  LIMIT 1


-- [Exercise 3.12a]
-- Create a new course “CS-001”, titled “Weekly Seminar”, with 0 credits.
-- The course ID is “CS-001”, which is stored as a string.
INSERT INTO course (course_id, title, dept_name, credits) 
            VALUES('CS-001','Weekly Seminar','Comp. Sci.',0)

-- [Exercise 3.12b]
-- Create a section of this course in Autumn 2009, with sec_id of 1.
INSERT INTO section (course_id,sec_id,semester,year) 
            VALUES('CS-001',1,'Autumn',2009)

-- [Exercise 3.12c]
-- c) Enroll every student in the Comp.Sci. department in the above section.
--    Don't forget the INSERT ... SELECT statement.
INSERT INTO takes (ID, course_id, sec_id, semester, year)
 SELECT ID, course_id, sec_id, semester, year
 FROM student, section
 where course_id = 'CS-001' AND dept_name = 'Comp. Sci.'

-- [Exercise 3.12d]
-- Delete enrollments in the above section where the student's name is Chavez.
--    You would normally also want to update the student's tot_cred "total credits" value, 
--    but since CS-001 is worth 0 credits, just concentrate on removing the appropriate rows from the takes table.
DELETE FROM takes 
  WHERE ID = (SELECT ID
              FROM student
              WHERE name = 'Chavez');

-- [Exercise 3.12e]
-- Delete the course CS-001. What will happen if you run this delete
-- statement  without first deleting offerings (sections) of this course?

-- database will denie the request duo to referential integrity constraint
-- we can solve this by 1- delete it manualy from `section` table
--                      2- add ON DELETE CASCADE
DELETE FROM course WHERE course_id = 'CS-001';

-- [Exercise 3.12f]
-- Delete all takes tuples corresponding to any section of any course with the 
-- word "database" as a part of the title
DELETE FROM takes 
WHERE course_id = (SELECT course_id
                   FROM course
                   WHERE title LIKE '%database%')


-- [Exercise 3.21a]
-- Retrieve the names of members who have borrowed `any` book published 
-- by "McGraw-Hill".
SELECT DISTINCT m.name
 FROM member m, book b, borrowed br
 WHERE m.memb_no = br.memb_no 
  AND b.isbn = br.isbn 
  AND publisher = 'McGraw-Hill';

-- [Exercise 3.21b]
-- Retrieve the names of members who have borrowed `all` books published 
-- by "McGraw-Hill".
SELECT name
  FROM member m, book b, borrowed br
  WHERE m.memb_no=br.memb_no AND b.isbn=br.isbn AND publisher='McGraw-Hill'
  GROUP BY name
  HAVING COUNT(*) = (SELECT COUNT(*) FROM book WHERE publisher='McGraw-Hill')

-- [Exercise 3.21c]
-- For each publisher, retrieve the names of members who have borrowed 
-- more than five books of that publisher.
SELECT m.name, bk.publisher
 FROM member m, borrowed b, book bk
 WHERE m.memb_no=b.memb_no AND bk.isbn=b.isbn
 GROUP BY m.name, bk.publisher
 HAVING COUNT(bk.isbn) > 5;

-- [Exercise 3.21d]
-- Compute the average number of books borrowed per member?
SELECT COUNT(*) * 1.0 / (SELECT COUNT(*) FROM member)
  FROM borrowed;