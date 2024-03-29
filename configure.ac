dnl Process this file with autoconf to produce a configure script.

AC_INIT([pcmanx-gtk2],[0.3.8],[http://groups.google.com/group/PCManX])

AC_CONFIG_HEADERS([config.h])
#AC_PREFIX_DEFAULT(/usr)
AM_INIT_AUTOMAKE
#AM_MAINTAINER_MODE
AC_C_CONST
AC_C_INLINE
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_STAT
AC_CHECK_FUNCS([gethostbyname isascii memset mkdir setenv socket strchr strrchr strstr])
AC_HEADER_STDBOOL
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h fcntl.h libintl.h locale.h netdb.h netinet/in.h stdlib.h string.h sys/ioctl.h sys/socket.h sys/time.h termios.h unistd.h utmp.h])
AC_PATH_X
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_PROG_CC
AC_PROG_CPP
AM_PROG_AS
AC_PROG_CXX
AM_DISABLE_STATIC
AC_PROG_RANLIB
AM_PROG_LIBTOOL
IT_PROG_INTLTOOL([],[no-xml])
AC_PROG_INSTALL

dnl define a new autoconf test, AC_CSRG_BASED, which will define
dnl CSRG_BASED for BSD systems in config.h.
AC_DEFUN([AC_CSRG_BASED],
[AC_MSG_CHECKING([for CSRG based system])
AC_EGREP_CPP(yes,
[#if defined(__Darwin__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
yes
#endif
],
[AC_MSG_RESULT([yes])
AC_DEFINE([CSRG_BASED],[],[Using a BSD system derived from CSRG sources])
ac_csrg_based=yes],
[AC_MSG_RESULT([no])
ac_csrg_based=no])
AM_CONDITIONAL([CSRG_BASED], test x$ac_csrg_based = xyes)
])

AC_CSRG_BASED

# Init gettext
ALL_LINGUAS="zh_TW zh_CN"
#AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION(0.14.1)
GETTEXT_PACKAGE=pcmanx
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [The gettext domain])
AM_GLIB_GNU_GETTEXT

