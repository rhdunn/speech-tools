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
 /*                                                                       */
 /*                 Author: Richard Caley <rjc@cstr.ed.ac.uk>             */
 /* -------------------------------------------------------------------   */
 /* Interface between java and C++ for EST_Item_Content.                  */
 /*                                                                       */
 /*************************************************************************/


#include <stdio.h>
#include "jni_Item_Content.h"
#include "ling_class/EST_Item_Content.h"
#include "ling_class/EST_item_content_aux.h"
#include "ling_class/EST_item_aux.h"
#include "ling_class/EST_Relation.h"

static jobject streamItem_class;
static jclass string_class;
static jfieldID handle_field;

static inline short abs(short s) { return s>0?s:-s; }

JNIEXPORT jboolean JNICALL
Java_cstr_est_Item_1Content_initialise_1cpp (JNIEnv *env, jclass myclass)
{
  streamItem_class = env->NewGlobalRef(myclass);
  string_class = (jclass)env->NewGlobalRef(env->FindClass("java/lang/String"));
  handle_field = env->GetFieldID(myclass, "cpp_handle", "J");

  if (!handle_field)
    {
    printf("can't find handle!\n");
    return 0;
    }

  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Item_1Content_finalise_1cpp (JNIEnv *env, jclass myclass)
{
  (void)env;
  (void)myclass;
  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Item_1Content_create_1cpp_1streamItem(JNIEnv *env, 
						      jobject self,
						      jlong handle
						      )
{
  EST_Item_Content *streamItem = (handle==0L
				 ? (new EST_Item_Content)
				 : (EST_Item_Content *)handle
				 );

  // printf("create streamItem %x\n", streamItem);

  env->SetLongField(self, handle_field, (jlong)streamItem);

  return 1;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Item_1Content_destroy_1cpp_1streamItem (JNIEnv *env, jobject self)
{
  EST_Item_Content *streamItem = (EST_Item_Content *) env->GetLongField(self, handle_field);

  // printf("destroy streamItem  %x\n", streamItem);

  delete streamItem;
  return 1;
}

JNIEXPORT jobjectArray JNICALL 
Java_cstr_est_Item_1Content_cpp_1featureNames (JNIEnv *env, jobject self)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);
  
  int n;
  EST_Features::Entries p;

  n=0;
  for (p.begin(item->f); p != 0; ++p)
      n++;

  jobjectArray names = env->NewObjectArray(n, string_class, NULL);

  p.beginning();

  for(int i=0; i<n; i++)
    {
      jstring fn = env->NewStringUTF(p->k);
      env->SetObjectArrayElement(names, i, fn);
      ++p;
    }
  return names;
}


JNIEXPORT jlong JNICALL 
Java_cstr_est_Item_1Content_cpp_1getItem(JNIEnv *env, 
	jobject self)
{
  EST_Item_Content *item_c = (EST_Item_Content *) env->GetLongField(self, handle_field);

  if (item_c->relations.length() == 0)
	return 0L;

  EST_Litem *p;
  p = item_c->relations.list.head();
      
  EST_Item *i = item(item_c->relations.list(p).v);

  return (long)i;
}

JNIEXPORT jstring JNICALL 
Java_cstr_est_Item_1Content_cpp_1getS(JNIEnv *env, 
	jobject self, 
	jstring jname,
	jstring jdef,
	jlong relHandle)
{
  EST_Item_Content *item_c = (EST_Item_Content *) env->GetLongField(self, handle_field);
  EST_Relation *rel = (EST_Relation *)relHandle;
  const char *name = env->GetStringUTFChars(jname, 0);
  
  EST_String val;
  EST_feat_status stat=efs_ok;

  if (rel != NULL)
    {
      //      cout << "getS " << name << " in " << rel->name() << "\n";

       EST_Item *item = item_c->Relation(rel->name());
       val  = getString(*item, name, EST_String::Empty, stat);
    }
  else
    {
      //      cout << "getS " << name << " in  no relation \n";
      val  = getString(*item_c, name, EST_String::Empty, stat);
    }

  env->ReleaseStringUTFChars(jname, name);
  
  if (stat != efs_ok)
    return jdef;

  return  env->NewStringUTF(val);
}

JNIEXPORT jfloat JNICALL 
Java_cstr_est_Item_1Content_cpp_1getF(JNIEnv *env, 
	jobject self, 
	jstring jname,
	jfloat  def,
	jlong relHandle)
{
  EST_Item_Content *item_c = (EST_Item_Content *) env->GetLongField(self, handle_field);
  EST_Relation *rel = (EST_Relation *)relHandle;
  const char *name = env->GetStringUTFChars(jname, 0);
  
  float val;
  EST_feat_status stat=efs_ok;

  if (rel != NULL)
    {
       EST_Item *item = item_c->Relation(rel->name());
       val = getFloat(*item, name, def, stat);
    }
  else
    val = getFloat(*item_c, name, def, stat);

  env->ReleaseStringUTFChars(jname, name);
  
  return  val;
}

JNIEXPORT jboolean JNICALL 
Java_cstr_est_Item_1Content_cpp_1featurePresent(JNIEnv *env, jobject self, jstring jname)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);
  const char *name = env->GetStringUTFChars(jname, 0);
  
  int val = item->f.present(name);

  env->ReleaseStringUTFChars(jname, name);

  return  val;
}

JNIEXPORT jfloat JNICALL 
Java_cstr_est_Item_1Content_cpp_1getStartTime(JNIEnv *env, jobject self)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);
  
  return  item?start(*item):-1.0;
}

JNIEXPORT jfloat JNICALL 
Java_cstr_est_Item_1Content_cpp_1getTime(JNIEnv *env, jobject self)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);

  return  item?time(*item):-1.0;
}

JNIEXPORT jfloat JNICALL 
Java_cstr_est_Item_1Content_cpp_1getMidTime(JNIEnv *env, jobject self)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);

  return  item?mid(*item):-1.0;
}

JNIEXPORT jfloat JNICALL 
Java_cstr_est_Item_1Content_cpp_1getEndTime(JNIEnv *env, jobject self)
{
  EST_Item_Content *item = (EST_Item_Content *) env->GetLongField(self, handle_field);

  return  item?end(*item):-1.0;
}




