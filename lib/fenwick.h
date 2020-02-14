/*
** Copyright (C) 2015 University of Oxford
**
** This file is part of msprime.
**
** msprime is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** msprime is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with msprime.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __FENWICK_H__
#define __FENWICK_H__

#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    size_t size;
    size_t log_size;
    int64_t *tree;
    int64_t *values;
} fenwick_t;

typedef struct {
    size_t size;
    size_t log_size;
    double prob_continue;
    double *gc_tree;
    int64_t *values;
} gc_fenwick_t;


int fenwick_alloc(fenwick_t *, size_t);
int fenwick_expand(fenwick_t *, size_t);
int fenwick_free(fenwick_t *);
int64_t fenwick_get_total(fenwick_t *);
void fenwick_increment(fenwick_t *, size_t, int64_t);
void fenwick_set_value(fenwick_t *, size_t, int64_t);
int64_t fenwick_get_cumulative_sum(fenwick_t *, size_t);
int64_t fenwick_get_value(fenwick_t *, size_t);
size_t fenwick_find(fenwick_t *, int64_t);
size_t fenwick_get_size(fenwick_t *);

int gc_fenwick_alloc(gc_fenwick_t *, size_t);
int gc_fenwick_expand(gc_fenwick_t *, size_t);
int gc_fenwick_free(gc_fenwick_t *);
double gc_fenwick_get_total_cleft(gc_fenwick_t *);
void gc_fenwick_increment(gc_fenwick_t *, size_t, int64_t);
void gc_fenwick_set_value(gc_fenwick_t *, size_t, int64_t);
double gc_fenwick_get_cumulative_sum(gc_fenwick_t *, size_t);
int64_t gc_fenwick_get_value(gc_fenwick_t *, size_t);
size_t gc_fenwick_find(gc_fenwick_t *, double);
size_t gc_fenwick_get_size(gc_fenwick_t *);

#endif /*__FENWICK_H__*/