dnl displaced from acconfig.h
AH_VERBATIM([PREFIX],[#undef PREFIX])
AH_VERBATIM([USE_DEBUG],[#undef USE_DEBUG])
AH_VERBATIM([USE_IPV6],[#undef USE_IPV6])
AH_VERBATIM([USE_MMX],[#undef USE_MMX])
AH_VERBATIM([USE_DOCKLET],[#undef USE_DOCKLET])
AH_VERBATIM([USE_NOTIFIER],[#undef USE_NOTIFIER])
AH_VERBATIM([USE_LIBNOTIFY],[#undef USE_LIBNOTIFY])
AH_VERBATIM([USE_SCRIPT],[#undef USE_SCRIPT])
AH_VERBATIM([USE_PLUGIN],[#undef USE_PLUGIN])
AH_VERBATIM([USE_NANCY],[#undef USE_NANCY])
AH_VERBATIM([USE_MOUSE],[#undef USE_MOUSE])
AH_VERBATIM([USE_EXTERNAL], [#undef USE_EXTERNAL])
AH_VERBATIM([USE_WGET], [#undef USE_WGET])
AH_VERBATIM([USE_IPLOOKUP], [#undef USE_IPLOOKUP])
AH_VERBATIM([USE_PROXY], [#undef USE_PROXY])
AH_VERBATIM([USE_SIGACTION],[#undef USE_SIGACTION])
AH_VERBATIM([USING_FREEBSD],[#undef USING_FREEBSD])
AH_VERBATIM([USING_LINUX],[#undef USING_LINUX])
AH_VERBATIM([socklen_t],[#undef socklen_t])

AC_PATH_PROG(unamepath, uname)
if test "_$unamepath" = _; then
	system="unknown"
else
	AC_MSG_CHECKING(system type)
	system=`$unamepath -s`
	AC_MSG_RESULT($system)
	if test "$system" = "Linux"; then
		AC_DEFINE(USING_LINUX)
	fi
	if test "$system" = "FreeBSD"; then
		AC_DEFINE(USING_FREEBSD)
	fi
fi

AC_DEFINE_UNQUOTED(VERSION, "$VERSION", [The version of pcmanx_gtk2])

dnl *********************************************************************
dnl ** configure switches ***********************************************
dnl *********************************************************************

AC_ARG_ENABLE([debug],
	AS_HELP_STRING([--enable-debug],
		[enable Debug (default: no)]),
        debug=$enableval, debug="no")

AC_ARG_ENABLE([mmx],
	AS_HELP_STRING([--disable-mmx],
		[disable MMX optimizations (default: yes)]),
        mmx=$enableval, mmx="yes")

AC_ARG_ENABLE([docklet],
	AS_HELP_STRING([--disable-docklet],
		[disable docklet / system tray support (default: yes)]),
	docklet=$enableval, docklet="yes")

AC_ARG_ENABLE([notifier],
	AS_HELP_STRING([--disable-notifier],
		[disable popup notifier support (default: yes)]),
	notifier=$enableval, notifier="yes")

AC_ARG_ENABLE([libnotify],
	AS_HELP_STRING([--enable-libnotify],
		[enable popup notifier support by libnotify (default: no)]),
	libnotify=$enableval, libnotify="no")

dnl AC_ARG_ENABLE([script],
dnl 	AS_HELP_STRING([--enable-script],
dnl		[enable script support (default: no)]),
dnl 	script=$enableval, script="no")

AC_ARG_ENABLE([nancy],
	AS_HELP_STRING([--disable-nancy],
		[disable nancy bot support (default: yes)]),
	nancy=$enableval, nancy="yes")

AC_ARG_ENABLE([mouse],
	AS_HELP_STRING([--disable-mouse],
		[disable mouse click and wheel support (default: yes)]),
	mouse=$enableval, mouse="yes")
	
AC_ARG_ENABLE([external],
	AS_HELP_STRING([--disable-external],
		[disable external SSH/Telnet support (default: yes)]),
	external=$enableval, external="yes")

AC_ARG_ENABLE([plugin],
	AS_HELP_STRING([--enable-plugin],
		[enable Mozilla/Firefox plugin support (default: no)]),
	plugin=$enableval, plugin="no")

AC_ARG_ENABLE([wget],
	AS_HELP_STRING([--enable-wget],
		[enable wget support (default: no)]),
	wget=$enableval, wget="no")

AC_ARG_ENABLE([iplookup],
	AS_HELP_STRING([--enable-iplookup],
		[enable IP location lookup. For Simplified Chinese users. Need qqwry.dat. (default: no)]),
	iplookup=$enableval, iplookup="no")

AC_ARG_ENABLE([proxy],
	AS_HELP_STRING([--enable-proxy],
		[enable proxy support (default: no)]),
	proxy=$enableval, proxy="no")

dnl *********************************************************************
dnl ** DEBUG ************************************************************
dnl *********************************************************************

if test "$debug" = yes; then
	AC_DEFINE(USE_DEBUG)
fi
AM_CONDITIONAL(ENABLE_DEBUG, test "$debug" = "yes")

dnl *********************************************************************
dnl ** GLIB *************************************************************
dnl *********************************************************************

AM_PATH_GLIB_2_0([2.4.0], [
                  GUI_CFLAGS="$GUI_CFLAGS $GLIB_CFLAGS"
                  GUI_LIBS="$GUI_LIBS $GLIB_LIBS"
                  ], [AC_MSG_ERROR([Cannot find Glib 2.4 (or above version)!])], [gthread])

dnl *********************************************************************
dnl ** GTK **************************************************************
dnl *********************************************************************

AM_PATH_GTK_2_0([2.4.0], [
                 GUI_CFLAGS="$GUI_CFLAGS $GTK_CFLAGS"
                 GUI_LIBS="$GUI_LIBS $GTK_LIBS"
                 ], [AC_MSG_ERROR([Cannot find GTK+/X11 2.4 (or above version)!])])

dnl *********************************************************************
dnl ** Freetype2 ********************************************************
dnl *********************************************************************

AC_CHECK_FT2()
GUI_CFLAGS="$GUI_CFLAGS $FT2_CFLAGS"
GUI_LIBS="$GUI_LIBS $FT2_LIBS"

dnl *********************************************************************
dnl ** XFT **************************************************************
dnl *********************************************************************

PKG_CHECK_MODULES([LIBXFT], [xft], [
                   GUI_CFLAGS="$GUI_CFLAGS $LIBXFT_CFLAGS"
                   GUI_LIBS="$GUI_LIBS $LIBXFT_LIBS"
                   ],[AC_MSG_ERROR([pcmanx_gtk2 depends on Xft!])]) 

dnl *********************************************************************
dnl ** IPv6 *************************************************************
dnl *********************************************************************

dnl purely for Solaris
AC_CHECK_FUNC(select, ,
	AC_CHECK_LIB(socket, select, ,
		AC_CHECK_LIB(nsl, select, ,
			AC_CHECK_LIB(inet, select, ,
				AC_CHECK_LIB(cposix, select, ,
					AC_CHECK_LIB(net, select, ,
						AC_MSG_WARN(i can not find select.  you might need to help me)))))))
AC_CHECK_LIB(socket, select)

if test "$ipv6" = yes; then
	AC_CHECK_FUNCS(getaddrinfo, have_getaddrinfo=yes)
	AC_MSG_CHECKING(whether to enable IPv6 support)
	if test "$have_getaddrinfo" = yes; then
		AC_MSG_RESULT(yes)
		AC_DEFINE(USE_IPV6)
	else
		ipv6=no
		AC_MSG_RESULT(no)
	fi
fi

dnl *********************************************************************
dnl ** MMX **************************************************************
dnl *********************************************************************

dnl we don't need mmx on *this* machine, just i386, because
dnl it's checked at runtime.
if test "$mmx" = "yes"; then
	case $host_cpu in
    i386|i486|i586|i686|i786|k6|k7|c3|c3_2|x86_64)
    mmx=yes
        ;;
     *)
    mmx=no
	esac
	if test "$system" = "OpenBSD"; then
		dnl openbsd fails because mmx_cmod doesn't prefix its symbols with underscore.
		dnl xtext.o: Undefined symbol `_shade_ximage_15_mmx' referenced from text segment
		mmx=no
	fi
	if test "$mmx" = "yes"; then
		AC_DEFINE(USE_MMX)
	fi
fi

AM_CONDITIONAL(USE_MMX, test "$mmx" = "yes")


dnl *********************************************************************
dnl ** Docklet **********************************************************
dnl *********************************************************************

if test "$docklet" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_DOCKLET, [1], [Enable docklet / system tray support])
fi

AM_CONDITIONAL(USE_DOCKLET, test "$docklet" = "yes")
AC_SUBST(USE_DOCKLET)


dnl *********************************************************************
dnl ** Notifier *********************************************************
dnl *********************************************************************

if test "$notifier" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_NOTIFIER, [1], [Enable popup notifier support])
fi

AM_CONDITIONAL(USE_NOTIFIER, test "$notifier" = "yes")
AC_SUBST(USE_NOTIFIER)

if test "$notifier" = "yes"; then
	if test "$libnotify" = "yes"; then
		AC_DEFINE_UNQUOTED(USE_LIBNOTIFY, [1], [Enable libnotify notifier support])
		PKG_CHECK_MODULES(LIBNOTIFY, libnotify) 
		CFLAGS="$CFLAGS $LIBNOTIFY_CFLAGS"
		LIBS="$LIBS $LIBNOTIFY_LIBS"
	fi
else
	AC_MSG_WARN(popup notifier support is not enabled, so this option is invalid.)
fi

AM_CONDITIONAL(USE_LIBNOTIFY, test "$libnotify" = "yes")
AC_SUBST(USE_LIBNOTIFY)

dnl *********************************************************************
dnl ** Script support ***************************************************
dnl *********************************************************************

dnl if test "$script" = "yes"; then
dnl   AC_MSG_CHECKING([for Python script support])
dnl   AC_DEFINE_UNQUOTED(USE_SCRIPT, [1], [Enable script support])
dnl   PYTHON_INC=`python -c 'import distutils.sysconfig;print distutils.sysconfig.get_python_inc()'`
dnl   real_python_inc="`cd ${PYTHON_INC} 2>/dev/null && pwd`"
dnl   if test -z "${real_python_inc}"; then
dnl     AC_MSG_ERROR([Fatal Error: no Python detected.])
dnl   fi
dnl   PYTHON_VERSION=`python -c 'import distutils.sysconfig;print distutils.sysconfig.get_python_version()'`
dnl   AC_MSG_RESULT([Python $PYTHON_VERSION found.])
dnl   PYTHON_CFLAGS="-I${PYTHON_INC}"
dnl   PYTHON_LIBS="-lpython${PYTHON_VERSION}"
dnl fi

dnl SCRIPT_CFLAGS="$PYTHON_CFLAGS"
dnl SCRIPT_LIBS="$PYTHON_LIBS"

AM_CONDITIONAL(USE_SCRIPT, test "$script" = "yes")
AC_SUBST(USE_SCRIPT)
dnl AC_SUBST(SCRIPT_CFLAGS)
dnl AC_SUBST(SCRIPT_LIBS)

dnl *********************************************************************
dnl ** NancyBot  ********************************************************
dnl *********************************************************************

if test "$nancy" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_NANCY, [1], [Enable NancyBot support])
fi

AM_CONDITIONAL(USE_NANCY, test "$nancy" = "yes")
AC_SUBST(USE_NANCY)

dnl *********************************************************************
dnl ** Mouse Click and Wheel ********************************************
dnl *********************************************************************

if test "$mouse" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_MOUSE, [1], [Enable mouse click and wheel support])
fi

AM_CONDITIONAL(USE_MOUSE, test "$mouse" = "yes")
AC_SUBST(USE_MOUSE)

dnl *********************************************************************
dnl ** External SSH/Telnet **********************************************
dnl *********************************************************************

if test "$external" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_EXTERNAL, [1], [Enable external SSH/Telnet support])
    dnl We need tty utility functions from libutil
    LIBS="$LIBS -lutil"
fi

AM_CONDITIONAL(USE_EXTERNAL, test "$external" = "yes")
AC_SUBST(USE_EXTERNAL)

dnl *********************************************************************
dnl ** wget support ***********************************
dnl *********************************************************************

if test "$wget" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_WGET, [1], [Enable wget support])
fi

AM_CONDITIONAL(USE_WGET, test "$wget" = "yes")
AC_SUBST(USE_WGET)

dnl *********************************************************************
dnl ** IP location lookup support ***********************************
dnl *********************************************************************

if test "$iplookup" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_IPLOOKUP, [1], [Enable IP location lookup])
fi

AM_CONDITIONAL(USE_IPLOOKUP, test "$iplookup" = "yes")
AC_SUBST(USE_IPLOOKUP)

dnl *********************************************************************
dnl ** proxy support ***********************************
dnl *********************************************************************

if test "$proxy" = "yes"; then
    AC_DEFINE_UNQUOTED(USE_PROXY, [1], [Enable proxy support])
fi

AM_CONDITIONAL(USE_PROXY, test "$proxy" = "yes")
AC_SUBST(USE_PROXY)

dnl *********************************************************************
dnl ** Mozilla/Firefox Plugin support ***********************************
dnl *********************************************************************

AC_ARG_WITH([mozilla],
  AS_HELP_STRING([--with-mozilla=DIR],
  [Specify Mozilla root directory]),
  [ INPUT_MOZILLA_ROOT="$withval" ])

if test "$plugin" = "yes"; then
  AC_MSG_CHECKING([for Mozilla support])
  gecko_provider=mozilla
  user_specified_mozilla=no

  if test ! -z "$INPUT_MOZILLA_ROOT"; then
    real_mozilla_root="`cd ${INPUT_MOZILLA_ROOT} 2>/dev/null && pwd`"
    if test ! -z "${real_mozilla_root}"; then
      INPUT_MOZILLA_ROOT="$real_mozilla_root"
      user_specified_mozilla=yes
      enable_mozilla=yes
    fi
  fi

  dnl Detect via pkg-config

  # Check Mozilla
  if test "$user_specified_mozilla" = "no"; then
    PKG_CHECK_MODULES(MOZILLA, $gecko_provider-plugin,
	enable_mozilla=yes, enable_mozilla=no)
  fi

  # Check Firefox
  if test "x$enable_mozilla" = "xno"; then
    gecko_provider=firefox
    PKG_CHECK_MODULES(MOZILLA, $gecko_provider-plugin,
	enable_mozilla=yes, enable_mozilla=no)
  fi

  # Check Firefox-plugin
  if test "x$enable_mozilla" = "xno"; then
    gecko_provider=firefox-plugin
    PKG_CHECK_MODULES(MOZILLA, $gecko_provider-plugin,
	enable_mozilla=yes, enable_mozilla=no)
  fi

  # Check XULRunner
  if test "x$enable_mozilla" = "xno"; then
    gecko_provider=xulrunner
    PKG_CHECK_MODULES(MOZILLA, $gecko_provider-plugin,
	enable_mozilla=yes, enable_mozilla=no)
  fi

  MOZILLA_LIB_DIR_SEARCH=
  AC_MSG_RESULT([$gecko_provider found!])
  if test "$user_specified_mozilla" = "no"; then
    if "$PKG_CONFIG" --exists "$gecko_provider-plugin >= 1.9"; then
      MOZILLA_INCLUDE_ROOT=`$PKG_CONFIG --cflags-only-I $gecko_provider-plugin`
      MOZILLA_LIB_ROOT=`$PKG_CONFIG --variable=sdkdir $gecko_provider-plugin`/bin
      MOZILLA_LIB_DIR_SEARCH="$MOZILLA_LIB_ROOT"
      MOZILLA_IDLDIR=`$PKG_CONFIG --variable=idldir libxul`/`$PKG_CONFIG --variable=includetype libxul`
    else
      dnl Note: with the infos from mozilla-plugin.pc
      dnl we got all includes and libraries for the C interface
      dnl to Mozilla, but not the XPCOM headers we also need.
      MOZILLA_INCLUDE_ROOT=`$PKG_CONFIG --cflags-only-I $gecko_provider-plugin $gecko_provider-xpcom`
      MOZILLA_LIB_ROOT=`$PKG_CONFIG --variable=libdir $gecko_provider-plugin`
      MOZILLA_LIB_DIR_SEARCH="$MOZILLA_LIB_ROOT"
    fi
  else
    dnl Don't depend on pkg-config
    MOZILLA_LIB_ROOT="$INPUT_MOZILLA_ROOT"
    MOZILLA_INCLUDE_ROOT="$INPUT_MOZILLA_ROOT/include"
    MOZILLA_LIBS="-L$INPUT_MOZILLA_ROOT -lxpcom -lplds4 -lplc4 -lnspr4 -lpthread -ldl"
    MOZILLA_CFLAGS=" \
      -I$MOZILLA_INCLUDE_ROOT \
      -I$MOZILLA_INCLUDE_ROOT/java \
      -I$MOZILLA_INCLUDE_ROOT/plugin \
      -I$MOZILLA_INCLUDE_ROOT/xpcom \
      -I$MOZILLA_INCLUDE_ROOT/string \
      -I$MOZILLA_INCLUDE_ROOT/nspr \
      -I$MOZILLA_INCLUDE_ROOT/xpcom \
      -I$MOZILLA_INCLUDE_ROOT/xpconnect"
  fi

  # Workaround
  MOZILLA_CFLAGS="$MOZILLA_CFLAGS -I$MOZILLA_INCLUDE_ROOT"

  dnl See if xpidl is found.
  XPIDL="$MOZILLA_LIB_ROOT/xpidl"
  if test ! -x "$XPIDL"; then
    echo "ERROR:"
    echo "The utility $XPIDL was not found. Please check your development packages."
    AC_MSG_ERROR([Fatal Error: no xpidl detected.])
  fi

  dnl Search for the idl include directory
  dnl This only works on Gecko 1.8
  if test "x$MOZILLA_IDLDIR" = "x"; then
    MOZILLA_IDLDIR="`$PKG_CONFIG --variable=idldir $gecko_provider-xpcom`"
  fi
  dnl Fallback for older versions
  if test "x$MOZILLA_IDLDIR" = "x"; then
    MOZILLA_IDLDIR="`echo $MOZILLA_LIB_ROOT | sed -e s!lib!share/idl!`"
  fi
  dnl Gentoo has it in unusual places
  if test "x$MOZILLA_IDLDIR" = "x"; then
    MOZILLA_IDLDIR="$MOZILLA_INCLUDE_ROOT/idl"
  fi
  dnl Debian/Ubuntu have it in unusual places, too.
  ADDITIONAL_IDLDIR=/usr/share/idl
  if test "x$gecko_provider" = "xfirefox"; then
    ADDITIONAL_IDLDIR=$ADDITIONAL_IDLDIR/mozilla-firefox
  else
    ADDITIONAL_IDLDIR=$ADDITIONAL_IDLDIR/mozilla
  fi
  XPIDL_INCL="-I$MOZILLA_IDLDIR \
-I$ADDITIONAL_IDLDIR \
-I/usr/lib/mozilla/include/idl"

  PATH_OF_PCMANX_HTML="$MOZILLA_LIB_DIR_SEARCH/components/pcmanx.html"

  AC_SUBST(PATH_OF_PCMANX_HTML)
  AC_SUBST(XPIDL)
  AC_SUBST([XPIDL_INCL])
  AC_SUBST(MOZILLA_CFLAGS)
  AC_SUBST(MOZILLA_LIBS)
  AC_SUBST(MOZILLA_LIB_DIR_SEARCH)
fi

if test "x$enable_mozilla" = "xno"; then
  plugin="no"
fi

AM_CONDITIONAL(USE_PLUGIN, test "$plugin" = "yes")

dnl *********************************************************************
dnl ** GCC FLAGS ********************************************************
dnl *********************************************************************

dnl CACHED_TRY_COMPILE(<description>,<cachevar>,<include>,<program>,<ifyes>,<ifno>)        
AC_DEFUN([CACHED_TRY_COMPILE],[
  AC_MSG_CHECKING($1)
  AC_CACHE_VAL($2,[
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[$3]], [[$4]])],[$2=yes],[$2=no])
  ])
  if test "x$$2" = xyes; then
    true
    $5
  else
    true
    $6
  fi
])

dnl GCC_ATTRIBUTE(<short-label>,<cachevar>,<func-params>,<attribute>,<HAVE>,<desc>,[<true-cmds>],[<false-cmds>])
AC_DEFUN([GCC_ATTRIBUTE],[
  CACHED_TRY_COMPILE(__attribute__(($1)),cv_c_gcc_attribute_$2,,
   [extern int testfunction($3) __attribute__(($4))],
   AC_MSG_RESULT(yes)
   AC_DEFINE(HAVE_GNUC25_$5,,$6)
   $7,
   AC_MSG_RESULT(no)
   $8)
])

AC_DEFUN([GCC_ATTRIBUTE_SUPPORTED],[
 GCC_ATTRIBUTE([,,],supported,[int x],[,,],ATTRIB,[Define if function attributes a la GCC 2.5 and higher are available.])
 AH_BOTTOM([/* GNU C attributes. */
#ifndef FUNCATTR
#ifdef HAVE_GNUC25_ATTRIB
#define FUNCATTR(x) __attribute__(x)
#else
#define FUNCATTR(x)
#endif
#endif])

])
AC_DEFUN([GCC_ATTRIBUTE_CONST],[
 AC_REQUIRE([GCC_ATTRIBUTE_SUPPORTED])
 GCC_ATTRIBUTE(const,const,[int x],const,CONST,[Define if constant functions a la GCC 2.5 and higher are available.])
 AH_BOTTOM([/* GNU C constant functions, or null. */
#ifndef ATTRCONST
#ifdef HAVE_GNUC25_CONST
#define ATTRCONST const
#else
#define ATTRCONST
#endif
#endif
#ifndef CONSTANT
#define CONSTANT FUNCATTR((ATTRCONST))
#endif])
])
AC_DEFUN([GCC_ATTRIBUTE_NORETURN],[
 AC_REQUIRE([GCC_ATTRIBUTE_SUPPORTED])
 GCC_ATTRIBUTE(noreturn,noreturn,[int x],noreturn,NORETURN,[Define if nonreturning functions a la GCC 2.5 and higher are available.])
 AH_BOTTOM([/* GNU C nonreturning functions, or null. */
#ifndef ATTRNORETURN
#ifdef HAVE_GNUC25_NORETURN
#define ATTRNORETURN noreturn
#else /* ! HAVE_GNUC25_NORETURN */
#define ATTRNORETURN
#endif /* HAVE_GNUC25_NORETURN */
#endif /* ATTRNORETURN */
#ifndef NONRETURNING
#define NONRETURNING FUNCATTR((ATTRNORETURN))
#endif /* NONRETURNING */])
])
AC_DEFUN([GCC_ATTRIBUTE_UNUSED],[
 AC_REQUIRE([GCC_ATTRIBUTE_SUPPORTED])
 GCC_ATTRIBUTE(unused,unused,[int x],unused,UNUSED,[Define if unused variables la GCC 2.5 and higher are available.])
 AH_BOTTOM([/* GNU C unused functions, or null. */
#ifndef ATTRUNUSED
#ifdef HAVE_GNUC25_UNUSED
#define ATTRUNUSED unused
#else
#define ATTRUNUSED
#endif
#endif
#ifndef UNUSED
#define UNUSED FUNCATTR((ATTRUNUSED))
#endif])
])
AC_DEFUN([GCC_ATTRIBUTE_PACKED],[
  AC_REQUIRE([GCC_ATTRIBUTE_SUPPORTED])
  GCC_ATTRIBUTE(packed,packed,[int x],packed,PACKED,[Define if packing of struct members a la GCC 2.5 and higher is available.])
  AH_BOTTOM([/* GNU C constant functions, or null. */
#ifndef ATTRPACKED
#ifdef HAVE_GNUC25_PACKED
#define ATTRPACKED packed
#else
#define ATTRPACKED
#endif
#endif
#ifndef PACKED
#define PACKED FUNCATTR((ATTRPACKED))
#endif])
])

dnl Only use -Wall and -pipe if we have gcc
if test "x$GCC" = "xyes"; then
	if test -z "`echo "$CFLAGS" | grep "\-Wall" 2> /dev/null`" ; then
		CFLAGS="$CFLAGS -Wall"
	fi
	if test "$system" = "Linux" -o "$system" = "FreeBSD"; then
		if test -z "`echo "$CFLAGS" | grep "\-pipe" 2> /dev/null`" ; then
			CFLAGS="$CFLAGS -pipe"
		fi
	fi
	if test -z "`echo "$CFLAGS" | grep "\-g " 2> /dev/null`" ; then
		CFLAGS="$CFLAGS -g"
	fi

	GCC_ATTRIBUTE_CONST
	GCC_ATTRIBUTE_NORETURN
	GCC_ATTRIBUTE_PACKED
	GCC_ATTRIBUTE_UNUSED
fi

dnl *********************************************************************
dnl ** FUNCTIONS/LIBS/CFLAGS ********************************************
dnl *********************************************************************

AC_MSG_CHECKING(for modern sigaction)
dnl libc5 on linux and FreeBSD 3.x doesn't have siginfo_t
dnl and the sa_sigation field.
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <signal.h>]], [[struct sigaction act;
	 siginfo_t *si;
	 act.sa_sigaction = 0;]])],[
		AC_MSG_RESULT(yes)
		AC_DEFINE(USE_SIGACTION) 
	],[AC_MSG_RESULT(no)])

dnl if we don't have this, use g_snprintf instead
AC_CHECK_FUNCS(snprintf)
AC_CHECK_FUNCS(vsnprintf)
AC_CHECK_FUNCS(memrchr)

AC_CHECK_FUNC(gethostbyname, ,
	AC_CHECK_LIB(resolv, gethostbyname, ,
		AC_CHECK_LIB(nsl, gethostbyname)))

AC_CHECK_FUNC(gethostname, , AC_CHECK_LIB(nsl, gethostname))

dnl necessary for IRIX
AC_CHECK_HEADERS(strings.h)

dnl Check for type in sys/socket.h - from Squid source (GPL)
AC_CACHE_CHECK(for socklen_t, ac_cv_type_socklen_t, [
AC_EGREP_CPP([socklen_t[^a-zA-Z_0-9]], [#include <sys/types.h>
#include <sys/socket.h>
#if STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif],
ac_cv_type_socklen_t=yes,
ac_cv_type_socklen_t=no)
])
if test $ac_cv_type_socklen_t = no; then
	AC_DEFINE(socklen_t, int)
fi

dnl FreeBSD needs this
LIBS="$LIBS $INTLLIBS"
CFLAGS="$CFLAGS $CPPFLAGS"

dnl Reduce C++ overhead
CXXFLAGS="$CXXFLAGS -fno-exceptions -fno-rtti"
LDFLAGS="$LDFLAGS $PACKAGE_LIBS" #-nodefaultlibs -lgcc -lc -lm"

dnl linker optimizations
AC_MSG_CHECKING([whether $LD accepts --as-needed])
case `$LD --as-needed -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  LDFLAGS="$LDFLAGS -Wl,--as-needed"
  AC_MSG_RESULT([yes])                                                              
  ;;
*)
  AC_MSG_RESULT([no])
  ;;
esac
AC_MSG_CHECKING([whether $LD accepts -O1])
case `$LD -O1 -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  LDFLAGS="$LDFLAGS -Wl,-O1"
  AC_MSG_RESULT([yes])
  ;;
*)
  AC_MSG_RESULT([no])
  ;;
esac
AC_MSG_CHECKING([whether $LD accepts -Bsymbolic-functions])
case `$LD -Bsymbolic-functions -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  LDFLAGS="$LDFLAGS -Wl,-Bsymbolic-functions"
  AC_MSG_RESULT([yes])
  ;;
*)                                                                              
  AC_MSG_RESULT([no])
  ;;
esac
AC_MSG_CHECKING([whether $LD accepts --sort-common])
case `$LD --sort-common -v 2>&1 </dev/null` in
*GNU* | *'with BFD'*)
  LDFLAGS="$LDFLAGS -Wl,--sort-common"
  AC_MSG_RESULT([yes])
  ;;
*)                                                                              
  AC_MSG_RESULT([no])
  ;;
esac

dnl Adds -fvisibility=hidden to CFLAGS if running with gcc 4 or greater.
AC_MSG_CHECKING([whether the compiler supports the visibility arg])
dnl Check for gcc4 or greater
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
void
#if defined(__GNUC__) && (__GNUC__ >= 4)
foo () {};                                                                                         
#endif
]], [[]])],[
  if test "$debug" = yes; then
dnl It's important for collecting runtime information
    has_visibility=no
  else
    has_visibility=yes
    CFLAGS="$CFLAGS -fvisibility=hidden"
    CXXFLAGS="$CXXFLAGS -fvisibility=hidden -fvisibility-inlines-hidden"
  fi
],[
  has_visibility=no

])
AC_MSG_RESULT($has_visibility)

dnl make these visible to all Makefiles
AC_SUBST(GUI_LIBS)
AC_SUBST(GUI_CFLAGS)
LIBTOOL_VERSION_INFO=`echo $PACKAGE_VERSION | awk -F. '{ printf "%d:%d:%d", $1+$2, $3, $2 }'`
AC_SUBST(LIBTOOL_VERSION_INFO)
LIBTOOL_EXPORT_OPTIONS='-export-symbols-regex "^[[^_]].*"'
AC_SUBST(LIBTOOL_EXPORT_OPTIONS)
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/core/Makefile
	po/Makefile.in
	data/Makefile
	pcmanx.desktop
	pcmanx-gtk2.spec
	Doxygen
])

dnl Extra files needed by plugin
AC_CONFIG_FILES([
	plugin/Makefile
	plugin/src/Makefile
	plugin/data/Makefile
	plugin/data/TelnetProtocol.js
])

AC_OUTPUT

echo
echo pcmanx_gtk2 ..................... : Version $VERSION
echo
echo Prefix........................... : $prefix
echo Debug support ................... : $debug
echo MMX optimization ................ : $mmx
echo Docklet / system tray support ... : $docklet
echo Popup notifier support........... : $notifier
echo Libnotify support................ : $libnotify
echo Nancy bot support ............... : $nancy
echo Mouse click and wheel support ... : $mouse
dnl if test "x$script" = "xyes"; then
dnl   echo "Python script support............ : $script (Using Python $PYTHON_VERSION)"
dnl else
dnl   echo "Python script support............ : $script"
dnl fi
echo External SSH/Telnet support...... : $external
if test "x$enable_mozilla" = "xyes"; then
  echo "Build Mozilla/Firefox plugin..... : $enable_mozilla (Using $gecko_provider)"
else
  echo "Mozilla/Firefox plugin support... : $plugin"
fi
echo wget support..................... : $wget
echo iplookup support................. : $iplookup
echo proxy support.................... : $proxy
echo
echo The binary will be installed in $prefix/bin
echo

echo configure complete, now type \'make\' and pray.
echo
