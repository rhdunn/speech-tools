 ###########################################################################
 ##                                                                       ##
 ##                Centre for Speech Technology Research                  ##
 ##                     University of Edinburgh, UK                       ##
 ##                         Copyright (c) 1996                            ##
 ##                        All Rights Reserved.                           ##
 ##                                                                       ##
 ##  Permission is hereby granted, free of charge, to use and distribute  ##
 ##  this software and its documentation without restriction, including   ##
 ##  without limitation the rights to use, copy, modify, merge, publish,  ##
 ##  distribute, sublicense, and/or sell copies of this work, and to      ##
 ##  permit persons to whom this work is furnished to do so, subject to   ##
 ##  the following conditions:                                            ##
 ##   1. The code must retain the above copyright notice, this list of    ##
 ##      conditions and the following disclaimer.                         ##
 ##   2. Any modifications must be clearly marked as such.                ##
 ##   3. Original authors' names are not deleted.                         ##
 ##   4. The authors' names are not used to endorse or promote products   ##
 ##      derived from this software without specific prior written        ##
 ##      permission.                                                      ##
 ##                                                                       ##
 ##  THE UNIVERSITY OF EDINBURGH AND THE CONTRIBUTORS TO THIS WORK        ##
 ##  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      ##
 ##  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   ##
 ##  SHALL THE UNIVERSITY OF EDINBURGH NOR THE CONTRIBUTORS BE LIABLE     ##
 ##  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    ##
 ##  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   ##
 ##  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          ##
 ##  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       ##
 ##  THIS SOFTWARE.                                                       ##
 ##                                                                       ##
 ###########################################################################
 ##                                                                       ##
 ##                 Author: Richard Caley (rjc@cstr.ed.ac.uk)             ##
 ##                   Date: Thu Oct  2 1997                               ##
 ## --------------------------------------------------------------------  ##
 ## Description of directory structure etc. at CSTR.                      ##
 ##                                                                       ##
 ###########################################################################

###########################################################################
## Names of various gcc versions

GCC26=gcc-2.6.3 
GCC27=gcc

###########################################################################
## Installation directories

INSTALL_PREFIX=/cstr

###########################################################################
## We have a master RCS tree below this directory

LOCAL_REPOSITORY = /projects

###########################################################################
## Some of our things are installed under /cstr or /usr/local/GNU, and we
## don't have the common /usr/X11 link on some machines, so we need to
## reset some paths.

NAS_INCLUDE = /cstr/include
NAS_LIB     = /cstr/lib

X11_INCLUDE = /usr/openwin/include
X11_LIB     = /usr/openwin/lib

DEFAULT_JAVA_HOME = /cstr/external/jdk
DEFAULT_JMF_HOME = /cstr/external/jmf

###########################################################################
# If we have this it's a _LOT_ faster than the java version

JAR=zip -0


