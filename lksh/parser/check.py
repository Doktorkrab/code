import requests
import json
import store
import sys
import time

LOG_FILE = sys.stdout
SESSION = '2018'


def get_json():
    """
    Get JSON with iformation
    :return: None
    """
    return json.loads(
        requests.get('https://sistema.lksh.ru/{}/entrance/results/data?start=0&length=-1'.format(SESSION)).text)


def check_and_update():
    """
    Update people
    :return: None
    """
    print('Updating at', time.ctime(time.time()))
    parsed = get_json()
    for men in parsed['data']:
        store.update(men['name'], men['parallel'], men['session'], LOG_FILE)
