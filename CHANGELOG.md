# Change Log

## [2.1-1]

Build fixes:

  * Fix building with the clang compiler.

Build system improvements:

  * Build improvements from [1.2.1-1](#1.2.1-1) and [1.2.96-1](#1.2.96-1).
  * Use g++ in the gcc default flags to compile C++ sources.
  * Support other Linux `OSTYPE` strings.
  * Remove the make.include files as part of the `clean` target.
  * Don't perform dependency calculations when running the `clean` target.
  * Fix not building shared libraries when `SHARED` is 0.
  * Support using the `gcov` code coverage tool.
  * Add a `clang.mak` configuration file for the clang compiler.
  * Use settings from `config/compilers` for the selected compiler.

Improved configure script:

  * Update configure.ac to comply with autoconf 2.69.
  * Merge the output of `autoscan` into configure.ac.
  * Use the `configure` results for the compiler and flags to use.
  * `./configure --disable-warn` support.
  * `./configure --enable-debug` support.
  * `./configure --enable-optimization` support.
  * `./configure --enable-profile` support.
  * `./configure --enable-shared` support.
  * `./configure --with-compiler` support.
  * `./configure --with-nas-audio` support.

## [2.1]

Upstream version 2.1.

## [2.0.95-1]

  * Build improvements from [1.2.1-1](#1.2.1-1) and [1.2.96-1](#1.2.96-1).

## [2.0.95]

Upstream version 2.0.95.

## [1.2.96-1]

  * Build improvements from [1.2.1-1](#1.2.1-1).
  * Backport the `strstr` return value build fix from 2.0.95.
  * Backport building `EST_DiscreteProbDistribution` on 64-bit platforms from
    2.0.95.
  * Use `this->` for template member functions to fix building with modern
    compilers, backported from 2.3.
  * Include `string.h` for the memory functions to fix building on modern
    systems, backported from 2.3.

## [1.2.96]

Upstream version 1.2.96.

## [1.2.95-1]

  * Build improvements from [1.2.1-1](#1.2.1-1).

## [1.2.95]

Upstream version 1.2.95.

## [1.2.3-1]

  * Build improvements from [1.2.1-1](#1.2.1-1).

## [1.2.3]

Upstream version 1.2.3.

## [1.2.2-1]

  * Build improvements from [1.2.1-1](#1.2.1-1).
  * Remove the derivable autoconf and automake files: config.{guess,sub},
    configure, install-sh, missing and mkinstalldirs.
  * Remove configure.in as this was added as configure.ac in [1.2.1-1](#1.2.1-1).

## [1.2.2]

Upsteam version 1.2.2.

## [1.2.1-1]

Add and modernize the standard project files:

  * Added a CHANGELOG.md file to track the project changes.
  * Converted the README file to markdown and added a "Compilation" section.
  * Added a .gitignore file to ignore the build output.
  * Support building HTML versions of the markdown files with `kramdown`.

Support the GNU standard project layout:

  * Move the license and copying information from README into a COPYING file.
  * Add an AUTHORS file.
  * Link NEWS and README to other files in the project.

Add autotools support:

  * Added an autogen.sh script to setup the configure script.
  * Backport configure.in from 1.2.2 as configure.ac.
  * Link to the automake files needed to run the configure script.
  * Use `autoconf` to generate the configure script.
  * Backport the `config/` changes from 1.2.2 to support more systems.

Other changes:

  * Removed the advertising clause for Berkeley BSD code as per
    [README.Impt.License.Change](ftp://ftp.cs.berkeley.edu/pub/4bsd/README.Impt.License.Change).

## [1.2.1]

Upstream version 1.2.1.
