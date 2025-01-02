select a.book_id, b.author_name, date_format(a.published_date, '%Y-%m-%d') as published_date
from book as a
inner join author as b on a.author_id = b.author_id
where a.category = '경제'
order by a.published_date asc;