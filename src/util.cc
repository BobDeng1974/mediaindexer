/*
 * Copyright (C) 2014 Canonical, Ltd.
 *
 * Authors:
 *    Jussi Pakkanen <jussi.pakkanen@canonical.com>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of version 3 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "util.h"

#include<sys/stat.h>

using namespace std;

static bool dir_exists(const string &path) {
    struct stat statbuf;
    stat(path.c_str(), &statbuf);
    return S_ISDIR(statbuf.st_mode) ;
}

bool is_rootlike(const string &path) {
    string s1 = path + "/usr";
    string s2 = path + "/var";
    string s3 = path + "/bin";
    string s4 = path + "/Program Files";
    return (dir_exists(s1) && dir_exists(s2) && dir_exists(s3)) || dir_exists(s4);
}
