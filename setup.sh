#! /bin/bash

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libgtk-3-dev
pkg-config --cflags gtk+-3.0
