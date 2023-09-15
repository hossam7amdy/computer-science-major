-- Part B: [Branch Statistics Materialized View]

-- [Problem 1] Write the index definition.
CREATE INDEX sub_idx ON account (account_number, branch_name);

-- [Problem 2] Table holding materialized results of the view branch_account_stats.
CREATE TABLE IF NOT EXISTS mv_branch_account_stats (
  branch_name VARCHAR(32) NOT NULL,
  num_accounts INT NOT NULL,
  total_deposits DECIMAL(12, 2) NOT NULL,
  min_balance DECIMAL(12, 2) NOT NULL,
  max_balance DECIMAL(12, 2) NOT NULL,
  PRIMARY KEY (branch_name)
);

-- [Problem 3] Populate the materialized view table mv_branch_account_stats.
INSERT INTO mv_branch_account_stats
  SELECT branch_name,
    COUNT(*) AS num_accounts,
    SUM(balance) AS total_deposits,
    MIN(balance) AS min_balance,
    MAX(balance) AS max_balance
  FROM account
  GROUP BY branch_name;

-- [Problem 4] Write the view definition for branch_account_stats.
CREATE VIEW branch_account_stats AS
  SELECT branch_name, num_accounts,
    (total_deposits / num_accounts) AS avg_balance,
    total_deposits, min_balance, max_balance
  FROM mv_branch_account_stats;

-- [Problem 5] Write the trigger (and related procedures) to handle.
DELIMITER !
-- A procedure to execute when inserting a new branch name and balance
-- to the bank account stats materialized view (mv_branch_account_stats).
-- If a branch is already in view, its current balance is updated
-- to account for total deposits and adjusted min/max balances.
CREATE PROCEDURE sp_branchstat_newacct(IN new_branch_name VARCHAR(32), IN new_balance DECIMAL(12, 2))
BEGIN    
	INSERT INTO mv_branch_account_stats
  -- If branch doesn't exist, create it.
	  VALUES (new_branch_name, 1, new_balance, new_balance, new_balance)
  ON DUPLICATE KEY UPDATE
    -- If branch already exists, update its stats.
    num_accounts = num_accounts + 1,
    total_deposits = total_deposits + new_balance,
    min_balance = LEAST(min_balance, new_balance),
    max_balance = GREATEST(max_balance, new_balance);
END !

-- Handles new rows added to account table, updates stats accordingly
CREATE TRIGGER trg_account_insert 
	AFTER INSERT ON account
    FOR EACH ROW
BEGIN    
	CALL sp_branchstat_newacct(NEW.branch_name, NEW.balance);
END !
DELIMITER ;

-- [Problem 6] Write the trigger (and related procedures) to handle deletes.
DELIMITER !
-- A procedure to execute when deleting a branch name and balance
-- from the bank account stats materialized view (mv_branch_account_stats).
-- If a branch is already in view, its current balance is updated
-- to account for total deposits and adjusted min/max balances.
CREATE PROCEDURE sp_branchstat_deleteacct(IN del_branch_name VARCHAR(32), IN del_balance DECIMAL(12, 2))
BEGIN    
  DELETE FROM mv_branch_account_stats WHERE branch_name = del_branch_name AND num_accounts = 1;

  IF del_branch_name IN (SELECT branch_name FROM mv_branch_account_stats 
    WHERE branch_name = del_branch_name) THEN
      UPDATE mv_branch_account_stats
        SET num_accounts = num_accounts - 1, 
            total_deposits = total_deposits - del_balance
        WHERE branch_name = del_branch_name;
  END IF;

  IF del_balance = (SELECT min_balance FROM mv_branch_account_stats 
      WHERE branch_name = del_branch_name)
      THEN UPDATE mv_branch_account_stats SET min_balance = 
        (SELECT MIN(balance) FROM account 
          WHERE branch_name = del_branch_name)
        WHERE branch_name = del_branch_name;

  ELSEIF(del_balance = (SELECT max_balance FROM mv_branch_account_stats 
      WHERE branch_name = del_branch_name)) THEN
        UPDATE mv_branch_account_stats SET max_balance = 
          (SELECT MAX(balance) FROM account 
            WHERE branch_name = del_branch_name)
          WHERE branch_name = del_branch_name;
  END IF;
END !

-- Handles new rows deleted from account table, updates stats accordingly
CREATE TRIGGER trg_account_delete AFTER DELETE
      ON account FOR EACH ROW
BEGIN
    CALL sp_branchstat_deleteacct(OLD.branch_name, OLD.balance);
END !
DELIMITER ;

-- [Problem 7] Write the trigger (and related procedures) to handle updates.
DELIMITER !
-- Handles new rows deleted from account table, updates stats accordingly
CREATE TRIGGER trg_account_update AFTER UPDATE
        ON account FOR EACH ROW
BEGIN
    IF OLD.branch_name <> NEW.branch_name THEN
        CALL sp_branchstat_newacct(NEW.branch_name, NEW.balance);
        CALL sp_branchstat_deleteacct(OLD.branch_name, OLD.balance);

    ELSEIF OLD.balance <> NEW.balance THEN
        UPDATE mv_branch_account_stats
            SET total_deposits = total_deposits + NEW.balance - OLD.balance,
            min_balance = LEAST(min_balance, NEW.balance),
            max_balance = GREATEST(max_balance, NEW.balance)
            WHERE branch_name = NEW.branch_name;
        
        IF OLD.balance = (SELECT min_balance FROM mv_branch_account_stats 
            WHERE branch_name = OLD.branch_name)
            THEN UPDATE mv_branch_account_stats SET min_balance =
                (SELECT MIN(balance) FROM account
                WHERE branch_name = NEW.branch_name)
                WHERE branch_name = OLD.branch_name;
        
        ELSEIF OLD.balance = (SELECT max_balance FROM mv_branch_account_stats 
            WHERE branch_name = OLD.branch_name)
            THEN UPDATE mv_branch_account_stats SET OLD.balance =
                (SELECT MAX(balance) FROM account
                    WHERE branch_name = NEW.branch_name)
            WHERE branch_name = OLD.branch_name;
        END IF;

    END IF;
END !
DELIMITER ;
