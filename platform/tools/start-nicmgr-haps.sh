#!/bin/sh

SYSCONFIG=/sysconfig/config0

export NIC_DIR='/nic'
export PLATFORM_DIR='/platform'
export LOG_DIR='/obfl'
export NICMGR_LOG_LEVEL=debug
export NICMGR_CONFIG_PATH=$PLATFORM_DIR/etc/nicmgrd
export NICMGR_LIBRARY_PATH=$PLATFORM_DIR/lib:$NIC_DIR/lib:$NIC_DIR/conf/sdk:$LD_LIBRARY_PATH
export HAL_CONFIG_PATH=$NIC_DIR/conf/

# Thie must be set before the script gets executed
# export FWD_MODE="$1"

# Remove logs
rm -f /nicmgr.log*

ulimit -c unlimited

export SYSUUID=""
if [ -r $SYSCONFIG/sysuuid ]; then
    export SYSUUID=`cat $SYSCONFIG/sysuuid`
fi

export CONFIG_FILE=""
if [ -r $SYSCONFIG/device.conf ]; then
    CONFIG_FILE="$SYSCONFIG/device.conf"
else
    CONFIG_FILE="none"
fi

export MODE_FLAG=""
if [[ "$FWD_MODE" != "classic" ]]; then
    MODE_FLAG="-s"
fi

ARGS="$MODE_FLAG -c $CONFIG_FILE -p haps"

export LD_LIBRARY_PATH=$NICMGR_LIBRARY_PATH
exec $PLATFORM_DIR/bin/nicmgrd $ARGS
