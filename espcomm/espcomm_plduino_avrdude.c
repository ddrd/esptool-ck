#include "espcomm_plduino_avrdude.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "infohelper.h"
static char avrdude_exe_path[1024] = "/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude";
static char avrdude_conf_path[1024] = "/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf";
static char gp0helper_path[1024] = "/Users/admin/Library/Arduino15/packages/PLDuino/tools/esptool-plduino/0.4.5/sys_gp0_low.ino.mega.hex";
static char temphex_path[1024] = "/Users/admin/temp/tmp.hex";

int flash_arduino_helper_sketch(const char *port) {
	return flash_arduino_sketch(port, gp0helper_path);
}

int flash_arduino_sketch(const char *port, const char *filename) {
    int ret = 0;
    char *cmd = (char *)malloc(1256);
    if (cmd) {
	    strcpy(cmd, avrdude_exe_path); strcat(cmd, " ");
	    strcat(cmd, "-D ");
	    strcat(cmd, "-v ");
	    strcat(cmd, "-F ");
	    strcat(cmd, "-V ");
	    strcat(cmd, "-c wiring ");
	    strcat(cmd, "-p ATmega2560 ");
	    strcat(cmd, "-P "); strcat(cmd, port); strcat(cmd, " ");
	    strcat(cmd, "-b 115200 ");
	    strcat(cmd, "-U flash:w:"); strcat(cmd, filename); strcat(cmd, ":i ");
	    strcat(cmd, "-C ");
	    strcat(cmd, avrdude_conf_path);
	    LOGVERBOSE("Running command:\n%s", cmd);
	    ret = system(cmd);
	    free(cmd);
	}
	else {
		ret = 1;
	}
	return ret;
}

int dump_arduino_sketch(const char *port, const char *filename) {
	int ret = 0;
    char *cmd = (char *)malloc(1256);
    if (cmd) {
		strcpy(cmd, avrdude_exe_path); strcat(cmd, " ");
		strcat(cmd, "-D ");
		strcat(cmd, "-v ");
		strcat(cmd, "-F ");
		strcat(cmd, "-V ");
		strcat(cmd, "-c wiring ");
		strcat(cmd, "-p ATmega2560 ");
		strcat(cmd, "-P "); strcat(cmd, port); strcat(cmd, " ");
		strcat(cmd, "-b 115200 ");
		strcat(cmd, "-U flash:r:"); strcat(cmd, filename); strcat(cmd, ":i ");
		strcat(cmd, "-C ");
		strcat(cmd, avrdude_conf_path);
		LOGVERBOSE("Running command:\n%s", cmd);
		ret = system(cmd);
		free(cmd);
	}
	else {
		ret = 1;
	}
    return ret;
}

int espcomm_set_avrdude_exe_path(const char *path) {
    LOGDEBUG("Setting avrdude executable path: %s", path);
    strcpy(avrdude_exe_path, path);
    return 1;
}

int espcomm_set_avrdude_conf_path(const char *path) {
    LOGDEBUG("Setting avrdude configuration file path: %s", path);
    strcpy(avrdude_conf_path, path);
    return 1;
}

int espcomm_set_gp0helper_path(const char *path) {
    LOGDEBUG("Setting GP0 helper path: %s", path);
    strcpy(gp0helper_path, path);
    return 1;
}

int espcomm_set_temphex_path(const char *path) {
    LOGDEBUG("Setting temp hex image path: %s", path);
    strcpy(temphex_path, path);
    return 1;
}

const char *espcomm_get_temphex_path() {
	return temphex_path;
}