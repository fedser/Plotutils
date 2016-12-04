## Process this file with automake to produce Makefile.in

bin_PROGRAMS = pic2plot

pic2plot_SOURCES = common.cc lex.cc main.cc object.cc plot.cc gram.yy fontlist.c file_handling.cc top_input.cc
pic2plot_LDADD = ../lib/libcommon.a ./libgroff/libgroff.a ../libplot/libplot.la

noinst_HEADERS = common.h object.h output.h pic.h

check_PROGRAMS = unittest

TESTS = unittest

unittest_SOURCES = test/unittest.cc plot.cc object.cc common.cc gram.yy lex.cc file_handling.cc top_input.cc test/unittest_output.cc
unittest_CPPFLAGS = -I/usr/include/unittest++
unittest_LDADD = -lUnitTest++ ../libplot/libplot.la ./libgroff/libgroff.a ../lib/libcommon.a

AM_YFLAGS = -d

AM_CPPFLAGS = -I$(srcdir)/../include -I$(srcdir)/include

CLEANFILES = fontlist.c

EXTRA_DIST = gram.h

SUBDIRS = doc include libgroff

fontlist.c: $(top_srcdir)/lib/fontlist.c
	@rm -f fontlist.c ; if $(LN_S) $(top_srcdir)/lib/fontlist.c fontlist.c ; then true ; else cp -p $(top_srcdir)/lib/fontlist.c fontlist.c ; fi
