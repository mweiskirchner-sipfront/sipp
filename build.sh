#!/bin/sh
set -e  # abort on error

MAKE=`which gmake make 2>/dev/null | head -n1`  # prefer GNU make
test -z "$MAKE" && echo "No (g)make found" >&2 && exit 1
CPUCOUNT=$(nproc --all 2>/dev/null || echo 1)
MAKEFLAGS="-j$CPUCOUNT"

if test -z "$*"; then
    echo "build.sh: Please specify configure options," \
        "--none for defaults, or --full for all" >&2
    exit 1
elif test "$*" = "--help" || test "$*" = "-h"; then
    echo "build.sh: Please specify configure options," \
        "--none for defaults, or --full for all" >&2
    exit 1
fi

if test "$*" = "--none"; then
    cmake . -DUSE_GSL=
elif test "$*" = "--common"; then
    cmake . -DUSE_GSL=1 -DUSE_PCAP=1 -DUSE_SSL= -DUSE_SCTP= -DUSE_MQTT=1
elif test "$*" = "--full"; then
    cmake . -DUSE_GSL=1 -DUSE_PCAP=1 -DUSE_SSL=1 -DUSE_SCTP=1 -DUSE_MQTT=1
else
    cmake . "$@"
fi

# For git checkout, run unit tests.
if test -e gtest/.git; then
	"$MAKE" $MAKEFLAGS sipp_unittest
	./sipp_unittest
fi

"$MAKE" $MAKEFLAGS
