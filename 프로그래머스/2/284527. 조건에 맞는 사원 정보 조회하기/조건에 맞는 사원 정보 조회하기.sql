select sum(c.score) as score, a.emp_no, a.emp_name, a.position, a.email
from hr_employees as a
inner join hr_department as b on a.dept_id = b.dept_id
inner join hr_grade as c on a.emp_no = c.emp_no
where c.year = 2022
group by a.emp_no
order by score desc
limit 1;