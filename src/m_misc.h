/*
========================================================================

                           D O O M  R e t r o
         The classic, refined DOOM source port. For Windows PC.

========================================================================

  Copyright © 1993-2012 id Software LLC, a ZeniMax Media company.
  Copyright © 2013-2016 Brad Harding.

  DOOM Retro is a fork of Chocolate DOOM.
  For a list of credits, see <http://credits.doomretro.com>.

  This file is part of DOOM Retro.

  DOOM Retro is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation, either version 3 of the License, or (at your
  option) any later version.

  DOOM Retro is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with DOOM Retro. If not, see <https://www.gnu.org/licenses/>.

  DOOM is a registered trademark of id Software LLC, a ZeniMax Media
  company, in the US and/or other countries and is used without
  permission. All other trademarks are the property of their respective
  holders. DOOM Retro is in no way affiliated with nor endorsed by
  id Software.

========================================================================
*/

#if !defined(__M_MISC_H__)
#define __M_MISC_H__

#include <stdio.h>
#include <stdlib.h>

#if defined(__OpenBSD__)
#include <stdarg.h>
#endif

#include "doomtype.h"

dboolean M_WriteFile(char *name, void *source, int length);
void M_MakeDirectory(const char *dir);
char *M_TempFile(char *s);
dboolean M_FileExists(const char *file);
long M_FileLength(FILE *handle);
char *M_ExtractFolder(char *path);

// Returns the file system location where application resource files are located.
// On Windows and Linux, this is the folder in which doomretro.exe is located;
// on OSX, this is the Contents/Resources folder within the application bundle.
char *M_GetResourceFolder(void);

// Returns the file system location where generated application
// data (configuration files, logs, savegames etc.) should be saved.
// On Windows and Linux, this is the folder in which doomretro.exe is located;
// on OSX, this is ~/Library/Application Support/DOOM Retro/.
char *M_GetAppDataFolder(void);

char *M_GetExecutableFolder(void);
dboolean M_StrToInt(const char *str, unsigned int *result);
char *M_StrCaseStr(char *haystack, char *needle);
dboolean M_StringCopy(char *dest, char *src, size_t dest_size);
char *M_StringReplace(char *haystack, char *needle, char *replacement);
char *M_StringJoin(char *s, ...);
dboolean M_StringStartsWith(char *s, char *prefix);
dboolean M_StringEndsWith(char *s, char *suffix);
int M_vsnprintf(char *buf, size_t buf_len, const char *s, va_list args);
int M_snprintf(char *buf, size_t buf_len, const char *s, ...);
char *M_SubString(const char *str, size_t begin, size_t len);
dboolean M_StringCompare(const char *str1, const char *str2);
char *uppercase(const char *str);
char *lowercase(const char *str);
char *titlecase(const char *str);
char *formatsize(const char *str);
char *commify(int64_t value);
char *uncommify(const char *input);
dboolean wildcard(char *input, char *pattern);
int gcd(int a, int b);
char *removespaces(const char *input);
char *trimwhitespace(char *input);
char *removenewlines(const char *str);
char *makevalidfilename(const char *input);
const char *leafname(const char *path);
char *removeext(const char *file);
dboolean isvowel(const char ch);
char *convertsize(const int size);
char *striptrailingzero(float value, int precision);
void strreplace(char *target, const char *needle, const char *replacement);

#endif
