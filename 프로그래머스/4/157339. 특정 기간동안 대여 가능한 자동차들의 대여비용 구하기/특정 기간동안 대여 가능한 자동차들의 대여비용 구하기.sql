select distinct c.car_id, c.car_type, round(c.daily_fee*30*(1-d.discount_rate*0.01)) as fee
from CAR_RENTAL_COMPANY_CAR as c
inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY as h
on c.car_id = h.car_id
inner join CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS d
on c.car_type = d.car_type and d.duration_type = '30일 이상'
where c.car_type in ('세단', 'SUV') 
and c.car_id not in (select car_id
                    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    where start_date <= '2022-11-30' and end_date >= '2022-11-01')
having fee between 500000 and 2000000-1
order by fee desc, c.car_type, c.car_id desc