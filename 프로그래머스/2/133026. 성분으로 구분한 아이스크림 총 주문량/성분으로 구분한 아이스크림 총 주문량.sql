select b.ingredient_type, sum(total_order) as total_order
from first_half as a
left join icecream_info as b on a.flavor = b.flavor
group by b.ingredient_type;