-- order numbers profit
-- SELECT (o.order_cost) - (i.source_price) - (s.shipping_cost) - (se.fee) as profit
-- FROM selling_fees se
-- 	JOIN  inventory i USING (product_id)
--     JOIN orders o using (product_id)
--     JOIN shipping_costs s USING (order_no)
-- WHERE o.order_no = 12;

-- total items in inventory
-- SELECT SUM(i.inventory)
-- FROM inventory i

-- how many of what item in inventory
-- SELECT i.product_name as pname, i.generation, i.inventory 
-- FROM inventory i
-- WHERE product_id = 12;

-- selling fee of product id
-- SELECT i.product_name, i.generation, s.fee
-- FROM inventory i
-- JOIN selling_fees s USING(product_id)
-- WHERE product_id = 6;

-- Total orders
-- SELECT COUNT(o.order_no)
-- FROM orders o
	