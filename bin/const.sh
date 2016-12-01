# for timing
declare -x ISO_8601='%Y-%m-%d %H:%M:%S %Z'

# version
declare -xr PROG_MAJOR_VERSION=0
declare -xr PROG_MINOR_VERSION=0
declare -xr PROG_PATCH_VERSION=1
declare -xr PROG_VERSION=${PROG_MAJOR_VERSION}.${PROG_MINOR_VERSION}.${PROG_PATCH_VERSION}

# default values
declare -xi DEFAULT_NUM_THREADS=8
