-- A simple table for testing the user-defined date functions.
-- The table is loaded with a handful of test dates listed below.

DROP TABLE IF EXISTS test_dates;

CREATE TABLE test_dates (
  test_date DATE        PRIMARY KEY,
  weekend   TINYINT,
  holiday   VARCHAR(20)
);

-- Neither weekends nor holidays.
INSERT INTO test_dates VALUES ('2005-05-12', 0, NULL);
INSERT INTO test_dates VALUES ('2008-12-31', 0, NULL);
INSERT INTO test_dates VALUES ('2004-08-02', 0, NULL);
INSERT INTO test_dates VALUES ('2007-01-18', 0, NULL);

-- Weekends and not holidays.
INSERT INTO test_dates VALUES ('2021-01-02', 0, NULL);
INSERT INTO test_dates VALUES ('2010-08-14', 1, NULL);
INSERT INTO test_dates VALUES ('2006-06-11', 1, NULL);
INSERT INTO test_dates VALUES ('2002-01-06', 1, NULL);
INSERT INTO test_dates VALUES ('2003-07-05', 1, NULL);
INSERT INTO test_dates VALUES ('2002-12-15', 1, NULL);

-- Holidays and not weekends.
INSERT INTO test_dates VALUES ('2021-01-01', 0, 'New Year''s Day');
INSERT INTO test_dates VALUES ('2001-11-22', 0, 'Thanksgiving');
INSERT INTO test_dates VALUES ('2002-07-04', 0, 'Independence Day');
INSERT INTO test_dates VALUES ('2002-09-02', 0, 'Labor Day');
INSERT INTO test_dates VALUES ('2005-05-30', 0, 'Memorial Day');
INSERT INTO test_dates VALUES ('2006-09-04', 0, 'Labor Day');
INSERT INTO test_dates VALUES ('2007-07-04', 0, 'Independence Day');
INSERT INTO test_dates VALUES ('2010-05-31', 0, 'Memorial Day');
INSERT INTO test_dates VALUES ('2010-11-25', 0, 'Thanksgiving');

-- Weekends and holidays.
INSERT INTO test_dates VALUES ('2000-01-01', 1, 'New Year''s Day');
INSERT INTO test_dates VALUES ('2021-07-04', 1, 'Independence Day');
INSERT INTO test_dates VALUES ('2006-01-01', 1, 'New Year''s Day');
INSERT INTO test_dates VALUES ('2010-07-04', 1, 'Independence Day');
