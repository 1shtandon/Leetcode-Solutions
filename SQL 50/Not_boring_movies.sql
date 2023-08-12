select *
from Cinema
where id % 2 = 1
    and not description = "boring"
order by rating desc