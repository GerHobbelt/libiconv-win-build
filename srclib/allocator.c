/* Memory allocators such as malloc+free.

   Copyright (C) 2011-2022 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#define _GL_USE_STDLIB_ALLOC 1
#include <config.h>
#include "allocator.h"
#include <stdlib.h>

static void *lcl_malloc(size_t size) {
	return malloc(size);
}
static void* lcl_realloc(void* ptr, size_t size) {
	return realloc(ptr, size);
}
static void lcl_free(void* ptr) {
	if (ptr != NULL) {
		free(ptr);
	}
}

struct allocator const stdlib_allocator = { lcl_malloc, lcl_realloc, lcl_free, NULL };
