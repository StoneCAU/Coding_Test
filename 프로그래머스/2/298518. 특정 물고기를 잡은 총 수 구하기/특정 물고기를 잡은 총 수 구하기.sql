select count(*) as fish_count
from fish_info as a
inner join fish_name_info as b on a.fish_type = b.fish_type
where b.fish_name = 'BASS' OR b.fish_name = 'SNAPPER';