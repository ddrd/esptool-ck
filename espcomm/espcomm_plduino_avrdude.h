#ifndef ESPCOMM_PLDUINO_AVRDUDE_H
#define ESPCOMM_PLDUINO_AVRDUDE_H

int flash_arduino_sketch(const char *port, const char *filename);
int flash_arduino_helper_sketch(const char *port);
int dump_arduino_sketch(const char *port, const char *filename);

int espcomm_set_avrdude_exe_path(const char *path);
int espcomm_set_avrdude_conf_path(const char *path);
int espcomm_set_gp0helper_path(const char *path);
int espcomm_set_temphex_path(const char *path);
const char *espcomm_get_temphex_path();

#endif // ESPCOMM_PLDUINO_AVRDUDE_H
