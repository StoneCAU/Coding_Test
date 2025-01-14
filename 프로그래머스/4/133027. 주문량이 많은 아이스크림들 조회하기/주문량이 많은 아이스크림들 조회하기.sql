select a.flavor
from first_half as a
inner join july as b on a.flavor = b.flavor
group by a.flavor
order by sum(a.total_order + b.total_order) desc
limit 3;