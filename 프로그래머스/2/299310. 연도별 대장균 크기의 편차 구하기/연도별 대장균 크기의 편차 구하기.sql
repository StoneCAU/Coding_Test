select year(a.DIFFERENTIATION_DATE) as year, 
(
    select max(b.size_of_colony)
    from ecoli_data as b
    where year = year(b.DIFFERENTIATION_DATE)
) - a.size_of_colony as year_dev
,id
from ecoli_data as a
order by year, year_dev