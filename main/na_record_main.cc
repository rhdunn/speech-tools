/*************************************************************************/
/*                                                                       */
/*                Centre for Speech Technology Research                  */
/*                     University of Edinburgh, UK                       */
/*                      Copyright (c) 1995,1996                          */
/*                        All Rights Reserved.                           */
/*                                                                       */
/*  Permission is hereby granted, free of charge, to use and distribute  */
/*  this software and its documentation without restriction, including   */
/*  without limitation the rights to use, copy, modify, merge, publish,  */
/*  distribute, sublicense, and/or sell copies of this work, and to      */
/*  permit persons to whom this work is furnished to do so, subject to   */
/*  the following conditions:                                            */
/*   1. The code must retain the above copyright notice, this list of    */
/*      conditions and the following disclaimer.                         */
/*   2. Any modifications must be clearly marked as such.                */
/*   3. Original authors' names are not deleted.                         */
/*   4. The authors' names are not used to endorse or promote products   */
/*      derived from this software without specific prior written        */
/*      permission.                                                      */
/*                                                                       */
/*  THE UNIVERSITY OF EDINBURGH AND THE CONTRIBUTORS TO THIS WORK        */
/*  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      */
/*  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   */
/*  SHALL THE UNIVERSITY OF EDINBURGH NOR THE CONTRIBUTORS BE LIABLE     */
/*  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    */
/*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   */
/*  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          */
/*  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       */
/*  THIS SOFTWARE.                                                       */
/*                                                                       */
/*************************************************************************/
/*                       Author: Alan W Black                            */
/*                       Date  : February 1998                           */
/*-----------------------------------------------------------------------*/
/*                     General recording program                         */
/*                                                                       */
/*=======================================================================*/
#include "EST.h"
#include "EST_audio.h"
#include "EST_cmd_line_options.h"

int record_voxware_wave(EST_Wave &inwave, EST_Option &al);

/** @name <command>na_record</command> <emphasis>Audio file recording</emphasis>
    @id na-record-manual
  * @toc
 */

//@{


/**@name Synopsis
  */
//@{

//@synopsis

/**

na_record records wavefors from an audio device.  It only supports
recording for N seconds (default is 10).  Specifiying the frequency
defines the recording frequency (if supported by the hardward).  This
currently doesn't support NAS audio in.

 */

//@}

/**@name OPTIONS
  */
//@{

//@options

//@}


int main (int argc, char *argv[])
{
    EST_Wave wave;
    EST_String out_file("-");
    EST_StrList files;
    EST_Option al;

    parse_command_line
	(argc,argv,
       EST_String("[options]\n")+
	 "Summary; record waveform from audio device\n"+
	 "use \"-\" to make output files stdout\n"+
	 "-h               options help\n"+
	 "-f <int>         Input sample rate\n"+
	 "-audiodevice <string> use specified audiodevice if appropriate\n"
	 "                 for protocol\n"
	 "-time <float>    Wave length in seconds\n"+
	 options_wave_output()+
	 "\n"+
	 "-p <string>      audio device protocol. Ths supported types are\n"+
	 "                 "+options_supported_audio()+"\n",
	 files,al);

    if (al.present("-f"))
	al.add_item("-sample_rate", al.val("-f"));
    else
	al.add_item("-sample_rate", "16000");

    if (!al.present("-time"))
	al.add_item("-time", "10");
    if (al.present("-o"))
	out_file = al.val("-o");

    if (record_wave(wave,al) != 0)
    {
	return -1;
    }

    write_wave(wave, out_file, al);
    return 0;
}


