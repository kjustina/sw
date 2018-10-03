#! /usr/bin/python3
import iota.harness.infra.utils.utils   as utils

__status = [
    'SUCCESS',
    'FAILURE',
    'INVALID_ARG',
    'RETRY',
]
status = utils.List2Enum(__status)

__level = {
    0: 'NONE',
    1: 'CRITICAL',
    2: 'ERROR',
    3: 'WARNING',
    4: 'INFO',
    5: 'DEBUG',
    6: 'VERBOSE',
    7: 'MAX'
}
loglevel = utils.Dict2Enum(__level)

__result = [
    'PASS',
    'FAIL',
]
result = utils.List2Enum(__result)

HEADER_SUMMARY = "=" * 90
FORMAT_TESTCASE_SUMMARY = "%-72s %-7s %-8s"
