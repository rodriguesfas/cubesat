# Cubesat

My CubeSat project baseline.

<hr/>

### Requiriments System

- [Ubuntu 20.04](#)
- [Python 3](#).
- [Pip 3](#).
- [MongoDB Compass Community](https://www.mongodb.com/) to save data or [RoboMongo](https://robomongo.org/).
- [NGrok](https://ngrok.com/) for public url.

<hr/>

## Server

Application web python monitoring dashboard.

### Virtual environments

    virtualenv .venv

    source .venv/bin/activate

### Install requirements

    pip install flask
    pip install pymongo

### Run 

    python run.py

### Tests

Used client [Postman](https://www.postman.com/) to tests web server [collection](https://www.getpostman.com/collections/5fe6061ccac8ff3ac443).

<hr/>

## Client

[Firmware](#) [Arduino](#) [NodeMCU V3](#).

### Config IDE Arduino

[Como programar o NodeMCU com IDE Arduino](https://www.filipeflop.com/blog/programar-nodemcu-com-ide-arduino/)

### 


### Error

OSError: [Errno 98] Address already in use.

    sudo lsof -t -i tcp:9999 | xargs kill -9