#!/bin/bash
#1.一些告知的操作
echo "Now,I will detect your linux service's services"
echo "The www,ftp,ssh,and mail will be detect!\n"
#2.开始一些测试任务，输出一些信息
testfile=/dev/shm/netstat_checking.txt
netstat -tuln > ${testfile} #转存数据到内存中，不用一直执行netstat
testing=$(grep ":80" ${testfile}) #检查80端口
if [ "${testing}" != "" ]; then
        echo "www is runing in your sys"
fi
testing=$(grep ":22" ${testfile}) #检查22端口
if [ "${testing}" != "" ]; then
        echo "SSH is running in your sys"
fi
testing=$(grep ":21" ${testfile}) #检查２１端口
if [ "${testing}" != "" ]; then
        echo "FTP is running in your sys"
fi
testing=$(grep ":25" ${testfile}) #检查25端口
if [ "${testing}" != "" ]; then
        echo "MAil is running in your sys"
fi
