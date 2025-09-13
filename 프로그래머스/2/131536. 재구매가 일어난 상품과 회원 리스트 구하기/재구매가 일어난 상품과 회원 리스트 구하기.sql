select distinct a.user_id, a.product_id
from online_sale as a
inner join online_sale as b on a.user_id = b.user_id and a.product_id = b.product_id 
and a.online_sale_id <> b.online_sale_id
order by a.user_id, a.product_id desc
