from urllib import request, error
import json
class ClientAPI:
    def __init__(self,base_url):
        self.base_url = base_url
    
    def read(self):
        url = f"{self.base_url}/read"
        try:
            req = request.Request(url,method="GET")
            with request.urlpopen(req) as response:
                data = json.loads(response.read().decode())
                return data
        except error.URLError as e:
            print(f"Error: {e}")
            return None
