-- [Problem 5]

-- a)
SELECT 
    first_name, last_name, flight_date, purchase_date
FROM
    airline.customer
        JOIN
    airline.purchase USING (cust_id)
        JOIN
    airline.ticket USING (purchase_id)
        JOIN
    airline.ticket_info USING (ticket_id)
WHERE
    customer.cust_id = 54321
ORDER BY flight_date DESC;

-- b)
WITH revenues AS (
    SELECT aircraft_type, SUM(price) AS revenue
    FROM flight NATURAL JOIN ticket NATURAL JOIN ticket_info
    WHERE TIMESTAMP(flight_date, flight_time)
        BETWEEN NOW() - INTERVAL 2 WEEK AND NOW()
    GROUP BY aircraft_type)
SELECT aircraft_code, IFNULL(revenue, 0) AS revenue
    FROM aircraft NATURAL LEFT JOIN revenues;

-- c)
SELECT cust_id, first_name, last_name, email
    FROM traveler NATURAL JOIN ticket NATURAL JOIN ticket_info NATURAL JOIN customer
    NATURAL JOIN flight
    WHERE international = TRUE AND (
        ISNULL(passport_number) OR ISNULL(country) OR ISNULL(emergency_name) OR
        ISNULL(emergency_phone));