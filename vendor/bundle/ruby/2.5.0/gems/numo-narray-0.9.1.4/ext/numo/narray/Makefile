
SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
ECHO1 = $(V:1=@ :)
ECHO = $(ECHO1:0=@ echo)
NULLCMD = :

#### Start of system configuration section. ####

srcdir = .
topdir = /Users/shou/.rbenv/versions/2.5.1/include/ruby-2.5.0
hdrdir = $(topdir)
arch_hdrdir = /Users/shou/.rbenv/versions/2.5.1/include/ruby-2.5.0/x86_64-darwin18
PATH_SEPARATOR = :
VPATH = $(srcdir):$(arch_hdrdir)/ruby:$(hdrdir)/ruby
prefix = $(DESTDIR)/Users/shou/.rbenv/versions/2.5.1
rubysitearchprefix = $(rubylibprefix)/$(sitearch)
rubyarchprefix = $(rubylibprefix)/$(arch)
rubylibprefix = $(libdir)/$(RUBY_BASE_NAME)
exec_prefix = $(prefix)
vendorarchhdrdir = $(vendorhdrdir)/$(sitearch)
sitearchhdrdir = $(sitehdrdir)/$(sitearch)
rubyarchhdrdir = $(rubyhdrdir)/$(arch)
vendorhdrdir = $(rubyhdrdir)/vendor_ruby
sitehdrdir = $(rubyhdrdir)/site_ruby
rubyhdrdir = $(includedir)/$(RUBY_VERSION_NAME)
vendorarchdir = $(vendorlibdir)/$(sitearch)
vendorlibdir = $(vendordir)/$(ruby_version)
vendordir = $(rubylibprefix)/vendor_ruby
sitearchdir = $(DESTDIR)./.gem.20190716-89304-1ftotkc
sitelibdir = $(DESTDIR)./.gem.20190716-89304-1ftotkc
sitedir = $(rubylibprefix)/site_ruby
rubyarchdir = $(rubylibdir)/$(arch)
rubylibdir = $(rubylibprefix)/$(ruby_version)
sitearchincludedir = $(includedir)/$(sitearch)
archincludedir = $(includedir)/$(arch)
sitearchlibdir = $(libdir)/$(sitearch)
archlibdir = $(libdir)/$(arch)
ridir = $(datarootdir)/$(RI_BASE_NAME)
mandir = $(datarootdir)/man
localedir = $(datarootdir)/locale
libdir = $(exec_prefix)/lib
psdir = $(docdir)
pdfdir = $(docdir)
dvidir = $(docdir)
htmldir = $(docdir)
infodir = $(datarootdir)/info
docdir = $(datarootdir)/doc/$(PACKAGE)
oldincludedir = $(SDKROOT)/usr/include
includedir = $(prefix)/include
localstatedir = $(prefix)/var
sharedstatedir = $(prefix)/com
sysconfdir = $(prefix)/etc
datadir = $(datarootdir)
datarootdir = $(prefix)/share
libexecdir = $(exec_prefix)/libexec
sbindir = $(exec_prefix)/sbin
bindir = $(exec_prefix)/bin
archdir = $(rubyarchdir)


CC = clang
CXX = clang++
LIBRUBY = $(LIBRUBY_A)
LIBRUBY_A = lib$(RUBY_SO_NAME)-static.a
LIBRUBYARG_SHARED = 
LIBRUBYARG_STATIC = -l$(RUBY_SO_NAME)-static -framework Foundation
empty =
OUTFLAG = -o $(empty)
COUTFLAG = -o $(empty)
CSRCFLAG = $(empty)

RUBY_EXTCONF_H = numo/extconf.h
cflags   = $(optflags) $(debugflags) $(warnflags)
cxxflags = $(optflags) $(debugflags) $(warnflags)
optflags = -O3
debugflags = -ggdb3
warnflags = -Wall -Wextra -Wno-unused-parameter -Wno-parentheses -Wno-long-long -Wno-missing-field-initializers -Wno-tautological-compare -Wno-parentheses-equality -Wno-constant-logical-operand -Wno-self-assign -Wunused-variable -Wimplicit-int -Wpointer-arith -Wwrite-strings -Wdeclaration-after-statement -Wshorten-64-to-32 -Wimplicit-function-declaration -Wdivision-by-zero -Wdeprecated-declarations -Wextra-tokens
CCDLFLAGS = -fno-common
CFLAGS   = $(CCDLFLAGS)  -O3 -Wno-error=shorten-64-to-32  -pipe $(ARCH_FLAG)
INCFLAGS = -I. -Itypes -I$(arch_hdrdir) -I$(hdrdir)/ruby/backward -I$(hdrdir) -I$(srcdir)
DEFS     = 
CPPFLAGS = -DRUBY_EXTCONF_H=\"$(RUBY_EXTCONF_H)\" -I/Users/shou/.rbenv/versions/2.5.1/include  -D_XOPEN_SOURCE -D_DARWIN_C_SOURCE -D_DARWIN_UNLIMITED_SELECT -D_REENTRANT $(DEFS) $(cppflags)
CXXFLAGS = $(CCDLFLAGS) $(cxxflags) $(ARCH_FLAG)
ldflags  = -L. -L/Users/shou/.rbenv/versions/2.5.1/lib  -fstack-protector -L/usr/local/lib
dldflags = -L/Users/shou/.rbenv/versions/2.5.1/lib  -Wl,-undefined,dynamic_lookup -Wl,-multiply_defined,suppress 
ARCH_FLAG = 
DLDFLAGS = $(ldflags) $(dldflags) $(ARCH_FLAG)
LDSHARED = $(CC) -dynamic -bundle
LDSHAREDXX = $(CXX) -dynamic -bundle
AR = libtool -static
EXEEXT = 

