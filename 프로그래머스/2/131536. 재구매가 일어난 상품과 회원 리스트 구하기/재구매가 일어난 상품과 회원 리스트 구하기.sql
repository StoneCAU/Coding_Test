-- 코드를 입력하세요
SELECT USER_ID, PRODUCT_ID
from ONLINE_SALE
group by 1, 2
having count(*) > 1
order by USER_ID ASC, PRODUCT_ID DESC;