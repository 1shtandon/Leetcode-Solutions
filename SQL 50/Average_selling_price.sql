select a.product_id,
    round(sum(b.units * a.price) / sum(b.units), 2) as average_price
from Prices a
    join UnitsSold b on a.product_id = b.product_id
where b.purchase_date between a.start_date and a.end_date
group by b.product_id