-- # Part	A: [Submit	Intervals]

-- 1) min_submit_interval
CREATE FUNCTION `min_submit_interval`(sub_id INT) RETURNS int
    DETERMINISTIC
BEGIN
	DECLARE min_interval INTEGER DEFAULT POWER(2, 31) - 1;
	DECLARE cur_time INTEGER DEFAULT 0;
    DECLARE prev_time INTEGER DEFAULT 0;
    DECLARE done INT DEFAULT 0;
    DECLARE sub_count INT DEFAULT 0;
    
    DECLARE cur CURSOR FOR
		SELECT UNIX_TIMESTAMP(f.sub_date) time_stamp
		FROM grades.fileset AS f
        WHERE f.sub_id = sub_id
		ORDER BY time_stamp ASC;
	
    DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' 
		SET done = 1;
	
	OPEN cur;
		WHILE NOT done DO
			FETCH cur INTO cur_time;
			IF NOT done THEN
				SET min_interval = LEAST(min_interval, cur_time - prev_time);
				SET prev_time = cur_time;
                SET sub_count = sub_count + 1;
			END IF;
		END WHILE;
	CLOSE cur;
    
    IF sub_count < 2 
		THEN return NULL;
	END IF;
    
    RETURN min_interval;
END

-- 2) max_submit_interval
CREATE FUNCTION `max_submit_interval`(sub_id INT) RETURNS int
    DETERMINISTIC
BEGIN
  DECLARE max_interval INTEGER DEFAULT 0;
  DECLARE cur_time INTEGER DEFAULT 0;
  DECLARE prev_time INTEGER DEFAULT 0;
  DECLARE done INT DEFAULT 0;
  DECLARE sub_count INT DEFAULT 0;
  
  DECLARE cur CURSOR FOR
    SELECT UNIX_TIMESTAMP(f.sub_date) time_stamp
    FROM grades.fileset AS f
        WHERE f.sub_id = sub_id
    ORDER BY time_stamp ASC;

  DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' 
    SET done = 1;
  
  OPEN cur;
    WHILE NOT done DO
      FETCH cur INTO cur_time;
      IF NOT done THEN
        SET max_interval = GREATEST(max_interval, cur_time - prev_time);
        SET prev_time = cur_time;
        SET sub_count = sub_count + 1;
      END IF;
    END WHILE;
  CLOSE cur;
    
  IF sub_count < 2 
    THEN return NULL;
  END IF;
    
  RETURN max_interval;
END

-- 3) avg_submit_interval
CREATE FUNCTION `avg_submit_interval`(sub_id INT) RETURNS double
    DETERMINISTIC
BEGIN
	declare avg_time DOUBLE default 0;
    
	SELECT 
		(MAX(UNIX_TIMESTAMP(sub_date)) - MIN(UNIX_TIMESTAMP(sub_date))) / COUNT(UNIX_TIMESTAMP(sub_date))
	INTO avg_time FROM
		fileset AS f
	WHERE
		f.sub_id = sub_id;
    
RETURN avg_time;
END

-- 4) improve performance
CREATE INDEX sub_idx ON fileset (sub_id, sub_date);