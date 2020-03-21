#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
if [ "${1}" == "Hello" ];then
    echo "Hello ,how are you"
elif [ "${1}" == "" ];then
    echo "You Must input parameters , ex> {${0} someword}"
else
    echo "The only parameters is 'Hello',ex> {${0} Hello}"
fi
