# Change Log

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
