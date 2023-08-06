import requests

url = 'https://jsonmock.hackerrank.com/api/weather/search?name='


def weatherStation(keyword=""):
    total_pages = requests.get(url + keyword).json()['total_pages']
    res = []
    for i in range(1 , total_pages + 1):
        page_data = requests.get(url + keyword + '&page=' + str(i)).json()['data']
        for d in page_data:
            name = d['name']
            weather = d['weather'].split(' ')[0]
            wind = d['status'][0][6: -4]
            humidity = d['status'][1][10: -1]
            
            res.append(name + ',' + weather + ',' + wind + ',' + humidity)
    
    res.sort()
    
    return res

op = weatherStation('Ad')
print(op)

    
    
    