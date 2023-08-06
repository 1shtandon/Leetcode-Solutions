import requests

url = 'https://jsonmock.hackerrank.com/api/articles'

def topArticles(limit):
    total_pages = requests.get(url).json()['total_pages']
    names =  []
    for i in range (1 , total_pages + 1):
        page_data = requests.get(url + '?page=' + str(i)).json()['data']
        for d in page_data:
            d['title'] = d['title'] if d['title'] else d['story_title'] if d['story_title'] else ''
            if not d['title']:
                continue        
            d['num_comments'] = d['num_comments'] if d['num_comments'] else 0
            names.append({d['title']: d['num_comments']})
    
    names.sort(key=lambda x : (-x.values()[0] , x.keys()[0]))
    
    res = []
    for name in names[:limit]:
        res.append(name['title'])
    
    return res

op = topArticles(5)
print(op)
    
