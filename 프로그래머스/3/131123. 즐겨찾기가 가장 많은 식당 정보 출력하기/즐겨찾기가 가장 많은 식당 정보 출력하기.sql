select food_type, rest_id, rest_name, favorites
from rest_info
where (food_type, favorites) in 
    (select a.food_type, max(a.favorites)
    from rest_info as a
    group by a.food_type) 
order by food_type desc