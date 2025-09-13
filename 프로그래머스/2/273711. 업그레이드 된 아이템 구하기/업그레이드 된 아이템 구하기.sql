select a.item_id, a.item_name, a.rarity
from item_info as a
inner join item_tree as b on a.item_id = b.item_id
where b.parent_item_id in (select c.item_id
                          from item_info as c
                          inner join item_tree as d on c.item_id = d.item_id
                          where rarity = 'rare')
order by a.item_id desc