select product.product_name,sales.year,sales.price
from sales 
left join product
on sales.product_id = product.product_id;