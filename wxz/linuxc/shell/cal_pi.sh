#!/bin/bash
#program:
#      user input a scale number to calculate pi number
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
echo "This program will calculate pi value.\n"
echo "You should input a float number to calculate pi value.\n"
read -p "The scale number (10~1000)?" checking
num=${checking:-"10"} #开始判断是否有输入数值
echo "Starting calculate pi value.Be patient."
time echo "scale=$(num);4*a(1)" | bc -lq
