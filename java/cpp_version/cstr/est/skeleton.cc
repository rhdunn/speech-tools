/*************************************************************************/
/*                                                                       */
/*                Centre for Speech Technology Research                  */
/*                     University of Edinburgh, UK                       */
/*                         Copyright (c) 1996                            */
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

#include <stdio.h>
#include "jni_Skeliton.h"
#include "ling_class/EST_Skeliton.h"

static jobject skeliton_class;
static jfieldID handle_field;

static inline short abs(short s) { return s>0?s:-s; }

JNIEXPORT jboolean JNICALL
Java_cstr_est_Skeliton_initialise_1cpp (JNIEnv *env, jclass myclass)
{
  skeliton_class = env->NewGlobalRef(myclass);
  handle_field = env->GetFieldID(myclass, "handle", "J");

  if (!handle_field)
    {
    printf("can't find handle!\n");
    return 0;
    }

  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Skeliton_finalise_1cpp (JNIEnv *env, jclass myclass)
{
  (void)env;
  (void)myclass;
  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Skeliton_create_11skeliton(JNIEnv *env, jobject self)
{
  EST_Skeliton *skeliton = new EST_Skeliton;

  // printf("create skeliton %x\n", skeliton);

  env->SetLongField(self, handle_field, (jlong)skeliton);

  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Skeliton_destroy_11skeliton (JNIEnv *env, jobject self)
{
  EST_Skeliton *skeliton = (EST_Skeliton *) env->GetLongField(self, handle_field);

  // printf("destroy skeliton  %x\n", skeliton);

  delete skeliton;
  return 1;
}

JNIEXPORT jstring JNICALL 
Java_cstr_est_Skeliton_1name(JNIEnv *env, jobject self)
{
  EST_Skeliton *skeliton = (EST_Skeliton *) env->GetLongField(self, handle_field);
  return  env->NewStringUTF(skeliton->name());
}

JNIEXPORT jstring JNICALL 
Java_cstr_est_Skeliton_1load (JNIEnv *env, jobject self, jstring jfilename)
{
  EST_Skeliton *skeliton = (EST_Skeliton *) env->GetLongField(self, handle_field);

  const char *filename = env->GetStringUTFChars(jfilename, 0);
  const char *res = "";

  EST_read_status stat = skeliton->load(filename);

  env->ReleaseStringUTFChars(jfilename, filename);

  if (stat == read_format_error)
    res = "skeliton format error";
  else if (stat == read_error) 
    res = "skeliton load error";
  
  return  env->NewStringUTF(res);
}

JNIEXPORT jstring JNICALL 
Java_cstr_est_Skeliton_1save (JNIEnv *env, jobject self, jstring jfilename, jstring jformat)
{
  const EST_Skeliton *skeliton = (EST_Skeliton *) env->GetLongField(self, handle_field);

  const char *filename = env->GetStringUTFChars(jfilename, 0);
  const char *format = env->GetStringUTFChars(jformat, 0);
  const char *res = "";

  EST_write_status stat = skeliton->save(filename,format);

  env->ReleaseStringUTFChars(jfilename, filename);
  env->ReleaseStringUTFChars(jformat, format);

  if (stat == write_error) 
    res = "skeliton save error";
  
  return  env->NewStringUTF(res);
}

