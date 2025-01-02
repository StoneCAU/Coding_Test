select b.car_id
from car_rental_company_car as a
inner join car_rental_company_rental_history as b on a.car_id = b.car_id
where a.car_type = '세단' and b.start_date like '2022-10%'
group by b.car_id
order by b.car_id desc;