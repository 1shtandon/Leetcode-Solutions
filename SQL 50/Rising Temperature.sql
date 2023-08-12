select a.id
from weather a,
    weather b
where a.temperature > b.temperature
    and datediff(a.recordDate, b.recordDate) = 1