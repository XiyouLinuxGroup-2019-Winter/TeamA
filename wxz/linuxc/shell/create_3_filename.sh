#!/bin/bash
#program:
#     Program creates three files,which named by user's input and date command.
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
#1.让使用者输入文件名称，并取得fileuser这个变量
echo "I will use 'touch' command to create 3 files." #纯粹显示信息
read -p "please input your filename:" fileuser #提示使用者输入
#2.为了避免使用者随意按Enter，利用变量功能分析文件名是否有设置？
filename=${fileuser:-"filename"} #开始判断是否配置文件名
#3.开始利用date命令来取得所需要的文件名了
date1=$(date --date='2 day ago' +%Y%m%d) #前两天的日期
date2=$(date --date='1 day ago' +%Y%m%d) #前一天的日期
date3=$(date +%Y%m%d) #今天的日期
file1=${filename}${date1} #下面三行在配置文件名
file2=${filename}${date2}
file3=${filename}${date3}
#4.将文件名建立吧！
touch "${file1}"
touch "${file2}"
touch "${file3}"
