#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
echo "The script name is   ==> ${0}" 
echo "Total parameter number is ==> $#"
[ "$#" -lt 2 ] && echo "The number of parameter is less then 2. stop here." && echo 0
echo "Your whole parameter is ==> '$@'"
echo "The 1st parameter ==> ${1}"
echo "The 2nd parameter ==> ${2}"
