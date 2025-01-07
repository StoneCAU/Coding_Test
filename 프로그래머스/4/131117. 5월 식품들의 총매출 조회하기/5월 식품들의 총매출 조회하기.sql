select b.product_id, a.product_name, sum(a.price * b.amount) as total_sales
from food_product as a
inner join food_order as b on a.product_id = b.product_id
where b.produce_date like '2022-05%'
group by b.product_id
order by total_sales desc, b.product_id asc;