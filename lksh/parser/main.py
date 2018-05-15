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
                     text='Привет {}, я вставлю здесь что-нибудь(надеюсь)'.format(update.message.chat.username))


def add(bot: telegram.Bot, update: telegram.Update, args):
    if not store.write_new(' '.join(args), update.message.chat.id, bot):
        bot.send_message(update.message.chat.id, '{} successfully added'.format(' '.join(args)))


def get_updates():
    check.check_and_update()
    store.print_update(updater.bot)
    threading.Timer(60 * 5, get_updates).start()


start_handler = telegram.ext.CommandHandler('start', start)
add_handler = telegram.ext.CommandHandler('add', add, pass_args=True)
# debug_handler = telegram.ext.CommandHandler('deb', debug)
dispatcher.add_handler(start_handler)
dispatcher.add_handler(add_handler)
# dispatcher.add_handler(debug_handler)

print('reading old data')
store.read_all()

atexit.register(store.save)

# print('starting polling')
updater.start_polling()
get_updates()
print('started polling')
