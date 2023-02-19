-- DDL
DROP TABLE IF EXISTS participated;
DROP TABLE IF EXISTS accident;
DROP TABLE IF EXISTS owns;
DROP TABLE IF EXISTS car;
DROP TABLE IF EXISTS person;

CREATE TABLE person (
 driver_id  CHAR(10),
 name       VARCHAR(32)  NOT NULL,
 address    VARCHAR(255) NOT NULL,

 PRIMARY KEY(driver_id),
 CHECK (LENGTH(driver_id) = 10)
);

CREATE TABLE car (
 license    CHAR(7),
 model      VARCHAR(32),
 year       CHAR(4),

 PRIMARY KEY (license),
 CHECK (LENGTH(year) = 4),
 CHECK (LENGTH(license) = 7)
);

CREATE TABLE owns (
 driver_id  CHAR(10),
 license    CHAR(7),

 PRIMARY KEY (driver_id, license),
 FOREIGN KEY (license) 
    REFERENCES car(license) ON DELETE CASCADE 
                           ON UPDATE CASCADE,
 FOREIGN KEY (driver_id) 
    REFERENCES person(driver_id) ON DELETE CASCADE 
                                 ON UPDATE CASCADE
);

CREATE TABLE accident (
 report_number  INT AUTO_INCREMENT,
 date_occurred  TIMESTAMP DEFAULT NOW(),
 location       VARCHAR(255) NOT NULL,
 description    TEXT,

 PRIMARY KEY(report_number)
);

CREATE TABLE participated (
 license       CHAR(7),
 driver_id     CHAR(10),
 report_number INT,
 damage_amount DECIMAL(10,2),

 PRIMARY KEY (driver_id, license, report_number),
 FOREIGN KEY (license) 
    REFERENCES car (license) ON UPDATE CASCADE,
 FOREIGN KEY (driver_id) 
    REFERENCES person (driver_id) ON UPDATE CASCADE,
 FOREIGN KEY (report_number) 
    REFERENCES accident (report_number) ON UPDATE CASCADE
);

-- Test Data
INSERT INTO person VALUES
   ('0123456789','Hossam Hamdy','6th of October City, Giza, Egypt'),
   ('DING696969', 'Ing', '16 Stanley Beach Road, Hong Kong'),
   ('KILE984123', 'Kil', '32 Dasan-ro, Jung gu, Seoul'),
   ('JJKFC12345', 'Olatunji', 
   'Buckingham Palace, London SW1A 1AA, United Kingdom');

INSERT INTO car VALUES
   ('1234567','BMW',2023),
   ('BEAST69', 'Bugatti', 2022),
   ('8008I35', 'Mercedes', 2020);
    
INSERT INTO car(license) VALUES ('KSIFLY1');

INSERT INTO accident(date_occurred, location, description) VALUES
   (null, 'Dokki, Giza', ''),
   ('2015-04-28 04:12:34', 'Camden', 'Car totaled.'),
   ('2022-01-25 12:43:15', 'Wan Chai', 'Another car crashed into Ing.');

INSERT INTO accident(date_occurred, location) VALUES
    ('2020-07-12 14:23:59', 'Los Angeles');

INSERT INTO owns VALUES
   ('0123456789','1234567'),
   ('KILE984123', '8008I35'),
   ('JJKFC12345', 'KSIFLY1');

INSERT INTO participated(driver_id, license, report_number, damage_amount) VALUES 
   ('0123456789', '1234567', 1, 12.99),
   ('JJKFC12345', 'KSIFLY1', 2, 9999.99),
   ('KILE984123', '8008I35', 3, 1.00);
    
INSERT INTO participated(driver_id, license, report_number) 
    VALUES ('DING696969', 'BEAST69', 4);

UPDATE person SET address = '1200 East California Boulevard' WHERE name = 'Ing';

UPDATE car SET license = 'KINGING' WHERE license = 'BEAST69';

DELETE FROM car WHERE license = 'KSIFLY1';