import os
from subprocess import call
import sys
import argparse

pwd          = os.getcwd()

# common files for both x86_64 and aarch64
files        = [ ]#'nic/tools/package/pack_common.txt' ]

# default is aarch64 packaging and strip the libs and binaries
arch         = 'aarch64'
arm_pkg      = 1
strip_target = 1
create_tgz   = 1
objcopy_bin  = '/tool/toolchain/aarch64-1.1/bin/aarch64-linux-gnu-objcopy'
strip_bin    = '/tool/toolchain/aarch64-1.1/bin/aarch64-linux-gnu-strip'
output_dir   = pwd + '/fake_root_target/aarch64'
tar_name     = 'nic'
rm_out_dir   = 0   #It is not clear if we need fake root targer. Till then we use this flag to determine if we need to remove "output_dir" after packaging


###########################
##### CMDLINE PARSING #####
###########################

parser = argparse.ArgumentParser()

parser.add_argument('--target', dest='target',
                    default='haps',
                    help='Package for sim, haps, arm-dev, zebu, debug, debug-arm')

# Do not strip the target shared libs and binaries
parser.add_argument('--no-strip', dest='no_strip',
                    default=None,
                    action='store_true',
                    help='Do not strip the target shared libs and binaries')

# Do not gzip the tar ball
parser.add_argument('--no-tgz', dest='no_tgz',
                    default=None,
                    action='store_true',
                    help='Do not gzip the tar ball')

# dry run - dumps debugs, doesn't package anything
parser.add_argument('--dry-run', dest='dry_run',
                    default=None,
                    action='store_true',
                    help='Dump debug info. Does not package anything')

# pipeline
parser.add_argument('--pipeline', dest='pipeline', default='iris',
                     action='store', choices=['apollo', 'gft', 'iris'],
                     help='Pipeline')

args = parser.parse_args()
def process_files(files, arch, pipeline):
    new_files = []
    for f in files:
        f.replace("$ARCH", arch)
        f.replace("$PIPELINE", pipeline);
        new_files.append(f);
    print files
    print "NEW files"
    print new_files
    return new_files

if args.target == 'sim':
    print ("Packaging for sim platform")
    arm_pkg     = 0
    objcopy_bin = 'objcopy'
    strip_bin   = 'strip'
    arch = 'x86_64'
    output_dir  = pwd + '/fake_root_target/x86_64'
    if args.pipeline == 'apollo':
        files.append('nic/tools/package/pack_apollo.txt')
    elif args.pipeline == 'gft':
        files.append('nic/tools/package/pack_gft.txt')
    else:
        files.append('nic/tools/package/pack_sim.txt')
elif args.target == 'zebu':
    print ("Packaging for zebu")
    arm_pkg     = 0
    objcopy_bin = 'objcopy'
    strip_bin   = 'strip'
    arch = 'x86_64'
    output_dir  = pwd + '/fake_root_target/x86_64'
    files.append('nic/tools/package/pack_zebu.txt')
elif args.target == 'arm-dev':
    print ("Packaging for arm-dev")
    files.append('nic/tools/package/pack_arm_dev.txt')
    files.append('nic/tools/package/pack_debug.txt')
elif args.target == 'haps-dbg':
    print ("Packaging for haps-dbg")
    files.append('nic/tools/package/pack_haps.txt')
    files.append('nic/tools/package/pack_haps_dbg.txt')
    files.append('nic/tools/package/pack_debug.txt')
elif args.target == 'host':
    print ("Packaging for host")
    arm_pkg     = 0
    objcopy_bin = 'objcopy'
    strip_bin   = 'strip'
    output_dir  = pwd + '/fake_root_target/x86_64'
    arch = 'x86_64'
    tar_name    = 'host'
    files = []
    files.append('nic/tools/package/pack_host.txt')
elif args.target == 'debug' or args.target == 'debug-arm':
    print ("Packaging for debug")
    if args.target == 'debug-arm':
        arch = 'aarch64'
    else:
        arch = 'x86_64'
        arm_pkg = 0
        objcopy_bin = 'objcopy'
        strip_bin   = 'strip'
    output_dir  = pwd + '/pack_tmp'
    rm_out_dir  = 1
    tar_name    = 'debug_' + arch + '_' +  args.pipeline
    files = []
    files.append('nic/tools/package/pack_debug.txt')
