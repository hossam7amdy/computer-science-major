-- [Problem 5]

-- DROP TABLE commands:
DROP TABLE IF EXISTS ticket_info;
DROP TABLE IF EXISTS ticket;
DROP TABLE IF EXISTS traveler;
DROP TABLE IF EXISTS purchase;
DROP TABLE IF EXISTS purchaser;
DROP TABLE IF EXISTS customer_phone;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS seat;
DROP TABLE IF EXISTS flight;
DROP TABLE IF EXISTS aircraft;

-- CREATE TABLE commands:

-- Represents data for types of aircraft used for flights.
CREATE TABLE aircraft (
    aircraft_type CHAR(3) NOT NULL,
    -- Eg. Boeing, Airbus
    manufacturer VARCHAR(20) NOT NULL,
    -- Model of aircraft, eg. A380
    model VARCHAR(20) NOT NULL,
    PRIMARY KEY (aircraft_type),
    UNIQUE (manufacturer, model)
);

-- Represents information for flights.
CREATE TABLE flight (
    flight_number VARCHAR(10) NOT NULL,
    flight_date DATE NOT NULL,
    flight_time TIME NOT NULL,
    -- IATA airport code, eg. LAX
    `source` CHAR(3) NOT NULL,
    -- IATA airport code, eg. LAX
    dest CHAR(3) NOT NULL,
    -- Flag if flight is international
    international BOOL NOT NULL, 
    aircraft_type CHAR(3) NOT NULL,
    PRIMARY KEY (flight_number, flight_date),
    FOREIGN KEY (aircraft_type) REFERENCES aircraft(aircraft_type)
);

-- Represents information for the seats available on flights.
CREATE TABLE seat (
    flight_number VARCHAR(10) NOT NULL,
    flight_date DATE NOT NULL,
    seat_number VARCHAR(3) NOT NULL,
    -- Class of seat, eg. "First Class"
    seat_class VARCHAR(30) NOT NULL,
    -- Type of seat, eg. "Aisle"
    seat_type VARCHAR(10) NOT NULL,
    -- Flag if seat is on exit row 
    exit_flag BOOL NOT NULL,
    PRIMARY KEY (flight_number, flight_date, seat_number),
    FOREIGN KEY (flight_number, flight_date) REFERENCES flight(flight_number, flight_date),
    CHECK (seat_type IN ('Aisle', 'Middle', 'Window'))
);

-- Represents data for customers of the airline.
-- A customer can be a purchaser and/or a traveler.
CREATE TABLE customer (
    cust_id INT AUTO_INCREMENT NOT NULL,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    email VARCHAR(50) NOT NULL,
    PRIMARY KEY (cust_id)
);

-- Represents data for the contact phone numbers of customers.
-- Each customer can have one or more phone numbers.
CREATE TABLE customer_phone (
    cust_id INT AUTO_INCREMENT NOT NULL,
    phone_no VARCHAR(20) NOT NULL,
    PRIMARY KEY (cust_id, phone_no),
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

-- Represents data for purchasers, customers who purchase tickets.
CREATE TABLE purchaser (
    cust_id INT AUTO_INCREMENT NOT NULL,
    -- Credit card number
    card_number NUMERIC(16,0),
    -- Credit card expiration date MM/YY
    exp_date CHAR(5),
    -- Credit card 3-digit verification code
    verif_code NUMERIC(3,0),
    PRIMARY KEY (cust_id),
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

-- Represents data for travelers, customers who use the tickets.
CREATE TABLE traveler (
    cust_id INT AUTO_INCREMENT NOT NULL,
    passport_no VARCHAR(20),
    -- Passport country of citizenship
    citizenship VARCHAR(50), 
    -- Emergency contact name
    emergency_name VARCHAR(100),
    -- Emergency contact phone number
    emergency_phone VARCHAR(20),
    freq_flyer_no CHAR(7),
    PRIMARY KEY (cust_id),
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
	UNIQUE (passport_no)
);

-- Represents data for purchase.
-- A purchase can contain one more more tickets.
CREATE TABLE purchase (
    purchase_id INT NOT NULL,
    cust_id INT AUTO_INCREMENT NOT NULL,
    purchase_date TIMESTAMP NOT NULL,
    -- Purchase confirmation number
    conf_number CHAR(6) NOT NULL,
    PRIMARY KEY (purchase_id),
    UNIQUE (conf_number),
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

-- Represents data for purchase information for tickets.
CREATE TABLE ticket (
    ticket_id INT NOT NULL,
    price NUMERIC(10, 2) NOT NULL,
    purchase_id INT NOT NULL,
    cust_id INT NOT NULL,
    PRIMARY KEY (ticket_id),
    FOREIGN KEY (purchase_id) REFERENCES purchase(purchase_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE 
);

-- Represents data for flight information of a ticket.
CREATE TABLE ticket_info (
    ticket_id INT NOT NULL,
    seat_number VARCHAR(3) NOT NULL,
    flight_number VARCHAR(10) NOT NULL,
    flight_date DATE NOT NULL,
    aircraft_type CHAR(3) NOT NULL,
    PRIMARY KEY (ticket_id),
    FOREIGN KEY (ticket_id) REFERENCES ticket(ticket_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
	FOREIGN KEY (flight_number, flight_date) REFERENCES flight(flight_number, flight_date)
	    ON UPDATE CASCADE
        ON DELETE CASCADE,
	FOREIGN KEY (flight_number, flight_date, seat_number) REFERENCES
        seat(flight_number, flight_date, seat_number)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
	FOREIGN KEY (aircraft_type) REFERENCES aircraft(aircraft_type)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);