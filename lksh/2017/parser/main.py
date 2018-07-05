import telegram.ext
import threading
import store
import atexit
import check

store.LOG_FILE = open('/parser/store.log', 'w')
check.LOG_FILE = open('/parser/check.log', 'w')

updater = telegram.ext.Updater(token="")
dispatcher = updater.dispatcher


def start(bot: telegram.Bot, update: telegram.Update):
    print('started with {}'.format(update.message.chat.username))
    bot.send_message(chat_id=update.message.chat.id,
                     text=('Привет, {}.\nДля добавления человека используйте /add <Имя Фамилия>, где  <Имя Фамилия>' +
                           ' - имя и фамилия человека, которого нужно добавить' +
                           ' в Ваш список отслеживаемых.\nНапример: /add Иван Иванов - добавит Ивана Иванова в ваш список отслеживаемых\n /get_list - просмотреть Ваш список отслеживамемых').format(
                         update.message.chat.username))


def add(bot: telegram.Bot, update: telegram.Update, args):
    if not len(args):
        bot.send_message(update.message.chat.id, 'Неверный синтаксис команды')
        return
    if not store.write_new(' '.join(args), update.message.chat.id, bot):
        bot.send_message(update.message.chat.id, '{} успешно добавлен в список отслеживаемых.'.format(' '.join(args)))


def get_list(bot: telegram.Bot, update: telegram.Update):
    names_list = store.get_list(update.message.chat.id)
    print('Getting list to {}({} {})'.format(update.message.chat.username, update.message.chat.first_name,
                                             update.message.chat.last_name))
    s = 'Ваш список:\n'
    for name_id in names_list:
        s += store.get_information(name_id) + '\n'
    bot.send_message(update.message.chat.id, s)

def get_updates():
    check.check_and_update()
    store.print_update(updater.bot)
    threading.Timer(60 * 5, get_updates).start()
    store.save()


start_handler = telegram.ext.CommandHandler('start', start)
add_handler = telegram.ext.CommandHandler('add', add, pass_args=True)
list_handler = telegram.ext.CommandHandler('get_list', get_list)

# debug_handler = telegram.ext.CommandHandler('deb', debug)
dispatcher.add_handler(start_handler)
dispatcher.add_handler(add_handler)
dispatcher.add_handler(list_handler)
# dispatcher.add_handler(debug_handler)

print('reading old data')
store.read_all()

atexit.register(store.save)

# print('starting polling')
updater.start_polling()
get_updates()
print('started polling')
store.save()
