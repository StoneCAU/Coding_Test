select b.id, b.genotype, a.genotype as parent_genotype
from ecoli_data as a
left join ecoli_data as b on a.id = b.parent_id
where b.genotype & a.genotype >= a.genotype;