RUBY_INSTALL_NAME = $(RUBY_BASE_NAME)
RUBY_SO_NAME = ruby.2.5.1
RUBYW_INSTALL_NAME = 
RUBY_VERSION_NAME = $(RUBY_BASE_NAME)-$(ruby_version)
RUBYW_BASE_NAME = rubyw
RUBY_BASE_NAME = ruby

arch = x86_64-darwin18
sitearch = $(arch)
ruby_version = 2.5.0
ruby = $(bindir)/$(RUBY_BASE_NAME)
RUBY = $(ruby)
ruby_headers = $(hdrdir)/ruby.h $(hdrdir)/ruby/backward.h $(hdrdir)/ruby/ruby.h $(hdrdir)/ruby/defines.h $(hdrdir)/ruby/missing.h $(hdrdir)/ruby/intern.h $(hdrdir)/ruby/st.h $(hdrdir)/ruby/subst.h $(arch_hdrdir)/ruby/config.h $(RUBY_EXTCONF_H)

RM = rm -f
RM_RF = $(RUBY) -run -e rm -- -rf
RMDIRS = rmdir -p
MAKEDIRS = /usr/local/bin/gmkdir -p
INSTALL = /usr/local/bin/ginstall -c
INSTALL_PROG = $(INSTALL) -m 0755
INSTALL_DATA = $(INSTALL) -m 644
COPY = cp
TOUCH = exit >

#### End of system configuration section. ####

preload = 
libpath = . $(libdir)
LIBPATH =  -L. -L$(libdir)
DEFFILE = 

CLEANFILES = mkmf.log
DISTCLEANFILES = 
DISTCLEANDIRS = 

extout = 
extout_prefix = 
target_prefix = /numo
LOCAL_LIBS = 
LIBS =   -lpthread -lgmp -ldl -lobjc 
ORIG_SRCS = SFMT.c array.c data.c index.c kwargs.c math.c narray.c ndloop.c rand.c step.c struct.c
SRCS = $(ORIG_SRCS) narray.c array.c step.c index.c ndloop.c data.c bit.c int8.c int16.c int32.c int64.c uint8.c uint16.c uint32.c uint64.c sfloat.c dfloat.c scomplex.c dcomplex.c robject.c math.c SFMT.c struct.c rand.c
OBJS = narray.o array.o step.o index.o ndloop.o data.o types/bit.o types/int8.o types/int16.o types/int32.o types/int64.o types/uint8.o types/uint16.o types/uint32.o types/uint64.o types/sfloat.o types/dfloat.o types/scomplex.o types/dcomplex.o types/robject.o math.o SFMT.o struct.o rand.o
HDRS = $(srcdir)/SFMT-params.h $(srcdir)/SFMT-params19937.h $(srcdir)/SFMT.h
LOCAL_HDRS = 
TARGET = narray
TARGET_NAME = narray
TARGET_ENTRY = Init_$(TARGET_NAME)
DLLIB = $(TARGET).bundle
EXTSTATIC = 
STATIC_LIB = 

TIMESTAMP_DIR = .
BINDIR        = $(bindir)
RUBYCOMMONDIR = $(sitedir)$(target_prefix)
RUBYLIBDIR    = $(sitelibdir)$(target_prefix)
RUBYARCHDIR   = $(sitearchdir)$(target_prefix)
HDRDIR        = $(rubyhdrdir)/ruby$(target_prefix)
ARCHHDRDIR    = $(rubyhdrdir)/$(arch)/ruby$(target_prefix)
TARGET_SO_DIR =
TARGET_SO     = $(TARGET_SO_DIR)$(DLLIB)
CLEANLIBS     = $(TARGET_SO) 
CLEANOBJS     = *.o  *.bak

