
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


mypower = 0
timestamp = time.time()
head_ene_hp = 0
info_time = time.time()
power_stamp=0
attacked_time = time.time()

def get_info():
    global info_time
    #print ret
    now = time.time()
    d = now - info_time
    if(d>=0.25):
        info_time = now
        ret = query(api_get_info_json % token);
    else :
        ret = "NO"
    return ret

def attac():
    global attacked_time
    now =time.time()
    if(attacked_time + 0.55 <=now):
        ret = query(api_enter_attack % token);
        attacked_time = now
        global mypower
        mypower = 0
        global power_stamp
        power_stamp =0
        print ret

def get_my_rank():
    ret = query(api_get_py_rank_json % token)
    ret_json = json.loads(ret)
    print json.dumps(ret_json, indent=4, separators=(',', ': '))
    
        
def update_power():
    global mypower
    global timestamp
    global power_stamp
    mypower = pow(time.time() - timestamp +power_stamp,2)    
    
def handle_info():

    info = get_info()
    if info == "OUT ROOM":
        attac()
        print info
        return
    elif info == "Error":
        print info
        return
    elif info == "NO":
        return
    else:
    
        info_json = json.loads(info)
        #print info_json
        
        global mypower
        global head_ene_hp
        global timestamp
        global power_stamp
        
        mypower = info_json["power"]
        head_ene_hp = info_json["hp"]
        timestamp = time.time()
        power_stamp = math.sqrt(mypower)
        
        print "power " + str(info_json["power"])
        print "eneHP " + str(info_json["hp"])




def do_action():
    global mypower
    global head_ene_hp

    
    
def main():
    get_my_rank()
    return

    
    while(1):
        global mypower
        global head_ene_hp
        handle_info()
        #"update_power()
        
        if mypower - head_ene_hp >100:
            attac()

        
#time.sleep(1)


main()


#get_info()
