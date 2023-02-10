/* clean up old tables;
   must drop tables with foreign keys first
   due to referential integrity constraints
*/

DROP TABLE IF EXISTS depositor;
DROP TABLE IF EXISTS borrower;
DROP TABLE IF EXISTS account;
DROP TABLE IF EXISTS branch;
DROP TABLE IF EXISTS loan;
DROP TABLE IF EXISTS customer;

CREATE TABLE account (
    account_number VARCHAR(15)   NOT NULL,
    branch_name    VARCHAR(15)   NOT NULL,
    balance        NUMERIC(12,2) NOT NULL,
    PRIMARY KEY (account_number)
);

CREATE TABLE branch (
    branch_name VARCHAR(15)   NOT NULL,
    branch_city VARCHAR(15)   NOT NULL,
    assets      NUMERIC(14,2) NOT NULL,
    PRIMARY KEY (branch_name)
);

CREATE TABLE customer (
    customer_name    VARCHAR(15) NOT NULL,
    customer_street  VARCHAR(12) NOT NULL,
    customer_city    VARCHAR(15) NOT NULL,
    PRIMARY KEY (customer_name)
);

CREATE TABLE loan (
    loan_number  VARCHAR(15)   NOT NULL,
    branch_name  VARCHAR(15)   NOT NULL,
    amount       NUMERIC(12,2) NOT NULL,
    primary key(loan_number)
);

CREATE TABLE depositor (
    customer_name  VARCHAR(15) NOT NULL,
    account_number VARCHAR(15) NOT NULL,
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (account_number) REFERENCES account(account_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name)
);

CREATE TABLE borrower (
    customer_name  VARCHAR(15) NOT NULL,
    loan_number    VARCHAR(15) NOT NULL,
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

/* populate relations */
INSERT INTO customer VALUES ('Jones', 'Main', 'Harrison');
INSERT INTO customer VALUES ('Smith', 'Main', 'Rye');
INSERT INTO customer VALUES ('Hayes', 'Main', 'Harrison');
INSERT INTO customer VALUES ('Curry', 'North', 'Rye');
INSERT INTO customer VALUES ('Lindsay', 'Park', 'Pittsfield');
INSERT INTO customer VALUES ('Turner', 'Putnam', 'Stamford');
INSERT INTO customer VALUES ('Williams', 'Nassau', 'Princeton');
INSERT INTO customer VALUES ('Adams', 'Spring', 'Pittsfield');
INSERT INTO customer VALUES ('Johnson', 'Alma', 'Palo Alto');
INSERT INTO customer VALUES ('Glenn', 'Sand Hill', 'Woodside');
INSERT INTO customer VALUES ('Brooks', 'Senator', 'Brooklyn');
INSERT INTO customer VALUES ('Green', 'Walnut', 'Stamford');
INSERT INTO customer VALUES ('Jackson', 'University', 'Salt Lake');
INSERT INTO customer VALUES ('Majeris', 'First', 'Rye');
INSERT INTO customer VALUES ('McBride', 'Safety', 'Rye');

INSERT INTO branch VALUES ('Downtown', 'Brooklyn',  900000);
INSERT INTO branch VALUES ('Redwood', 'Palo Alto', 2100000);
INSERT INTO branch VALUES ('Perryridge', 'Horseneck', 1700000);
INSERT INTO branch VALUES ('Mianus', 'Horseneck',  400200);
INSERT INTO branch VALUES ('Round Hill', 'Horseneck', 8000000);
INSERT INTO branch VALUES ('Pownal', 'Bennington',  400000);
INSERT INTO branch VALUES ('North Town', 'Rye', 3700000);
INSERT INTO branch VALUES ('Brighton', 'Brooklyn', 7000000);
INSERT INTO branch VALUES ('Central', 'Rye',  400280);

INSERT INTO account VALUES ('A-101', 'Downtown', 500);
INSERT INTO account VALUES ('A-215', 'Mianus', 700);
INSERT INTO account VALUES ('A-102', 'Perryridge', 400);
INSERT INTO account VALUES ('A-305', 'Round Hill', 350);
INSERT INTO account VALUES ('A-201', 'Perryridge', 900);
INSERT INTO account VALUES ('A-222', 'Redwood', 700);
INSERT INTO account VALUES ('A-217', 'Brighton', 750);
INSERT INTO account VALUES ('A-333', 'Central', 850);
INSERT INTO account VALUES ('A-444', 'North Town', 625);

INSERT INTO depositor VALUES ('Johnson', 'A-101');
INSERT INTO depositor VALUES ('Smith', 'A-215');
INSERT INTO depositor VALUES ('Hayes', 'A-102');
INSERT INTO depositor VALUES ('Hayes', 'A-101');
INSERT INTO depositor VALUES ('Turner', 'A-305');
INSERT INTO depositor VALUES ('Johnson', 'A-201');
INSERT INTO depositor VALUES ('Jones', 'A-217');
INSERT INTO depositor VALUES ('Lindsay', 'A-222');
INSERT INTO depositor VALUES ('Majeris', 'A-333');
INSERT INTO depositor VALUES ('Smith', 'A-444');

INSERT INTO loan VALUES ('L-17', 'Downtown', 1000);
INSERT INTO loan VALUES ('L-23', 'Redwood', 2000);
INSERT INTO loan VALUES ('L-15', 'Perryridge', 1500);
INSERT INTO loan VALUES ('L-14', 'Downtown', 1500);
INSERT INTO loan VALUES ('L-93', 'Mianus', 500);
INSERT INTO loan VALUES ('L-11', 'Round Hill', 900);
INSERT INTO loan VALUES ('L-16', 'Perryridge', 1300);
INSERT INTO loan VALUES ('L-20', 'North Town', 7500);
INSERT INTO loan VALUES ('L-21', 'Central', 570);

INSERT INTO borrower VALUES ('Jones', 'L-17');
INSERT INTO borrower VALUES ('Smith', 'L-23');
INSERT INTO borrower VALUES ('Hayes', 'L-15');
INSERT INTO borrower VALUES ('Jackson', 'L-14');
INSERT INTO borrower VALUES ('Curry', 'L-93');
INSERT INTO borrower VALUES ('Smith', 'L-11');
INSERT INTO borrower VALUES ('Williams', 'L-17');
INSERT INTO borrower VALUES ('Adams', 'L-16');
INSERT INTO borrower VALUES ('McBride', 'L-20');
INSERT INTO borrower VALUES ('Smith', 'L-21');
