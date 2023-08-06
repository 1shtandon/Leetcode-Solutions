import requests

url = 'https://jsonmock.hackerrank.com/api/countries/'


def findCountries(region='', keyword=''):
    total_pages = requests.get(
        url + 'search?region=&name=').json()['total_pages']

    res = []
    for i in range(1,  total_pages + 1):
        page_data = requests.get(
            url + 'search?region=' + region + '&name=' + keyword + '&page=' + str(i)).json()['data']
        for d in page_data:
            res.append([d['name'], d['population']])

    res.sort(key=lambda x: (x[1], x[0]))

    op = []

    for country in res:
        op.append(country[0] + ',' + str(country[1]))
        
    return op


op = findCountries('asia' , 'in')
print(op)
