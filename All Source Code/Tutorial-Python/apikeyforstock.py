import http.client
conn = http.client.HTTPSConnection("https://mboum.com")
headers = {
    'X-Mboum-Secret': "demo"
    }
conn.request("GET", "/api/v1/qu/quote/financial-data/?symbol=F", headers=headers)
res = conn.getresponse()
data = res.read()
print(data.decode("utf-8"))