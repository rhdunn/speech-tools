# Edinburgh Speech Tools

- [Compilation](#compilation)
- [Acknowledgements](#acknowledgements)
- [File/Directory Structure](#filedirectory-structure)
- [Documentation](#documentation)
- [Bugs/Comments Etc](#bugscomments-etc)
- [Additional Software](#additional-software)
- [License](#license)

----------

The [Edinburgh speech tools](http://www.cstr.ed.ac.uk/projects/speech_tools)
system is a library of C++ classes, functions and utility programs that are
frequently used in speech software. The system compiles to a single unix
library `.a` file which can be linked with software. At present, C++ classes
for several useful speech and language classes have been written, along with
audio software and some basic signal processing software.

Although this is a considered stable release, there are still a number
of known parts are missing or incomplete.

The following c++ programs are available:

| Program    | Description |
|------------|-------------|
| `na_play`  | Generic playback program for use with `net_audio` and CSTR ao. |
| `ch_wave`  | Waveform file conversion program. |
| `ch_lab`   | Label file conversion program. |
| `ch_track` | Track file conversion program. |
| `wagon`    | A CART tree build and test program. |

And others.

The following C++ sub-libraries are available:

| Library        | Description |
|----------------|-------------|
| `audio`        | C++ audio functions for Network Audio system, Suns Linux and FreeBSD. |
| `speech_class` | C++ speech classes, including waveform and track. |
| `ling_class`   | C++ linguistic classes. |
| `sigpr`        | Signal processing. |
| `utils`        | Various utilities. |

## Compilation

The `speech_tools` project uses a standard autogen-based build system. It
can be built using the following commands:

    ./autogen.sh
    ./configure --prefix=/usr
    make
    sudo make install

## Acknowledgements

Most of the software was written by Paul Taylor, Alan W Black, Simon
King, Richard Caley, Rob Clark and Korin Richmond. Additional
contributions have been made by the following people.  Slightly
different licence agreements accompany these pieces of code, so it is
important that the various agreements be properly understood.

| Authors                                     | Acknowledgement |
|---------------------------------------------|-----------------|
| Tony Robinson                               | Some signal processing code. |
| Markus Mummert                              | Sample rate converter (rateconv.cc). |
| Craig Reese and Joe Campbell                | ulaw conversion code. |
| Paul Bagshaw                                | Pitch tracker. |
| Theo Veenker                                | IRIX audio support. |
| Stan Chen                                   | AIX support. |
| Paradigm Assoc. and George Carrett          | For Scheme In One Defun. |
| Simmule Turner and Rich Salz                | For editline. |
| Henry Spencer                               | For regex code. |
| The Regents of the University of California | Some string comparison code. |
| Richard Tobin                               | RXP, XML parser. |
| Arthur Toth                                 | Windows server code. |

## File/Directory Structure

The `main` directory contains minimal wrap-around `main()` functions
which compile to form executables which use the algorithms in the
speech tools. All these `main()` functions really do is to read
command line options and read and write files, the algorithms
themselves are completely contained within the libraries.

The directory structure is as follows:

| Directory      | Description |
|----------------|-------------|
| `config`       | Shared make rules and configuration make rules. |
| `speech_class` | General speech class files, including waveforms, contours etc. |
| `ling_class`   | General linguistic class files, including a stream-based architecture. |
| `sigpr`        | Signal processing code. |
| `doc`          | Basic documentation, generates html, info and postscript. |
| `include`      | Class and general header files. |
| `lib`          | Where the `.a` files are kept. |
| `main`         | Directory containing main files which compile to executables. |

## Documentation

There are two sources of documentation.

Man pages exist for the more important stand-alone programs. These are
found in the main directory.

The library documentation has substantiall improved in this version
using an integrated DOC++, JADE and docbook combination. Classes are
described at the overview, theorectical, practical and code level.
The build process for the documentation is still dependent on some
more obscure packages so it is recommended that you take the
pre-built documentation.  Or access it
[on-line](http://www.cstr.ed.ac.uk/projects/speech_tools).

The library documentation is in texinfo format which can be converted
into GNU info HTML and postscript, see `Makefile` in `doc/`.

Note the documentation is not up to date. We are in the process of
moving the documentation to Doxygen.

## Bugs/Comments Etc

Substantial parts of this release are considered mature and should be
relatively free of bugs, however there are newer parts which have not
been rigourously tested yet.  If you find any bugs, please send a bug
report to speechtools@cstr.ed.ac.uk. Any useful comments will also be
appreciated. See also the bugs file in the doc directory.

If you have some software that you think could be integrated into the
speechtools system, please contact us at
speechtools@cstr.ed.ac.uk. The whole point of writing and releasing
code such as this is to prevent duplication of effort, and therefore
we would appreciate greatly any code which will add to the usefulness
of the system. Signal processing routines are particularly welcome.

## Additional Software

[CSTR](http://www.cstr.ed.ac.uk/) supplies a number of different speech
technology systems including speech synthesis systems and (in the future)
a recognition system.

    Centre for Speech Technology
    University of Edinburgh
    2 Buccleuch Place
    Edinburgh EH8 9LW, UK

## License

The `speech_tools` project is released under a [4-clause BSD license](COPYING)
with the following copyright:

    Centre for Speech Technology Research
    University of Edinburgh, UK
    Copyright (c) 1994-2009
    All Rights Reserved.

The changes to the project are described in the [CHANGELOG.md](CHANGELOG.md)
file in order to comply with clause 2 of the BSD license.
