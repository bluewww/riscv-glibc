/* Copyright (C) 2017 Free Software Foundation, Inc.
   Contributed by Andrew Waterman (andrew@sifive.com).
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#if __riscv_flen >= 64 && __riscv_xlen >= 64

long long
__llrint (double x)
{
  long long res;
  asm ("fcvt.l.d %0, %1" : "=r" (res) : "f" (x));
  return res;
}

weak_alias (__llrint, llrint)
#ifdef __LP64__
strong_alias (__llrint, __lrint)
weak_alias (__llrint, lrint)
#endif

#else

#include <sysdeps/ieee754/dbl-64/s_llrint.c>

#endif