import telegram
import sys

LOG_FILE = sys.stdout  # file to log, setting by main file

names = {'': 0}  # Stores all names -> indexes, Numeration from 1
names_list = ['']  # Stores all names sorted with id, Numeration from 1
names_in_ids = {}  # for each name stores id of clients to answer
exists = {}  # for each name stores parallel and session
parallels = ['AA', 'A-ML', "A'", "B", "B'", "C.python", "C.C++", "C'", "D", "P"]  # names of parallels
sessions = ["Июль", "Август"]  # name of sessions
last_update = []  # names which were updated with last update

PARALLELS_FILE = '/parser/parallels.txt'
SESSIONS_FILE = '/parser/sessions.txt'
NAMES_FILE = '/parser/names.txt'
NAME_ID_FILE = '/parser/name.id'


def read_all():
    """
    Read from external files all necessary information
    :return: None
    """
    global parallels
    global sessions
    global names_in_ids

    try:  # Read parallels
        with open(PARALLELS_FILE) as parallels_file:
            parallels = parallels_file.readline().rstrip().split()
    except Exception as e:
        print(e, file=LOG_FILE)

    try:  # Read Session
        with open(SESSIONS_FILE) as session_file:
            sessions = session_file.readline().rstrip().split()
    except Exception as e:
        print(e, file=LOG_FILE)

    with open(NAMES_FILE) as names_file:  # Read all names
        name = names_file.readline().rstrip()
        while name != '':
            name.rstrip()
            parallel_name, session_name = names_file.readline().split()
            add_name(name)
            if parallel_name != 'None':
                exists[name] = (get_parallel(parallel_name), get_session(session_name))
            name = names_file.readline().rstrip()

    with open(NAME_ID_FILE) as names_in_ids_file:  # Read all men, who needs some name
        for i in range(len(names)):
            names_in_ids[i] = list(map(int, names_in_ids_file.readline().split()))


def write_new(name: str, id: int, bot: telegram.Bot):
    """
    Add the new name from id and answer if can.
    :param name: name of the man
    :param id: id of client
    :param bot: bot which used to senc messages
    :return: True if answered now else False
    """
    print('Adding {}(id {}) to {}'.format(name, get_id(name), id), file=LOG_FILE)
    names_in_ids[get_id(name)] = names_in_ids.get(get_id(name), []) + [id]
    if get_id(name) in exists:  # If we can answer now, let's do it
        last_update.append(get_id(name))
        print_update(bot)
        return True
    return False


def add_name(name: str):
    """
    If name don't in base add it
    :param name: Name of man
    :return: None
    """
    if name.lower() not in names:
        names[name.lower()] = len(names)
        names_list.append(name)


def get_parallel(parallel: str):
    """
    Trying to find parallel, if not append new parallel
    :param parallel: Name of parallel
    :return: index of parallel
    """
    try:
        return parallels.index(parallel)
    except Exception as e:
        parallels.append(parallel)
        print(e, file=LOG_FILE)
        return len(parallels) - 1


def get_session(session: str):
    """
    Trying to find session, if not append new session
    :param session: Name of session
    :return: index of session
    """
    try:
        return sessions.index(session)
    except Exception as e:
        sessions.append(session)
        print(e, file=LOG_FILE)
        return len(sessions) - 1


def get_id(name: str):
    """
    Return id of name
    :param name: Name of man
    :return: name's id
    """
    name = name.lower()
    add_name(name)
    return names[name]


def save():
    """
    Save all data to files
    :return: None
    """
    with open(NAMES_FILE, 'w') as names_file:  # Save man's name, parallel and session
        for name in names_list:
            print(name, file=names_file)
            print(parallels[exists[get_id(name)][0]] if get_id(name) in exists else 'None',
                  sessions[exists[get_id(name)][1]] if get_id(name) in exists else 'None', file=names_file)

    with open(NAME_ID_FILE, 'w') as names_file:  # Save ids of mans who need men
        for name in names_in_ids.keys():
            print(*names_in_ids[name], file=names_file)

    with open(PARALLELS_FILE, 'w') as parallels_file:  # Save parallels
        print(*parallels, file=parallels_file)

    with open(SESSIONS_FILE, 'w') as sessions_file:  # SAve sessions
        print(*sessions, file=sessions_file)


def update(name: str, parallel: str, session: str, log_file):
    """
    Updates parallel and session of men
    :param name: name of person with was updated
    :param parallel: new parallel
    :param session: new session
    :param log_file: file to log
    :return: None
    """
    print('Updating {}({} from {})'.format(name, parallel, session), file=log_file)
    add_name(name)
    if name not in exists:
        last_update.append(get_id(name))
        exists[get_id(name)] = (get_parallel(parallel), get_session(session))


def print_update(bot: telegram.Bot):
    """
    Send a messages to clients with updates and remove from pool
    :param bot: Bot, who send messages
    :return: None
    """

    global last_update
    new_information = {}  # Dict with men's id -> (name's id, parallel, session)
    for name in last_update:
        if name not in names_in_ids:
            continue
        for id in names_in_ids[name]:
            new_information[id] = new_information.get(id, []) + [(
                name, parallels[exists[name][0]], sessions[exists[name][1]])]
        names_in_ids[name] = []

    print('Answering to {} client'.format(str(len(new_information))), file=LOG_FILE)
    for id in new_information.keys():  # Clean all updates men
        s = ''
        to_delete = set()
        for name, parallel, session in new_information[id]:
            s += '{} → {}({})\n'.format(names_list[name], parallel, session)
            to_delete.add(name)
        print('Sending message to {} with text:\n{}'.format(str(id), s), file=LOG_FILE)
        bot.send_message(id, s)

    last_update = []
