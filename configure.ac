dnl########################################################################
dnl                                                                      ##
dnl               Centre for Speech Technology Research                  ##
dnl                    University of Edinburgh, UK                       ##
dnl                      Copyright (c) 1996-2001                         ##
dnl                       All Rights Reserved.                           ##
dnl                                                                      ##
dnl Permission is hereby granted, free of charge, to use and distribute  ##
dnl this software and its documentation without restriction, including   ##
dnl without limitation the rights to use, copy, modify, merge, publish,  ##
dnl distribute, sublicense, and/or sell copies of this work, and to      ##
dnl permit persons to whom this work is furnished to do so, subject to   ##
dnl the following conditions:                                            ##
dnl  1. The code must retain the above copyright notice, this list of    ##
dnl     conditions and the following disclaimer.                         ##
dnl  2. Any modifications must be clearly marked as such.                ##
dnl  3. Original authors' names are not deleted.                         ##
dnl  4. The authors' names are not used to endorse or promote products   ##
dnl     derived from this software without specific prior written        ##
dnl     permission.                                                      ##
dnl                                                                      ##
dnl THE UNIVERSITY OF EDINBURGH AND THE CONTRIBUTORS TO THIS WORK        ##
dnl DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      ##
dnl ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   ##
dnl SHALL THE UNIVERSITY OF EDINBURGH NOR THE CONTRIBUTORS BE LIABLE     ##
dnl FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    ##
dnl WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   ##
dnl AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          ##
dnl ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       ##
dnl THIS SOFTWARE.                                                       ##
dnl                                                                      ##
dnl########################################################################
AC_PREREQ([2.69])
AC_INIT([speech-tools], [2.4-1], [festival-talk@festvox.org])
AC_CONFIG_SRCDIR([include/EST.h])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_CHECK_TOOL(AR, ar)

AC_CANONICAL_TARGET
AC_C_BIGENDIAN

dnl Set compiler type in order to force honoring of CFLAGS, etc.
AC_MSG_CHECKING([which C/C++ compiler configuration to use])
AC_ARG_WITH([compiler],
            [AS_HELP_STRING([--with-compiler],
              [Explicitly set the compiler to use.])],
            [ if   test "x$withval" = "x"; then
                COMPILER=`basename $CC`
              else
                COMPILER=$withval
              fi
            ],
            [COMPILER=`basename $CC`])
if ! test -f "config/compilers/$COMPILER.mak"; then
    AS_CASE([x$CC],
            [xclang*],[COMPILER=clang],
            [xegcs*], [COMPILER=egcs],
            [xgcc*],  [COMPILER=gcc],
            [xicc*],  [COMPILER=intel80],
            [COMPILER=custom])
fi
AC_MSG_RESULT([$COMPILER])
AC_SUBST(COMPILER)

# Checks for libraries.
AC_CHECK_LIB(ncurses, tputs, [TERMCAPLIB=-lncurses], [TERMCAPLIB=-lcurses])
AC_SUBST(TERMCAPLIB)

LINUXAUDIO=none
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <alsa/version.h>]],
               [[int j=
                #if SND_LIB_SUBMINOR >= 11
                3;
                #endif]])],
              [LINUXAUDIO="alsa"],[])
AC_SUBST(LINUXAUDIO)

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h limits.h netdb.h netinet/in.h sgtty.h stddef.h stdlib.h string.h sys/ioctl.h sys/socket.h sys/time.h termios.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([dup2 floor getcwd gethostbyname gethostname gettimeofday inet_ntoa memmove memset pow putenv rint socket sqrt strcasecmp strchr strcspn strdup strerror strrchr strspn strstr strtol])

# Configuration options
AC_ARG_ENABLE([shared],[AS_HELP_STRING([--enable-shared  Enable building shared libraries])],
 [ if   test "x$enableval" = "x0"; then
       SHARED=0
   elif test "x$enableval" = "xno"; then
       SHARED=0
   elif test "x$enableval" = "x1"; then
       SHARED=1
   else
       SHARED=2
   fi
 ], [ SHARED=0 ])
AC_SUBST(SHARED)

AC_ARG_ENABLE([debug],[AS_HELP_STRING([--enable-debug  Produce debugging information])],
 [ if   test "x$enableval" = "x0"; then
       DEBUG=0
   elif test "x$enableval" = "xno"; then
       DEBUG=0
   else
       DEBUG=1
   fi
 ], [ DEBUG=0 ])
AC_SUBST(DEBUG)

AC_ARG_ENABLE([optimization],[ AS_HELP_STRING([--enable-optimization=NUM Choose optimization level from 0 to 4. Default 3. Level 4 disables debug.])],
 [ if   test "x$enableval" = "x0"; then
       OPTIMISE=0
   elif test "x$enableval" = "xno"; then
       OPTIMISE=0
   elif test "x$enableval" = "x1"; then
       OPTIMISE=1
   elif test "x$enableval" = "x2"; then
       OPTIMISE=2
   elif test "x$enableval" = "x4"; then
       OPTIMISE=4
   else
       OPTIMISE=3
   fi
  ], [ OPTIMISE=3 ])
AC_SUBST(OPTIMISE)

AC_ARG_ENABLE([profile],[ AS_HELP_STRING([--enable-profile  Enable a profiled build])],
 [ if   test "x$enableval" = "xgprof"; then
       PROFILE=gprof
   elif test "x$enableval" = "xgcov"; then
       PROFILE=gcov
   elif test "x$enableval" = "xno"; then
       PROFILE=
   else
       PROFILE=gprof
   fi
 ], [ PROFILE= ])
AC_SUBST(PROFILE)

AC_ARG_ENABLE([warn],[AS_HELP_STRING([--disable-warn  Disable warning flags])],
 [ if test "x$enableval" = "xno"; then
       WARN=0
   else
       WARN=1
   fi
 ], [ WARN=1 ])
AC_SUBST(WARN)

AC_ARG_WITH([nas_audio],[AS_HELP_STRING([--with-nas-audio],[Enable network audio system (NAS) support])],
            [if test "x$with_nas_audio" = "xyes"; then
                 NAS_AUDIO=NAS_AUDIO
             else
                 NAS_AUDIO=
             fi],
            [NAS_AUDIO=])
AC_SUBST(NAS_AUDIO)

AC_CONFIG_FILES([config/config config/compilers/custom.mak])
AC_OUTPUT
