-- [Problem 1a]
-- Retrieve the loan-numbers and amounts of loans with amounts of at least $1000, and at most $2000.
SELECT loan_number, amount
 FROM loan
 WHERE amount >= 1000 AND amount <= 2000;

-- [Problem 1b]
-- Retrieve the loan-number and amount of all loans owned by Smith. Order the results by increasing loan number.
SELECT loan_number, amount
 FROM loan JOIN borrower 
 USING (loan_number)
 WHERE customer_name='Smith';

-- [Problem 1c]
-- Retrieve the city of the branch where account A-444 is open.
SELECT branch_city
 FROM branch JOIN account
 USING (branch_name)
 WHERE account_number='A-444'

-- [Problem 1d]
-- Retrieve the customer name, account number, branch name, and balance, of accounts owned by customers whose names start with “J”. 
-- Order the results by increasing customer name.
SELECT customer_name, account_number, branch_name, balance
 FROM depositor JOIN account
 USING (account_number)
 WHERE customer_name LIKE 'J%';

-- [Problem 1e]
-- Retrieve the names of all customers with more than five bank accounts.
SELECT customer_name
 FROM depositor
 GROUP BY customer_name
 HAVING count(*) > 5;



-- [Problem 2a]
-- A view called pownal_customers containing the account numbers and customer names
-- (but not the balances) for all accounts at the Pownal branch.
CREATE VIEW pownal_customers AS
 SELECT account_number, customer_name
  FROM depositor JOIN account
  USING (account_number)
  WHERE branch_name = 'Pownal';

-- [Problem 2b]
-- A view called onlyacct_customers containing the name, street, and city of all customers who have an account with the bank,
-- but do not have a loan.  This view can be defined such that it is updatable; for full points you must make sure that it is.
CREATE VIEW onlyacct_customers AS
SELECT * FROM customer
WHERE customer_name IN
 (SELECT customer_name FROM borrower
 EXCEPT
 SELECT customer_name FROM depositor)

-- [Problem 2c]
-- A view called branch_deposits that lists all branches in the bank, along with the total account balance of each branch, 
-- and the average account balance of each branch.   Make sure all computed values are given reasonable names in the view.
CREATE VIEW branch_deposits AS
SELECT *
 FROM 
 (SELECT branch_name, SUM(IFNULL(balance,0)) AS total_acc_balance
  FROM branch LEFT JOIN account
  USING (branch_name)
  GROUP BY branch_name) T1
 JOIN
 (SELECT branch_name, AVG(balance) AS avg_acc_balance
  FROM branch LEFT JOIN account
  USING (branch_name)
  GROUP BY branch_name) T2
 USING (branch_name)
 ORDER BY total_acc_balance;



-- [Problem 3a]
-- Generate a list of all cities that customers live in, where there is no bank branch in that city
-- Make sure that the results are distinct; no city should appear twice. Also, sort the cities inincreasing alphabetical order.

-- Approach 1: Difference Operation
SELECT * 
 FROM 
 (SELECT customer_city AS city FROM customer
 EXCEPT
 SELECT branch_city AS city FROM branch) temp
 ORDER BY city;
-- Approach 2: Membership Test
SELECT DISTINCT customer_city AS city
 FROM customer
 WHERE customer_city NOT IN
 (SELECT DISTINCT customer_city
  FROM customer c, branch b
  WHERE c.customer_city = b.branch_city)
 ORDER BY city;

-- [Problem 3b]
-- Are there any customers who have neither an account nor a loan?
-- Note that MySQL does not support the EXCEPT operator! But there is more than one way…

-- Approach 1: Membership Test
SELECT *
 FROM customer
 WHERE customer_name NOT IN
 (SELECT DISTINCT c.customer_name
  FROM customer c, borrower b, depositor d
  WHERE c.customer_name = b.customer_name OR c.customer_name = d.customer_name)
 ORDER BY customer_name;
-- Approach 2: UNION Operation + Membership Test
SELECT customer_name
 FROM customer
 WHERE customer_name NOT IN
  (SELECT customer_name FROM borrower
  UNION
  SELECT customer_name FROM depositor)
-- Approach 3: Difference Operation
SELECT customer_name FROM customer
 EXCEPT
(SELECT customer_name FROM borrower 
 UNION
SELECT customer_name FROM depositor)

-- [Problem 3c]
-- The bank decides to promote its branches located in the city of Horseneck, so it wants to make a $50 gift-deposit into 
-- all accounts held at branches in the city of Horseneck. Write the SQL UPDATE command for performing this operation.
UPDATE account
 SET balance = balance + 50
 WHERE branch_name IN
		(SELECT branch_name
		FROM branch
		WHERE branch_city = 'Horseneck');

-- [Problem 3d]
-- Write another answer to part c.  Note that you can also give the tables in the UPDATE clause aliases.
UPDATE account, branch SET account.balance = account.balance + 75
    WHERE account.branch_name = branch.branch_name 
    AND branch_city = 'Horseneck';

-- [Problem 3e]
-- Retrieve all details (account_number, branch_name, balance) for the largest account at each branch.  
-- Implement this query as a join against a derived relation in the FROM clause.
SELECT a.account_number, a.branch_name, a.balance
 FROM account a JOIN
	(SELECT branch_name, MAX(balance) max_balance
	 FROM account
	 GROUP BY branch_name) tm
 ON a.balance = tm.max_balance AND a.branch_name = tm.branch_name;

-- [Problem 3f]
-- Implement the same query as in the previous problem, this time using an IN predicate with multiple columns, e.g.
-- “(branch_name, balance) IN ...”
SELECT account_number, branch_name, balance
 FROM account
 WHERE (branch_name, balance) IN
	(SELECT branch_name, MAX(balance) balance
	 FROM account
	 GROUP BY branch_name)

-- [ Problem 4 ]
-- Compute the rank of all bank branches, 
-- based on the amount of assets that each branch holds.
SELECT COUNT(*) AS 'rank', b1.branch_name, b1.assets
 FROM branch b1 LEFT JOIN branch b2
 ON b1.assets > b2.assets OR b1.branch_name = b2.branch_name
 GROUP BY b1.branch_name, b1.assets
 ORDER BY b1.assets DESC;