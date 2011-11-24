/* sample radare2 plugin - LGPL - Copyright 2011 swdunlop@gmail.com
   with portions derived from radare - LGPL - Copyright 2010 pancake<@nopcode.org> */

#include <r_types.h>
#include <r_lib.h>
#include <r_cmd.h>
#include <r_core.h>

#define _GNU_SOURCE
#include <stdio.h>

/* invoked by r_cmd whenever a command is submitted with the contents of the command; 
   return R_TRUE if radare2 should not proceed to the next command plugin */

static int call(void *user, const char *cmd) {
    RCore* core = (RCore*)user;
    if(user == NULL) return R_FALSE; /* WTF? */

    if (strcmp (cmd, "sample")) return R_FALSE;    
    printf("sample command invoked\n");
    return R_TRUE;
}

struct r_cmd_plugin_t r_cmd_plugin_sample = {
    /** the following is the "name" of the command in the plugin list */
    .name = "sample",
    /** the following is the "description" of the command in the plugin list */
    .desc = "a sample command",
    .call = call,
};

#ifndef CORELIB
struct r_lib_struct_t radare_plugin = {
    .type = R_LIB_TYPE_CMD,
    .data = &r_cmd_plugin_sample
};
#endif
