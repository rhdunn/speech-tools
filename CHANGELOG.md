# Change Log

## [1.2.1-1]

Add and modernize the standard project files:

  * Added a CHANGELOG.md file to track the project changes.
  * Added a .gitignore file to ignore the build output.

Support the GNU standard project layout:

  * Move the license and copying information from README into a COPYING file.
  * Link NEWS to another file in the project.

Add autotools support:

  * Added an autogen.sh script to setup the configure script.
  * Backport configure.in from 1.2.2 as configure.ac.
  * Link to the automake files needed to run the configure script.
  * Use `autoconf` to generate the configure script.
  * Backport the `config/` changes from 1.2.2 to support more systems.

## [1.2.1]

Upstream version 1.2.1.
