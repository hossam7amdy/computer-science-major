-- [Problem 1a]
-- Compute what would be a “perfect score” in the course, by adding up the perfect score values for all assignments,
-- quizzes and exams.
SELECT SUM(perfectscore) AS perectscore FROM assignment;

-- [Problem 1b]
-- Write a query that lists every section’s name, and how many students are in that section.
SELECT sec_name, COUNT(*) students
FROM section NATURAL JOIN student
GROUP BY sec_id

-- [Problem 1c]
-- Create a view named totalscores, which computes each student’s total score over all assignments in the course. 
-- The view’s result should contain each student’s username, and the total score for that student. 
CREATE VIEW score_totals AS
    SELECT username, SUM(score) AS totalscore
    FROM submission WHERE graded = 1
    GROUP BY username;

-- [Problem 1d]
-- This course happens to be pass/fail, and a passing grade is a total score of 40 or higher. 
-- Using the totalscores view, a view called passing which lists the usernames and scores of all students that are passing.
CREATE VIEW passing AS 
 SELECT username, totalscore
 FROM totalscores
 WHERE totalscore >= 40;

-- [Problem 1e]
-- Similarly, create a view called failing, which lists the usernames and scores of all students that are failing.
CREATE VIEW failing AS 
 SELECT username, totalscore
 FROM totalscores
 WHERE totalscore < 40;

-- [Problem 1f]
-- Write a SQL query that lists the usernames of all students that failed to submit work for at least 
-- one lab assignment, but still managed to pass the course.
SELECT username
FROM(
 SELECT DISTINCT username, shortname
 FROM submission
 JOIN assignment USING(asn_id)
 JOIN fileset USING(sub_id)
 WHERE shortname LIKE 'lab%'
 ) tmp
JOIN passing USING (username)
GROUP BY username
HAVING COUNT(*) < (SELECT COUNT(*) FROM assignment WHERE shortname LIKE 'lab%')

--
SELECT DISTINCT username 
FROM passing NATURAL JOIN submission
WHERE sub_id NOT IN
 (SELECT sub_id FROM fileset)
  AND asn_id IN
 (SELECT asn_id FROM assignment WHERE shortname LIKE 'lab%');

-- [Problem 1g]
-- Finally, for kicks, update and rerun this query to show all students that failed to submit either 
-- the midterm or the final, yet still managed to pass the course.
SELECT DISTINCT username 
FROM passing NATURAL JOIN submission
 WHERE sub_id NOT IN
(SELECT sub_id FROM fileset)
 AND asn_id IN
(SELECT asn_id FROM assignment WHERE shortname = 'midterm' OR shortname = 'final');

-- [Problem 2a]
SELECT DISTINCT username 
FROM submission NATURAL JOIN fileset NATURAL JOIN assignment
WHERE shortname = 'midterm' AND sub_date > due;

-- [Problem 2b]
SELECT EXTRACT(hour FROM sub_date) hour, COUNT(*) num_submits
FROM submission NATURAL JOIN fileset NATURAL JOIN assignment
WHERE shortname LIKE 'lab%'
GROUP BY hour;

-- [Problem 2c]
SELECT COUNT(*) num_submits
FROM submission NATURAL JOIN fileset NATURAL JOIN assignment
WHERE shortname = 'final' 
AND sub_date BETWEEN (due - INTERVAL 30 minute) AND due

-- [Problem 3a]
-- Add a column named “email” to the student table, which is a VARCHAR(200).  When you 
-- create the new column, allow NULL values.
-- Populate the new email column by concatenating the student’s username to “@school.edu”.
ALTER TABLE student ADD COLUMN email VARCHAR(200);
UPDATE student SET email = CONCAT(username, '@school.edu');
ALTER TABLE student MODIFY COLUMN email VARCHAR(200) NOT NULL;

-- [Problem 3b]
-- Add a column named “submit_files” to the assignment table, which is a BOOLEAN column.  
-- Make the default value TRUE.
ALTER TABLE assignment ADD COLUMN submit_files BOOLEAN DEFAULT TRUE;

-- Write an UPDATE command that sets all “daily quiz” assignments to have submit_files = FALSE.
UPDATE assignment SET submit_files = FALSE
WHERE shortname LIKE 'dq%'

-- [Problem 3c]
-- Create a new table “gradescheme” with the following columns:
-- • scheme_id (integer, primary key)
-- • scheme_desc (variable-length character field, max of 100 characters, not null)
CREATE TABLE gradescheme (
 scheme_id   INT PRIMARY KEY,
 scheme_desc VARCHAR(100) NOT NULL,
);

-- Insert the following rows into the new table:
INSERT INTO gradescheme VALUES
 (0, 'Lab assignment with min-grading.')
 (1, 'Daily quiz.')
 (2, 'Midterm or final exam.')

-- In the assignment table, rename the gradescheme column to be named “scheme_id”.
ALTER TABLE assignment CHANGE COLUMN gradescheme scheme_id NOT NULL;

-- Finally, add a foreign key constraint from assignment.scheme_id to the new 
-- gradescheme.scheme_id column.
ALTER TABLE assignment ADD FOREIGN KEY (scheme_id) REFERENCES gradescheme(scheme_id);

-- [Problem 4a]
-- Write a user-defined function named is_weekend that takes a DATE value and returns a BOOLEAN.
DELIMITER !
CREATE FUNCTION is_weekend(
d DATE
) RETURNS BOOLEAN
BEGIN
 IF WEEKDAY(d) = 5 OR WEEKDAY(d) = 6
  THEN RETURN TRUE;
 ELSE
  RETURN FALSE;
 END IF;
END !
DELIMITER ;

-- [Problem 4b]
DELIMITER !
CREATE FUNCTION `is_holiday`(
d DATE
) RETURNS varchar(100) DETERMINISTIC
BEGIN
 DECLARE day INT DEFAULT DAY(d);
 DECLARE month INT DEFAULT MONTH(d);
 DECLARE day_of_week INT DEFAULT DAYOFWEEK(d);
 DECLARE day_of_month INT DEFAULT DAYOFMONTH(d);
  
 IF month = 1 AND day = 1
  THEN RETURN `January 1: "New Year\'s Day"`;
 ELSEIF month = 7 AND day = 4
  THEN RETURN 'July 4: "Independence Day"';
 ELSEIF month = 5 AND day_of_month > 20 AND day_of_week = 2
  THEN RETURN 'The last Monday in May: "Memorial Day"';
 ELSEIF  month = 9 AND day_of_month < 7 AND day_of_week = 2
  THEN RETURN 'The first Monday in September: "Labor Day"';
 ELSEIF month = 11 AND day_of_month BETWEEN 22 AND 28 AND day_of_week = 5
  THEN RETURN 'The fourth Thursday in November: "Thanksgiving"';
 ELSE RETURN NULL;
 END IF ;
END !
DELIMITER ;


-- [Problem 5a]
-- Write a query that reports how many filesets were submitted on the various holidays recognized by your is_holiday() function.
SELECT is_holiday(sub_date) holiday, COUNT(*) submissions
FROM fileset
GROUP BY holiday

-- [Problem 5b]
-- Write another query that reports how many filesets were submitted on a weekend, and how many were not submitted on a weekend.
SELECT COUNT(*) submissions,
 CASE
  WHEN is_weekend(sub_date) = 1 THEN 'weekend'
  ELSE 'weekday'
 END is_weekend
FROM fileset
GROUP BY is_weekend