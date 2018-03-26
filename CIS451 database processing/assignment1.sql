--  1

SELECT c.fname, c.lname, c.company 
FROM stores7.customer c
WHERE c.company LIKE '%Sport' OR c.company LIKE  '%Sports';


-- 2
SELECT Concat(c.fname, ' ', c.lname) AS customer_name, c.city, c.state, s.description
FROM stores7.customer c 
        JOIN orders o USING(customer_num)
        JOIN items i USING(order_num)
        JOIN stock s USING(stock_num, manu_code)
        JOIN manufact m USING(manu_code)
		WHERE manu_name = 'smith';



-- 3
SELECT s.sname, Concat(c.fname, ' ', c.lname) AS customer_name
FROM stores7.state s LEFT JOIN stores7.customer c ON c.state = s.code;




-- 4
SELECT e.fname, e.lname, w.hours, p.pname

FROM company.employee e JOIN company.works_on w ON e.ssn = w.essn
		JOIN company.project p ON p.pnumber = w.pno
        WHERE p.pname =  'ProductY' AND w.hours > 8;
         



-- 5
SELECT d.dname, e.fname AS dependent_name 
FROM company.department d JOIN company.employee e ON d.dnumber = e.dno


-- 6
SELECT Concat(e.fname, ' ', e.lname) AS supervisor, Concat(m.fname, ' ', m.lname) AS supervisee
		FROM company.employee e 
		JOIN company.employee m ON e.ssn = m.superssn;

-- 7
SELECT Concat(c.first_name, ' ', c.last_name) AS full_name, f.title AS movie
		FROM sakila.customer c
        JOIN rental r USING(customer_id)
        JOIN inventory i USING(inventory_id)
        JOIN film f USING(film_id)
        WHERE MONTHNAME(r.rental_date) = 'June';
        
        
        

	
-- 	8
SELECT Concat(e.first_name, ' ', e.last_name) AS full_name, e.email 
		FROM sakila.customer e 
		JOIN payment p USING(customer_id)
		JOIN rental r USING(rental_id)
        JOIN inventory i USING(inventory_id)
        JOIN film_category f USING(film_id)
        JOIN category c USING(category_id)
        WHERE p.amount > 2 AND c.name = 'family';
    


-- 9
SELECT COUNT(f.title) as 'COUNT(rental_id)'
		FROM sakila.rental r
        JOIN inventory i USING(inventory_id)
        JOIN film f USING(film_id)
        WHERE f.title LIKE '%TEEN%'
        






