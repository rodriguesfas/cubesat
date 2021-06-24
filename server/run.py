#!/usr/bin/env python
# -*- coding: utf-8 -*-

import configparser

from flask import Flask
from flask import request
 
app = Flask(__name__)

config = configparser.ConfigParser()
config.read('config.ini')

host = config['cubesat']['host']
port = config['cubesat']['port']

@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"
 
@app.route('/postjson', methods = ['POST'])
def postJsonHandler():
    content = request.get_json()
    print (content)
    return 'JSON posted'

if __name__ == '__main__':
    app.run(host=host, port=port, debug=True)