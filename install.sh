#!/bin/bash

if [ ! -d "/usr/local/bin/killua" ]; then
    sudo mkdir -p /usr/local/bin/killua
fi

g++ @linker 
sudo cp killua /usr/local/bin/killua/

sudo chmod +x /usr/local/bin/killua/killua

echo "export PATH=\$PATH:/usr/local/bin/killua" >> ~/.bashrc
source ~/.bashrc

echo "Program killua installed successfully. You can run it by typing killua in the terminal."

exec bash