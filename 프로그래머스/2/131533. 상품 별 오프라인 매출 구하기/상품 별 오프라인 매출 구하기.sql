select b.product_code, sum(a.sales_amount * b.price) as sales
from offline_sale as a
left join product as b on a.product_id = b.product_id
group by b.product_code
order by sales desc, b.product_code asc;
