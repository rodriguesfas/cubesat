# Cubesat

My CubeSat project baseline.

<hr/>

### Requiriments System

- [Ubuntu 20.04](#)
- [Python 3](#).
- [Pip 3](#).
- [MongoDB Compass Community](https://www.mongodb.com/) to save data.
- [NGrok](https://ngrok.com/) for public url.

<hr/>

## Server

Application web python monitoring dashboard.

### Virtual environments

    virtualenv .venv

    source .venv/bin/activate

### Install requirements

    pip install flask
    pip install mongodb

### Run 

    python run.py

### Tests

Used client [Postman](https://www.postman.com/) to tests web server.

<hr/>

## Client

[Firmware](#) [Arduino](#) [NodeMCU V3](#).

### Config IDE Arduino

[Como programar o NodeMCU com IDE Arduino](https://www.filipeflop.com/blog/programar-nodemcu-com-ide-arduino/)

### 


### Error

OSError: [Errno 98] Address already in use.

    sudo lsof -t -i tcp:9999 | xargs kill -9