select a.apnt_no, b.pt_name, b.pt_no, a.mcdp_cd, c.dr_name, a.apnt_ymd
from appointment as a
inner join patient as b on a.pt_no = b.pt_no
inner join doctor as c on c.dr_id = a.mddr_id
where a.apnt_ymd like '2022-04-13%' and a.apnt_cncl_yn = 'N' and a.mcdp_cd = 'CS'
order by a.apnt_ymd