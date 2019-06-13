#!/bin/bash

###############################################################################
#
# Referred: http://easyfwgen.morizot.net/gen/index.php
#

# IPTables location - change accordingly
IPT="/usr/sbin/iptables"

# OOB Interface
OOB_IFACE="oob_mnic0"

###############################################################################
#
# Flush any existing rules or chains
#

echo "Flushing IP Tables ..."

# Reset Default Policies
$IPT -P INPUT ACCEPT
$IPT -P FORWARD ACCEPT
$IPT -P OUTPUT ACCEPT

# Flush all rules
$IPT -F

# Erase all non-default chains
$IPT -X

###############################################################################
#
# User-Specified Chains
#
# Create user chains to reduce the number of rules each packet
# must traverse.
$IPT -N udp_inbound

###############################################################################
#
# Populate User Chains
#

# udp_inbound
# This chain is for inbound udp packets only.
# Block traceroute on OOB and inband:
# - traceroute has different implementations in linux vs windows.
#   For linux: https://2buntu.com/articles/1203/traceroute-how-does-it-work/
#   For Windows:
#    https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-2000-server/cc940128(v=technet.10)
#   The difference is linux sends UDP packets with a set of reserved dports
#   whereas windows uses ICMP echo request with ICMP echo reply.
#   But for windows its getting tricky as it may affect normal ping as well.
$IPT -A udp_inbound -p UDP --dport 33434:33474 -j DROP

# Not matched, so return for logging
$IPT -A udp_inbound -p UDP -j RETURN

###############################################################################
#
# INPUT Chain
#

echo "Process INPUT chain ..."

# Route to appropriate user chain
$IPT -A INPUT -p UDP -j udp_inbound
#$IPT -A INPUT -p UDP -i $OOB_IFACE -j udp_inbound

