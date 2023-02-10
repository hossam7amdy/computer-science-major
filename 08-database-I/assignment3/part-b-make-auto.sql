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
INSERT INTO person VALUES('0123456789','Hossam Hamdy','6th of October City, Giza, Egypt');

CREATE TABLE car (
 license    CHAR(7),
 model      VARCHAR(32),
 year       CHAR(4),

 PRIMARY KEY (license),
 CHECK (LENGTH(year) = 4),
 CHECK (LENGTH(license) = 7)
);
INSERT INTO car VALUES('1234567','BMW',2023);

CREATE TABLE owns (
 driver_id  CHAR(10),
 license    CHAR(7),

 PRIMARY KEY (driver_id, license),
 FOREIGN KEY (license) 
    REFERENCES car(license) ON DELETE CASCADE ON UPDATE CASCADE,
 FOREIGN KEY (driver_id) 
    REFERENCES person(driver_id) ON DELETE CASCADE ON UPDATE CASCADE
);
INSERT INTO owns VALUES('0123456789','1234567');

CREATE TABLE accident (
 report_number  INT AUTO_INCREMENT,
 date_occurred  TIMESTAMP DEFAULT NOW(),
 location       VARCHAR(255) NOT NULL,
 description    TEXT,

 PRIMARY KEY(report_number)
);
INSERT INTO accident (location, description) VALUES('Dokki, Giza', 'I was driving slowly and he hitted me badly :D');

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
INSERT INTO participated VALUES('1234567', '0123456789', 1, 12.99);
