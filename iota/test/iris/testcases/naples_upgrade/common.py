import subprocess
import json
import time
import iota.harness.api as api
import iota.harness.infra.store as store
import iota.test.iris.testcases.drivers.cmd_builder as cmd_builder
import iota.test.iris.utils.naples_host as naples_host_util

UPGRADE_ROOT_DIR = 'upgrade_bin'

UPGRADE_NAPLES_PKG = "nic/naples_fw.tar"
