select c.id
from ecoli_data as a
left join ecoli_data as b on a.id = b.parent_id
left join ecoli_data as c on b.id = c.parent_id
where a.parent_id is null and c.id is not null;