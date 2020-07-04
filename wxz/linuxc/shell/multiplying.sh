#!/bin/bash
#program:
#     user inputs 2 integer numbers;program will cross these two numbers
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
echo "You SHOULD input 2 numbers,I will multiplying them!\n"
read -p "first number: " firstnu
read -p "second number: " secnu
total=$((${firstnu}*${secnu}))
echo "\nThe result of ${firstnu} x ${secnu} is ==>${total}"
