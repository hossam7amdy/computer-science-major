/*
Given two relation schemas R = (A, B, C), and S = (D, E, F), 
and two relations r(R) and s(S), write SQL queries that produce 
identical results to the following relational algebra expressions.  
*/

-- 1. ΠA(r)
SELECT A FROM r

-- 2. σB=17(r)
SELECT * 
 FROM r
 WHERE B = 17

-- 3. r × s
SELECT *
 FROM r,s

-- 4. ΠA,F(σC=D(r × s))
SELECT A,F
 FROM r,s
 WHERE r.C = s.D

-- 5. r1 ∪ r2
SELECT DISTINCT * FROM r1
 UNION
SELECT DISTINCT * FROM r2

-- 6. r1 ∩ r2
SELECT DISTINCT * FROM r1
 INTERSECT
SELECT DISTINCT * FROM r2

-- 7. r1 – r2
SELECT DISTINCT * FROM r1
 EXCEPT
SELECT DISTINCT * FROM r2