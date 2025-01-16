select case when month(differentiation_date) between 1 and 3 then '1Q'
            when month(differentiation_date) between 4 and 6 then '2Q'
            when month(differentiation_date) between 7 and 9 then '3Q'
            when month(differentiation_date) between 10 and 12 then '4Q'
        end as quarter,
        count(*) as ecoli_count
from ecoli_data
group by quarter
order by quarter 
