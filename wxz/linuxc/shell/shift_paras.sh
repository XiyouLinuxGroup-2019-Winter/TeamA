#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
echo "Total parameter number is ==> $#"
echo "Your whole parameter is ==> '$@'"
shift #进行第一次［一个变量的shift］
echo "Total parameter number is ==> $#"
echo "Your whole parameter is ==> '$@'"
shift 3 #进行第二次［三个变量的shift］
echo "Total parameter number is ==> $#"
echo "Your whole parameter is ==> '$@'"
