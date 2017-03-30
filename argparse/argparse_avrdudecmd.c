#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "infohelper.h"
#include "argparse_avrdudecmd.h"
#include "espcomm.h"
#include "espcomm_plduino_avrdude.h"


int argparse_avrdudecmd(int num_args, char **arg_ptr) {
    if (arg_ptr[0][1] == 'a' && num_args--) {
        char *cur_cmd = &arg_ptr[0][2];
        arg_ptr++;
        switch(*cur_cmd++) {
            case 'x': // executable path
                LOGDEBUG("exepath=%s\n", arg_ptr[0]);
                espcomm_set_avrdude_exe_path(arg_ptr[0]);
                return 2;
                break;
            case 'c': // conf path
                LOGDEBUG("confpath=%s\n", arg_ptr[0]);
                espcomm_set_avrdude_conf_path(arg_ptr[0]);
                return 2;
                break;
            case 'h': // helper path
                LOGDEBUG("helperpath=%s\n", arg_ptr[0]);
                espcomm_set_gp0helper_path(arg_ptr[0]);
                return 2;
                break;
            case 't': // temp path
                LOGDEBUG("temphexpath=%s\n", arg_ptr[0]);
                espcomm_set_temphex_path(arg_ptr[0]);
                return 2;
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
