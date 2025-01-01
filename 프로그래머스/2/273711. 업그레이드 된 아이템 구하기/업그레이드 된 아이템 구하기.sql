-- 코드를 작성해주세요
select i.item_id, i.item_name, i.rarity
from item_info as i, item_tree as t
where t.parent_item_id in (select a.item_id
                            from item_info as a
                            inner join item_tree as b on a.item_id = b.item_id
                            where rarity = 'rare')
        and i.item_id = t.item_id
order by item_id desc;