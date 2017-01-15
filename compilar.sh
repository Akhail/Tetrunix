#! /bin/bash
gcc tetris.c -o tetris.sh -lncurses -lpthread -I "$PWD"
chmod 755 tetris.sh