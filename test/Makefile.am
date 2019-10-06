AM_CFLAGS =-DFAKE_SLEEP -DFAKE_INTERNAL_CALLS -I../ -I../src

AM_LDFLAGS = @CHECK_LIBS@

check_PROGRAMS = timetest t_parser_1
timetest_SOURCES = timetest.c

t_parser_1_SOURCES = t_parser_1.c
t_parser_1_CFLAGS = -I../src/
# t_parser_1_LDADD = -lfaketime

if SOLARIS
	AM_CFLAGS += -D__EXTENSIONS__ -D_XOPEN_SOURCE=600
	AM_LDFLAGS += -Wl,--version-script=libfaketime.map
endif
if !MACOS
	AM_CFLAGS += -std=gnu99 -Wall -Wextra -Werror -DFAKE_STAT -DFAKE_PTHREAD -DFAKE_TIMERS -DFAKE_INTERNAL_CALLS -fPIC	-Wno-nonnull-compare
	timetest_LDADD = -ldl -lm -lrt -lpthread
endif

TESTS = ./testframe.sh $(check_PROGRAMS)

# test-local : check
# 	./testframe.sh