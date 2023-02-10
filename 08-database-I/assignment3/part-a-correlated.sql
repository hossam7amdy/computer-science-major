-- a) Briefly state what this query is computing. Then, create a decorrelated version of the same query.
-- Computes: How many loans each customer has?
SELECT customer_name,
 (SELECT COUNT(*) FROM borrower b
  WHERE b.customer_name = c.customer_name) AS num_loans
FROM customer c 
ORDER BY num_loans DESC;

-- Decorrelated Version
SELECT customer_name, COUNT(loan_number) num_loans
 FROM borrower RIGHT JOIN customer USING (customer_name)
 GROUP BY customer_name
 ORDER BY num_loans DESC;


-- b) Briefly state what this query is computing. Then, create a decorrelated version of the same query.
-- Computes: Branches that has loans > assets
SELECT branch_name FROM branch b
 WHERE assets < 
    (SELECT SUM(amount) FROM loan l
     WHERE l.branch_name = b.branch_name);

-- Decorrelated Version
SELECT b.branch_name
 FROM branch b, (SELECT branch_name, SUM(amount) total_loans
     FROM loan
     GROUP BY branch_name) t
 WHERE b.branch_name = t.branch_name AND b.assets < t.total_loans;


-- c) Using correlated subqueries in the SELECT clause, write a SQL query that computes the 
--    number of accounts and the number of loans at each branch.
SELECT branch_name, 
 (SELECT COUNT(*) FROM account a WHERE b.branch_name = a.branch_name) AS num_accounts,
 (SELECT COUNT(*) FROM loan l WHERE b.branch_name = l.branch_name) AS num_loans
FROM branch b
ORDER BY branch_name;


-- d) Create a decorrelated version of the previous query.  Make sure the results are the same.
SELECT branch_name, ifnull(t1.num_accounts, 0) num_accounts, ifnull(t2.num_loans,0) num_loans
FROM branch LEFT JOIN 
(SELECT branch_name, COUNT(*) num_accounts
 FROM account
 GROUP BY branch_name) t1 USING (branch_name)
 LEFT JOIN 
(SELECT branch_name, COUNT(*) num_loans
 FROM loan
 GROUP BY branch_name) t2 USING (branch_name)
 ORDER BY branch_name