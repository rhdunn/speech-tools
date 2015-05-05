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
AC_INIT([speech-tools], [2.1-1], [festival-talk@festvox.org])
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

# Checks for libraries.
AC_CHECK_LIB(ncurses, tputs, [TERMCAPLIB=-lncurses], [TERMCAPLIB=-lcurses])
AC_SUBST(TERMCAPLIB)

dnl Which version of GCC do we have here
COMPILERTYPE=gcc
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
               [[int j= 
                #if __GNUC__ == 2 && __GNUC_MINOR__ == 95
                3;
                #endif ]])],
               [COMPILERTYPE=gcc295],[])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
               [[int j= 
                #if __GNUC__ == 3 
                3;
                #endif ]])],
               [COMPILERTYPE=gcc32],[])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
               [[int j=
                #if __GNUC__ == 2 && __GNUC_MINOR__ == 96
                3;
                #endif ]])],
               [COMPILERTYPE=gcc296],[])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
               [[int j=
                #if __GNUC__ == 2 && __GNUC_MINOR__ == 91
                3;
                #endif ]])],
               [COMPILERTYPE=egcs],[])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
               [[int j=
                #if __GNUC__ == 2 && __GNUC_MINOR__ == 8
                3;
                #endif ]])],
               [COMPILERTYPE=gcc28],[])
AC_SUBST(COMPILERTYPE)

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

AC_CONFIG_FILES([config/config])
AC_OUTPUT
