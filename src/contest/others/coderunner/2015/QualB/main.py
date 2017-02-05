
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

enemys_HP =[]
friend_powers =[]

last_info ={}

attack_bool = 0

def get_info():
    global info_time
    #print ret
    now = time.time()
    d = now - info_time
    if(d>=0.25):
        ret = query(api_get_info_json % token);
        if ret!="Error":
            info_time = now
    else :
        ret = "NO"
    return ret


def attac():
    global attacked_time
    now =time.time()
    if(attacked_time + 0.55 <=now):
        ret = query(api_enter_attack % token);
        if ret != "Error":
            attacked_time = now
        else :
            print 'attack error'
        global mypower
        mypower = -100000
        global power_stamp
        power_stamp =0
        print ret

        
def update_power():
    global mypower
    global timestamp
    global power_stamp
    #mypower = pow(time.time() - timestamp +power_stamp,2)    
    
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
        global last_info
        last_info = info_json
        #print json.dumps(info_json, indent=4, separators=(',', ': '))
        
        global mypower
        global head_ene_hp
        global timestamp
        global power_stamp
        
        mypower = info_json["power"]
        head_ene_hp = info_json["hp"]
        timestamp = time.time()
        power_stamp = math.sqrt(mypower)
        global enemys_HP
        enemys_HP = info_json["hps"]
        #print "power " + str(info_json["power"])
        #print "eneHP " + str(info_json["hp"])
        global attack_bool


        if len(enemys_HP) ==10:
            odd_sum = 0
            even_sum = 0
            for i in range(len(enemys_HP)):
                if i%2==0:
                    even_sum += enemys_HP[i]
                else:
                    odd_sum += enemys_HP[i]
            if odd_sum >= even_sum:
                attack_bool =0
            else:
                attack_bool =1


def do_action():
    global mypower
    global head_ene_hp
    global enemys_HP
    if mypower - head_ene_hp >= 1000 : #and len(enemys_HP)%2 == attack_bool :
        #global last_info
        #print json.dumps(last_info, indent=4, separators=(',', ': '))
        print "now : " + str(head_ene_hp) +" " + str(mypower)
        print enemys_HP
        attac()
            

            
def main():

    while(1):
        global mypower
        global head_ene_hp
        handle_info()
        #"update_power()
        do_action()
        

        
#time.sleep(1)


main()


#get_info()
