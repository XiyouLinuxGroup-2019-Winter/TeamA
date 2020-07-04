#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
read -p "Please input (Y/N):" yn
if [ "${yn}" == "Y" ] || [ "${yn}" == "y" ]; then
        echo "Ok continue" 
        exit 0
fi
if [ "${yn}" == "N" ] || [ "${yn}" == "n" ]; then
        echo "Oh,interrupt!"
        exit 0
fi
echo "I don't konw what your choice is" && exit 0
