#! /bin/bash

set -e
export NICDIR=`pwd`
export NON_PERSISTENT_LOGDIR=${NICDIR}
export ZMQ_SOC_DIR=${NICDIR}
export CAPRI_MOCK_MODE=1
export CAPRI_MOCK_MEMORY_MODE=1
export SKIP_VERIFY=1
export BUILD_DIR=${NICDIR}/build/x86_64/apulu/
export GEN_TEST_RESULTS_DIR=${BUILD_DIR}/gtest_results
export CONFIG_PATH=${NICDIR}/conf
#export GDB='gdb --args'
# @kalyanbade please figure out thats going on
export VPP_IPC_MOCK_MODE=1

cfgfile=apulu/scale_cfg.json
if [[ "$1" ==  --cfg ]]; then
    cfgfile=$2
fi

function finish {
    echo "===== Collecting logs ====="
    ${NICDIR}/apollo/test/tools/savelogs.sh
    rm -f ${NICDIR}/conf/pipeline.json
    pkill -9 vpp
    rm -f /tmp/pen_ipc_*
    rm -f /dev/ipc_*
}
trap finish EXIT

export PATH=${PATH}:${BUILD_DIR}/bin
rm -f $NICDIR/conf/pipeline.json
ln -s $NICDIR/conf/apulu/pipeline.json $NICDIR/conf/pipeline.json

echo "Starting VPP"
sudo $NICDIR/vpp/tools/start-vpp-mock.sh --pipeline apulu
if [[ $? != 0 ]]; then
    echo "Failed to bring up VPP"
    exit -1
fi

$GDB apulu_scale_test -c hal.json -i ${NICDIR}/apollo/test/scale/$cfgfile --gtest_output="xml:${GEN_TEST_RESULTS_DIR}/apulu_scale_test.xml"
rm -f $NICDIR/conf/pipeline.json
if [ $? -eq 0 ]
then
    rm -f apulu_scale_test.log
else
    tail -100 apulu_scale_test.log
fi
#$GDB apulu_scale_test -p p1 -c hal.json -i ${NICDIR}/apollo/test/scale/scale_cfg_p1.json --gtest_output="xml:${GEN_TEST_RESULTS_DIR}/apulu_scale_test.xml"
#$GDB apulu_scale_test -c hal.json -i ${NICDIR}/apollo/test/scale/scale_cfg_v4_only.json --gtest_output="xml:${GEN_TEST_RESULTS_DIR}/apulu_scale_test.xml"
#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --gen-suppressions=all --verbose --error-limit=no --log-file=valgrind-out.txt apulu_scale_test -c hal.json -i ${NICDIR}/apollo/test/scale/scale_cfg_v4_only.json
