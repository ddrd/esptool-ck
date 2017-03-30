/**********************************************************************************
 **********************************************************************************
 ***
 ***    argparese.h
 ***    - header file for argparse.c
 ***
 ***    Copyright (C) 2014 Christian Klippel <ck@atelier-klippel.de>
 ***
 ***    This program is free software; you can redistribute it and/or modify
 ***    it under the terms of the GNU General Public License as published by
 ***    the Free Software Foundation; either version 2 of the License, or
 ***    (at your option) any later version.
 ***
 ***    This program is distributed in the hope that it will be useful,
 ***    but WITHOUT ANY WARRANTY; without even the implied warranty of
 ***    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ***    GNU General Public License for more details.
 ***
 ***    You should have received a copy of the GNU General Public License along
 ***    with this program; if not, write to the Free Software Foundation, Inc.,
 ***    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 ***
 **/

#ifndef ARGPARSE_H
#define ARGPARSE_H

int parse_arg(int num_args, char **arg_ptr);
int argparse_elfcmd(int num_args, char **arg_ptr);
int argparse_binimagecmd(int num_args, char **arg_ptr);
int argparse_commcmd(int num_args, char **arg_ptr);
int argparse_avrdudecmd(int num_args, char **arg_ptr);

#endif
