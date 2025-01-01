-- 코드를 입력하세요
SELECT f.FLAVOR
FROM FIRST_HALF as f, ICECREAM_INFO as i
where f.FLAVOR = i.FLAVOR and f.TOTAL_ORDER > 3000 and i.INGREDIENT_TYPE = 'fruit_based'
order by f.TOTAL_ORDER desc;