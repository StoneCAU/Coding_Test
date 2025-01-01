-- 코드를 입력하세요
SELECT count(*) as USERS
from user_info
where age >= 20 and age <= 29 and year(joined) = 2021;