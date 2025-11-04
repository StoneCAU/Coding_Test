with recursive hours as (
    select 0 as hour
    union all
    select hour + 1
    from hours
    where hour < 23
)
select h.hour, count(a.datetime) as count
from hours h
left join animal_outs as a on hour(a.datetime) = h.hour
group by h.hour
order by h.hour