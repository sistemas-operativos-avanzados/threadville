#! /bin/bash

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libgtk-3-dev
pkg-config --cflags gtk+-3.0


# sudo docker build --rm -t threadville .
# sudo docker run -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/.Xauthority:/home/developer/.Xauthority --net=host --pid=host --ipc=host threadville
