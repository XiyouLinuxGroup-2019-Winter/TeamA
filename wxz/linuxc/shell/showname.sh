#!/bin/bash
#program:
#      user inputs first name and last name.
#History:
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
read -p "Please input your name first name:" firstname #提示使用者输入
read -p "Please input your name last name:" lastname #提示使用者输入
echo "\n Your full name is: ${fistname} ${lastname}" #结果由屏幕输出

