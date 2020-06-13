TOOLS_DIR=`dirname $0`
ABS_TOOLS_DIR=`readlink -f $TOOLS_DIR`
NIC_DIR=`dirname $ABS_TOOLS_DIR`
export HAL_CONFIG_PATH=$NIC_DIR/conf/
export LD_LIBRARY_PATH=$NIC_DIR/conf/sdk/external:$NIC_DIR/conf/sdk:$NIC_DIR/lib:/usr/local/lib:$LD_LIBRARY_PATH
export MODEL_ZMQ_TYPE_TCP=1
ulimit -c unlimited
ldd $NIC_DIR/build/x86_64/iris/bin
$GDB $NIC_DIR/build/x86_64/iris/bin/hal -c hal.json
