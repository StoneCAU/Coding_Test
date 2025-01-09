select year(b.sales_date) as year, month(b.sales_date) as month, a.gender, count(distinct a.user_id) as users
from user_info as a
inner join online_sale as b on a.user_id = b.user_id
where gender is not null
group by year, month, a.gender
order by year, month, a.gender
