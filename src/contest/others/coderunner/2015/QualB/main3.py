
import urllib2
import time
import json
import time
import math
import random


def query(url):
    try:
	res = urllib2.urlopen(url)
        ret =res.read()
    except:
        ret = "Error"
        
    return ret

    
token = "KPP52J0VX3MNF96O66B9BFV3AW6BG3JT"

api_enter_attack = "http://game.coderunner.jp/enter?token=%s"
api_get_info_json = "http://game.coderunner.jp/infoJson?token=%s"
api_get_py_rank_json = "http://game.coderunner.jp/myrankJson?token=%s"
api_get_all_rank_json = "http://game.coderunner.jp/rankJson?uid=%s"
api_get_room = "http://game.coderunner.jp/roomJson?rid=%d"


def get_hist():
    ret = query(api_get_py_rank_json % token)
    ret_json = json.loads(ret)
    #print json.dumps(ret_json, indent=4, separators=(',', ': '))

    room = ret_json[0]["room"]
    
    ret = query(api_get_room % room)
    ret_json = json.loads(ret)
    print json.dumps(ret_json, indent=4, separators=(',', ': '))
    
    
    
def main():
    get_hist()
    return

    
    while(1):
        global mypower
        global head_ene_hp
        handle_info()
        #"update_power()
        
        if mypower - head_ene_hp >500:
            attac()

        
#time.sleep(1)


main()


#get_info()
