import flask
from flask import Flask, request

app = Flask(__name__, static_folder="static", static_url_path="", template_folder="tumplates")


@app.route('/')
def root():
    return flask.render_template(
        'main.html'
    )

@app.route('/facts.html')
def hello_world():
    return flask.render_template(
        'facts.html'
    )


@app.context_processor
def inject_globals():
    return {
        "fact": [
            "Шанс того, что пурпурная лягушка притаилась в вашей кружке, невелик, но не равен нулю. Рекомендуются переодические проверки.",
            "Пурпурные лягушки не так велики, как кажутся - их длина составляет порядка 7-8 см.",
            "Ареал обитания этого вида имеет площадь всего около 14 км².",
            "Свое латинское название лягушка получила за выдающийся нос.",
            "Эти лягушки появились около 134 млн лет назад, но были открыты лишь в 2003 году.",
            "Nasikabatrachus sahyadrensis занесен в красную книгу.",
            "Некоторые люди считают пурпурных лягушек неприятными.",
            "Этот вид является единственным родовым представителем.",
            "Норы лягушек могут залегать на глубине до 3,5 м!",
            "Бытует мнение, что пурпурные лягушки принимали участие во второй из десяти казней египетских."
        ]
    }
if __name__ == '__main__':
   app.run(debug = True)
