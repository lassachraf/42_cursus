#!/bin/bash

#Architecture
arch=$(uname -a)

#CPU (Physical/ Virtual)
pcpu=$(grep "physical id" /proc/cpuinfo | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
lcpu=$(mpstat | grep all | awk '{print 100 - $NF}')

#Memory
umem=$(free -m | awk '$1 == "Mem:" {print $3}')
tmem=$(free -m | awk '$1 == "Mem:" {print $2}')
pmem=$(free -m | awk '$1 == "Mem:" {printf("%.2f", $3/$2*100)}')

#Disk
udsk=$(df -Bm | grep "/dev/mapper" | awk '{ud+=$3} END {print ud}')
tdsk=$(df -Bg | grep "/dev/mapper" | awk '{fd+=$2} END {print fd}')
pdsk=$(df -Bm | grep "/dev/mapper" | awk '{ft+=$2} {ud+=$3} END {printf("%d", ud/ft*100)}')

#Boot
lboot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

#LVM
tlvm=$(lsblk | grep "lvm" | wc -l)
ulvm=$(if [ $tlvm -eq 0 ]; then echo no; else echo yes; fi)

#Connections TCP
ctcp=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')

#User log
ulog=$(users | wc -w)

#Network
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')

#Sudo cmd
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "
	#Architecture    : $arch
	#CPU physical    : $pcpu
	#vCPU            : $vcpu
	#Memory Usage    : $umem/$tmem MB ($pmem%)
	#Disk Usage      : $udsk/$tdsk Gb ($pdsk%)
	#CPU load        : $lcpu%
	#Last boot       : $lboot
	#LVM use         : $ulvm
	#Connections TCP : $ctcp ESTABLISHED
	#User log        : $ulog
	#Network         : IP $ip ($mac)
	#Sudo            : $sudo cmd
"
