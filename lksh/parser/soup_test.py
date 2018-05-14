import telegram
import telegram.ext
import json
import store

updater = telegram.ext.Updater(token="567069520:AAEPGrrFo4Y7jjNpKlwpA6j5V-sSCSZCxaI")
dispatcher = updater.dispatcher


def start(bot: telegram.Bot, update: telegram.Update):
    bot.send_message(chat_id=update.message.chat.id,
                     text='Привет {}, я вставлю здесь что-нибудь(надеюсь)'.format(update.message.chat.username))


def add(bot: telegram.Bot, update: telegram.Update, args):
    try:
        store.write_new(' '.join(args), update.message.chat.id)
        bot.send_message(update.message.chat.id, '{} successfully added'.format(' '.join(args)))
    except store.PermissionException:
        bot.send_message(update.message.chat.id, 'You tried to add name with non-allowed chars')


start_handler = telegram.ext.CommandHandler('start', start)
add_handler = telegram.ext.CommandHandler('add', add, pass_args=True)
dispatcher.add_handler(start_handler)
dispatcher.add_handler(add_handler)

updater.start_polling()
