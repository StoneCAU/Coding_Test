select case
            when price < 10000 then 0
            else truncate(price, -4)
        end as price_group, count(*) products
from product
group by price_group
order by price_group;
