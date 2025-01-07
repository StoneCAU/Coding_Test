select b.user_id, b.nickname, concat(city, ' ', street_address1, ' ', street_address2) as '전체주소',
concat(substr(TLNO, 1, 3), '-', substr(TLNO, 4, 4), '-', substr(TLNO, 8, 4)) as '전화번호'
from used_goods_board as a
inner join used_goods_user as b on a.writer_id = b.user_id
group by a.writer_id
having count(*) >= 3
order by a.writer_id desc