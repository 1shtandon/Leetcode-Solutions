import requests
url = 'https://jsonmock.hackerrank.com/api/transactions'

def maximumTransfer(userName , city):
    r = requests.get(url)
    data = r.json()
    total_pages = data['total_pages']
    max_debit = max_credit = 0 
    max_deb = max_cred = '$0.00'
    for i in range(1 , total_pages + 1):
        page_data = requests.get(url + '?page=' + str(i)).json()['data']
        for d in page_data:
            if d['userName'] == userName and d['location']['city'] == city:
                if d['txnType'] == 'debit':
                    if float(d['amount'][1:].replace(',' , '')) > max_debit:
                        max_debit = float(d['amount'][1:].replace(',' , ''))
                        max_deb = d['amount']
                elif d['txnType'] == 'credit':
                    if float(d['amount'][1:].replace(',' , '')) > max_credit:
                        max_credit = float(d['amount'][1:].replace(',' , ''))
                        max_cred = d['amount']  
            else:
                continue
    
    res = [max_cred , max_deb]
    return res

op = maximumTransfer('Bob Martin' , 'Bourg')
print(op)   
        
    

