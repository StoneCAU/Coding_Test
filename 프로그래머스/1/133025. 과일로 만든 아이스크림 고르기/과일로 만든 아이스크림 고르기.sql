select a.flavor 
from first_half as a
inner join icecream_info as b on a.flavor = b.flavor
where b.ingredient_type = 'fruit_based' and a.total_order >= 3000
order by total_order desc