select id, case
                when a.per <= 0.25 then 'CRITICAL'
                when a.per <= 0.5 then 'HIGH'
                when a.per <= 0.75 then 'MEDIUM'
                else 'LOW'
            end as colony_name
from (select id,
     percent_rank() over (order by size_of_colony desc) as per
     from ecoli_data) as a
order by a.id asc;