else:
    print ("Packaging for haps")

    if args.pipeline == 'apollo':
        files.append('nic/tools/package/pack_apollo.txt')
    elif args.pipeline == 'gft':
        files.append('nic/tools/package/pack_gft.txt')
    else:
        files.append('nic/tools/package/pack_haps.txt')
        # skip platform for apollo
        files.append('nic/tools/package/pack_platform.txt')

    files.append('nic/tools/package/pack_debug.txt')

if args.no_strip == True:
    strip_target = 0

if args.no_tgz == True:
    create_tgz = 0

if args.dry_run == True:
    print ("strip target: " + str(strip_target))
    sys.exit(0)

###################################
##### Process packaging files #####
###################################

# Process input files
for input_file in files:
    print ("Processing input file: " + input_file)
    f  = open(input_file, 'r')

    for line in f:
        # skip comments or empty line
        if line.startswith('#') or line == '\n':
            continue

        items = line.split()
        items[0] = items[0].replace("$ARCH", arch)
        items[0] = items[0].replace("$PIPELINE", args.pipeline)
        items[1] = items[1].replace("$PIPELINE", args.pipeline)

        output_file = output_dir + '/' + items[1]

        if items[1][-1] == '/':
            directory = output_file
        else:
            directory = os.path.dirname(output_file)

        if not os.path.exists(directory):
            print ('Creating dir: ' + directory)
            os.makedirs(directory)

        if (os.path.isdir(items[0])):
            print('Copying dir: ' + items[0] + '/*  --> ' + directory)
            cmd = 'cp -rL ' + items[0] + '/* ' + directory
            call(cmd, shell=True)
        else:
            if not 'dummy' in items[0]:
                if '.tar' in items[0]:
                    cmd = 'tar -xvf' + items[0] + ' -C ' + directory
                else:
                    cmd = 'cp ' + items[0] + ' ' + output_file
                print (cmd)
                call(cmd, shell=True)

###################################
##### strip libs and binaries #####
###################################

for root, dirs, files in os.walk(output_dir):
    for file in files:
        if '.so' in file or 'hal' in file or 'linkmgr' in file:
            non_stripped = os.path.join(root, file)
            call(['chmod', '755', non_stripped])
            # strip the libs and binaries
            if strip_target == 1:
                call([objcopy_bin, '--only-keep-debug', non_stripped, non_stripped + '.debug'])
                call([strip_bin, non_stripped])
                call([objcopy_bin, '--add-gnu-debuglink=' + non_stripped + '.debug', non_stripped])

###########################
##### post processing #####
###########################

cmd = 'mkdir -p ' + output_dir + '/nic/lib'
call(cmd, shell=True)

# remove dol plugin for aarch64
if arm_pkg == 1:
    cmd = 'rm -rf ' + output_dir + '/nic/conf/plugins/dol'
    call(cmd, shell=True)

# remove *.log from nic/conf/init_bins libs
cmd = 'find ' + output_dir + '/nic/conf/init_bins -name "*.log" | xargs rm -f'
call(cmd, shell=True)

##### TODO REVERT LATER #####

# remove *.a from platform libs
cmd = 'rm -f ' + output_dir + '/platform/lib/*.a'
call(cmd, shell=True)

# remove csrlite until main csr lib is not removed
cmd = 'rm -f ' + output_dir + '/nic/conf/sdk/external/libcsrlite.so'
call(cmd, shell=True)

# rename libzmq.so to libzmq.so.3
if arm_pkg == 0:
    cmd = 'mv ' + output_dir + '/nic/lib/libzmq.so ' + output_dir + '/nic/lib/libzmq.so.3'
    call(cmd, shell=True)

#####################################
##### Generate NIC version file #####
#####################################

if args.target != 'host':
    cmd = "./nic/tools/gen_version.py --output-dir " + output_dir + "/nic/etc/"
    call(cmd, shell=True)

############################
##### create tar balls #####
############################

print ("creating " + tar_name + " tar ball")

tar_output_dir = pwd + '/nic'

cmd = 'cd ' + output_dir + ' && tar --exclude=*.debug -cf ' + tar_output_dir + '/' + tar_name + '.tar *'
call(cmd, shell=True)

# create tar.gz
if create_tgz == 1:
    print ("creating gzipped " + tar_name + " tar ball")
    cmd = 'cd ' + output_dir + ' && tar --exclude=*.debug -czf ' + tar_output_dir + '/' + tar_name + '.tgz * && chmod 766 ' + tar_output_dir + '/' + tar_name + '.tgz'
    call(cmd, shell=True)
    if rm_out_dir:
        cmd= 'rm -rf ' + output_dir
        print cmd
        call(cmd, shell=True)
