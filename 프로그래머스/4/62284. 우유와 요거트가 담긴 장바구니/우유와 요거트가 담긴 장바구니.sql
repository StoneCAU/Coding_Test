select distinct a.cart_id
from cart_products as a
inner join cart_products as b on a.cart_id = b.cart_id
where a.name = 'Milk' and b.name = "Yogurt"