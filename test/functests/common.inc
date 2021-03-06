# libfaketime-specific common support routines for tests

LIB_BUILD_PATH="../src/$(grep 'LT_OBJDIR' ../config.h | cut -d'"' -f2)"
LIBFAKETIME_LA=$(find "$LIB_BUILD_PATH" | grep 'libfaketime\.\(dylib\|so\)$')

# say which *_fakecmd wrapper to use
platform()
{
	# may want to expand the pattern for linuxlike
	typeset out=$(uname)
	case "$out" in
	*Darwin*) echo "mac" ;;
	*Linux*) echo "linuxlike" ;;
    GNU|GNU/kFreeBSD) echo "linuxlike" ;;
        *SunOS*) echo "sunos" ;;
	*) echo 1>&2 unsupported platform, uname=\"$out\" ;;
	esac
}

# run faked command on a mac
# UNTESTED
mac_fakecmd()
{
	typeset timestring="$1"; shift
	typeset fakelib="$LIBFAKETIME_LA"
	export DYLD_INSERT_LIBRARIES=$fakelib
	export DYLD_FORCE_FLAT_NAMESPACE=1
	FAKETIME="$timestring" \
	"$@"
}

sunos_fakecmd()
{
        typeset timestring="$1"; shift
        typeset fakelib="$LIBFAKETIME_LA"
        export LD_PRELOAD=$fakelib
        FAKETIME="$timestring" \
        "$@"
}

# run faked command on linuxlike OS
linuxlike_fakecmd()
{
	typeset timestring="$1"; shift
	typeset fakelib="$LIBFAKETIME_LA"
	export LD_PRELOAD=$fakelib
	FAKETIME="$timestring" \
	"$@"
}

# run a command with libfaketime using the given timestring
fakecmd()
{
	${PLATFORM}_fakecmd "$@"
}

# generate a sequence of numbers from a to b
range()
{
	typeset a=$1 b=$2
	typeset i=$a
	while ((i <= b)); do
		echo $i
		((i = i+1))
	done
}