all:    $(DLLIB)
static: $(STATIC_LIB)
.PHONY: all install static install-so install-rb
.PHONY: clean clean-so clean-static clean-rb

clean-static::
clean-rb-default::
clean-rb::
clean-so::
clean: clean-so clean-static clean-rb-default clean-rb
		-$(Q)$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES) .*.time

distclean-rb-default::
distclean-rb::
distclean-so::
distclean-static::
distclean: clean distclean-so distclean-static distclean-rb-default distclean-rb
		-$(Q)$(RM) Makefile $(RUBY_EXTCONF_H) conftest.* mkmf.log
		-$(Q)$(RM) core ruby$(EXEEXT) *~ $(DISTCLEANFILES)
		-$(Q)$(RMDIRS) $(DISTCLEANDIRS) 2> /dev/null || true

realclean: distclean
install: install-so install-rb

install-so: $(DLLIB) $(TIMESTAMP_DIR)/.sitearchdir.-.numo.time
	$(INSTALL_PROG) $(DLLIB) $(RUBYARCHDIR)
clean-static::
	-$(Q)$(RM) $(STATIC_LIB)
install-rb: pre-install-rb do-install-rb install-rb-default
install-rb-default: pre-install-rb-default do-install-rb-default
pre-install-rb: Makefile
pre-install-rb-default: Makefile
do-install-rb:
do-install-rb-default:
pre-install-rb-default:
	@$(NULLCMD)
