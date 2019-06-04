#! /bin/bash

set -e
export NICDIR=`pwd`
export HAL_LOG_DIR=${NICDIR}
export ZMQ_SOC_DIR=${NICDIR}
export CAPRI_MOCK_MODE=1
export CAPRI_MOCK_MEMORY_MODE=1
export SKIP_VERIFY=1
export BUILD_DIR=${NICDIR}/build/x86_64/apollo/
export GEN_TEST_RESULTS_DIR=${BUILD_DIR}/gtest_results
export HAL_CONFIG_PATH=${NICDIR}/conf
export COVFILE=${NICDIR}/coverage/sim_bullseye_hal.cov
#export GDB='gdb --args'

if [[ "$1" ==  --coveragerun ]]; then
    export COVFILE=${NICDIR}/coverage/sim_bullseye_hal.cov
fi

function finish {
   echo "===== Collecting logs ====="
   ${NICDIR}/apollo/test/tools/savelogs.sh
}
trap finish EXIT

export PATH=${PATH}:${BUILD_DIR}/bin

# gtests
echo "Running policy test"
$GDB apollo_policy_test -c hal.json -f apollo -n 1024 --gtest_output="xml:${GEN_TEST_RESULTS_DIR}/apollo_policy_test.xml" > apollo_policy_test.log.txt
[[ $? -ne 0 ]] && echo "apollo_policy_test failed!" && exit 1
echo "Success"
