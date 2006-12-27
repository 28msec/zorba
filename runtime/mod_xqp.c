/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Apache module.
 *
 * IMPORTANT NOTE
 * ==============
 *
 * This module is not currently thread-safe for all MPMs.
 *
 */

#include "httpd.h"
#include "http_config.h"
#include "http_core.h"
#include "http_log.h"
#include "http_main.h"
#include "http_protocol.h"
#include "http_request.h"
#include "util_script.h"
#include "http_connection.h"

#include "apr_strings.h"

#include <stdio.h>
#include <dlfcn.h>
#include "content_handler.h"

/*--------------------------------------------------------------------------*/
/*                                                                          */
/* Data declarations.                                                       */
/*                                                                          */
/* Here are the static cells and structure declarations private to our      */
/* module.                                                                  */
/*                                                                          */
/*--------------------------------------------------------------------------*/



static apr_pool_t *x_pool = NULL;
static apr_pool_t *x_subpool = NULL;


#ifndef DEFAULT_MOD_XQP_STRING
#define DEFAULT_MOD_XQP_STRING "apache2_mod_XQP"
#endif

typedef struct {
  char *string;
} cfg;


static void *create_mod_xqp_config(
  apr_pool_t *p, 
  server_rec *s)
{
  cfg *newcfg;
  newcfg = (cfg *) apr_pcalloc(p, sizeof(cfg));
  newcfg->string = DEFAULT_MOD_XQP_STRING;
  return (void *) newcfg;
}

module AP_MODULE_DECLARE_DATA xqp_module;


/*
 * Stub content handler. 
 *
 * The return value instructs the caller concerning what happened and what to
 * do next:
 *
 *  OK ("we did our thing")
 *  DECLINED ("this isn't something with which we want to get involved")
 *  HTTP_mumble ("an error status should be reported")
 */


extern void handle_request(
  const char* version, 
  const char* built,
  char* buf,
  int max);
  
 
 
static int mod_xqp_method_handler(request_rec *r)
{
    
  // Get the module configuration
  cfg *s_cfg = ap_get_module_config(r->server->module_config, &xqp_module);

  // Send a message to the log file.
  fprintf(stderr,"%s",s_cfg->string);
    
  // check for '/xqp'
  if (strcmp(r->handler, "xqp-handler")) return DECLINED;
     
  //--need to start a timer to defend against broken connections
    
  // set content type here: may want 'application/xquery'
  ap_set_content_type(r, "text/html");
    
  // check for head requests
  if (r->header_only) return OK;

  // stub C++ interface: handle_request in a separately-compiled C++ module
  void *lib_handle;
  void (*fn)(const char*,const char*,char*,int);
  int x;
  char* error;
  
  lib_handle = dlopen("/lib/apache2/libtest.so", RTLD_LAZY);
  if (!lib_handle) {
    ap_rputs("<h2>Dynamic link error: failed to load '/lib/apache2/libtest.so</h2>\n", r);
  }
  
  fn = dlsym(lib_handle,"handle_request");
  if ((error = dlerror()) !=NULL) {
    ap_rputs("<h2>Dynamic link error: failed to find function 'handle_request'</h2>\n", r);
    return OK;
  }
  
  char buf[65536];
  (*fn)(ap_get_server_version(),ap_get_server_built(),buf,65536);
  ap_rputs(buf, r);
  
  dlclose(lib_handle);
    
  // --cancel the timer.
  return OK;
}


/*
static const char *set_mod_xqp_string(
  cmd_parms *parms,
  void *mconfig, 
  const char *arg)
{
  cfg *s_cfg = (cfg*)ap_get_module_config(
    parms->server->module_config, &xqp_module);

  s_cfg->string = (char *) arg;
  return NULL;
}
*/


static const command_rec mod_xqp_cmds[] =
{
  AP_INIT_TAKE1(
    "ModuleXQPString",
    NULL, //set_mod_xqp_string,
    NULL,
    0,
    "ModXQP2String (string) The error_log string."
  ),
  {NULL}
};


/*--------------------------------------------------------------------------*/
/*                                                                          */
/* Which functions are responsible for which hooks in the server.           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*
 * Each function our module provides to handle a particular hook is
 * specified here.  The functions are registered using
 * ap_hook_foo(name, predecessors, successors, position)
 * where foo is the name of the hook.
 *
 * The args are as follows:
 * name         -> the name of the function to call.
 * predecessors -> a list of modules whose calls to this hook must be
 *                 invoked before this module.
 * successors   -> a list of modules whose calls to this hook must be
 *                 invoked after this module.
 * position     -> The relative position of this module.  One of
 *                 APR_HOOK_FIRST, APR_HOOK_MIDDLE, or APR_HOOK_LAST.
 *                 Most modules will use APR_HOOK_MIDDLE.  If multiple
 *                 modules use the same relative position, Apache will
 *                 determine which to call first.
 *                 If your module relies on another module to run first,
 *                 or another module running after yours, use the
 *                 predecessors and/or successors.
 *
 * The number in brackets indicates the order in which the routine is called
 * during request processing.  Note that not all routines are necessarily
 * called (such as if a resource doesn't have access restrictions).
 * The actual delivery of content to the browser [9] is not handled by
 * a hook; see the handler declarations below.
 */
static void mod_xqp_register_hooks(apr_pool_t *p)
{
  ap_hook_handler(mod_xqp_method_handler, NULL, NULL, APR_HOOK_MIDDLE);
}



/*--------------------------------------------------------------------------*/
/*                                                                          */
/* Finally, the list of callback routines and data structures that provide  */
/* the static hooks into our module from the other parts of the server.     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*
 * Module definition for configuration.  If a particular callback is not
 * needed, replace its routine name below with the word NULL.
 */
module AP_MODULE_DECLARE_DATA xqp_module =
{
    STANDARD20_MODULE_STUFF,
    NULL,                         /* per-directory config creator */
    NULL,                         /* dir config merger */
    create_mod_xqp_config,        /* server config creator */
    NULL,                         /* server config merger */
    mod_xqp_cmds,                 /* command table */
    mod_xqp_register_hooks        /* set up other request processing hooks */
};
