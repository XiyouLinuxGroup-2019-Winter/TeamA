#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
read -p "Please input (Y/N):" yn
[ "${yn}"== "Y" -o "${yn}" == "y" ] && echo "Ok continue" && exit 0
[ "${yn}" == "N" -o "${yn}" == "n" ] && echo "Oh,interrupt!" && exit 0
echo "I don't konw what your choice is" && exit 0
