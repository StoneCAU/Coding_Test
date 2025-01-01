-- 코드를 입력하세요
SELECT a.rest_id, a.rest_name, a.food_type, a.favorites, a.address
, round(avg(b.review_score),2) as score
from rest_info as a
right join rest_review as b on a.rest_id = b.rest_id
group by a.rest_id
having a.address like '서울%'
order by score desc, favorites desc;