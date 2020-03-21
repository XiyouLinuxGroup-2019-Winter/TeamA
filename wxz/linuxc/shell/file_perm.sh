#!/bin/bash

PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
#1.让使用者输入文件名，并且判断使用者是否真的有输入字符？
echo "please input a filename,I will check the filename's type and permisson. \n\n"
read -p "Input a filename:" filename
test -z ${filename} && echo "You MUST input a filename." && exit 0
#2.判断文件是否存在？若不存在则显示信息并结束脚本
test ! -e ${filename} && echo "The filename '${filename}' DO NOT exist" && exit 0
#3.开始判断文件类型与属性
test -f ${filename} && filetype="regulare file"
test -d ${filename} && filetype="directory"
test -r ${filename} && perm="readable"
test -w ${filename} && perm="${perm} writable"
test -x ${filename} && perm="${perm} executable"
#4.开始输出信息
echo "The filename: ${filename} is a ${filetype}"
echo "And the permisson for you are : ${perm}"
