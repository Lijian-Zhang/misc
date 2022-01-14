/*
 * macros.h - definitions for a simple macro expander
 *
 *  Copyright (c) 2010-2020 Cisco and/or its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef included_macros_h
#define included_macros_h

#include <vppinfra/vec.h>
#include <vppinfra/hash.h>
#include <vppinfra/format.h>

#ifdef CLIB_UNIX
#include <stdlib.h>
#include <unistd.h>
#endif

typedef struct
{
  uword *the_builtin_eval_hash;
  uword *the_value_table_hash;
} clib_macro_main_t;

int clib_macro_unset (clib_macro_main_t * mm, char *name);
int clib_macro_set_value (clib_macro_main_t * mm, char *name, char *value);
void clib_macro_add_builtin (clib_macro_main_t * mm, char *name,
			     void *eval_fn);
i8 *clib_macro_get_value (clib_macro_main_t * mm, char *name);
i8 *clib_macro_eval (clib_macro_main_t * mm, i8 * s, i32 complain,
		     u16 level, u16 max_level);
i8 *clib_macro_eval_dollar (clib_macro_main_t * mm, i8 * s, i32 complain);
void clib_macro_init (clib_macro_main_t * mm);
void clib_macro_free (clib_macro_main_t * mm);

format_function_t format_clib_macro_main;

#endif /* included_macros_h */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
