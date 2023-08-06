import requests

url = 'https://jsonmock.hackerrank.com/api/universities'



def bestUniversityByCountry(country):
    total_pages = requests.get(url).json()['total_pages']
    max_rank = 0
    res = ""
    for i in range(1, total_pages + 1):
        page_data = requests.get(url + '?page=' + str(i)).json()['data']
        for d in page_data:
            if d['location']['country'] == country:
                if int(d['rank_display']) > max_rank:
                    max_rank = int(d['rank_display'])
                    res = d['university']

    
    return res

print(bestUniversityByCountry('Switzerland'))