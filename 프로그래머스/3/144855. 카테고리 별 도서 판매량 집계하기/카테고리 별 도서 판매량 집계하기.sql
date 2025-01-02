select b.category, sum(a.sales) as total_sales
from book_sales as a
left join book as b on a.book_id = b.book_id
where a.sales_date like '2022-01%'
group by b.category
order by b.category asc;