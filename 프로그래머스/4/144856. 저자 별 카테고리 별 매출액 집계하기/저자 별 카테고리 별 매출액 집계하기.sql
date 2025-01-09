select a.author_id, b.author_name, a.category, sum(a.price * c.sales) as total_sales
from book as a
inner join author as b on a.author_id = b.author_id
inner join book_sales as c on a.book_id = c.book_id
where c.sales_date like '2022-01%'
group by a.author_id, a.category
order by a.author_id, a.category desc