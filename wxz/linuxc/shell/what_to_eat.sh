#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
eat[1]="汉堡"
eat[2]="肯德基"
eat[3]="便当"
eat[4]="炒菜"
eatnum=4
check=$((${RANDOM}*${eatnum}/32767+1))
echo "your may eat ${eat[${check}]}"
