#!/bin/bash
PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
export PATH
users=$(cut -d ":" -f1 /etc/passwd)
for username in ${users}
do
    id ${username}
done
