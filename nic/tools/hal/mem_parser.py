# {C} Copyright 2018 Pensando Systems Inc. All rights reserved\n

import json
import sys
import os
import re
import pdb

# Input file name
fname_in = sys.argv[1]

# Output file name
fname_out = sys.argv[2]
try:
    d = os.path.dirname(fname_out)
    os.makedirs(d)
except:
    pass

# Name header
name = "MEM_REGION_"

# Headers and footers for the output file
hdr="""
// {C} Copyright 2018 Pensando Systems Inc. All rights reserved\n
#ifndef __%sHPP__\n#define __%sHPP__
// This is an auto generated file

#include "platform/utils/mcache_pipe.hpp"

#ifdef  __cplusplus
namespace mem {
namespace regions {
#endif

"""%(name, name)

ftr="""
#define MEM_REGION_BASE_ADDR       0x0C0000000UL
#define MEM_REGION_ADDR(name)      (MEM_REGION_BASE_ADDR + MEM_REGION_##name##_START_OFFSET)

#ifdef  __cplusplus
} // namespace mem
} // namespace regions

#endif //__cplusplus
#endif
"""

cache_pipes = {
    'p4ig': "MEM_REGION_CACHE_PIPE_P4IG",
    'p4eg': "MEM_REGION_CACHE_PIPE_P4EG",
    'p4plus-txdma': "MEM_REGION_CACHE_PIPE_P4PLUS_TXDMA",
    'p4plus-rxdma': "MEM_REGION_CACHE_PIPE_P4PLUS_RXDMA",
    'p4plus-all': "MEM_REGION_CACHE_PIPE_P4PLUS_ALL" }

try:
    fd = open(fname_out, "w+")
except:
    print "File open failed : " + fname_out
    exit(-1)

def size_str_to_bytes(size_str):
    if "G" in size_str:
        mf = 1024 * 1024 * 1024
    elif "M" in size_str:
        mf = 1024 * 1024
    elif "K" in size_str:
        mf = 1024
    elif "B" in size_str:
        mf = 1
    else:
        return -1

    value = size_str[:-1]
    if value.isdecimal():
        mv = long(size_str[:-1])
    else:
        return -1
    return mf * mv

def parse_file():

    nlist = ""
    olist = ""
    slist = ""
    clist = ""
    rlist = ""
    idx = 0

    with open(sys.argv[1], 'r') as f:
        data = json.load(f)

    if True:
        off = 0
        for e in data['regions']:
            print >> fd, ""
            n = e['name']
            mf = long(1)
            mv = long(0)
            mem_type = e['size']
            s = size_str_to_bytes(mem_type)
            if s == -1:
                print('Invalid size specified for region %s', n)
                exit(-1)
            if e.get('element_size') is None:
                es = -1
            else:
                es = size_str_to_bytes(e['element_size'])

            # Derive the basename for the macros 
            nbase = name + (re.sub("[ -]", "_", n)).upper() + "_"

            # Update name and size
            print >> fd, "#define %-60s \"%s\"" %(nbase + "NAME", n)
            print >> fd, "#define %-60s %ld" %(nbase + "SIZE", s)
            print >> fd, "#define %-60s %ld" %(nbase + "ELEMENT_SIZE", es)

            # Update start offset
            print >> fd, "#define %-60s 0x%lxUL" %(nbase + "START_OFFSET", off);
            off = long(off) + s

            # Update cache pipe
            cv = "MEM_REGION_CACHE_PIPE_NONE"
            if 'cache' in e:
                v = e['cache']
                if v in cache_pipes:
                    cv = str(cache_pipes[v])
                else:
                    print "Invalid cache pipe speciciation : " + v
                    exit(-1)
            print >> fd, "#define %-60s %s" %(nbase + "CACHE_PIPE", cv)

            # Update reset
            reset = 0
            if 'reset' in e and str(e['reset']).lower() == "true":
                reset = 1
            print >> fd, "#define %-60s %d" %(nbase + "RESET", reset)

            idx = idx + 1

            nlist = nlist + "\n    " + nbase + "NAME, \\"
            olist = olist + "\n    " + nbase + "START_OFFSET, \\"
            slist = slist + "\n    " + nbase + "SIZE, \\"
            eslist = slist + "\n    " + nbase + "ELEMENT_SIZE, \\"
            clist = clist + "\n    " + nbase + "CACHE_PIPE, \\"
            rlist = rlist + "\n    " + nbase + "RESET, \\"

    print >> fd, "\n/////////////////////////////////////////////////////////\n"


   # Total regions count
    print >> fd, "#define %-60s %d" %(name + "COUNT" , idx)

    print >> fd, "\n/////////////////////////////////////////////////////////\n"

    # Dump the list of value for name , size etc
    print >> fd, "#define %s {   \\%s }" %(name + "NAME_LIST", nlist[:-3])
    print >> fd, "\n#define %s {   \\%s }" %(name + "SIZE_LIST", slist[:-3])
    print >> fd, "\n#define %s {   \\%s }" %(name + "ELEMENT_SIZE_LIST", eslist[:-3])
    print >> fd, "\n#define %s {   \\%s }" %(name + "START_OFFSET_LIST", olist[:-3])
    print >> fd, "\n#define %s {   \\%s }" %(name + "CACHE_PIPE_LIST", clist[:-3])
    print >> fd, "\n#define %s {   \\%s }" %(name + "RESET_LIST", rlist[:-3])

    print >> fd, "\n/////////////////////////////////////////////////////////\n"

try:
    print >> fd, hdr
    parse_file()
    print >> fd, ftr
    exit(0)
except Exception,e:
    print "Error in opening the file, "  + sys.argv[1]
    print e
    exit(-1)
