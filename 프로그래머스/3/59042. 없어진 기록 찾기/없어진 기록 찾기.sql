select b.animal_id, b.name
from animal_ins as a
right join animal_outs as b on a.animal_id = b.animal_id
where a.name is null and b.name is not null
