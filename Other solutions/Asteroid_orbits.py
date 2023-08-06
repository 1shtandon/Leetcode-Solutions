import requests

url = 'https://jsonmock.hackerrank.com/api/asteroids'


def asteroidOrbits(year, keyword=''):
    total_pages = requests.get(
        url + '/search?orbit_class=' + keyword).json()['total_pages']
    total_pages
    res = []
    for i in range(1, total_pages + 1):
        page_data = requests.get(
            url + '/search?orbit_class=' + keyword + '&page=' + str(i)).json()['data']
        for d in page_data:
            if int(d['discovery_date'][:4]) == year:
                res.append(d)

    op = []
    res.sort(key=lambda x: (float(x['period_yr']) if 'period_yr' in x else 1, x['designation']))
    for name in res:
        op.append(name['designation'])

    return op


op = asteroidOrbits(2010 , 'aten')
print(op)