pre-install-rb: $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
do-install-rb: $(RUBYARCHDIR)/numo/ndloop.h
$(RUBYARCHDIR)/numo/ndloop.h: $(srcdir)/numo/ndloop.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/ndloop.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/intern.h
$(RUBYARCHDIR)/numo/intern.h: $(srcdir)/numo/intern.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/intern.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/compat.h
$(RUBYARCHDIR)/numo/compat.h: $(srcdir)/numo/compat.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/compat.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/narray.h
$(RUBYARCHDIR)/numo/narray.h: $(srcdir)/numo/narray.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/narray.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/template.h
$(RUBYARCHDIR)/numo/template.h: $(srcdir)/numo/template.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/template.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/extconf.h
$(RUBYARCHDIR)/numo/extconf.h: $(srcdir)/numo/extconf.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/extconf.h $(@D)
pre-install-rb: $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
do-install-rb: $(RUBYARCHDIR)/numo/types/float_macro.h
$(RUBYARCHDIR)/numo/types/float_macro.h: $(srcdir)/numo/types/float_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/float_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/dfloat.h
$(RUBYARCHDIR)/numo/types/dfloat.h: $(srcdir)/numo/types/dfloat.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/dfloat.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/float_def.h
$(RUBYARCHDIR)/numo/types/float_def.h: $(srcdir)/numo/types/float_def.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/float_def.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/int_macro.h
$(RUBYARCHDIR)/numo/types/int_macro.h: $(srcdir)/numo/types/int_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/int_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/uint_macro.h
$(RUBYARCHDIR)/numo/types/uint_macro.h: $(srcdir)/numo/types/uint_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/uint_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/scomplex.h
$(RUBYARCHDIR)/numo/types/scomplex.h: $(srcdir)/numo/types/scomplex.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/scomplex.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/int64.h
$(RUBYARCHDIR)/numo/types/int64.h: $(srcdir)/numo/types/int64.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/int64.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/xint_macro.h
$(RUBYARCHDIR)/numo/types/xint_macro.h: $(srcdir)/numo/types/xint_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/xint_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/uint32.h
$(RUBYARCHDIR)/numo/types/uint32.h: $(srcdir)/numo/types/uint32.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/uint32.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/int16.h
$(RUBYARCHDIR)/numo/types/int16.h: $(srcdir)/numo/types/int16.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/int16.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/real_accum.h
$(RUBYARCHDIR)/numo/types/real_accum.h: $(srcdir)/numo/types/real_accum.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/real_accum.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/bit.h
$(RUBYARCHDIR)/numo/types/bit.h: $(srcdir)/numo/types/bit.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/bit.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/robj_macro.h
$(RUBYARCHDIR)/numo/types/robj_macro.h: $(srcdir)/numo/types/robj_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/robj_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/int32.h
$(RUBYARCHDIR)/numo/types/int32.h: $(srcdir)/numo/types/int32.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/int32.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/uint16.h
$(RUBYARCHDIR)/numo/types/uint16.h: $(srcdir)/numo/types/uint16.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/uint16.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/complex_macro.h
$(RUBYARCHDIR)/numo/types/complex_macro.h: $(srcdir)/numo/types/complex_macro.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/complex_macro.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/dcomplex.h
$(RUBYARCHDIR)/numo/types/dcomplex.h: $(srcdir)/numo/types/dcomplex.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/dcomplex.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/sfloat.h
$(RUBYARCHDIR)/numo/types/sfloat.h: $(srcdir)/numo/types/sfloat.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/sfloat.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/uint8.h
$(RUBYARCHDIR)/numo/types/uint8.h: $(srcdir)/numo/types/uint8.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/uint8.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/robject.h
$(RUBYARCHDIR)/numo/types/robject.h: $(srcdir)/numo/types/robject.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/robject.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/complex.h
$(RUBYARCHDIR)/numo/types/complex.h: $(srcdir)/numo/types/complex.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/complex.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/uint64.h
$(RUBYARCHDIR)/numo/types/uint64.h: $(srcdir)/numo/types/uint64.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/uint64.h $(@D)
do-install-rb: $(RUBYARCHDIR)/numo/types/int8.h
$(RUBYARCHDIR)/numo/types/int8.h: $(srcdir)/numo/types/int8.h $(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time
	$(Q) $(INSTALL_DATA) $(srcdir)/numo/types/int8.h $(@D)
pre-install-rb:
	$(Q1:0=@$(MAKE) -q do-install-rb || )$(ECHO1:0=echo) installing narray libraries
$(TIMESTAMP_DIR)/.sitearchdir.-.numo.time:
	$(Q) $(MAKEDIRS) $(@D) $(RUBYARCHDIR)
	$(Q) $(TOUCH) $@
$(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.time:
	$(Q) $(MAKEDIRS) $(@D) $(RUBYARCHDIR)/numo
	$(Q) $(TOUCH) $@
$(TIMESTAMP_DIR)/.sitearchdir.-.numo.-.numo.-.types.time:
	$(Q) $(MAKEDIRS) $(@D) $(RUBYARCHDIR)/numo/types
	$(Q) $(TOUCH) $@

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

.SUFFIXES: .c .m .cc .mm .cxx .cpp .o .S

.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cc.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.mm.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.mm.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cxx.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cxx.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cpp.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cpp.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.c.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.c.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.m.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.m.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

$(TARGET_SO): $(OBJS) Makefile
	$(ECHO) linking shared-object numo/$(DLLIB)
	-$(Q)$(RM) $(@)
	$(Q) $(LDSHARED) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LOCAL_LIBS) $(LIBS)
	$(Q) $(POSTLINK)



###
$(OBJS): $(RUBY_EXTCONF_H)

TAGSRC = \
 ../../ruby/include/ruby/*.h \
 ../../ruby/*.c \
 *.h \
 types/*.h \
 *.c \
 types/*.c

tags : TAGS
TAGS : $(TAGSRC)
	etags $(TAGSRC)

doc :
	yard doc *.c types/*.c

C_TMPL = /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_numeric.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/clip.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_binary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/eye.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/allocate.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/logseq.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/poly.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/bincount.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_class.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast_array.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/class.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/frexp.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/map_with_index.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/each_with_index.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/format.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/inspect.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary2.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/module.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_module.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/set2.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/coerce_cast.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_array.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_bit.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/pow.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/fill.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/powint.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/new_dim0.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary_s.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/aset.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary2.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/format_to_a.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/aref.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/each.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_ret2.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand_norm.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/to_a.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/allocate.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/extract.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/store_from.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/where.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/each_with_index.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/format.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/inspect.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/store_array.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/binary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/store_bit.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/unary.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/bit_reduce.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/fill.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/aset.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/mask.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/format_to_a.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/bit_count.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/none_p.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/aref.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/each.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/where2.c /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl_bit/to_a.c

COGEN = /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/cogen.rb
DEPENDS = $(C_TMPL) /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/*.rb


types/int8.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int8.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int8.rb

types/robject.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/robject.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/robject.rb

types/dcomplex.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/dcomplex.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/dcomplex.rb

types/int32.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int32.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int32.rb

types/bit.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/bit.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/bit.rb

types/int16.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int16.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int16.rb

types/uint64.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint64.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint64.rb

types/uint32.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint32.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint32.rb

types/uint16.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint16.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint16.rb

types/scomplex.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/scomplex.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/scomplex.rb

types/int64.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int64.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/int64.rb

types/dfloat.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/dfloat.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/dfloat.rb

types/uint8.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint8.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/uint8.rb

types/sfloat.c: /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/sfloat.rb $(DEPENDS)
	$(MAKEDIRS) $(@D) types
	ruby $(COGEN) -l -o $@ /Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/def/sfloat.rb


src : types/int8.c types/robject.c types/dcomplex.c types/int32.c types/bit.c types/int16.c types/uint64.c types/uint32.c types/uint16.c types/scomplex.c types/int64.c types/dfloat.c types/uint8.c types/sfloat.c

CLEANOBJS = *.o */*.o *.bak types/*.c
