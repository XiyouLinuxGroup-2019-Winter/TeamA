#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
read -p "Please input(y/n) :" yn
if [ "${yn}" == "Y" ] || [ "${yn}" == "y" ]; then
    echo "ok,continue"
elif [ "${yn}" == "N" ] || [ "${yn}" == "n" ]; then
    echo "on,interrput!"
else
    echo "I don't konw what your choice is"
fi
