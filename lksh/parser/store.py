import string

allowed_letters = set(''.join([chr(i) for i in range(ord('а'), ord('ё') + 1)]) + ' -' + string.ascii_lowercase)
stored_id = {}


class PermissionException(Exception):
    def __init__(self, message, errors):
        # Call the base class constructor with the parameters it needs
        super(PermissionException, self).__init__(message)
        # Now for your custom code...
        self.errors = errors


def read_all():
    with open('ids.txt') as stored_ids_file:
        for id_now_str in stored_ids_file:
            id_now = int(id_now_str)
            global next_id
            next_id = max(next_id, id_now + 1)
            stored_id[id_now] = []
            with open(id_now_str + '.id') as people:
                stored_id[id_now] = [i for i in people]


def write_new(name: str, id: int):
    for char in name:
        if char not in allowed_letters:
            raise PermissionException
    stored_id[id] = stored_id.get(id, []).append(name)


def save():
    stored_ids_file = open('ids.txt', 'w')
    for id in stored_id.keys():
        print(id, file=stored_ids_file)
        with open(str(id) + '.id') as id_file:
            for name in stored_id[id]:
                print(name, file=id_file)

