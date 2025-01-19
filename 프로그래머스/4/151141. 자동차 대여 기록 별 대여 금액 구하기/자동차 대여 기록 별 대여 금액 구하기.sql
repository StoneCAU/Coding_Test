SELECT 
    a.history_id, 
    round(a.daily_fee * period - (a.daily_fee * period * ifnull(d.discount_rate,0) * 0.01)) as fee
FROM (
    SELECT 
        c.history_id, 
        b.daily_fee, 
        DATEDIFF(c.end_date, c.start_date) + 1 AS period,
        CASE 
            WHEN DATEDIFF(c.end_date, c.start_date) + 1 >= 90 THEN '90일 이상'
            WHEN DATEDIFF(c.end_date, c.start_date) + 1 >= 30 THEN '30일 이상'
            WHEN DATEDIFF(c.end_date, c.start_date) + 1 >= 7 THEN '7일 이상'
            else 0
        END AS duration_type
    FROM 
        CAR_RENTAL_COMPANY_CAR AS b
    INNER JOIN 
        CAR_RENTAL_COMPANY_RENTAL_HISTORY AS c 
    ON 
        b.car_id = c.car_id
    where b.car_type = '트럭'
) AS a
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as d on a.duration_type = d.duration_type and d.car_type = '트럭'
order by fee desc, history_id desc