
#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
/*
  types/sfloat.c
  Ruby/Numo::GSL - GSL wrapper for Ruby/Numo::NArray

  created on: 2017-03-11
  Copyright (C) 2017 Masahiro Tanaka
*/

#include <ruby.h>
#include <assert.h>
#include "numo/narray.h"
#include "numo/template.h"
#include "SFMT.h"

#define m_map(x) m_num_to_data(rb_yield(m_data_to_num(x)))

#line 18 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
#include <emmintrin.h>
#define SIMD_ALIGNMENT_SIZE 16

static ID id_cast;
static ID id_copysign;
static ID id_divmod;
static ID id_eq;
static ID id_ge;
static ID id_gt;
static ID id_le;
static ID id_lt;
static ID id_mulsum;
static ID id_nan;
static ID id_ne;
static ID id_nearly_eq;
static ID id_pow;

#line 27 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
#include <numo/types/sfloat.h>

#line 30 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
VALUE cT;
extern VALUE cRT;


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/class.c"
/*
  class definition: Numo::SFloat
*/

VALUE cT;

static VALUE sfloat_store(VALUE,VALUE);








#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c"
static size_t
sfloat_memsize(const void* ptr)
{
    size_t size = sizeof(narray_data_t);
    const narray_data_t *na = (const narray_data_t*)ptr;

    assert(na->base.type == NARRAY_DATA_T);

    if (na->ptr != NULL) {
  
#line 13 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c"
        size += na->base.size * sizeof(dtype);
  
    }
    if (na->base.size > 0) {
        if (na->base.shape != NULL && na->base.shape != &(na->base.size)) {
            size += sizeof(size_t) * na->base.ndim;
        }
    }
    return size;
}

static void
sfloat_free(void* ptr)
{
    narray_data_t *na = (narray_data_t*)ptr;

    assert(na->base.type == NARRAY_DATA_T);

    if (na->ptr != NULL) {
        xfree(na->ptr);
        na->ptr = NULL;
    }
    if (na->base.size > 0) {
        if (na->base.shape != NULL && na->base.shape != &(na->base.size)) {
            xfree(na->base.shape);
            na->base.shape = NULL;
        }
    }
    xfree(na);
}

static narray_type_info_t sfloat_info = {
  
#line 50 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c"
    0,             // element_bits
    sizeof(dtype), // element_bytes
    sizeof(dtype), // element_stride (in bytes)
  
};


#line 83 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c"
static const rb_data_type_t sfloat_data_type = {
    "Numo::SFloat",
    {0, sfloat_free, sfloat_memsize,},
    &na_data_type,
    &sfloat_info,
    0, // flags
};


#line 93 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/alloc_func.c"
static VALUE
sfloat_s_alloc_func(VALUE klass)
{
    narray_data_t *na = ALLOC(narray_data_t);

    na->base.ndim = 0;
    na->base.type = NARRAY_DATA_T;
    na->base.flag[0] = NA_FL0_INIT;
    na->base.flag[1] = NA_FL1_INIT;
    na->base.size = 0;
    na->base.shape = NULL;
    na->base.reduce = INT2FIX(0);
    na->ptr = NULL;
    return TypedData_Wrap_Struct(klass, &sfloat_data_type, (void*)na);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/allocate.c"
static VALUE
sfloat_allocate(VALUE self)
{
    narray_t *na;
    char *ptr;

    GetNArray(self,na);

    switch(NA_TYPE(na)) {
    case NARRAY_DATA_T:
        ptr = NA_DATA_PTR(na);
        if (na->size > 0 && ptr == NULL) {
            ptr = xmalloc(sizeof(dtype) * na->size);
            
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/allocate.c"
            NA_DATA_PTR(na) = ptr;
        }
        break;
    case NARRAY_VIEW_T:
        rb_funcall(NA_VIEW_DATA(na), rb_intern("allocate"), 0);
        break;
    case NARRAY_FILEMAP_T:
        //ptr = ((narray_filemap_t*)na)->ptr;
        // to be implemented
    default:
        rb_bug("invalid narray type : %d",NA_TYPE(na));
    }
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract.c"
/*
  Extract an element only if self is a dimensionless NArray.
  @overload extract
  @return [Numeric,Numo::NArray]
  --- Extract element value as Ruby Object if self is a dimensionless NArray,
  otherwise returns self.
*/
static VALUE
sfloat_extract(VALUE self)
{
    volatile VALUE v;
    char *ptr;
    narray_t *na;
    GetNArray(self,na);

    if (na->ndim==0) {
        ptr = na_get_pointer_for_read(self) + na_get_offset(self);
        v = m_extract(ptr);
        na_release_lock(self);
        return v;
    }
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/new_dim0.c"
static VALUE
sfloat_new_dim0(dtype x)
{
    VALUE v;
    dtype *ptr;

    v = nary_new(cT, 0, NULL);
    ptr = (dtype*)(char*)na_get_pointer_for_write(v);
    *ptr = x;
    na_release_lock(v);
    return v;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"

#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_numeric.c"
static VALUE
sfloat_store_numeric(VALUE self, VALUE obj)
{
    dtype x;
    x = m_num_to_data(obj);
    obj = sfloat_new_dim0(x);
    sfloat_store(self,obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_bit.c"
static void
iter_sfloat_store_bit(na_loop_t *const lp)
{
    size_t     i;
    char      *p1;
    size_t     p2;
    ssize_t    s1, s2;
    size_t    *idx1, *idx2;
    BIT_DIGIT *a2, x;
    dtype      y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT_IDX(lp, 1, a2, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                LOAD_BIT(a2, p2+*idx2, x); idx2++;
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                LOAD_BIT(a2, p2+*idx2, x); idx2++;
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                LOAD_BIT(a2, p2, x); p2 += s2;
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                LOAD_BIT(a2, p2, x); p2 += s2;
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_bit(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = {iter_sfloat_store_bit, FULL_LOOP, 2,0, ain,0};

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_dfloat(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    double x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,double,x);
                y = m_from_real(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,double,x);
                y = m_from_real(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,double,x);
                y = m_from_real(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,double,x);
                y = m_from_real(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_dfloat(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_dfloat, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_sfloat(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    float x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,float,x);
                y = m_from_real(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,float,x);
                y = m_from_real(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,float,x);
                y = m_from_real(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,float,x);
                y = m_from_real(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_sfloat(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_sfloat, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_int64(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    int64_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int64_t,x);
                y = m_from_int64(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int64_t,x);
                y = m_from_int64(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int64_t,x);
                y = m_from_int64(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int64_t,x);
                y = m_from_int64(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_int64(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_int64, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_int32(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    int32_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int32_t,x);
                y = m_from_int32(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int32_t,x);
                y = m_from_int32(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int32_t,x);
                y = m_from_int32(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int32_t,x);
                y = m_from_int32(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_int32(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_int32, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_int16(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    int16_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int16_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int16_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int16_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int16_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_int16(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_int16, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_int8(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    int8_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int8_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,int8_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int8_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,int8_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_int8(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_int8, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_uint64(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    u_int64_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int64_t,x);
                y = m_from_uint64(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int64_t,x);
                y = m_from_uint64(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int64_t,x);
                y = m_from_uint64(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int64_t,x);
                y = m_from_uint64(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_uint64(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_uint64, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_uint32(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    u_int32_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int32_t,x);
                y = m_from_uint32(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int32_t,x);
                y = m_from_uint32(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int32_t,x);
                y = m_from_uint32(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int32_t,x);
                y = m_from_uint32(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_uint32(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_uint32, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_uint16(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    u_int16_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int16_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int16_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int16_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int16_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_uint16(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_uint16, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_uint8(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    u_int8_t x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int8_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,u_int8_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int8_t,x);
                y = m_from_sint(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,u_int8_t,x);
                y = m_from_sint(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_uint8(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_uint8, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_from.c"
static void
iter_sfloat_store_robject(na_loop_t *const lp)
{
    size_t  i, s1, s2;
    char   *p1, *p2;
    size_t *idx1, *idx2;
    VALUE x;
    dtype y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx2) {
        if (idx1) {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,VALUE,x);
                y = m_num_to_data(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p2,idx2,VALUE,x);
                y = m_num_to_data(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    } else {
        if (idx1) {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,VALUE,x);
                y = m_num_to_data(x);
                SET_DATA_INDEX(p1,idx1,dtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p2,s2,VALUE,x);
                y = m_num_to_data(x);
                SET_DATA_STRIDE(p1,s1,dtype,y);
            }
        }
    }
}


static VALUE
sfloat_store_robject(VALUE self, VALUE obj)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{Qnil,0}};
    ndfunc_t ndf = { iter_sfloat_store_robject, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, obj);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store_array.c"
static void
iter_sfloat_store_array(na_loop_t *const lp)
{
    size_t i, n;
    size_t i1, n1;
    VALUE  v1, *ptr;
    char   *p1;
    size_t s1, *idx1;
    VALUE  x;
    double y;
    dtype  z;
    size_t len, c;
    double beg, step;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    v1 = lp->args[1].value;
    i = 0;

    if (lp->args[1].ptr) {
        if (v1 == Qtrue) {
            iter_sfloat_store_sfloat(lp);
            i = lp->args[1].shape[0];
            if (idx1) {
                idx1 += i;
            } else {
                p1 += s1 * i;
            }
        }
        goto loop_end;
    }

    ptr = &v1;

    switch(TYPE(v1)) {
    case T_ARRAY:
        n1 = RARRAY_LEN(v1);
        ptr = RARRAY_PTR(v1);
        break;
    case T_NIL:
        n1 = 0;
        break;
    default:
        n1 = 1;
    }

    if (idx1) {
        for (i=i1=0; i1<n1 && i<n; i++,i1++) {
            x = ptr[i1];
            if (rb_obj_is_kind_of(x, rb_cRange) || rb_obj_is_kind_of(x, na_cStep)) {
                nary_step_sequence(x,&len,&beg,&step);
                for (c=0; c<len && i<n; c++,i++) {
                    y = beg + step * c;
                    z = m_from_double(y);
                    SET_DATA_INDEX(p1, idx1, dtype, z);
                }
            }
            else if (TYPE(x) != T_ARRAY) {
                z = m_num_to_data(x);
                SET_DATA_INDEX(p1, idx1, dtype, z);
            }
        }
    } else {
        for (i=i1=0; i1<n1 && i<n; i++,i1++) {
            x = ptr[i1];
            if (rb_obj_is_kind_of(x, rb_cRange) || rb_obj_is_kind_of(x, na_cStep)) {
                nary_step_sequence(x,&len,&beg,&step);
                for (c=0; c<len && i<n; c++,i++) {
                    y = beg + step * c;
                    z = m_from_double(y);
                    SET_DATA_STRIDE(p1, s1, dtype, z);
                }
            }
            else if (TYPE(x) != T_ARRAY) {
                z = m_num_to_data(x);
                SET_DATA_STRIDE(p1, s1, dtype, z);
            }
        }
    }

 loop_end:
    z = m_zero;
    if (idx1) {
        for (; i<n; i++) {
            SET_DATA_INDEX(p1, idx1, dtype, z);
        }
    } else {
        for (; i<n; i++) {
            SET_DATA_STRIDE(p1, s1, dtype, z);
        }
    }
}

static VALUE
sfloat_store_array(VALUE self, VALUE rary)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{rb_cArray,0}};
    ndfunc_t ndf = {iter_sfloat_store_array, FULL_LOOP, 2, 0, ain, 0};

    na_ndloop_store_rarray(&ndf, self, rary);
    return self;
}

#line 5 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
/*
  Store elements to Numo::SFloat from other.
  @overload store(other)
  @param [Object] other
  @return [Numo::SFloat] self
*/
static VALUE
sfloat_store(VALUE self, VALUE obj)
{
    VALUE r, klass;

    klass = rb_obj_class(obj);

    
    if (klass==numo_cSFloat) {
        sfloat_store_sfloat(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (IS_INTEGER_CLASS(klass) || klass==rb_cFloat || klass==rb_cComplex) {
        sfloat_store_numeric(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cBit) {
        sfloat_store_bit(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cDFloat) {
        sfloat_store_dfloat(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cInt64) {
        sfloat_store_int64(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cInt32) {
        sfloat_store_int32(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cInt16) {
        sfloat_store_int16(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cInt8) {
        sfloat_store_int8(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cUInt64) {
        sfloat_store_uint64(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cUInt32) {
        sfloat_store_uint32(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cUInt16) {
        sfloat_store_uint16(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cUInt8) {
        sfloat_store_uint8(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==numo_cRObject) {
        sfloat_store_robject(self,obj);
        return self;
    }
    
#line 19 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    if (klass==rb_cArray) {
        sfloat_store_array(self,obj);
        return self;
    }
    

    if (IsNArray(obj)) {
        r = rb_funcall(obj, rb_intern("coerce_cast"), 1, cT);
        if (rb_obj_class(r)==cT) {
            sfloat_store(self,r);
            return self;
        }
    }

    
#line 36 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/store.c"
    rb_raise(nary_eCastError, "unknown conversion from %s to %s",
             rb_class2name(rb_obj_class(obj)),
             rb_class2name(rb_obj_class(self)));
    
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
/*
  Convert a data value of obj (with a single element) to dtype.
*/
static dtype
sfloat_extract_data(VALUE obj)
{
    narray_t *na;
    dtype  x;
    char  *ptr;
    size_t pos;
    VALUE  r, klass;

    if (IsNArray(obj)) {
        GetNArray(obj,na);
        if (na->size != 1) {
            rb_raise(nary_eShapeError,"narray size should be 1");
        }
        klass = rb_obj_class(obj);
        ptr = na_get_pointer_for_read(obj);
        pos = na_get_offset(obj);
        
        if (klass==numo_cSFloat) {
            x = m_from_real(*(float*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cBit) {
            {BIT_DIGIT b; LOAD_BIT(ptr,pos,b); x = m_from_sint(b);};
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cDFloat) {
            x = m_from_real(*(double*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cInt64) {
            x = m_from_int64(*(int64_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cInt32) {
            x = m_from_int32(*(int32_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cInt16) {
            x = m_from_sint(*(int16_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cInt8) {
            x = m_from_sint(*(int8_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cUInt64) {
            x = m_from_uint64(*(u_int64_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cUInt32) {
            x = m_from_uint32(*(u_int32_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cUInt16) {
            x = m_from_sint(*(u_int16_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cUInt8) {
            x = m_from_sint(*(u_int8_t*)(ptr+pos));
            return x;
        }
        
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        if (klass==numo_cRObject) {
            x = m_num_to_data(*(VALUE*)(ptr+pos));
            return x;
        }
        

        // coerce
        r = rb_funcall(obj, rb_intern("coerce_cast"), 1, cT);
        if (rb_obj_class(r)==cT) {
            return sfloat_extract_data(r);
        }
        
#line 36 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/extract_data.c"
        rb_raise(nary_eCastError, "unknown conversion from %s to %s",
                 rb_class2name(rb_obj_class(obj)),
                 rb_class2name(cT));
        
    }
    if (TYPE(obj)==T_ARRAY) {
        if (RARRAY_LEN(obj) != 1) {
            rb_raise(nary_eShapeError,"array size should be 1");
        }
        return m_num_to_data(RARRAY_AREF(obj,0));
    }
    return m_num_to_data(obj);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast_array.c"
static VALUE
sfloat_cast_array(VALUE rary)
{
    VALUE nary;
    narray_t *na;

    nary = na_s_new_like(cT, rary);
    GetNArray(nary,na);
    if (na->size > 0) {
        sfloat_store_array(nary,rary);
    }
    return nary;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast.c"
#line 5 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast.c"
/*
  Cast object to Numo::SFloat.
  @overload [](elements)
  @overload cast(array)
  @param [Numeric,Array] elements
  @param [Array] array
  @return [Numo::SFloat]
*/
static VALUE
sfloat_s_cast(VALUE type, VALUE obj)
{
    VALUE v;
    narray_t *na;
    dtype x;

    if (rb_obj_class(obj)==cT) {
        return obj;
    }
    if (RTEST(rb_obj_is_kind_of(obj,rb_cNumeric))) {
        x = m_num_to_data(obj);
        return sfloat_new_dim0(x);
    }
    if (RTEST(rb_obj_is_kind_of(obj,rb_cArray))) {
        return sfloat_cast_array(obj);
    }
    if (IsNArray(obj)) {
        GetNArray(obj,na);
        v = nary_new(cT, NA_NDIM(na), NA_SHAPE(na));
        if (NA_SIZE(na) > 0) {
            sfloat_store(v,obj);
        }
        return v;
    }
    
#line 41 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cast.c"
    rb_raise(nary_eCastError,"cannot cast to %s",rb_class2name(type));
    return Qnil;
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/aref.c"
/*
  Array element referenece or slice view.
  @overload [](dim0,...,dimL)
  @param [Numeric,Range,etc] dim0,...,dimL  Multi-dimensional Index.
  @return [Numeric,NArray::SFloat] Element object or NArray view.

  --- Returns the element at +dim0+, +dim1+, ... are Numeric indices
  for each dimension, or returns a NArray View as a sliced subarray if
  +dim0+, +dim1+, ... includes other than Numeric index, e.g., Range
  or Array or true.

  @example
      a = Numo::DFloat.new(4,5).seq
      => Numo::DFloat#shape=[4,5]
      [[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9],
       [10, 11, 12, 13, 14],
       [15, 16, 17, 18, 19]]

      a[1,1]
      => 6.0

      a[1..3,1]
      => Numo::DFloat#shape=[3]
      [6, 11, 16]

      a[1,[1,3,4]]
      => Numo::DFloat#shape=[3]
      [6, 8, 9]

      a[true,2].fill(99)
      a
      => Numo::DFloat#shape=[4,5]
      [[0, 1, 99, 3, 4],
       [5, 6, 99, 8, 9],
       [10, 11, 99, 13, 14],
       [15, 16, 99, 18, 19]]
 */
static VALUE
sfloat_aref(int argc, VALUE *argv, VALUE self)
{
    int nd;
    size_t pos;
    char *ptr;

    nd = na_get_result_dimension(self, argc, argv, sizeof(dtype), &pos);
    if (nd) {
        return na_aref_main(argc, argv, self, 0, nd);
    } else {
        ptr = na_get_pointer_for_read(self) + pos;
        return m_extract(ptr);
    }
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/aset.c"
/*
  Array element(s) set.
  @overload []=(dim0,..,dimL,val)
  @param [Numeric,Range,etc] dim0,..,dimL  Multi-dimensional Index.
  @param [Numeric,Numo::NArray,etc] val  Value(s) to be set to self.
  @return [Numeric] returns val (last argument).

  --- Replace element(s) at +dim0+, +dim1+, ... (index/range/array/true
  for each dimention). Broadcasting mechanism is applied.

  @example
      a = Numo::DFloat.new(3,4).seq
      => Numo::DFloat#shape=[3,4]
      [[0, 1, 2, 3],
       [4, 5, 6, 7],
       [8, 9, 10, 11]]

      a[1,2]=99
      a
      => Numo::DFloat#shape=[3,4]
      [[0, 1, 2, 3],
       [4, 5, 99, 7],
       [8, 9, 10, 11]]

      a[1,[0,2]] = [101,102]
      a
      => Numo::DFloat#shape=[3,4]
      [[0, 1, 2, 3],
       [101, 5, 102, 7],
       [8, 9, 10, 11]]

      a[1,true]=99
      a
      => Numo::DFloat#shape=[3,4]
      [[0, 1, 2, 3],
       [99, 99, 99, 99],
       [8, 9, 10, 11]]

*/
static VALUE
sfloat_aset(int argc, VALUE *argv, VALUE self)
{
    int nd;
    size_t pos;
    char *ptr;
    VALUE a;
    dtype x;

    argc--;
    if (argc==0) {
        sfloat_store(self, argv[argc]);
    } else {
        nd = na_get_result_dimension(self, argc, argv, sizeof(dtype), &pos);
        if (nd) {
            a = na_aref_main(argc, argv, self, 0, nd);
            sfloat_store(a, argv[argc]);
        } else {
            x = sfloat_extract_data(argv[argc]);
            ptr = na_get_pointer_for_read_write(self) + pos;
            *(dtype*)ptr = x;
        }

    }
    return argv[argc];
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/coerce_cast.c"
/*
  return NArray with cast to the type of self.
  @overload coerce_cast(type)
  @return [nil]
*/
static VALUE
sfloat_coerce_cast(VALUE self, VALUE type)
{
    return Qnil;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/to_a.c"
static void
iter_sfloat_to_a(na_loop_t *const lp)
{
    size_t i, s1;
    char *p1;
    size_t *idx1;
    dtype x;
    volatile VALUE a, y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    a = rb_ary_new2(i);
    rb_ary_push(lp->args[1].value, a);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            y = m_data_to_num(x);
            rb_ary_push(a,y);
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            y = m_data_to_num(x);
            rb_ary_push(a,y);
        }
    }
}

/*
  Convert self to Array.
  @overload to_a
  @return [Array]
*/
static VALUE
sfloat_to_a(VALUE self)
{
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{sym_loop_opt},{sym_option}};
    ndfunc_arg_out_t aout[1] = {{rb_cArray,0}}; // dummy?
    ndfunc_t ndf = { iter_sfloat_to_a, FULL_LOOP_NIP, 3, 1, ain, aout };
    return na_ndloop_cast_narray_to_rarray(&ndf, self, Qnil);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/fill.c"
static void
iter_sfloat_fill(na_loop_t *const lp)
{
    size_t   i;
    char    *p1;
    ssize_t  s1;
    size_t  *idx1;
    VALUE    x = lp->option;
    dtype    y;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    y = m_num_to_data(x);
    if (idx1) {
        for (; i--;) {
            SET_DATA_INDEX(p1,idx1,dtype,y);
        }
    } else {
        for (; i--;) {
            SET_DATA_STRIDE(p1,s1,dtype,y);
        }
    }
}

/*
  Fill elements with other.
  @overload fill other
  @param [Numeric] other
  @return [Numo::SFloat] self.
*/
static VALUE
sfloat_fill(VALUE self, VALUE val)
{
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{sym_option}};
    ndfunc_t ndf = { iter_sfloat_fill, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, val);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/format.c"
static VALUE
format_sfloat(VALUE fmt, dtype* x)
{
    // fix-me
    char s[48];
    int n;

    if (NIL_P(fmt)) {
        n = m_sprintf(s,*x);
        return rb_str_new(s,n);
    }
    return rb_funcall(fmt, '%', 1, m_data_to_num(*x));
}

static void
iter_sfloat_format(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1;
    dtype *x;
    VALUE y;
    VALUE fmt = lp->option;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR(lp, 1, p2, s2);
    if (idx1) {
        for (; i--;) {
            x = (dtype*)(p1+*idx1); idx1++;
            y = format_sfloat(fmt, x);
            SET_DATA_STRIDE(p2, s2, VALUE, y);
        }
    } else {
        for (; i--;) {
            x = (dtype*)p1;         p1+=s1;
            y = format_sfloat(fmt, x);
            SET_DATA_STRIDE(p2, s2, VALUE, y);
        }
    }
}

/*
  Format elements into strings.
  @overload format format
  @param [String] format
  @return [Numo::RObject] array of formated strings.
*/
static VALUE
sfloat_format(int argc, VALUE *argv, VALUE self)
{
    VALUE fmt=Qnil;

    ndfunc_arg_in_t ain[2] = {{Qnil,0},{sym_option}};
    ndfunc_arg_out_t aout[1] = {{numo_cRObject,0}};
    ndfunc_t ndf = { iter_sfloat_format, FULL_LOOP_NIP, 2, 1, ain, aout };

    rb_scan_args(argc, argv, "01", &fmt);
    return na_ndloop(&ndf, 2, self, fmt);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/format_to_a.c"
static void
iter_sfloat_format_to_a(na_loop_t *const lp)
{
    size_t  i;
    char   *p1;
    ssize_t s1;
    size_t *idx1;
    dtype *x;
    VALUE y;
    volatile VALUE a;
    VALUE fmt = lp->option;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    a = rb_ary_new2(i);
    rb_ary_push(lp->args[1].value, a);
    if (idx1) {
        for (; i--;) {
            x = (dtype*)(p1 + *idx1);  idx1++;
            y = format_sfloat(fmt, x);
            rb_ary_push(a,y);
        }
    } else {
        for (; i--;) {
            x = (dtype*)p1;  p1+=s1;
            y = format_sfloat(fmt, x);
            rb_ary_push(a,y);
        }
    }
}

/*
  Format elements into strings.
  @overload format_to_a format
  @param [String] format
  @return [Array] array of formated strings.
*/
static VALUE
sfloat_format_to_a(int argc, VALUE *argv, VALUE self)
{
    VALUE fmt=Qnil;
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{sym_loop_opt},{sym_option}};
    ndfunc_arg_out_t aout[1] = {{rb_cArray,0}}; // dummy?
    ndfunc_t ndf = { iter_sfloat_format_to_a, FULL_LOOP_NIP, 3, 1, ain, aout };

    rb_scan_args(argc, argv, "01", &fmt);
    return na_ndloop_cast_narray_to_rarray(&ndf, self, fmt);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/inspect.c"
static VALUE
iter_sfloat_inspect(char *ptr, size_t pos, VALUE fmt)
{
#line 7 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/inspect.c"
    return format_sfloat(fmt, (dtype*)(ptr+pos));
#line 9 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/inspect.c"
}

/*
  Returns a string containing a human-readable representation of NArray.
  @overload inspect
  @return [String]
*/
static VALUE
sfloat_inspect(VALUE ary)
{
    return na_ndloop_inspect(ary, iter_sfloat_inspect, Qnil);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/each.c"
static void
iter_sfloat_each(na_loop_t *const lp)
{
    size_t i, s1;
    char *p1;
    size_t *idx1;
    dtype x;
    VALUE y;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            y = m_data_to_num(x);
            rb_yield(y);
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            y = m_data_to_num(x);
            rb_yield(y);
        }
    }
}

/*
  Calls the given block once for each element in self,
  passing that element as a parameter.
  @overload each
  @return [Numo::NArray] self
  For a block {|x| ... }
  @yield [x]  x is element of NArray.
*/
static VALUE
sfloat_each(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{Qnil,0}};
    ndfunc_t ndf = {iter_sfloat_each, FULL_LOOP_NIP, 1,0, ain,0};

    na_ndloop(&ndf, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_map(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_map(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_map(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_map(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_map(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_map(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_map(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary map.
  @overload map
  @return [Numo::SFloat] map of self.
*/
static VALUE
sfloat_map(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_map, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/each_with_index.c"
static inline void
yield_each_with_index(dtype x, size_t *c, VALUE *a, int nd, int md)
{
    int j;

    a[0] = m_data_to_num(x);
    for (j=0; j<=nd; j++) {
        a[j+1] = SIZET2NUM(c[j]);
    }
    rb_yield(rb_ary_new4(md,a));
}


static void
iter_sfloat_each_with_index(na_loop_t *const lp)
{
    size_t i, s1;
    char *p1;
    size_t *idx1;
    dtype x;
    VALUE *a;
    size_t *c;
    int nd, md;

    c = (size_t*)(lp->opt_ptr);
    nd = lp->ndim;
    if (nd > 0) {nd--;}
    md = nd + 2;
    a = ALLOCA_N(VALUE,md);

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    c[nd] = 0;
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            yield_each_with_index(x,c,a,nd,md);
            c[nd]++;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            yield_each_with_index(x,c,a,nd,md);
            c[nd]++;
        }
    }
}

/*
  Invokes the given block once for each element of self,
  passing that element and indices along each axis as parameters.
  @overload each_with_index
  @return [Numo::NArray] self
  For a block {|x,i,j,...| ... }
  @yield [x,i,j,...]  x is an element, i,j,... are multidimensional indices.
*/
static VALUE
sfloat_each_with_index(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{Qnil,0}};
    ndfunc_t ndf = {iter_sfloat_each_with_index, FULL_LOOP_NIP, 1,0, ain,0};

    na_ndloop_with_index(&ndf, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/map_with_index.c"
static inline dtype
yield_map_with_index(dtype x, size_t *c, VALUE *a, int nd, int md)
{
    int j;
    VALUE y;

    a[0] = m_data_to_num(x);
    for (j=0; j<=nd; j++) {
        a[j+1] = SIZET2NUM(c[j]);
    }
    y = rb_yield(rb_ary_new4(md,a));
    return m_num_to_data(y);
}

static void
iter_sfloat_map_with_index(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype x;
    VALUE *a;
    size_t *c;
    int nd, md;

    c = (size_t*)(lp->opt_ptr);
    nd = lp->ndim;
    if (nd > 0) {nd--;}
    md = nd + 2;
    a = ALLOCA_N(VALUE,md);

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    c[nd] = 0;
    if (idx1) {
        if (idx2) {
            for (; i--;) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = yield_map_with_index(x,c,a,nd,md);
                SET_DATA_INDEX(p2,idx2,dtype,x);
                c[nd]++;
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = yield_map_with_index(x,c,a,nd,md);
                SET_DATA_STRIDE(p2,s2,dtype,x);
                c[nd]++;
            }
        }
    } else {
        if (idx2) {
            for (; i--;) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = yield_map_with_index(x,c,a,nd,md);
                SET_DATA_INDEX(p2,idx2,dtype,x);
                c[nd]++;
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = yield_map_with_index(x,c,a,nd,md);
                SET_DATA_STRIDE(p2,s2,dtype,x);
                c[nd]++;
            }
        }
    }
}

/*
  Invokes the given block once for each element of self,
  passing that element and indices along each axis as parameters.
  Creates a new NArray containing the values returned by the block.
  Inplace option is allowed, i.e., `nary.inplace.map` overwrites `nary`.

  @overload map_with_index

  For a block {|x,i,j,...| ... }
  @yield [x,i,j,...]  x is an element, i,j,... are multidimensional indices.

  @return [Numo::NArray] mapped array

*/
static VALUE
sfloat_map_with_index(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{Qnil,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_map_with_index, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop_with_index(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary2.c"
static void
iter_sfloat_abs(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;
    rtype y;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);
    if (idx1) {
        if (idx2) {
            for (; i--;) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                y = m_abs(x);
                SET_DATA_INDEX(p2,idx2,rtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                y = m_abs(x);
                SET_DATA_STRIDE(p2,s2,rtype,y);
            }
        }
    } else {
        if (idx2) {
            for (; i--;) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                y = m_abs(x);
                SET_DATA_INDEX(p2,idx2,rtype,y);
            }
        } else {
            for (; i--;) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                y = m_abs(x);
                SET_DATA_STRIDE(p2,s2,rtype,y);
            }
        }
    }
}


/*
  abs of self.
  @overload abs
  @return [Numo::SFloat] abs of self.
*/
static VALUE
sfloat_abs(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cRT,0}};
    ndfunc_t ndf = { iter_sfloat_abs, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_add(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    size_t cnt;
    size_t cnt_simd_loop = -1;
  
#line 26 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    __m128 a;
    __m128 b;
  
    size_t num_pack; // Number of elements packed for SIMD.
    num_pack = SIMD_ALIGNMENT_SIZE / sizeof(dtype);
#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            // Check number of elements. & Check same alignment.
            if ((n >= num_pack) && is_same_aligned3(&((dtype*)p1)[i], &((dtype*)p2)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                // Calculate up to the position just before the start of SIMD computation.
                cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                if (p1 == p3) { // inplace case
                    for (; i < cnt; i++) {
                        ((dtype*)p1)[i] = m_add(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i < cnt; i++) {
                        ((dtype*)p3)[i] = m_add(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }

                // Get the count of SIMD computation loops.
                cnt_simd_loop = (n - i) % num_pack;

                // SIMD computation.
                if (p1 == p3) { // inplace case
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_add_ps(a, b);
                        _mm_store_ps(&((dtype*)p1)[i], a);
                    }
                } else {
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_add_ps(a, b);
                        _mm_stream_ps(&((dtype*)p3)[i], a);
                    }
                }
            }

            // Compute the remainder of the SIMD operation.
            if (cnt_simd_loop != 0){
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_add(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_add(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 96 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 111 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    // Broadcast a scalar value and use it for SIMD computation.
                    b = _mm_load1_ps(&((dtype*)p2)[0]);

                    // Check number of elements. & Check same alignment.
                    if ((n >= num_pack) && is_same_aligned2(&((dtype*)p1)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                        // Calculate up to the position just before the start of SIMD computation.
                        cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                        if (p1 == p3) { // inplace case
                            for (; i < cnt; i++) {
                                ((dtype*)p1)[i] = m_add(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i < cnt; i++) {
                                ((dtype*)p3)[i] = m_add(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }

                        // Get the count of SIMD computation loops.
                        cnt_simd_loop = (n - i) % num_pack;

                        // SIMD computation.
                        if (p1 == p3) { // inplace case
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_add_ps(a, b);
                                _mm_store_ps(&((dtype*)p1)[i], a);
                            }
                        } else {
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_add_ps(a, b);
                                _mm_stream_ps(&((dtype*)p3)[i], a);
                            }
                        }
                    }

                    // Compute the remainder of the SIMD operation.
                    if (cnt_simd_loop != 0){
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_add(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_add(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 160 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_add(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_add(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_add(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_add(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_add_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_add, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary add.
  @overload + other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self + other
*/
static VALUE
sfloat_add(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_add_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, '+', 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_sub(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    size_t cnt;
    size_t cnt_simd_loop = -1;
  
#line 26 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    __m128 a;
    __m128 b;
  
    size_t num_pack; // Number of elements packed for SIMD.
    num_pack = SIMD_ALIGNMENT_SIZE / sizeof(dtype);
#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            // Check number of elements. & Check same alignment.
            if ((n >= num_pack) && is_same_aligned3(&((dtype*)p1)[i], &((dtype*)p2)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                // Calculate up to the position just before the start of SIMD computation.
                cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                if (p1 == p3) { // inplace case
                    for (; i < cnt; i++) {
                        ((dtype*)p1)[i] = m_sub(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i < cnt; i++) {
                        ((dtype*)p3)[i] = m_sub(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }

                // Get the count of SIMD computation loops.
                cnt_simd_loop = (n - i) % num_pack;

                // SIMD computation.
                if (p1 == p3) { // inplace case
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_sub_ps(a, b);
                        _mm_store_ps(&((dtype*)p1)[i], a);
                    }
                } else {
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_sub_ps(a, b);
                        _mm_stream_ps(&((dtype*)p3)[i], a);
                    }
                }
            }

            // Compute the remainder of the SIMD operation.
            if (cnt_simd_loop != 0){
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_sub(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_sub(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 96 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 111 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    // Broadcast a scalar value and use it for SIMD computation.
                    b = _mm_load1_ps(&((dtype*)p2)[0]);

                    // Check number of elements. & Check same alignment.
                    if ((n >= num_pack) && is_same_aligned2(&((dtype*)p1)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                        // Calculate up to the position just before the start of SIMD computation.
                        cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                        if (p1 == p3) { // inplace case
                            for (; i < cnt; i++) {
                                ((dtype*)p1)[i] = m_sub(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i < cnt; i++) {
                                ((dtype*)p3)[i] = m_sub(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }

                        // Get the count of SIMD computation loops.
                        cnt_simd_loop = (n - i) % num_pack;

                        // SIMD computation.
                        if (p1 == p3) { // inplace case
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_sub_ps(a, b);
                                _mm_store_ps(&((dtype*)p1)[i], a);
                            }
                        } else {
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_sub_ps(a, b);
                                _mm_stream_ps(&((dtype*)p3)[i], a);
                            }
                        }
                    }

                    // Compute the remainder of the SIMD operation.
                    if (cnt_simd_loop != 0){
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_sub(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_sub(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 160 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_sub(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_sub(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_sub(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_sub(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_sub_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_sub, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary sub.
  @overload - other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self - other
*/
static VALUE
sfloat_sub(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_sub_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, '-', 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_mul(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    size_t cnt;
    size_t cnt_simd_loop = -1;
  
#line 26 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    __m128 a;
    __m128 b;
  
    size_t num_pack; // Number of elements packed for SIMD.
    num_pack = SIMD_ALIGNMENT_SIZE / sizeof(dtype);
#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            // Check number of elements. & Check same alignment.
            if ((n >= num_pack) && is_same_aligned3(&((dtype*)p1)[i], &((dtype*)p2)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                // Calculate up to the position just before the start of SIMD computation.
                cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                if (p1 == p3) { // inplace case
                    for (; i < cnt; i++) {
                        ((dtype*)p1)[i] = m_mul(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i < cnt; i++) {
                        ((dtype*)p3)[i] = m_mul(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }

                // Get the count of SIMD computation loops.
                cnt_simd_loop = (n - i) % num_pack;

                // SIMD computation.
                if (p1 == p3) { // inplace case
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_mul_ps(a, b);
                        _mm_store_ps(&((dtype*)p1)[i], a);
                    }
                } else {
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_mul_ps(a, b);
                        _mm_stream_ps(&((dtype*)p3)[i], a);
                    }
                }
            }

            // Compute the remainder of the SIMD operation.
            if (cnt_simd_loop != 0){
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_mul(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_mul(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 96 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 111 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    // Broadcast a scalar value and use it for SIMD computation.
                    b = _mm_load1_ps(&((dtype*)p2)[0]);

                    // Check number of elements. & Check same alignment.
                    if ((n >= num_pack) && is_same_aligned2(&((dtype*)p1)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                        // Calculate up to the position just before the start of SIMD computation.
                        cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                        if (p1 == p3) { // inplace case
                            for (; i < cnt; i++) {
                                ((dtype*)p1)[i] = m_mul(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i < cnt; i++) {
                                ((dtype*)p3)[i] = m_mul(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }

                        // Get the count of SIMD computation loops.
                        cnt_simd_loop = (n - i) % num_pack;

                        // SIMD computation.
                        if (p1 == p3) { // inplace case
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_mul_ps(a, b);
                                _mm_store_ps(&((dtype*)p1)[i], a);
                            }
                        } else {
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_mul_ps(a, b);
                                _mm_stream_ps(&((dtype*)p3)[i], a);
                            }
                        }
                    }

                    // Compute the remainder of the SIMD operation.
                    if (cnt_simd_loop != 0){
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_mul(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_mul(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 160 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_mul(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_mul(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_mul(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_mul(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_mul_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_mul, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary mul.
  @overload * other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self * other
*/
static VALUE
sfloat_mul(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_mul_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, '*', 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_div(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    size_t cnt;
    size_t cnt_simd_loop = -1;
  
#line 26 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    __m128 a;
    __m128 b;
  
    size_t num_pack; // Number of elements packed for SIMD.
    num_pack = SIMD_ALIGNMENT_SIZE / sizeof(dtype);
#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            // Check number of elements. & Check same alignment.
            if ((n >= num_pack) && is_same_aligned3(&((dtype*)p1)[i], &((dtype*)p2)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                // Calculate up to the position just before the start of SIMD computation.
                cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                if (p1 == p3) { // inplace case
                    for (; i < cnt; i++) {
                        ((dtype*)p1)[i] = m_div(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i < cnt; i++) {
                        ((dtype*)p3)[i] = m_div(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }

                // Get the count of SIMD computation loops.
                cnt_simd_loop = (n - i) % num_pack;

                // SIMD computation.
                if (p1 == p3) { // inplace case
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_div_ps(a, b);
                        _mm_store_ps(&((dtype*)p1)[i], a);
                    }
                } else {
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        b = _mm_load_ps(&((dtype*)p2)[i]);
                        a = _mm_div_ps(a, b);
                        _mm_stream_ps(&((dtype*)p3)[i], a);
                    }
                }
            }

            // Compute the remainder of the SIMD operation.
            if (cnt_simd_loop != 0){
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_div(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_div(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 96 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 111 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    // Broadcast a scalar value and use it for SIMD computation.
                    b = _mm_load1_ps(&((dtype*)p2)[0]);

                    // Check number of elements. & Check same alignment.
                    if ((n >= num_pack) && is_same_aligned2(&((dtype*)p1)[i], &((dtype*)p3)[i], SIMD_ALIGNMENT_SIZE)){
                        // Calculate up to the position just before the start of SIMD computation.
                        cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                        if (p1 == p3) { // inplace case
                            for (; i < cnt; i++) {
                                ((dtype*)p1)[i] = m_div(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i < cnt; i++) {
                                ((dtype*)p3)[i] = m_div(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }

                        // Get the count of SIMD computation loops.
                        cnt_simd_loop = (n - i) % num_pack;

                        // SIMD computation.
                        if (p1 == p3) { // inplace case
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_div_ps(a, b);
                                _mm_store_ps(&((dtype*)p1)[i], a);
                            }
                        } else {
                            for(; i < n - cnt_simd_loop; i += num_pack){
                                a = _mm_load_ps(&((dtype*)p1)[i]);
                                a = _mm_div_ps(a, b);
                                _mm_stream_ps(&((dtype*)p3)[i], a);
                            }
                        }
                    }

                    // Compute the remainder of the SIMD operation.
                    if (cnt_simd_loop != 0){
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_div(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_div(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 160 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                    }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_div(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_div(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_div(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_div(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_div_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_div, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary div.
  @overload / other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self / other
*/
static VALUE
sfloat_div(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_div_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, '/', 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_mod(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_mod(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_mod(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_mod(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_mod(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_mod(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_mod(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_mod(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_mod(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_mod_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_mod, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary mod.
  @overload % other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self % other
*/
static VALUE
sfloat_mod(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_mod_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, '%', 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary2.c"
static void
iter_sfloat_divmod(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3, *p4;
    ssize_t  s1, s2, s3, s4;
    dtype    x, y, a, b;
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    INIT_PTR(lp, 3, p4, s4);
    for (i=n; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
#line 22 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary2.c"
        m_divmod(x,y,a,b);
        SET_DATA_STRIDE(p3,s3,dtype,a);
        SET_DATA_STRIDE(p4,s4,dtype,b);
    }
}

static VALUE
sfloat_divmod_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[2] = {{cT,0},{cT,0}};
    ndfunc_t ndf = { iter_sfloat_divmod, STRIDE_LOOP, 2, 2, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary divmod.
  @overload divmod other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] divmod of self and other.
*/
static VALUE
sfloat_divmod(VALUE self, VALUE other)
{
    
#line 50 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary2.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_divmod_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_divmod, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/pow.c"
static void
iter_sfloat_pow(na_loop_t *const lp)
{
    size_t  i;
    char    *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype    x, y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        x = m_pow(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

static void
iter_sfloat_pow_int32(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype   x;
    int32_t y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,int32_t,y);
        x = m_pow_int(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

static VALUE
sfloat_pow_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_in_t ain_i[2] = {{cT,0},{numo_cInt32,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_pow, STRIDE_LOOP, 2, 1, ain, aout };
    ndfunc_t ndf_i = { iter_sfloat_pow_int32, STRIDE_LOOP, 2, 1, ain_i, aout };

    // fixme : use na.integer?
    if (FIXNUM_P(other) || rb_obj_is_kind_of(other,numo_cInt32)) {
        return na_ndloop(&ndf_i, 2, self, other);
    } else {
        return na_ndloop(&ndf, 2, self, other);
    }
}

/*
  Binary power.
  @overload ** other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self to the other-th power.
*/
static VALUE
sfloat_pow(VALUE self, VALUE other)
{
    
#line 69 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/pow.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_pow_self(self,other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_pow, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_minus(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_minus(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_minus(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_minus(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_minus(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_minus(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_minus(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary minus.
  @overload -@
  @return [Numo::SFloat] minus of self.
*/
static VALUE
sfloat_minus(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_minus, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_reciprocal(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_reciprocal(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_reciprocal(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_reciprocal(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_reciprocal(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_reciprocal(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_reciprocal(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary reciprocal.
  @overload reciprocal
  @return [Numo::SFloat] reciprocal of self.
*/
static VALUE
sfloat_reciprocal(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_reciprocal, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_sign(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sign(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sign(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sign(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_sign(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_sign(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sign(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary sign.
  @overload sign
  @return [Numo::SFloat] sign of self.
*/
static VALUE
sfloat_sign(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_sign, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_square(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_square(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_square(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_square(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_square(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_square(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_square(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary square.
  @overload square
  @return [Numo::SFloat] square of self.
*/
static VALUE
sfloat_square(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_square, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}





#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_eq(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_eq(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_eq_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_eq, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison eq other.
  @overload eq other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self eq other.
*/
static VALUE
sfloat_eq(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_eq_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_eq, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_ne(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_ne(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_ne_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_ne, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison ne other.
  @overload ne other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self ne other.
*/
static VALUE
sfloat_ne(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_ne_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_ne, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_nearly_eq(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_nearly_eq(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_nearly_eq_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_nearly_eq, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison nearly_eq other.
  @overload nearly_eq other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self nearly_eq other.
*/
static VALUE
sfloat_nearly_eq(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_nearly_eq_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_nearly_eq, 1, other);
    }
    
}



#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_floor(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_floor(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_floor(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_floor(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_floor(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_floor(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_floor(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary floor.
  @overload floor
  @return [Numo::SFloat] floor of self.
*/
static VALUE
sfloat_floor(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_floor, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_round(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_round(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_round(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_round(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_round(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_round(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_round(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary round.
  @overload round
  @return [Numo::SFloat] round of self.
*/
static VALUE
sfloat_round(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_round, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_ceil(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_ceil(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_ceil(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_ceil(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_ceil(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_ceil(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_ceil(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary ceil.
  @overload ceil
  @return [Numo::SFloat] ceil of self.
*/
static VALUE
sfloat_ceil(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_ceil, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_trunc(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_trunc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_trunc(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_trunc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_trunc(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_trunc(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_trunc(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary trunc.
  @overload trunc
  @return [Numo::SFloat] trunc of self.
*/
static VALUE
sfloat_trunc(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_trunc, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary.c"
static void
iter_sfloat_rint(na_loop_t *const lp)
{
    size_t  i, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_rint(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_rint(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_rint(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            //
            if (is_aligned(p1,sizeof(dtype)) &&
                is_aligned(p2,sizeof(dtype)) ) {
                if (s1 == sizeof(dtype) &&
                    s2 == sizeof(dtype) ) {
                    for (i=0; i<n; i++) {
                        ((dtype*)p2)[i] = m_rint(((dtype*)p1)[i]);
                    }
                    return;
                }
                if (is_aligned_step(s1,sizeof(dtype)) &&
                    is_aligned_step(s2,sizeof(dtype)) ) {
                    //
                    for (i=0; i<n; i++) {
                        *(dtype*)p2 = m_rint(*(dtype*)p1);
                        p1 += s1;
                        p2 += s2;
                    }
                    return;
                    //
                }
            }
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_rint(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
            //
        }
    }
}

/*
  Unary rint.
  @overload rint
  @return [Numo::SFloat] rint of self.
*/
static VALUE
sfloat_rint(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = {iter_sfloat_rint, FULL_LOOP, 1,1, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#line 8 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
#define check_intdivzero(y) {}

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
static void
iter_sfloat_copysign(na_loop_t *const lp)
{
    size_t   i=0;
    size_t   n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

#line 32 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    //
    if (is_aligned(p1,sizeof(dtype)) &&
        is_aligned(p2,sizeof(dtype)) &&
        is_aligned(p3,sizeof(dtype)) ) {

        if (s1 == sizeof(dtype) &&
            s2 == sizeof(dtype) &&
            s3 == sizeof(dtype) ) {
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                if (p1 == p3) { // inplace case
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p1)[i] = m_copysign(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                } else {
                    for (; i<n; i++) {
                        check_intdivzero(((dtype*)p2)[i]);
                        ((dtype*)p3)[i] = m_copysign(((dtype*)p1)[i],((dtype*)p2)[i]);
                    }
                }
#line 98 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
            return;
        }

        if (is_aligned_step(s1,sizeof(dtype)) &&
            is_aligned_step(s2,sizeof(dtype)) &&
            is_aligned_step(s3,sizeof(dtype)) ) {
            //

            if (s2 == 0){ // Broadcasting from scalar value.
                check_intdivzero(*(dtype*)p2);
                if (s1 == sizeof(dtype) &&
                    s3 == sizeof(dtype) ) {
#line 150 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                        if (p1 == p3) { // inplace case
                            for (; i<n; i++) {
                                ((dtype*)p1)[i] = m_copysign(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        } else {
                            for (; i<n; i++) {
                                ((dtype*)p3)[i] = m_copysign(((dtype*)p1)[i],*(dtype*)p2);
                            }
                        }
#line 162 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
                } else {
                    for (i=0; i<n; i++) {
                        *(dtype*)p3 = m_copysign(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p3 += s3;
                    }
                }
            } else {
                if (p1 == p3) { // inplace case
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p1 = m_copysign(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                    }
                } else {
                    for (i=0; i<n; i++) {
                        check_intdivzero(*(dtype*)p2);
                        *(dtype*)p3 = m_copysign(*(dtype*)p1,*(dtype*)p2);
                        p1 += s1;
                        p2 += s2;
                        p3 += s3;
                    }
                }
            }

            return;
            //
        }
    }
    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        check_intdivzero(y);
        z = m_copysign(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
    //
}
#undef check_intdivzero

static VALUE
sfloat_copysign_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_copysign, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Binary copysign.
  @overload copysign other
  @param [Numo::NArray,Numeric] other
  @return [Numo::NArray] self copysign other
*/
static VALUE
sfloat_copysign(VALUE self, VALUE other)
{
    
#line 226 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary.c"
    VALUE klass, v;

    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_copysign_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_copysign, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_signbit(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_signbit(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_signbit(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of signbit.
  @overload signbit
  @return [Numo::Bit] Condition of signbit.
*/
static VALUE
sfloat_signbit(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_signbit, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_ret2.c"
static void
iter_sfloat_modf(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype   x, y, z;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        m_modf(x,y,z);
        SET_DATA_STRIDE(p2,s2,dtype,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
}

/*
  modf of self.
  @overload modf
  @return [Numo::SFloat] modf of self.
*/
static VALUE
sfloat_modf(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[2] = {{cT,0},{cT,0}};
    ndfunc_t ndf = {iter_sfloat_modf, STRIDE_LOOP, 1,2, ain,aout};

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_gt(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_gt(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_gt_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_gt, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison gt other.
  @overload gt other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self gt other.
*/
static VALUE
sfloat_gt(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_gt_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_gt, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_ge(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_ge(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_ge_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_ge, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison ge other.
  @overload ge other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self ge other.
*/
static VALUE
sfloat_ge(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_ge_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_ge, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_lt(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_lt(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_lt_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_lt, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison lt other.
  @overload lt other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self lt other.
*/
static VALUE
sfloat_lt(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_lt_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_lt, 1, other);
    }
    
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
static void
iter_sfloat_le(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2;
    BIT_DIGIT *a3;
    size_t  p3;
    ssize_t s1, s2, s3;
    dtype   x, y;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR_BIT(lp, 2, a3, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        b = (m_le(x,y)) ? 1:0;
        STORE_BIT(a3,p3,b);
        p3+=s3;
    }
}

static VALUE
sfloat_le_self(VALUE self, VALUE other)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_le, STRIDE_LOOP, 2, 1, ain, aout };

    return na_ndloop(&ndf, 2, self, other);
}

/*
  Comparison le other.
  @overload le other
  @param [Numo::NArray,Numeric] other
  @return [Numo::Bit] result of self le other.
*/
static VALUE
sfloat_le(VALUE self, VALUE other)
{
    
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_binary.c"
    VALUE klass, v;
    klass = na_upcast(rb_obj_class(self),rb_obj_class(other));
    if (klass==cT) {
        return sfloat_le_self(self, other);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall(v, id_le, 1, other);
    }
    
}






#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/clip.c"
static void
iter_sfloat_clip(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2, *p3, *p4;
    ssize_t s1, s2, s3, s4;
    dtype   x, min, max;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    INIT_PTR(lp, 3, p4, s4);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,min);
        GET_DATA_STRIDE(p3,s3,dtype,max);
        if (m_gt(min,max)) {rb_raise(nary_eOperationError,"min is greater than max");}
        if (m_lt(x,min)) {x=min;}
        if (m_gt(x,max)) {x=max;}
        SET_DATA_STRIDE(p4,s4,dtype,x);
    }
}

static void
iter_sfloat_clip_min(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype   x, min;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,min);
        if (m_lt(x,min)) {x=min;}
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

static void
iter_sfloat_clip_max(na_loop_t *const lp)
{
    size_t  i;
    char   *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype   x, max;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,max);
        if (m_gt(x,max)) {x=max;}
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

/*
  Clip array elements by [min,max].
  If either of min or max is nil, one side is clipped.
  @overload clip(min,max)
  @param [Numo::NArray,Numeric] min
  @param [Numo::NArray,Numeric] max
  @return [Numo::NArray] result of clip.

  @example
      a = Numo::Int32.new(10).seq
      p a.clip(1,8)
      # Numo::Int32#shape=[10]
      # [1, 1, 2, 3, 4, 5, 6, 7, 8, 8]

      p a
      # Numo::Int32#shape=[10]
      # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

      p a.inplace.clip(3,6)
      # Numo::Int32(view)#shape=[10]
      # [3, 3, 3, 3, 4, 5, 6, 6, 6, 6]

      p a
      # Numo::Int32#shape=[10]
      # [3, 3, 3, 3, 4, 5, 6, 6, 6, 6]

      p a = Numo::Int32.new(10).seq
      # Numo::Int32#shape=[10]
      # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

      p a.clip([3,4,1,1,1,4,4,4,4,4], 8)
      # Numo::Int32#shape=[10]
      # [3, 4, 2, 3, 4, 5, 6, 7, 8, 8]
*/
static VALUE
sfloat_clip(VALUE self, VALUE min, VALUE max)
{
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf_min = { iter_sfloat_clip_min, STRIDE_LOOP, 2, 1, ain, aout };
    ndfunc_t ndf_max = { iter_sfloat_clip_max, STRIDE_LOOP, 2, 1, ain, aout };
    ndfunc_t ndf_both = { iter_sfloat_clip, STRIDE_LOOP, 3, 1, ain, aout };

    if (RTEST(min)) {
        if (RTEST(max)) {
            return na_ndloop(&ndf_both, 3, self, min, max);
        } else {
            return na_ndloop(&ndf_min, 2, self, min);
        }
    } else {
        if (RTEST(max)) {
            return na_ndloop(&ndf_max, 2, self, max);
        }
    }
    rb_raise(rb_eArgError,"min and max are not given");
    return Qnil;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_isnan(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_isnan(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_isnan(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of isnan.
  @overload isnan
  @return [Numo::Bit] Condition of isnan.
*/
static VALUE
sfloat_isnan(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_isnan, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_isinf(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_isinf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_isinf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of isinf.
  @overload isinf
  @return [Numo::Bit] Condition of isinf.
*/
static VALUE
sfloat_isinf(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_isinf, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_isposinf(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_isposinf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_isposinf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of isposinf.
  @overload isposinf
  @return [Numo::Bit] Condition of isposinf.
*/
static VALUE
sfloat_isposinf(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_isposinf, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_isneginf(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_isneginf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_isneginf(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of isneginf.
  @overload isneginf
  @return [Numo::Bit] Condition of isneginf.
*/
static VALUE
sfloat_isneginf(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_isneginf, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cond_unary.c"
static void
iter_sfloat_isfinite(na_loop_t *const lp)
{
    size_t    i;
    char     *p1;
    BIT_DIGIT *a2;
    size_t    p2;
    ssize_t   s1, s2;
    size_t   *idx1;
    dtype     x;
    BIT_DIGIT b;
    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_BIT(lp, 1, a2, p2, s2);
    if (idx1) {
        for (; i--;) {
            GET_DATA_INDEX(p1,idx1,dtype,x);
            b = (m_isfinite(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    } else {
        for (; i--;) {
            GET_DATA_STRIDE(p1,s1,dtype,x);
            b = (m_isfinite(x)) ? 1:0;
            STORE_BIT(a2,p2,b);
            p2+=s2;
        }
    }
}

/*
  Condition of isfinite.
  @overload isfinite
  @return [Numo::Bit] Condition of isfinite.
*/
static VALUE
sfloat_isfinite(VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{numo_cBit,0}};
    ndfunc_t ndf = { iter_sfloat_isfinite, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, self);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_sum(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_sum(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_sum_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_sum_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  sum of self.
  @overload sum(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of sum.
*/
static VALUE
sfloat_sum(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_sum, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_sum_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_prod(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_prod(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_prod_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_prod_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  prod of self.
  @overload prod(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of prod.
*/
static VALUE
sfloat_prod(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_prod, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_prod_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_mean(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_mean(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_mean_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_mean_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  mean of self.
  @overload mean(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of mean.
*/
static VALUE
sfloat_mean(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_mean, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_mean_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_stddev(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_stddev(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_stddev_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_stddev_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  stddev of self.
  @overload stddev(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of stddev.
*/
static VALUE
sfloat_stddev(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cRT,0}};
    ndfunc_t ndf = { iter_sfloat_stddev, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_stddev_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    return rb_funcall(v,rb_intern("extract"),0);
  
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_var(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_var(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_var_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_var_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  var of self.
  @overload var(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of var.
*/
static VALUE
sfloat_var(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cRT,0}};
    ndfunc_t ndf = { iter_sfloat_var, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_var_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    return rb_funcall(v,rb_intern("extract"),0);
  
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_rms(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_rms(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_rms_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(rtype*)p2 = f_rms_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  rms of self.
  @overload rms(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of rms.
*/
static VALUE
sfloat_rms(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cRT,0}};
    ndfunc_t ndf = { iter_sfloat_rms, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_rms_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
#line 46 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    return rb_funcall(v,rb_intern("extract"),0);
  
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_min(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_min(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_min_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_min_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  min of self.
  @overload min(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of min.
*/
static VALUE
sfloat_min(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_min, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_min_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_max(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_max(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_max_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_max_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  max of self.
  @overload max(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of max.
*/
static VALUE
sfloat_max(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_max, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_max_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_ptp(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_ptp(n,p1,s1);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
static void
iter_sfloat_ptp_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1, *p2;
    ssize_t  s1;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    p2 = lp->args[1].ptr + lp->args[1].iter[0].pos;

    *(dtype*)p2 = f_ptp_nan(n,p1,s1);
}

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
/*
  ptp of self.
  @overload ptp(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN for sum/mean etc, or, return NaN for min/max etc).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns result of ptp.
*/
static VALUE
sfloat_ptp(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_ptp, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE, 2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_ptp_nan);
  
#line 42 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
    v =  na_ndloop(&ndf, 2, self, reduce);
  
    return sfloat_extract(v);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum.c"
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int64_t
static void
iter_sfloat_max_index_index64(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_max_index(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int32_t
static void
iter_sfloat_max_index_index32(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_max_index(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int64_t
static void
iter_sfloat_max_index_index64_nan(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_max_index_nan(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int32_t
static void
iter_sfloat_max_index_index32_nan(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_max_index_nan(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 23 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
/*
  max_index. Return an index of result.
  @overload max_index(axis:nil, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (return NaN posision if exist).
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @return [Integer,Numo::Int] returns result index of max_index.
  @example
  
      Numo::NArray[3,4,1,2].max_index => 1
      Numo::NArray[[3,4,1],[2,0,5]].max_index => 5
      Numo::NArray[[3,4,1],[2,0,5]].max_index(axis: 1) => [1, 5]
      Numo::NArray[[3,4,1],[2,0,5]].max_index(axis: 0) => [0, 1, 5]
  
 */
static VALUE
sfloat_max_index(int argc, VALUE *argv, VALUE self)
{
    narray_t *na;
    VALUE idx, reduce;
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{Qnil,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{0,0,0}};
    ndfunc_t ndf = {0, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE|NDF_EXTRACT, 3,1, ain,aout};

    GetNArray(self,na);
    if (na->ndim==0) {
        return INT2FIX(0);
    }
    if (na->size > (~(u_int32_t)0)) {
        aout[0].type = numo_cInt64;
        idx = nary_new(numo_cInt64, na->ndim, na->shape);
        ndf.func = iter_sfloat_max_index_index64;
      
        reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_max_index_index64_nan);
      
#line 68 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
    } else {
        aout[0].type = numo_cInt32;
        idx = nary_new(numo_cInt32, na->ndim, na->shape);
        ndf.func = iter_sfloat_max_index_index32;
      
        reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_max_index_index32_nan);
      
#line 77 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
    }
    rb_funcall(idx, rb_intern("seq"), 0);

    return na_ndloop(&ndf, 3, self, idx, reduce);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int64_t
static void
iter_sfloat_min_index_index64(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_min_index(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int32_t
static void
iter_sfloat_min_index_index32(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_min_index(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int64_t
static void
iter_sfloat_min_index_index64_nan(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_min_index_nan(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
#define idx_t int32_t
static void
iter_sfloat_min_index_index32_nan(na_loop_t *const lp)
{
    size_t   n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);

    idx = f_min_index_nan(n,d_ptr,d_step);

    INIT_PTR(lp, 1, i_ptr, i_step);
    o_ptr = NDL_PTR(lp,2);
    *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
}
#undef idx_t

#line 23 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
/*
  min_index. Return an index of result.
  @overload min_index(axis:nil, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (return NaN posision if exist).
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @return [Integer,Numo::Int] returns result index of min_index.
  @example
  
      Numo::NArray[3,4,1,2].min_index => 2
      Numo::NArray[[3,4,1],[2,0,5]].min_index => 4
      Numo::NArray[[3,4,1],[2,0,5]].min_index(axis: 1) => [2, 4]
      Numo::NArray[[3,4,1],[2,0,5]].min_index(axis: 0) => [3, 4, 2]
  
 */
static VALUE
sfloat_min_index(int argc, VALUE *argv, VALUE self)
{
    narray_t *na;
    VALUE idx, reduce;
    ndfunc_arg_in_t ain[3] = {{Qnil,0},{Qnil,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{0,0,0}};
    ndfunc_t ndf = {0, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE|NDF_EXTRACT, 3,1, ain,aout};

    GetNArray(self,na);
    if (na->ndim==0) {
        return INT2FIX(0);
    }
    if (na->size > (~(u_int32_t)0)) {
        aout[0].type = numo_cInt64;
        idx = nary_new(numo_cInt64, na->ndim, na->shape);
        ndf.func = iter_sfloat_min_index_index64;
      
        reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_min_index_index64_nan);
      
#line 68 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
    } else {
        aout[0].type = numo_cInt32;
        idx = nary_new(numo_cInt32, na->ndim, na->shape);
        ndf.func = iter_sfloat_min_index_index32;
      
        reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_min_index_index32_nan);
      
#line 77 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_index.c"
    }
    rb_funcall(idx, rb_intern("seq"), 0);

    return na_ndloop(&ndf, 3, self, idx, reduce);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c"
static void
iter_sfloat_minmax(na_loop_t *const lp)
{
    size_t   n;
    char    *p1;
    ssize_t  s1;
    dtype    xmin,xmax;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);

    f_minmax(n,p1,s1,&xmin,&xmax);

    *(dtype*)(lp->args[1].ptr + lp->args[1].iter[0].pos) = xmin;
    *(dtype*)(lp->args[2].ptr + lp->args[2].iter[0].pos) = xmax;
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c"
static void
iter_sfloat_minmax_nan(na_loop_t *const lp)
{
    size_t   n;
    char    *p1;
    ssize_t  s1;
    dtype    xmin,xmax;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);

    f_minmax_nan(n,p1,s1,&xmin,&xmax);

    *(dtype*)(lp->args[1].ptr + lp->args[1].iter[0].pos) = xmin;
    *(dtype*)(lp->args[2].ptr + lp->args[2].iter[0].pos) = xmax;
}

#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c"
/*
  minmax of self.
  @overload minmax(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (return NaN if exist).
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat,Numo::SFloat] min and max of self.
*/
static VALUE
sfloat_minmax(int argc, VALUE *argv, VALUE self)
{
    VALUE reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[2] = {{cT,0},{cT,0}};
    ndfunc_t ndf = {iter_sfloat_minmax, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE|NDF_EXTRACT, 2,2, ain,aout};

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_minmax_nan);
  
#line 45 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/minmax.c"
    return na_ndloop(&ndf, 2, self, reduce);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
/*
  Element-wise maximum of two arrays.

  @overload maximum(a1, a2, nan:false)
  @param [Numo::NArray,Numeric] a1  The array to be compared.
  @param [Numo::NArray,Numeric] a2  The array to be compared.
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (return NaN if exist).
  @return [Numo::SFloat]
*/

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static void
iter_sfloat_s_maximum(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        GET_DATA(p3,dtype,z);
        z = f_maximum(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
}
#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static void
iter_sfloat_s_maximum_nan(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        GET_DATA(p3,dtype,z);
        z = f_maximum_nan(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
}

#line 40 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static VALUE
sfloat_s_maximum(int argc, VALUE *argv, VALUE mod)
{
    VALUE a1 = Qnil;
    VALUE a2 = Qnil;
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_s_maximum, STRIDE_LOOP_NIP, 2, 1, ain, aout };

    
    VALUE kw_hash = Qnil;
    ID kw_table[1] = {id_nan};
    VALUE opts[1] = {Qundef};

    rb_scan_args(argc, argv, "20:", &a1, &a2, &kw_hash);
    rb_get_kwargs(kw_hash, kw_table, 0, 1, opts);
    if (opts[0] != Qundef) {
        ndf.func = iter_sfloat_s_maximum_nan;
    }
    

#line 63 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
    return na_ndloop(&ndf, 2, a1, a2);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
/*
  Element-wise minimum of two arrays.

  @overload minimum(a1, a2, nan:false)
  @param [Numo::NArray,Numeric] a1  The array to be compared.
  @param [Numo::NArray,Numeric] a2  The array to be compared.
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (return NaN if exist).
  @return [Numo::SFloat]
*/

#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static void
iter_sfloat_s_minimum(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        GET_DATA(p3,dtype,z);
        z = f_minimum(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
}
#line 17 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static void
iter_sfloat_s_minimum_nan(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    for (i=0; i<n; i++) {
        dtype x, y, z;
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        GET_DATA(p3,dtype,z);
        z = f_minimum_nan(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,z);
    }
}

#line 40 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
static VALUE
sfloat_s_minimum(int argc, VALUE *argv, VALUE mod)
{
    VALUE a1 = Qnil;
    VALUE a2 = Qnil;
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_s_minimum, STRIDE_LOOP_NIP, 2, 1, ain, aout };

    
    VALUE kw_hash = Qnil;
    ID kw_table[1] = {id_nan};
    VALUE opts[1] = {Qundef};

    rb_scan_args(argc, argv, "20:", &a1, &a2, &kw_hash);
    rb_get_kwargs(kw_hash, kw_table, 0, 1, opts);
    if (opts[0] != Qundef) {
        ndf.func = iter_sfloat_s_minimum_nan;
    }
    

#line 63 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/ewcomp.c"
    return na_ndloop(&ndf, 2, a1, a2);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
static void
iter_sfloat_cumsum(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2;
    ssize_t  s1, s2;
    dtype    x, y;

    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    //printf("i=%lu p1=%lx s1=%lu p2=%lx s2=%lu\n",i,(size_t)p1,s1,(size_t)p2,s2);

    GET_DATA_STRIDE(p1,s1,dtype,x);
    SET_DATA_STRIDE(p2,s2,dtype,x);
    //printf("i=%lu x=%f\n",i,x);
    for (i--; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,y);
        m_cumsum(x,y);
        SET_DATA_STRIDE(p2,s2,dtype,x);
        //printf("i=%lu x=%f\n",i,x);
    }
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
static void
iter_sfloat_cumsum_nan(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2;
    ssize_t  s1, s2;
    dtype    x, y;

    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    //printf("i=%lu p1=%lx s1=%lu p2=%lx s2=%lu\n",i,(size_t)p1,s1,(size_t)p2,s2);

    GET_DATA_STRIDE(p1,s1,dtype,x);
    SET_DATA_STRIDE(p2,s2,dtype,x);
    //printf("i=%lu x=%f\n",i,x);
    for (i--; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,y);
        m_cumsum_nan(x,y);
        SET_DATA_STRIDE(p2,s2,dtype,x);
        //printf("i=%lu x=%f\n",i,x);
    }
}

#line 27 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
/*
  cumsum of self.
  @overload cumsum(axis:nil, nan:false)
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN if exists).
  @return [Numo::SFloat] cumsum of self.
*/
static VALUE
sfloat_cumsum(int argc, VALUE *argv, VALUE self)
{
    VALUE reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_cumsum, STRIDE_LOOP|NDF_FLAT_REDUCE|NDF_CUM,
                     2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_cumsum_nan);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
    return na_ndloop(&ndf, 2, self, reduce);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
static void
iter_sfloat_cumprod(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2;
    ssize_t  s1, s2;
    dtype    x, y;

    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    //printf("i=%lu p1=%lx s1=%lu p2=%lx s2=%lu\n",i,(size_t)p1,s1,(size_t)p2,s2);

    GET_DATA_STRIDE(p1,s1,dtype,x);
    SET_DATA_STRIDE(p2,s2,dtype,x);
    //printf("i=%lu x=%f\n",i,x);
    for (i--; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,y);
        m_cumprod(x,y);
        SET_DATA_STRIDE(p2,s2,dtype,x);
        //printf("i=%lu x=%f\n",i,x);
    }
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
static void
iter_sfloat_cumprod_nan(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2;
    ssize_t  s1, s2;
    dtype    x, y;

    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    //printf("i=%lu p1=%lx s1=%lu p2=%lx s2=%lu\n",i,(size_t)p1,s1,(size_t)p2,s2);

    GET_DATA_STRIDE(p1,s1,dtype,x);
    SET_DATA_STRIDE(p2,s2,dtype,x);
    //printf("i=%lu x=%f\n",i,x);
    for (i--; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,y);
        m_cumprod_nan(x,y);
        SET_DATA_STRIDE(p2,s2,dtype,x);
        //printf("i=%lu x=%f\n",i,x);
    }
}

#line 27 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
/*
  cumprod of self.
  @overload cumprod(axis:nil, nan:false)
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @param [TrueClass] nan  If true, apply NaN-aware algorithm (avoid NaN if exists).
  @return [Numo::SFloat] cumprod of self.
*/
static VALUE
sfloat_cumprod(int argc, VALUE *argv, VALUE self)
{
    VALUE reduce;
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_cumprod, STRIDE_LOOP|NDF_FLAT_REDUCE|NDF_CUM,
                     2, 1, ain, aout };

  
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_cumprod_nan);
  
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/cum.c"
    return na_ndloop(&ndf, 2, self, reduce);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_binary.c"
//
static void
iter_sfloat_mulsum(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    if (s3==0) {
        dtype z;
        // Reduce loop
        GET_DATA(p3,dtype,z);
        for (i=0; i<n; i++) {
            dtype x, y;
            GET_DATA_STRIDE(p1,s1,dtype,x);
            GET_DATA_STRIDE(p2,s2,dtype,y);
            m_mulsum(x,y,z);
        }
        SET_DATA(p3,dtype,z);
        return;
    } else {
        for (i=0; i<n; i++) {
            dtype x, y, z;
            GET_DATA_STRIDE(p1,s1,dtype,x);
            GET_DATA_STRIDE(p2,s2,dtype,y);
            GET_DATA(p3,dtype,z);
            m_mulsum(x,y,z);
            SET_DATA_STRIDE(p3,s3,dtype,z);
        }
    }
}
//
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_binary.c"
static void
iter_sfloat_mulsum_nan(na_loop_t *const lp)
{
    size_t   i, n;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);

    if (s3==0) {
        dtype z;
        // Reduce loop
        GET_DATA(p3,dtype,z);
        for (i=0; i<n; i++) {
            dtype x, y;
            GET_DATA_STRIDE(p1,s1,dtype,x);
            GET_DATA_STRIDE(p2,s2,dtype,y);
            m_mulsum_nan(x,y,z);
        }
        SET_DATA(p3,dtype,z);
        return;
    } else {
        for (i=0; i<n; i++) {
            dtype x, y, z;
            GET_DATA_STRIDE(p1,s1,dtype,x);
            GET_DATA_STRIDE(p2,s2,dtype,y);
            GET_DATA(p3,dtype,z);
            m_mulsum_nan(x,y,z);
            SET_DATA_STRIDE(p3,s3,dtype,z);
        }
    }
}
//

static VALUE
sfloat_mulsum_self(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    VALUE naryv[2];
    ndfunc_arg_in_t ain[4] = {{cT,0},{cT,0},{sym_reduce,0},{sym_init,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_mulsum, STRIDE_LOOP_NIP, 4, 1, ain, aout };

    if (argc < 1) {
        rb_raise(rb_eArgError,"wrong number of arguments (%d for >=1)",argc);
    }
    // should fix below: [self.ndim,other.ndim].max or?
    naryv[0] = self;
    naryv[1] = argv[0];
    //
    reduce = na_reduce_dimension(argc-1, argv+1, 2, naryv, &ndf, iter_sfloat_mulsum_nan);
    //

#line 60 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_binary.c"
    v =  na_ndloop(&ndf, 4, self, argv[0], reduce, m_mulsum_init);
    return sfloat_extract(v);
}

/*
  Binary mulsum.

  @overload mulsum(other, axis:nil, keepdims:false, nan:false)
  @param [Numo::NArray,Numeric] other
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @param [TrueClass] nan (keyword) If true, apply NaN-aware algorithm (avoid NaN if exists).
  @return [Numo::NArray] mulsum of self and other.
*/
static VALUE
sfloat_mulsum(int argc, VALUE *argv, VALUE self)
{
    //
    VALUE klass, v;
    //
    if (argc < 1) {
        rb_raise(rb_eArgError,"wrong number of arguments (%d for >=1)",argc);
    }
    //
#line 92 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/accum_binary.c"
    klass = na_upcast(rb_obj_class(self),rb_obj_class(argv[0]));
    if (klass==cT) {
        return sfloat_mulsum_self(argc, argv, self);
    } else {
        v = rb_funcall(klass, id_cast, 1, self);
        return rb_funcall2(v, rb_intern("mulsum"), argc, argv);
    }
    //
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
#line 4 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
typedef dtype seq_data_t;

#line 10 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
typedef double seq_count_t;

#line 13 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
typedef struct {
    seq_data_t beg;
    seq_data_t step;
    seq_count_t count;
} seq_opt_t;

static void
iter_sfloat_seq(na_loop_t *const lp)
{
    size_t  i;
    char   *p1;
    ssize_t s1;
    size_t *idx1;
    dtype   x;
    seq_data_t beg, step;
    seq_count_t c;
    seq_opt_t *g;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    g = (seq_opt_t*)(lp->opt_ptr);
    beg  = g->beg;
    step = g->step;
    c    = g->count;
    if (idx1) {
        for (; i--;) {
            x = f_seq(beg,step,c++);
            *(dtype*)(p1+*idx1) = x;
            idx1++;
        }
    } else {
        for (; i--;) {
            x = f_seq(beg,step,c++);
            *(dtype*)(p1) = x;
            p1 += s1;
        }
    }
    g->count = c;
}

/*
  Set linear sequence of numbers to self. The sequence is obtained from
     beg+i*step
  where i is 1-dimensional index.
  @overload seq([beg,[step]])
  @param [Numeric] beg  begining of sequence. (default=0)
  @param [Numeric] step  step of sequence. (default=1)
  @return [Numo::SFloat] self.
  @example
    Numo::DFloat.new(6).seq(1,-0.2)
    => Numo::DFloat#shape=[6]
       [1, 0.8, 0.6, 0.4, 0.2, 0]
    Numo::DComplex.new(6).seq(1,-0.2+0.2i)
    => Numo::DComplex#shape=[6]
       [1+0i, 0.8+0.2i, 0.6+0.4i, 0.4+0.6i, 0.2+0.8i, 0+1i]
*/
static VALUE
sfloat_seq(int argc, VALUE *args, VALUE self)
{
    seq_opt_t *g;
    VALUE vbeg=Qnil, vstep=Qnil;
    ndfunc_arg_in_t ain[1] = {{OVERWRITE,0}};
    ndfunc_t ndf = {iter_sfloat_seq, FULL_LOOP, 1,0, ain,0};

    g = ALLOCA_N(seq_opt_t,1);
    g->beg = m_zero;
    g->step = m_one;
    g->count = 0;
    rb_scan_args(argc, args, "02", &vbeg, &vstep);
#line 86 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
    if (vbeg!=Qnil) {g->beg = m_num_to_data(vbeg);}
    if (vstep!=Qnil) {g->step = m_num_to_data(vstep);}

#line 90 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/seq.c"
    na_ndloop3(&ndf, g, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/logseq.c"
typedef struct {
    seq_data_t beg;
    seq_data_t step;
    seq_data_t base;
    seq_count_t count;
} logseq_opt_t;

static void
iter_sfloat_logseq(na_loop_t *const lp)
{
    size_t  i;
    char   *p1;
    ssize_t s1;
    size_t *idx1;
    dtype   x;
    seq_data_t beg, step, base;
    seq_count_t c;
    logseq_opt_t *g;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    g = (logseq_opt_t*)(lp->opt_ptr);
    beg  = g->beg;
    step = g->step;
    base = g->base;
    c    = g->count;
    if (idx1) {
        for (; i--;) {
            x = f_seq(beg,step,c++);
            *(dtype*)(p1+*idx1) = m_pow(base,x);
            idx1++;
        }
    } else {
        for (; i--;) {
            x = f_seq(beg,step,c++);
            *(dtype*)(p1) = m_pow(base,x);
            p1 += s1;
        }
    }
    g->count = c;
}

/*
  Set logarithmic sequence of numbers to self. The sequence is obtained from
     base**(beg+i*step)
  where i is 1-dimensional index.
  Applicable classes: DFloat, SFloat, DComplex, SCopmplex.

  @overload logseq(beg,step,[base])
  @param [Numeric] beg  The begining of sequence.
  @param [Numeric] step  The step of sequence.
  @param [Numeric] base  The base of log space. (default=10)
  @return [Numo::SFloat] self.

  @example
    Numo::DFloat.new(5).logseq(4,-1,2)
    => Numo::DFloat#shape=[5]
      [16, 8, 4, 2, 1]
    Numo::DComplex.new(5).logseq(0,1i*Math::PI/3,Math::E)
    => Numo::DComplex#shape=[5]
      [1+7.26156e-310i, 0.5+0.866025i, -0.5+0.866025i, -1+1.22465e-16i, ...]
*/
static VALUE
sfloat_logseq(int argc, VALUE *args, VALUE self)
{
    logseq_opt_t *g;
    VALUE vbeg, vstep, vbase;
    ndfunc_arg_in_t ain[1] = {{OVERWRITE,0}};
    ndfunc_t ndf = {iter_sfloat_logseq, FULL_LOOP, 1,0, ain,0};

    g = ALLOCA_N(logseq_opt_t,1);
    rb_scan_args(argc, args, "21", &vbeg, &vstep, &vbase);
    g->beg = m_num_to_data(vbeg);
    g->step = m_num_to_data(vstep);
    if (vbase==Qnil) {
        g->base = m_from_real(10);
    } else {
        g->base = m_num_to_data(vbase);
    }
    na_ndloop3(&ndf, g, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/eye.c"
static void
iter_sfloat_eye(na_loop_t *const lp)
{
    size_t   n0, n1;
    size_t   i0, i1;
    ssize_t  s0, s1;
    char    *p0, *p1;
    char    *g;
    ssize_t kofs;
    dtype   data;

    g = (char*)(lp->opt_ptr);
    kofs = *(ssize_t*)g;
    data = *(dtype*)(g+sizeof(ssize_t));

    n0 = lp->args[0].shape[0];
    n1 = lp->args[0].shape[1];
    s0 = lp->args[0].iter[0].step;
    s1 = lp->args[0].iter[1].step;
    p0 = NDL_PTR(lp,0);

    for (i0=0; i0 < n0; i0++) {
        p1 = p0;
        for (i1=0; i1 < n1; i1++) {
            *(dtype*)p1 = (i0+kofs==i1) ? data : m_zero;
            p1 += s1;
        }
        p0 += s0;
    }
}

/*
  Eye: Set a value to diagonal components, set 0 to non-diagonal components.
  @overload eye([element,offset])
  @param [Numeric] element  Diagonal element to be stored. Default is 1.
  @param [Integer] offset Diagonal offset from the main diagonal.  The
      default is 0. k>0 for diagonals above the main diagonal, and k<0
      for diagonals below the main diagonal.
  @return [Numo::SFloat] eye of self.
*/
static VALUE
sfloat_eye(int argc, VALUE *argv, VALUE self)
{
    ndfunc_arg_in_t ain[1] = {{OVERWRITE,2}};
    ndfunc_t ndf = {iter_sfloat_eye, NO_LOOP, 1,0, ain,0};
    ssize_t kofs;
    dtype data;
    char *g;
    int nd;
    narray_t *na;

    // check arguments
    if (argc > 2) {
        rb_raise(rb_eArgError,"too many arguments (%d for 0..2)",argc);
    } else if (argc == 2) {
        data = m_num_to_data(argv[0]);
        kofs = NUM2SSIZET(argv[1]);
    } else if (argc == 1) {
        data = m_num_to_data(argv[0]);
        kofs = 0;
    } else {
        data = m_one;
        kofs = 0;
    }

    GetNArray(self,na);
    nd = na->ndim;
    if (nd < 2) {
        rb_raise(nary_eDimensionError,"less than 2-d array");
    }

    // Diagonal offset from the main diagonal.
    if (kofs >= 0) {
        if ((size_t)(kofs) >= na->shape[nd-1]) {
            rb_raise(rb_eArgError,"invalid diagonal offset(%"SZF"d) for "
                     "last dimension size(%"SZF"d)",kofs,na->shape[nd-1]);
        }
    } else {
        if ((size_t)(-kofs) >= na->shape[nd-2]) {
            rb_raise(rb_eArgError,"invalid diagonal offset(%"SZF"d) for "
                     "last-1 dimension size(%"SZF"d)",kofs,na->shape[nd-2]);
        }
    }

    g = ALLOCA_N(char,sizeof(ssize_t)+sizeof(dtype));
    *(ssize_t*)g = kofs;
    *(dtype*)(g+sizeof(ssize_t)) = data;

    na_ndloop3(&ndf, g, 1, self);
    return self;
}



#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c"


#line 69 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c"
typedef struct {
    dtype low;
    dtype max;
} rand_opt_t;

static void
iter_sfloat_rand(na_loop_t *const lp)
{
    size_t   i;
    char    *p1;
    ssize_t  s1;
    size_t  *idx1;
    dtype    x;
    rand_opt_t *g;
    dtype    low;
    dtype max;
    

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    g = (rand_opt_t*)(lp->opt_ptr);
    low = g->low;
    max = g->max;
    

    if (idx1) {
        for (; i--;) {
            x = m_add(m_rand(max),low);
            SET_DATA_INDEX(p1,idx1,dtype,x);
        }
    } else {
        for (; i--;) {
            x = m_add(m_rand(max),low);
            SET_DATA_STRIDE(p1,s1,dtype,x);
        }
    }
}


/*
  Generate uniformly distributed random numbers on self narray.
  @overload rand([[low],high])
  @param [Numeric] low  lower inclusive boundary of random numbers. (default=0)
  @param [Numeric] high  upper exclusive boundary of random numbers. (default=1 or 1+1i for complex types)
  @return [Numo::SFloat] self.
  @example
    Numo::DFloat.new(6).rand
    => Numo::DFloat#shape=[6]
       [0.0617545, 0.373067, 0.794815, 0.201042, 0.116041, 0.344032]
    Numo::DComplex.new(6).rand(5+5i)
    => Numo::DComplex#shape=[6]
       [2.69974+3.68908i, 0.825443+0.254414i, 0.540323+0.34354i, 4.52061+2.39322i, ...]
    Numo::Int32.new(6).rand(2,5)
    => Numo::Int32#shape=[6]
       [4, 3, 3, 2, 4, 2]
*/
static VALUE
sfloat_rand(int argc, VALUE *args, VALUE self)
{
    rand_opt_t g;
    VALUE v1=Qnil, v2=Qnil;
    dtype high;
    ndfunc_arg_in_t ain[1] = {{OVERWRITE,0}};
    ndfunc_t ndf = {iter_sfloat_rand, FULL_LOOP, 1,0, ain,0};

    
#line 140 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c"
    rb_scan_args(argc, args, "02", &v1, &v2);
    if (v2==Qnil) {
        g.low = m_zero;
        if (v1==Qnil) {
            
#line 147 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c"
            g.max = high = m_one;
            
        } else {
            g.max = high = m_num_to_data(v1);
        }
    
    } else {
        g.low = m_num_to_data(v1);
        high = m_num_to_data(v2);
        g.max = m_sub(high,g.low);
    }
    
#line 163 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand.c"
    na_ndloop3(&ndf, &g, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand_norm.c"
typedef struct {
    dtype mu;
    rtype sigma;
} randn_opt_t;

static void
iter_sfloat_rand_norm(na_loop_t *const lp)
{
    size_t   i;
    char    *p1;
    ssize_t  s1;
    size_t  *idx1;
    
#line 16 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand_norm.c"
    dtype   *a0, *a1;
    
    dtype    mu;
    rtype    sigma;
    randn_opt_t *g;

    INIT_COUNTER(lp, i);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    g = (randn_opt_t*)(lp->opt_ptr);
    mu = g->mu;
    sigma = g->sigma;

    if (idx1) {
        
#line 36 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand_norm.c"
        for (; i>1; i-=2) {
            a0 = (dtype*)(p1+*idx1);
            a1 = (dtype*)(p1+*(idx1+1));
            m_rand_norm(mu,sigma,a0,a1);
            idx1 += 2;
        }
        if (i>0) {
            a0 = (dtype*)(p1+*idx1);
            m_rand_norm(mu,sigma,a0,0);
        }
        
    } else {
        
#line 55 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/rand_norm.c"
        for (; i>1; i-=2) {
            a0 = (dtype*)(p1);
            a1 = (dtype*)(p1+s1);
            m_rand_norm(mu,sigma,a0,a1);
            p1 += s1*2;
        }
        if (i>0) {
            a0 = (dtype*)(p1);
            m_rand_norm(mu,sigma,a0,0);
        }
        
    }
}

/*
  Generates random numbers from the normal distribution on self narray
  using Box-Muller Transformation.
  @overload rand_norm([mu,[sigma]])
  @param [Numeric] mu  mean of normal distribution. (default=0)
  @param [Numeric] sigma  standard deviation of normal distribution. (default=1)
  @return [Numo::SFloat] self.
  @example
    Numo::DFloat.new(5,5).rand_norm
    => Numo::DFloat#shape=[5,5]
       [[-0.581255, -0.168354, 0.586895, -0.595142, -0.802802],
        [-0.326106, 0.282922, 1.68427, 0.918499, -0.0485384],
        [-0.464453, -0.992194, 0.413794, -0.60717, -0.699695],
        [-1.64168, 0.48676, -0.875871, -1.43275, 0.812172],
        [-0.209975, -0.103612, -0.878617, -1.42495, 1.0968]]
    Numo::DFloat.new(5,5).rand_norm(10,0.1)
    => Numo::DFloat#shape=[5,5]
       [[9.9019, 9.90339, 10.0826, 9.98384, 9.72861],
        [9.81507, 10.0272, 9.91445, 10.0568, 9.88923],
        [10.0234, 9.97874, 9.96011, 9.9006, 9.99964],
        [10.0186, 9.94598, 9.92236, 9.99811, 9.97003],
        [9.79266, 9.95044, 9.95212, 9.93692, 10.2027]]
    Numo::DComplex.new(3,3).rand_norm(5+5i)
    => Numo::DComplex#shape=[3,3]
       [[5.84303+4.40052i, 4.00984+6.08982i, 5.10979+5.13215i],
        [4.26477+3.99655i, 4.90052+5.00763i, 4.46607+2.3444i],
        [4.5528+7.11003i, 5.62117+6.69094i, 5.05443+5.35133i]]
*/
static VALUE
sfloat_rand_norm(int argc, VALUE *args, VALUE self)
{
    int n;
    randn_opt_t g;
    VALUE v1=Qnil, v2=Qnil;
    ndfunc_arg_in_t ain[1] = {{OVERWRITE,0}};
    ndfunc_t ndf = {iter_sfloat_rand_norm, FULL_LOOP, 1,0, ain,0};

    n = rb_scan_args(argc, args, "02", &v1, &v2);
    if (n == 0) {
        g.mu = m_zero;
    } else {
        g.mu = m_num_to_data(v1);
    }
    if (n == 2) {
        g.sigma = NUM2DBL(v2);
    } else {
        g.sigma = 1;
    }
    na_ndloop3(&ndf, &g, 1, self);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/poly.c"
static void
iter_sfloat_poly(na_loop_t *const lp)
{
    size_t  i;
    dtype  x, y, a;

    x = *(dtype*)(lp->args[0].ptr + lp->args[0].iter[0].pos);
    i = lp->narg - 2;
    y = *(dtype*)(lp->args[i].ptr + lp->args[i].iter[0].pos);
    for (; --i;) {
        y = m_mul(x,y);
        a = *(dtype*)(lp->args[i].ptr + lp->args[i].iter[0].pos);
        y = m_add(y,a);
    }
    i = lp->narg - 1;
    *(dtype*)(lp->args[i].ptr + lp->args[i].iter[0].pos) = y;
}

/*
  Polynomial.: a0 + a1*x + a2*x**2 + a3*x**3 + ... + an*x**n
  @overload poly a0, a1, ...
  @param [Numo::NArray,Numeric] a0
  @param [Numo::NArray,Numeric] a1 , ...
  @return [Numo::SFloat]
*/
static VALUE
sfloat_poly(VALUE self, VALUE args)
{
    int argc, i;
    VALUE *argv;
    volatile VALUE v, a;
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_poly, NO_LOOP, 0, 1, 0, aout };

    argc = RARRAY_LEN(args);
    ndf.nin = argc+1;
    ndf.ain = ALLOCA_N(ndfunc_arg_in_t,argc+1);
    for (i=0; i<argc+1; i++) {
        ndf.ain[i].type = cT;
    }
    argv = ALLOCA_N(VALUE,argc+1);
    argv[0] = self;
    for (i=0; i<argc; i++) {
        argv[i+1] = RARRAY_PTR(args)[i];
    }
    a = rb_ary_new4(argc+1, argv);
    v = na_ndloop2(&ndf, a);
    return sfloat_extract(v);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
/*
  qsort.c
  Numerical Array Extension for Ruby
    modified by Masahiro TANAKA
*/

/*
 *      qsort.c: standard quicksort algorithm
 *
 *      Modifications from vanilla NetBSD source:
 *        Add do ... while() macro fix
 *        Remove __inline, _DIAGASSERTs, __P
 *        Remove ill-considered "swap_cnt" switch to insertion sort,
 *        in favor of a simple check for presorted input.
 *
 *      CAUTION: if you change this file, see also qsort_arg.c
 *
 *      $PostgreSQL: pgsql/src/port/qsort.c,v 1.12 2006/10/19 20:56:22 tgl Exp $
 */

/*      $NetBSD: qsort.c,v 1.13 2003/08/07 16:43:42 agc Exp $   */

/*-
 * Copyright (c) 1992, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *        may be used to endorse or promote products derived from this software
 *        without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.      IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef QSORT_INCL
#define QSORT_INCL
#define Min(x, y)               ((x) < (y) ? (x) : (y))

/*
 * Qsort routine based on J. L. Bentley and M. D. McIlroy,
 * "Engineering a sort function",
 * Software--Practice and Experience 23 (1993) 1249-1265.
 * We have modified their original by adding a check for already-sorted input,
 * which seems to be a win per discussions on pgsql-hackers around 2006-03-21.
 */
#define swapcode(TYPE, parmi, parmj, n)         \
    do {                                        \
        size_t i = (n) / sizeof (TYPE);         \
        TYPE *pi = (TYPE *)(void *)(parmi);     \
        TYPE *pj = (TYPE *)(void *)(parmj);     \
        do {                                    \
            TYPE    t = *pi;                    \
            *pi++ = *pj;                        \
            *pj++ = t;                          \
        } while (--i > 0);                      \
    } while (0)

#define SWAPINIT(a, es) swaptype = ((char *)(a) - (char *)0) % sizeof(long) || \
        (es) % sizeof(long) ? 2 : (es) == sizeof(long)? 0 : 1;

static inline void
swapfunc(a, b, n, swaptype)
     char       *a,
     *b;
     size_t          n;
     int                     swaptype;
{
    if (swaptype <= 1)
        swapcode(long, a, b, n);
    else
        swapcode(char, a, b, n);
}

#define swap(a, b)                                      \
    if (swaptype == 0) {                                \
        long t = *(long *)(void *)(a);                  \
        *(long *)(void *)(a) = *(long *)(void *)(b);    \
        *(long *)(void *)(b) = t;                       \
    } else                                              \
        swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) if ((n) > 0) swapfunc((a), (b), (size_t)(n), swaptype)

#define med3(a,b,c,_cmp)                                \
    (cmpgt(b,a) ?                                       \
     (cmpgt(c,b) ? b : (cmpgt(c,a) ? c : a))            \
     : (cmpgt(b,c) ? b : (cmpgt(c,a) ? a : c)))
#endif

#undef qsort_dtype
#define qsort_dtype dtype
#undef qsort_cast
#define qsort_cast *(dtype*)
#line 112 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
#undef cmp
#undef cmpgt
#define cmp(a,b) cmp_prnan(a,b)
#define cmpgt(a,b) cmpgt_prnan(a,b)

#line 119 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
static void
sfloat_qsort_prnan(void *a, size_t n, ssize_t es)
{
    char       *pa,
        *pb,
        *pc,
        *pd,
        *pl,
        *pm,
        *pn;
    int                     d,
        r,
        swaptype,
        presorted;

 loop:SWAPINIT(a, es);
    if (n < 7)
        {
            for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                for (pl = pm; pl > (char *) a && cmpgt(pl - es, pl);
                     pl -= es)
                    swap(pl, pl - es);
            return;
        }
    presorted = 1;
    for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
        {
            if (cmpgt(pm - es, pm))
                {
                    presorted = 0;
                    break;
                }
        }
    if (presorted)
        return;
    pm = (char *) a + (n / 2) * es;
    if (n > 7)
        {
            pl = (char *) a;
            pn = (char *) a + (n - 1) * es;
            if (n > 40)
                {
                    d = (n / 8) * es;
                    pl = med3(pl, pl + d, pl + 2 * d, cmp);
                    pm = med3(pm - d, pm, pm + d, cmp);
                    pn = med3(pn - 2 * d, pn - d, pn, cmp);
                }
            pm = med3(pl, pm, pn, cmp);
        }
    swap(a, pm);
    pa = pb = (char *) a + es;
    pc = pd = (char *) a + (n - 1) * es;
    for (;;)
        {
            while (pb <= pc && (r = cmp(pb, a)) <= 0)
                {
                    if (r == 0)
                        {
                            swap(pa, pb);
                            pa += es;
                        }
                    pb += es;
                }
            while (pb <= pc && (r = cmp(pc, a)) >= 0)
                {
                    if (r == 0)
                        {
                            swap(pc, pd);
                            pd -= es;
                        }
                    pc -= es;
                }
            if (pb > pc)
                break;
            swap(pb, pc);
            pb += es;
            pc -= es;
        }
    pn = (char *) a + n * es;
    r = Min(pa - (char *) a, pb - pa);
    vecswap(a, pb - r, r);
    r = Min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es)
        sfloat_qsort_prnan(a, r / es, es);
    if ((r = pd - pc) > es)
        {
            /* Iterate rather than recurse to save stack space */
            a = pn - r;
            n = r / es;
            goto loop;
        }
    /*              qsort(pn - r, r / es, es, cmp);*/
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
/*
  qsort.c
  Numerical Array Extension for Ruby
    modified by Masahiro TANAKA
*/

/*
 *      qsort.c: standard quicksort algorithm
 *
 *      Modifications from vanilla NetBSD source:
 *        Add do ... while() macro fix
 *        Remove __inline, _DIAGASSERTs, __P
 *        Remove ill-considered "swap_cnt" switch to insertion sort,
 *        in favor of a simple check for presorted input.
 *
 *      CAUTION: if you change this file, see also qsort_arg.c
 *
 *      $PostgreSQL: pgsql/src/port/qsort.c,v 1.12 2006/10/19 20:56:22 tgl Exp $
 */

/*      $NetBSD: qsort.c,v 1.13 2003/08/07 16:43:42 agc Exp $   */

/*-
 * Copyright (c) 1992, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *        may be used to endorse or promote products derived from this software
 *        without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.      IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef QSORT_INCL
#define QSORT_INCL
#define Min(x, y)               ((x) < (y) ? (x) : (y))

/*
 * Qsort routine based on J. L. Bentley and M. D. McIlroy,
 * "Engineering a sort function",
 * Software--Practice and Experience 23 (1993) 1249-1265.
 * We have modified their original by adding a check for already-sorted input,
 * which seems to be a win per discussions on pgsql-hackers around 2006-03-21.
 */
#define swapcode(TYPE, parmi, parmj, n)         \
    do {                                        \
        size_t i = (n) / sizeof (TYPE);         \
        TYPE *pi = (TYPE *)(void *)(parmi);     \
        TYPE *pj = (TYPE *)(void *)(parmj);     \
        do {                                    \
            TYPE    t = *pi;                    \
            *pi++ = *pj;                        \
            *pj++ = t;                          \
        } while (--i > 0);                      \
    } while (0)

#define SWAPINIT(a, es) swaptype = ((char *)(a) - (char *)0) % sizeof(long) || \
        (es) % sizeof(long) ? 2 : (es) == sizeof(long)? 0 : 1;

static inline void
swapfunc(a, b, n, swaptype)
     char       *a,
     *b;
     size_t          n;
     int                     swaptype;
{
    if (swaptype <= 1)
        swapcode(long, a, b, n);
    else
        swapcode(char, a, b, n);
}

#define swap(a, b)                                      \
    if (swaptype == 0) {                                \
        long t = *(long *)(void *)(a);                  \
        *(long *)(void *)(a) = *(long *)(void *)(b);    \
        *(long *)(void *)(b) = t;                       \
    } else                                              \
        swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) if ((n) > 0) swapfunc((a), (b), (size_t)(n), swaptype)

#define med3(a,b,c,_cmp)                                \
    (cmpgt(b,a) ?                                       \
     (cmpgt(c,b) ? b : (cmpgt(c,a) ? c : a))            \
     : (cmpgt(b,c) ? b : (cmpgt(c,a) ? a : c)))
#endif

#undef qsort_dtype
#define qsort_dtype dtype
#undef qsort_cast
#define qsort_cast *(dtype*)
#line 112 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
#undef cmp
#undef cmpgt
#define cmp(a,b) cmp_ignan(a,b)
#define cmpgt(a,b) cmpgt_ignan(a,b)

#line 119 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
static void
sfloat_qsort_ignan(void *a, size_t n, ssize_t es)
{
    char       *pa,
        *pb,
        *pc,
        *pd,
        *pl,
        *pm,
        *pn;
    int                     d,
        r,
        swaptype,
        presorted;

 loop:SWAPINIT(a, es);
    if (n < 7)
        {
            for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                for (pl = pm; pl > (char *) a && cmpgt(pl - es, pl);
                     pl -= es)
                    swap(pl, pl - es);
            return;
        }
    presorted = 1;
    for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
        {
            if (cmpgt(pm - es, pm))
                {
                    presorted = 0;
                    break;
                }
        }
    if (presorted)
        return;
    pm = (char *) a + (n / 2) * es;
    if (n > 7)
        {
            pl = (char *) a;
            pn = (char *) a + (n - 1) * es;
            if (n > 40)
                {
                    d = (n / 8) * es;
                    pl = med3(pl, pl + d, pl + 2 * d, cmp);
                    pm = med3(pm - d, pm, pm + d, cmp);
                    pn = med3(pn - 2 * d, pn - d, pn, cmp);
                }
            pm = med3(pl, pm, pn, cmp);
        }
    swap(a, pm);
    pa = pb = (char *) a + es;
    pc = pd = (char *) a + (n - 1) * es;
    for (;;)
        {
            while (pb <= pc && (r = cmp(pb, a)) <= 0)
                {
                    if (r == 0)
                        {
                            swap(pa, pb);
                            pa += es;
                        }
                    pb += es;
                }
            while (pb <= pc && (r = cmp(pc, a)) >= 0)
                {
                    if (r == 0)
                        {
                            swap(pc, pd);
                            pd -= es;
                        }
                    pc -= es;
                }
            if (pb > pc)
                break;
            swap(pb, pc);
            pb += es;
            pc -= es;
        }
    pn = (char *) a + n * es;
    r = Min(pa - (char *) a, pb - pa);
    vecswap(a, pb - r, r);
    r = Min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es)
        sfloat_qsort_ignan(a, r / es, es);
    if ((r = pd - pc) > es)
        {
            /* Iterate rather than recurse to save stack space */
            a = pn - r;
            n = r / es;
            goto loop;
        }
    /*              qsort(pn - r, r / es, es, cmp);*/
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c"
static void
iter_sfloat_sort_ignan(na_loop_t *const lp)
{
    size_t n;
    char *ptr;
    ssize_t step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, ptr, step);
    sfloat_qsort_ignan(ptr, n, step);
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c"
static void
iter_sfloat_sort_prnan(na_loop_t *const lp)
{
    size_t n;
    char *ptr;
    ssize_t step;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, ptr, step);
    sfloat_qsort_prnan(ptr, n, step);
}

#line 15 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c"
/*
  sort of self.
  @overload sort(axis:nil, nan:false)
  @param [TrueClass] nan  If true, propagete NaN. If false, ignore NaN.
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @return [Numo::SFloat] returns result of sort.
  @example
      Numo::DFloat[3,4,1,2].sort => Numo::DFloat[1,2,3,4]
*/
static VALUE
sfloat_sort(int argc, VALUE *argv, VALUE self)
{
    VALUE reduce;
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{sym_reduce,0}};
    ndfunc_t ndf = {0, STRIDE_LOOP|NDF_FLAT_REDUCE, 2,0, ain,0};

    if (!TEST_INPLACE(self)) {
        self = na_copy(self);
    }
  
    ndf.func = iter_sfloat_sort_ignan;
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_sort_prnan);
  
#line 45 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort.c"
    na_ndloop(&ndf, 2, self, reduce);
    return self;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
/*
  qsort.c
  Numerical Array Extension for Ruby
    modified by Masahiro TANAKA
*/

/*
 *      qsort.c: standard quicksort algorithm
 *
 *      Modifications from vanilla NetBSD source:
 *        Add do ... while() macro fix
 *        Remove __inline, _DIAGASSERTs, __P
 *        Remove ill-considered "swap_cnt" switch to insertion sort,
 *        in favor of a simple check for presorted input.
 *
 *      CAUTION: if you change this file, see also qsort_arg.c
 *
 *      $PostgreSQL: pgsql/src/port/qsort.c,v 1.12 2006/10/19 20:56:22 tgl Exp $
 */

/*      $NetBSD: qsort.c,v 1.13 2003/08/07 16:43:42 agc Exp $   */

/*-
 * Copyright (c) 1992, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *        may be used to endorse or promote products derived from this software
 *        without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.      IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef QSORT_INCL
#define QSORT_INCL
#define Min(x, y)               ((x) < (y) ? (x) : (y))

/*
 * Qsort routine based on J. L. Bentley and M. D. McIlroy,
 * "Engineering a sort function",
 * Software--Practice and Experience 23 (1993) 1249-1265.
 * We have modified their original by adding a check for already-sorted input,
 * which seems to be a win per discussions on pgsql-hackers around 2006-03-21.
 */
#define swapcode(TYPE, parmi, parmj, n)         \
    do {                                        \
        size_t i = (n) / sizeof (TYPE);         \
        TYPE *pi = (TYPE *)(void *)(parmi);     \
        TYPE *pj = (TYPE *)(void *)(parmj);     \
        do {                                    \
            TYPE    t = *pi;                    \
            *pi++ = *pj;                        \
            *pj++ = t;                          \
        } while (--i > 0);                      \
    } while (0)

#define SWAPINIT(a, es) swaptype = ((char *)(a) - (char *)0) % sizeof(long) || \
        (es) % sizeof(long) ? 2 : (es) == sizeof(long)? 0 : 1;

static inline void
swapfunc(a, b, n, swaptype)
     char       *a,
     *b;
     size_t          n;
     int                     swaptype;
{
    if (swaptype <= 1)
        swapcode(long, a, b, n);
    else
        swapcode(char, a, b, n);
}

#define swap(a, b)                                      \
    if (swaptype == 0) {                                \
        long t = *(long *)(void *)(a);                  \
        *(long *)(void *)(a) = *(long *)(void *)(b);    \
        *(long *)(void *)(b) = t;                       \
    } else                                              \
        swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) if ((n) > 0) swapfunc((a), (b), (size_t)(n), swaptype)

#define med3(a,b,c,_cmp)                                \
    (cmpgt(b,a) ?                                       \
     (cmpgt(c,b) ? b : (cmpgt(c,a) ? c : a))            \
     : (cmpgt(b,c) ? b : (cmpgt(c,a) ? a : c)))
#endif

#undef qsort_dtype
#define qsort_dtype dtype*
#undef qsort_cast
#define qsort_cast **(dtype**)
#line 112 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
#undef cmp
#undef cmpgt
#define cmp(a,b) cmp_prnan(a,b)
#define cmpgt(a,b) cmpgt_prnan(a,b)

#line 119 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
static void
sfloat_index_qsort_prnan(void *a, size_t n, ssize_t es)
{
    char       *pa,
        *pb,
        *pc,
        *pd,
        *pl,
        *pm,
        *pn;
    int                     d,
        r,
        swaptype,
        presorted;

 loop:SWAPINIT(a, es);
    if (n < 7)
        {
            for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                for (pl = pm; pl > (char *) a && cmpgt(pl - es, pl);
                     pl -= es)
                    swap(pl, pl - es);
            return;
        }
    presorted = 1;
    for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
        {
            if (cmpgt(pm - es, pm))
                {
                    presorted = 0;
                    break;
                }
        }
    if (presorted)
        return;
    pm = (char *) a + (n / 2) * es;
    if (n > 7)
        {
            pl = (char *) a;
            pn = (char *) a + (n - 1) * es;
            if (n > 40)
                {
                    d = (n / 8) * es;
                    pl = med3(pl, pl + d, pl + 2 * d, cmp);
                    pm = med3(pm - d, pm, pm + d, cmp);
                    pn = med3(pn - 2 * d, pn - d, pn, cmp);
                }
            pm = med3(pl, pm, pn, cmp);
        }
    swap(a, pm);
    pa = pb = (char *) a + es;
    pc = pd = (char *) a + (n - 1) * es;
    for (;;)
        {
            while (pb <= pc && (r = cmp(pb, a)) <= 0)
                {
                    if (r == 0)
                        {
                            swap(pa, pb);
                            pa += es;
                        }
                    pb += es;
                }
            while (pb <= pc && (r = cmp(pc, a)) >= 0)
                {
                    if (r == 0)
                        {
                            swap(pc, pd);
                            pd -= es;
                        }
                    pc -= es;
                }
            if (pb > pc)
                break;
            swap(pb, pc);
            pb += es;
            pc -= es;
        }
    pn = (char *) a + n * es;
    r = Min(pa - (char *) a, pb - pa);
    vecswap(a, pb - r, r);
    r = Min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es)
        sfloat_index_qsort_prnan(a, r / es, es);
    if ((r = pd - pc) > es)
        {
            /* Iterate rather than recurse to save stack space */
            a = pn - r;
            n = r / es;
            goto loop;
        }
    /*              qsort(pn - r, r / es, es, cmp);*/
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
/*
  qsort.c
  Numerical Array Extension for Ruby
    modified by Masahiro TANAKA
*/

/*
 *      qsort.c: standard quicksort algorithm
 *
 *      Modifications from vanilla NetBSD source:
 *        Add do ... while() macro fix
 *        Remove __inline, _DIAGASSERTs, __P
 *        Remove ill-considered "swap_cnt" switch to insertion sort,
 *        in favor of a simple check for presorted input.
 *
 *      CAUTION: if you change this file, see also qsort_arg.c
 *
 *      $PostgreSQL: pgsql/src/port/qsort.c,v 1.12 2006/10/19 20:56:22 tgl Exp $
 */

/*      $NetBSD: qsort.c,v 1.13 2003/08/07 16:43:42 agc Exp $   */

/*-
 * Copyright (c) 1992, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *        may be used to endorse or promote products derived from this software
 *        without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.      IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef QSORT_INCL
#define QSORT_INCL
#define Min(x, y)               ((x) < (y) ? (x) : (y))

/*
 * Qsort routine based on J. L. Bentley and M. D. McIlroy,
 * "Engineering a sort function",
 * Software--Practice and Experience 23 (1993) 1249-1265.
 * We have modified their original by adding a check for already-sorted input,
 * which seems to be a win per discussions on pgsql-hackers around 2006-03-21.
 */
#define swapcode(TYPE, parmi, parmj, n)         \
    do {                                        \
        size_t i = (n) / sizeof (TYPE);         \
        TYPE *pi = (TYPE *)(void *)(parmi);     \
        TYPE *pj = (TYPE *)(void *)(parmj);     \
        do {                                    \
            TYPE    t = *pi;                    \
            *pi++ = *pj;                        \
            *pj++ = t;                          \
        } while (--i > 0);                      \
    } while (0)

#define SWAPINIT(a, es) swaptype = ((char *)(a) - (char *)0) % sizeof(long) || \
        (es) % sizeof(long) ? 2 : (es) == sizeof(long)? 0 : 1;

static inline void
swapfunc(a, b, n, swaptype)
     char       *a,
     *b;
     size_t          n;
     int                     swaptype;
{
    if (swaptype <= 1)
        swapcode(long, a, b, n);
    else
        swapcode(char, a, b, n);
}

#define swap(a, b)                                      \
    if (swaptype == 0) {                                \
        long t = *(long *)(void *)(a);                  \
        *(long *)(void *)(a) = *(long *)(void *)(b);    \
        *(long *)(void *)(b) = t;                       \
    } else                                              \
        swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) if ((n) > 0) swapfunc((a), (b), (size_t)(n), swaptype)

#define med3(a,b,c,_cmp)                                \
    (cmpgt(b,a) ?                                       \
     (cmpgt(c,b) ? b : (cmpgt(c,a) ? c : a))            \
     : (cmpgt(b,c) ? b : (cmpgt(c,a) ? a : c)))
#endif

#undef qsort_dtype
#define qsort_dtype dtype*
#undef qsort_cast
#define qsort_cast **(dtype**)
#line 112 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
#undef cmp
#undef cmpgt
#define cmp(a,b) cmp_ignan(a,b)
#define cmpgt(a,b) cmpgt_ignan(a,b)

#line 119 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/qsort.c"
static void
sfloat_index_qsort_ignan(void *a, size_t n, ssize_t es)
{
    char       *pa,
        *pb,
        *pc,
        *pd,
        *pl,
        *pm,
        *pn;
    int                     d,
        r,
        swaptype,
        presorted;

 loop:SWAPINIT(a, es);
    if (n < 7)
        {
            for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                for (pl = pm; pl > (char *) a && cmpgt(pl - es, pl);
                     pl -= es)
                    swap(pl, pl - es);
            return;
        }
    presorted = 1;
    for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
        {
            if (cmpgt(pm - es, pm))
                {
                    presorted = 0;
                    break;
                }
        }
    if (presorted)
        return;
    pm = (char *) a + (n / 2) * es;
    if (n > 7)
        {
            pl = (char *) a;
            pn = (char *) a + (n - 1) * es;
            if (n > 40)
                {
                    d = (n / 8) * es;
                    pl = med3(pl, pl + d, pl + 2 * d, cmp);
                    pm = med3(pm - d, pm, pm + d, cmp);
                    pn = med3(pn - 2 * d, pn - d, pn, cmp);
                }
            pm = med3(pl, pm, pn, cmp);
        }
    swap(a, pm);
    pa = pb = (char *) a + es;
    pc = pd = (char *) a + (n - 1) * es;
    for (;;)
        {
            while (pb <= pc && (r = cmp(pb, a)) <= 0)
                {
                    if (r == 0)
                        {
                            swap(pa, pb);
                            pa += es;
                        }
                    pb += es;
                }
            while (pb <= pc && (r = cmp(pc, a)) >= 0)
                {
                    if (r == 0)
                        {
                            swap(pc, pd);
                            pd -= es;
                        }
                    pc -= es;
                }
            if (pb > pc)
                break;
            swap(pb, pc);
            pb += es;
            pc -= es;
        }
    pn = (char *) a + n * es;
    r = Min(pa - (char *) a, pb - pa);
    vecswap(a, pb - r, r);
    r = Min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es)
        sfloat_index_qsort_ignan(a, r / es, es);
    if ((r = pd - pc) > es)
        {
            /* Iterate rather than recurse to save stack space */
            a = pn - r;
            n = r / es;
            goto loop;
        }
    /*              qsort(pn - r, r / es, es, cmp);*/
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
#define idx_t int64_t
static void
sfloat_index64_qsort_ignan(na_loop_t *const lp)
{
    size_t   i, n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step, o_step;
    char   **ptr;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);
    INIT_PTR(lp, 1, i_ptr, i_step);
    INIT_PTR(lp, 2, o_ptr, o_step);

    ptr = (char**)(lp->opt_ptr);

    //printf("(ptr=%lx, d_ptr=%lx,d_step=%ld, i_ptr=%lx,i_step=%ld, o_ptr=%lx,o_step=%ld)\n",(size_t)ptr,(size_t)d_ptr,(ssize_t)d_step,(size_t)i_ptr,(ssize_t)i_step,(size_t)o_ptr,(ssize_t)o_step);

    if (n==1) {
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr);
        return;
    }

    for (i=0; i<n; i++) {
        ptr[i] = d_ptr + d_step * i;
        //printf("(%ld,%.3f)",i,*(double*)ptr[i]);
    }

    sfloat_index_qsort_ignan(ptr, n, sizeof(dtype*));

    //d_ptr = lp->args[0].ptr;
    //printf("(d_ptr=%lx)\n",(size_t)d_ptr);

    for (i=0; i<n; i++) {
        idx = (ptr[i] - d_ptr) / d_step;
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
        //printf("(idx[%ld]=%ld,%d)",i,idx,*(idx_t*)o_ptr);
        o_ptr += o_step;
    }
    //printf("\n");
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
#define idx_t int32_t
static void
sfloat_index32_qsort_ignan(na_loop_t *const lp)
{
    size_t   i, n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step, o_step;
    char   **ptr;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);
    INIT_PTR(lp, 1, i_ptr, i_step);
    INIT_PTR(lp, 2, o_ptr, o_step);

    ptr = (char**)(lp->opt_ptr);

    //printf("(ptr=%lx, d_ptr=%lx,d_step=%ld, i_ptr=%lx,i_step=%ld, o_ptr=%lx,o_step=%ld)\n",(size_t)ptr,(size_t)d_ptr,(ssize_t)d_step,(size_t)i_ptr,(ssize_t)i_step,(size_t)o_ptr,(ssize_t)o_step);

    if (n==1) {
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr);
        return;
    }

    for (i=0; i<n; i++) {
        ptr[i] = d_ptr + d_step * i;
        //printf("(%ld,%.3f)",i,*(double*)ptr[i]);
    }

    sfloat_index_qsort_ignan(ptr, n, sizeof(dtype*));

    //d_ptr = lp->args[0].ptr;
    //printf("(d_ptr=%lx)\n",(size_t)d_ptr);

    for (i=0; i<n; i++) {
        idx = (ptr[i] - d_ptr) / d_step;
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
        //printf("(idx[%ld]=%ld,%d)",i,idx,*(idx_t*)o_ptr);
        o_ptr += o_step;
    }
    //printf("\n");
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
#define idx_t int64_t
static void
sfloat_index64_qsort_prnan(na_loop_t *const lp)
{
    size_t   i, n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step, o_step;
    char   **ptr;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);
    INIT_PTR(lp, 1, i_ptr, i_step);
    INIT_PTR(lp, 2, o_ptr, o_step);

    ptr = (char**)(lp->opt_ptr);

    //printf("(ptr=%lx, d_ptr=%lx,d_step=%ld, i_ptr=%lx,i_step=%ld, o_ptr=%lx,o_step=%ld)\n",(size_t)ptr,(size_t)d_ptr,(ssize_t)d_step,(size_t)i_ptr,(ssize_t)i_step,(size_t)o_ptr,(ssize_t)o_step);

    if (n==1) {
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr);
        return;
    }

    for (i=0; i<n; i++) {
        ptr[i] = d_ptr + d_step * i;
        //printf("(%ld,%.3f)",i,*(double*)ptr[i]);
    }

    sfloat_index_qsort_prnan(ptr, n, sizeof(dtype*));

    //d_ptr = lp->args[0].ptr;
    //printf("(d_ptr=%lx)\n",(size_t)d_ptr);

    for (i=0; i<n; i++) {
        idx = (ptr[i] - d_ptr) / d_step;
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
        //printf("(idx[%ld]=%ld,%d)",i,idx,*(idx_t*)o_ptr);
        o_ptr += o_step;
    }
    //printf("\n");
}
#undef idx_t

#line 3 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
#define idx_t int32_t
static void
sfloat_index32_qsort_prnan(na_loop_t *const lp)
{
    size_t   i, n, idx;
    char    *d_ptr, *i_ptr, *o_ptr;
    ssize_t  d_step, i_step, o_step;
    char   **ptr;

    INIT_COUNTER(lp, n);
    INIT_PTR(lp, 0, d_ptr, d_step);
    INIT_PTR(lp, 1, i_ptr, i_step);
    INIT_PTR(lp, 2, o_ptr, o_step);

    ptr = (char**)(lp->opt_ptr);

    //printf("(ptr=%lx, d_ptr=%lx,d_step=%ld, i_ptr=%lx,i_step=%ld, o_ptr=%lx,o_step=%ld)\n",(size_t)ptr,(size_t)d_ptr,(ssize_t)d_step,(size_t)i_ptr,(ssize_t)i_step,(size_t)o_ptr,(ssize_t)o_step);

    if (n==1) {
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr);
        return;
    }

    for (i=0; i<n; i++) {
        ptr[i] = d_ptr + d_step * i;
        //printf("(%ld,%.3f)",i,*(double*)ptr[i]);
    }

    sfloat_index_qsort_prnan(ptr, n, sizeof(dtype*));

    //d_ptr = lp->args[0].ptr;
    //printf("(d_ptr=%lx)\n",(size_t)d_ptr);

    for (i=0; i<n; i++) {
        idx = (ptr[i] - d_ptr) / d_step;
        *(idx_t*)o_ptr = *(idx_t*)(i_ptr + i_step * idx);
        //printf("(idx[%ld]=%ld,%d)",i,idx,*(idx_t*)o_ptr);
        o_ptr += o_step;
    }
    //printf("\n");
}
#undef idx_t

#line 47 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
/*
  sort_index. Returns an index array of sort result.
  @overload sort_index(axis:nil, nan:false)
  @param [TrueClass] nan  If true, propagete NaN. If false, ignore NaN.
  @param [Numeric,Array,Range] axis  Affected dimensions.
  @return [Integer,Numo::Int] returns result index of sort_index.
  @example
      Numo::NArray[3,4,1,2].sort_index => Numo::Int32[2,3,0,1]
*/
static VALUE
sfloat_sort_index(int argc, VALUE *argv, VALUE self)
{
    size_t size;
    narray_t *na;
    VALUE idx, tmp, reduce, res;
    char *buf;
    ndfunc_arg_in_t ain[3] = {{cT,0},{0,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{0,0,0}};
    ndfunc_t ndf = {0, STRIDE_LOOP_NIP|NDF_FLAT_REDUCE|NDF_CUM, 3,1, ain,aout};

    GetNArray(self,na);
    if (na->ndim==0) {
        return INT2FIX(0);
    }
    if (na->size > (~(u_int32_t)0)) {
        ain[1].type =
        aout[0].type = numo_cInt64;
        idx = nary_new(numo_cInt64, na->ndim, na->shape);
       
         ndf.func = sfloat_index64_qsort_ignan;
         reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf,
                                      sfloat_index64_qsort_prnan);
       
#line 87 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
    } else {
        ain[1].type =
        aout[0].type = numo_cInt32;
        idx = nary_new(numo_cInt32, na->ndim, na->shape);
       
         ndf.func = sfloat_index32_qsort_ignan;
         reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf,
                                      sfloat_index32_qsort_prnan);
       
#line 99 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/sort_index.c"
    }
    rb_funcall(idx, rb_intern("seq"), 0);

    size = na->size*sizeof(void*); // max capa
    buf = rb_alloc_tmp_buffer(&tmp, size);
    res = na_ndloop3(&ndf, buf, 3, self, idx, reduce);
    rb_free_tmp_buffer(&tmp);
    return res;
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c"
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c"
static void
iter_sfloat_median_ignan(na_loop_t *const lp)
{
    size_t n;
    char *p1, *p2;
    dtype *buf;

    INIT_COUNTER(lp, n);
    p1 = (lp->args[0]).ptr + (lp->args[0].iter[0]).pos;
    p2 = (lp->args[1]).ptr + (lp->args[1].iter[0]).pos;
    buf = (dtype*)p1;

    sfloat_qsort_ignan(buf, n, sizeof(dtype));

    
    for (; n; n--) {
        if (!isnan(buf[n-1])) break;
    }
    

    if (n==0) {
        *(dtype*)p2 = buf[0];
    }
    else if (n%2==0) {
        *(dtype*)p2 = (buf[n/2-1]+buf[n/2])/2;
    }
    else {
        *(dtype*)p2 = buf[(n-1)/2];
    }
}
#line 2 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c"
static void
iter_sfloat_median_prnan(na_loop_t *const lp)
{
    size_t n;
    char *p1, *p2;
    dtype *buf;

    INIT_COUNTER(lp, n);
    p1 = (lp->args[0]).ptr + (lp->args[0].iter[0]).pos;
    p2 = (lp->args[1]).ptr + (lp->args[1].iter[0]).pos;
    buf = (dtype*)p1;

    sfloat_qsort_prnan(buf, n, sizeof(dtype));

    
    for (; n; n--) {
        if (!isnan(buf[n-1])) break;
    }
    

    if (n==0) {
        *(dtype*)p2 = buf[0];
    }
    else if (n%2==0) {
        *(dtype*)p2 = (buf[n/2-1]+buf[n/2])/2;
    }
    else {
        *(dtype*)p2 = buf[(n-1)/2];
    }
}

#line 34 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c"
/*
  median of self.
  @overload median(axis:nil, keepdims:false, nan:false)
  @param [TrueClass] nan (keyword) If true, propagete NaN. If false, ignore NaN.
  @param [Numeric,Array,Range] axis (keyword) Affected dimensions.
  @param [TrueClass] keepdims (keyword) If true, the reduced axes are left in the result array as dimensions with size one.
  @return [Numo::SFloat] returns median of self.
*/

static VALUE
sfloat_median(int argc, VALUE *argv, VALUE self)
{
    VALUE v, reduce;
    ndfunc_arg_in_t ain[2] = {{OVERWRITE,0},{sym_reduce,0}};
    ndfunc_arg_out_t aout[1] = {{INT2FIX(0),0}};
    ndfunc_t ndf = {0, NDF_HAS_LOOP|NDF_FLAT_REDUCE, 2,1, ain,aout};

    self = na_copy(self); // as temporary buffer
  
    ndf.func = iter_sfloat_median_ignan;
    reduce = na_reduce_dimension(argc, argv, 1, &self, &ndf, iter_sfloat_median_prnan);
  
#line 63 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/median.c"
    v = na_ndloop(&ndf, 2, self, reduce);
    return sfloat_extract(v);
}



#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/module.c"
/*
  module definition: Numo::SFloat::NMath
*/

#line 6 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/module.c"
VALUE mTM;


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_sqrt(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    size_t cnt;
    size_t cnt_simd_loop = -1;
    
#line 16 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    __m128 a;
    
    size_t num_pack; // Number of elements packed for SIMD.
    num_pack = SIMD_ALIGNMENT_SIZE / sizeof(dtype);
#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sqrt(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sqrt(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sqrt(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 48 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            // Check number of elements. & Check same alignment.
            if ((n >= num_pack) && is_same_aligned2(&((dtype*)p1)[i], &((dtype*)p2)[i], SIMD_ALIGNMENT_SIZE)){
                // Calculate up to the position just before the start of SIMD computation.
                cnt = get_count_of_elements_not_aligned_to_simd_size(&((dtype*)p1)[i], SIMD_ALIGNMENT_SIZE, sizeof(dtype));
                for (i=0; i < cnt; i++) {
                    ((dtype*)p2)[i] = m_sqrt(((dtype*)p1)[i]);
                }

                // Get the count of SIMD computation loops.
                cnt_simd_loop = (n - i) % num_pack;

                // SIMD computation.
                if (p1 == p2) { // inplace case
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        a = _mm_sqrt_ps(a);
                        _mm_store_ps(&((dtype*)p1)[i], a);
                    }
                } else {
                    for(; i < n - cnt_simd_loop; i += num_pack){
                        a = _mm_load_ps(&((dtype*)p1)[i]);
                        a = _mm_sqrt_ps(a);
                        _mm_stream_ps(&((dtype*)p2)[i], a);
                    }
                }

            }
            // Compute the remainder of the SIMD operation.
            if (cnt_simd_loop != 0){
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_sqrt(((dtype*)p1)[i]);
                }
#line 82 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate sqrt(x).
  @overload sqrt(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of sqrt(x).
*/
static VALUE
sfloat_math_s_sqrt(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_sqrt, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_cbrt(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cbrt(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cbrt(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_cbrt(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_cbrt(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate cbrt(x).
  @overload cbrt(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of cbrt(x).
*/
static VALUE
sfloat_math_s_cbrt(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_cbrt, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_log(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_log(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_log(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate log(x).
  @overload log(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of log(x).
*/
static VALUE
sfloat_math_s_log(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_log, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_log2(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log2(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log2(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_log2(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_log2(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate log2(x).
  @overload log2(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of log2(x).
*/
static VALUE
sfloat_math_s_log2(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_log2, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_log10(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log10(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log10(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_log10(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_log10(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate log10(x).
  @overload log10(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of log10(x).
*/
static VALUE
sfloat_math_s_log10(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_log10, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_exp(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_exp(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_exp(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate exp(x).
  @overload exp(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of exp(x).
*/
static VALUE
sfloat_math_s_exp(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_exp, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_exp2(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp2(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp2(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_exp2(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_exp2(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate exp2(x).
  @overload exp2(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of exp2(x).
*/
static VALUE
sfloat_math_s_exp2(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_exp2, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_exp10(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp10(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_exp10(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_exp10(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_exp10(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate exp10(x).
  @overload exp10(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of exp10(x).
*/
static VALUE
sfloat_math_s_exp10(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_exp10, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_sin(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sin(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sin(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sin(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_sin(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate sin(x).
  @overload sin(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of sin(x).
*/
static VALUE
sfloat_math_s_sin(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_sin, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_cos(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cos(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cos(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_cos(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_cos(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate cos(x).
  @overload cos(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of cos(x).
*/
static VALUE
sfloat_math_s_cos(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_cos, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_tan(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_tan(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_tan(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_tan(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_tan(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate tan(x).
  @overload tan(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of tan(x).
*/
static VALUE
sfloat_math_s_tan(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_tan, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_asin(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_asin(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_asin(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_asin(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_asin(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate asin(x).
  @overload asin(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of asin(x).
*/
static VALUE
sfloat_math_s_asin(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_asin, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_acos(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_acos(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_acos(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_acos(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_acos(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate acos(x).
  @overload acos(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of acos(x).
*/
static VALUE
sfloat_math_s_acos(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_acos, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_atan(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_atan(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_atan(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_atan(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_atan(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate atan(x).
  @overload atan(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of atan(x).
*/
static VALUE
sfloat_math_s_atan(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_atan, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_sinh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sinh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sinh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sinh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_sinh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate sinh(x).
  @overload sinh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of sinh(x).
*/
static VALUE
sfloat_math_s_sinh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_sinh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_cosh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cosh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_cosh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_cosh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_cosh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate cosh(x).
  @overload cosh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of cosh(x).
*/
static VALUE
sfloat_math_s_cosh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_cosh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_tanh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_tanh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_tanh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_tanh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_tanh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate tanh(x).
  @overload tanh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of tanh(x).
*/
static VALUE
sfloat_math_s_tanh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_tanh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_asinh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_asinh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_asinh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_asinh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_asinh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate asinh(x).
  @overload asinh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of asinh(x).
*/
static VALUE
sfloat_math_s_asinh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_asinh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_acosh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_acosh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_acosh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_acosh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_acosh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate acosh(x).
  @overload acosh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of acosh(x).
*/
static VALUE
sfloat_math_s_acosh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_acosh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_atanh(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_atanh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_atanh(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_atanh(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_atanh(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate atanh(x).
  @overload atanh(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of atanh(x).
*/
static VALUE
sfloat_math_s_atanh(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_atanh, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_sinc(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sinc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_sinc(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_sinc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_sinc(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate sinc(x).
  @overload sinc(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of sinc(x).
*/
static VALUE
sfloat_math_s_sinc(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_sinc, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary_s.c"
static void
iter_sfloat_math_s_atan2(na_loop_t *const lp)
{
    size_t  i;
    char    *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype    x, y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        x = m_atan2(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

/*
  Calculate atan2(a1,a2).
  @overload atan2(a1,a2)
  @param [Numo::NArray,Numeric] a1  first value
  @param [Numo::NArray,Numeric] a2  second value
  @return [Numo::SFloat] atan2(a1,a2).
*/
static VALUE
sfloat_math_s_atan2(VALUE mod, VALUE a1, VALUE a2)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_atan2, STRIDE_LOOP, 2, 1, ain, aout };
    return na_ndloop(&ndf, 2, a1, a2);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary_s.c"
static void
iter_sfloat_math_s_hypot(na_loop_t *const lp)
{
    size_t  i;
    char    *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype    x, y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        x = m_hypot(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

/*
  Calculate hypot(a1,a2).
  @overload hypot(a1,a2)
  @param [Numo::NArray,Numeric] a1  first value
  @param [Numo::NArray,Numeric] a2  second value
  @return [Numo::SFloat] hypot(a1,a2).
*/
static VALUE
sfloat_math_s_hypot(VALUE mod, VALUE a1, VALUE a2)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_hypot, STRIDE_LOOP, 2, 1, ain, aout };
    return na_ndloop(&ndf, 2, a1, a2);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_erf(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_erf(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_erf(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_erf(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_erf(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate erf(x).
  @overload erf(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of erf(x).
*/
static VALUE
sfloat_math_s_erf(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_erf, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_erfc(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_erfc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_erfc(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_erfc(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_erfc(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate erfc(x).
  @overload erfc(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of erfc(x).
*/
static VALUE
sfloat_math_s_erfc(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_erfc, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_log1p(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log1p(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_log1p(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_log1p(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_log1p(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate log1p(x).
  @overload log1p(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of log1p(x).
*/
static VALUE
sfloat_math_s_log1p(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_log1p, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
static void
iter_sfloat_math_s_expm1(na_loop_t *const lp)
{
    size_t  i=0, n;
    char   *p1, *p2;
    ssize_t s1, s2;
    size_t *idx1, *idx2;
    dtype   x;

#line 21 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
    INIT_COUNTER(lp, n);
    INIT_PTR_IDX(lp, 0, p1, s1, idx1);
    INIT_PTR_IDX(lp, 1, p2, s2, idx2);

    if (idx1) {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_expm1(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
            for (i=0; i<n; i++) {
                GET_DATA_INDEX(p1,idx1,dtype,x);
                x = m_expm1(x);
                SET_DATA_STRIDE(p2,s2,dtype,x);
            }
        }
    } else {
        if (idx2) {
            for (i=0; i<n; i++) {
                GET_DATA_STRIDE(p1,s1,dtype,x);
                x = m_expm1(x);
                SET_DATA_INDEX(p2,idx2,dtype,x);
            }
        } else {
#line 78 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
                for (; i<n; i++) {
                    ((dtype*)p2)[i] = m_expm1(((dtype*)p1)[i]);
                }
#line 84 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/unary_s.c"
            return;
        }
    }
}

/*
  Calculate expm1(x).
  @overload expm1(x)
  @param [Numo::NArray,Numeric] x  input value
  @return [Numo::SFloat] result of expm1(x).
*/
static VALUE
sfloat_math_s_expm1(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_expm1, FULL_LOOP, 1, 1, ain, aout };

    return na_ndloop(&ndf, 1, a1);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/binary_s.c"
static void
iter_sfloat_math_s_ldexp(na_loop_t *const lp)
{
    size_t  i;
    char    *p1, *p2, *p3;
    ssize_t s1, s2, s3;
    dtype    x, y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        GET_DATA_STRIDE(p2,s2,dtype,y);
        x = m_ldexp(x,y);
        SET_DATA_STRIDE(p3,s3,dtype,x);
    }
}

/*
  Calculate ldexp(a1,a2).
  @overload ldexp(a1,a2)
  @param [Numo::NArray,Numeric] a1  first value
  @param [Numo::NArray,Numeric] a2  second value
  @return [Numo::SFloat] ldexp(a1,a2).
*/
static VALUE
sfloat_math_s_ldexp(VALUE mod, VALUE a1, VALUE a2)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{cT,0}};
    ndfunc_arg_out_t aout[1] = {{cT,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_ldexp, STRIDE_LOOP, 2, 1, ain, aout };
    return na_ndloop(&ndf, 2, a1, a2);
}


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/frexp.c"
static void
iter_sfloat_math_s_frexp(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2, *p3;
    ssize_t  s1, s2, s3;
    dtype    x;
    int      y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);
    INIT_PTR(lp, 2, p3, s3);
    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,dtype,x);
        x = m_frexp(x,&y);
        SET_DATA_STRIDE(p2,s2,dtype,x);
        SET_DATA_STRIDE(p3,s3,int32_t,y);
    }
}

/*
  split the number x into a normalized fraction and an exponent.
  Returns [mantissa, exponent], where x = mantissa * 2**exponent.

  @overload frexp(x)
  @param [Numo::NArray,Numeric]  x
  @return [Numo::SFloat,Numo::Int32]  mantissa and exponent.

*/
static VALUE
sfloat_math_s_frexp(VALUE mod, VALUE a1)
{
    ndfunc_arg_in_t ain[1] = {{cT,0}};
    ndfunc_arg_out_t aout[2] = {{cT,0},{numo_cInt32,0}};
    ndfunc_t ndf = { iter_sfloat_math_s_frexp, STRIDE_LOOP, 1,2, ain,aout };
    return na_ndloop(&ndf, 1, a1);
}



#line 37 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
void
Init_numo_sfloat(void)
{
    VALUE hCast, mNumo;

    mNumo = rb_define_module("Numo");

    
    id_cast = rb_intern("cast");
    id_copysign = rb_intern("copysign");
    id_divmod = rb_intern("divmod");
    id_eq = rb_intern("eq");
    id_ge = rb_intern("ge");
    id_gt = rb_intern("gt");
    id_le = rb_intern("le");
    id_lt = rb_intern("lt");
    id_mulsum = rb_intern("mulsum");
    id_nan = rb_intern("nan");
    id_ne = rb_intern("ne");
    id_nearly_eq = rb_intern("nearly_eq");
    id_pow = rb_intern("pow");


#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_class.c"
    /*
      Document-class: Numo::SFloat
      
    */
    cT = rb_define_class_under(mNumo, "SFloat", cNArray);

  
    // alias of SFloat
    rb_define_const(mNumo, "Float32", numo_cSFloat);
  

    hCast = rb_hash_new();
    rb_define_const(cT, "UPCAST", hCast);
    rb_hash_aset(hCast, rb_cArray,   cT);
    
    #ifdef RUBY_INTEGER_UNIFICATION
    rb_hash_aset(hCast, rb_cInteger, cT);
    #else
    rb_hash_aset(hCast, rb_cFixnum, cT);
    rb_hash_aset(hCast, rb_cBignum, cT);
    #endif
    rb_hash_aset(hCast, rb_cFloat, cT);
    rb_hash_aset(hCast, rb_cComplex, numo_cSComplex);
    rb_hash_aset(hCast, numo_cRObject, numo_cRObject);
    rb_hash_aset(hCast, numo_cDComplex, numo_cDComplex);
    rb_hash_aset(hCast, numo_cSComplex, numo_cSComplex);
    rb_hash_aset(hCast, numo_cDFloat, numo_cDFloat);
    rb_hash_aset(hCast, numo_cSFloat, numo_cSFloat);
    rb_hash_aset(hCast, numo_cInt64, numo_cSFloat);
    rb_hash_aset(hCast, numo_cInt32, numo_cSFloat);
    rb_hash_aset(hCast, numo_cInt16, numo_cSFloat);
    rb_hash_aset(hCast, numo_cInt8, numo_cSFloat);
    rb_hash_aset(hCast, numo_cUInt64, numo_cSFloat);
    rb_hash_aset(hCast, numo_cUInt32, numo_cSFloat);
    rb_hash_aset(hCast, numo_cUInt16, numo_cSFloat);
    rb_hash_aset(hCast, numo_cUInt8, numo_cSFloat);

    
    /**/
    rb_define_const(cT,"ELEMENT_BIT_SIZE",INT2FIX(sizeof(dtype)*8));
    /**/
    rb_define_const(cT,"ELEMENT_BYTE_SIZE",INT2FIX(sizeof(dtype)));
    /**/
    rb_define_const(cT,"CONTIGUOUS_STRIDE",INT2FIX(sizeof(dtype)));
    /**/
    rb_define_const(cT,"EPSILON",M_EPSILON);
    /**/
    rb_define_const(cT,"MAX",M_MAX);
    /**/
    rb_define_const(cT,"MIN",M_MIN);
    rb_define_alloc_func(cT, sfloat_s_alloc_func);
    rb_define_method(cT, "allocate", sfloat_allocate, 0);
    rb_define_method(cT, "extract", sfloat_extract, 0);
    
    rb_define_method(cT, "store", sfloat_store, 1);
    
    
    rb_define_singleton_method(cT, "cast", sfloat_s_cast, 1);
    rb_define_method(cT, "[]", sfloat_aref, -1);
    rb_define_method(cT, "[]=", sfloat_aset, -1);
    rb_define_method(cT, "coerce_cast", sfloat_coerce_cast, 1);
    rb_define_method(cT, "to_a", sfloat_to_a, 0);
    rb_define_method(cT, "fill", sfloat_fill, 1);
    rb_define_method(cT, "format", sfloat_format, -1);
    rb_define_method(cT, "format_to_a", sfloat_format_to_a, -1);
    rb_define_method(cT, "inspect", sfloat_inspect, 0);
    rb_define_method(cT, "each", sfloat_each, 0);
    rb_define_method(cT, "map", sfloat_map, 0);
    rb_define_method(cT, "each_with_index", sfloat_each_with_index, 0);
    rb_define_method(cT, "map_with_index", sfloat_map_with_index, 0);
    rb_define_method(cT, "abs", sfloat_abs, 0);
    rb_define_method(cT, "+", sfloat_add, 1);
    rb_define_method(cT, "-", sfloat_sub, 1);
    rb_define_method(cT, "*", sfloat_mul, 1);
    rb_define_method(cT, "/", sfloat_div, 1);
    rb_define_method(cT, "%", sfloat_mod, 1);
    rb_define_method(cT, "divmod", sfloat_divmod, 1);
    rb_define_method(cT, "**", sfloat_pow, 1);
    rb_define_method(cT, "-@", sfloat_minus, 0);
    rb_define_method(cT, "reciprocal", sfloat_reciprocal, 0);
    rb_define_method(cT, "sign", sfloat_sign, 0);
    rb_define_method(cT, "square", sfloat_square, 0);
    rb_define_alias(cT, "conj", "view");
    rb_define_alias(cT, "im", "view");
    rb_define_alias(cT, "conjugate", "conj");
    rb_define_method(cT, "eq", sfloat_eq, 1);
    rb_define_method(cT, "ne", sfloat_ne, 1);
    rb_define_method(cT, "nearly_eq", sfloat_nearly_eq, 1);
    rb_define_alias(cT, "close_to", "nearly_eq");
    rb_define_method(cT, "floor", sfloat_floor, 0);
    rb_define_method(cT, "round", sfloat_round, 0);
    rb_define_method(cT, "ceil", sfloat_ceil, 0);
    rb_define_method(cT, "trunc", sfloat_trunc, 0);
    rb_define_method(cT, "rint", sfloat_rint, 0);
    rb_define_method(cT, "copysign", sfloat_copysign, 1);
    rb_define_method(cT, "signbit", sfloat_signbit, 0);
    rb_define_method(cT, "modf", sfloat_modf, 0);
    rb_define_method(cT, "gt", sfloat_gt, 1);
    rb_define_method(cT, "ge", sfloat_ge, 1);
    rb_define_method(cT, "lt", sfloat_lt, 1);
    rb_define_method(cT, "le", sfloat_le, 1);
    rb_define_alias(cT, ">", "gt");
    rb_define_alias(cT, ">=", "ge");
    rb_define_alias(cT, "<", "lt");
    rb_define_alias(cT, "<=", "le");
    rb_define_method(cT, "clip", sfloat_clip, 2);
    rb_define_method(cT, "isnan", sfloat_isnan, 0);
    rb_define_method(cT, "isinf", sfloat_isinf, 0);
    rb_define_method(cT, "isposinf", sfloat_isposinf, 0);
    rb_define_method(cT, "isneginf", sfloat_isneginf, 0);
    rb_define_method(cT, "isfinite", sfloat_isfinite, 0);
    rb_define_method(cT, "sum", sfloat_sum, -1);
    rb_define_method(cT, "prod", sfloat_prod, -1);
    rb_define_method(cT, "mean", sfloat_mean, -1);
    rb_define_method(cT, "stddev", sfloat_stddev, -1);
    rb_define_method(cT, "var", sfloat_var, -1);
    rb_define_method(cT, "rms", sfloat_rms, -1);
    rb_define_method(cT, "min", sfloat_min, -1);
    rb_define_method(cT, "max", sfloat_max, -1);
    rb_define_method(cT, "ptp", sfloat_ptp, -1);
    rb_define_method(cT, "max_index", sfloat_max_index, -1);
    rb_define_method(cT, "min_index", sfloat_min_index, -1);
    rb_define_method(cT, "minmax", sfloat_minmax, -1);
    rb_define_module_function(cT, "maximum", sfloat_s_maximum, -1);
    rb_define_module_function(cT, "minimum", sfloat_s_minimum, -1);
    rb_define_method(cT, "cumsum", sfloat_cumsum, -1);
    rb_define_method(cT, "cumprod", sfloat_cumprod, -1);
    rb_define_method(cT, "mulsum", sfloat_mulsum, -1);
    rb_define_method(cT, "seq", sfloat_seq, -1);
    rb_define_method(cT, "logseq", sfloat_logseq, -1);
    rb_define_method(cT, "eye", sfloat_eye, -1);
    rb_define_alias(cT, "indgen", "seq");
    rb_define_method(cT, "rand", sfloat_rand, -1);
    rb_define_method(cT, "rand_norm", sfloat_rand_norm, -1);
    rb_define_method(cT, "poly", sfloat_poly, -2);
    
    
    rb_define_method(cT, "sort", sfloat_sort, -1);
    
    
    rb_define_method(cT, "sort_index", sfloat_sort_index, -1);
    rb_define_method(cT, "median", sfloat_median, -1);
#line 20 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_class.c"
    rb_define_singleton_method(cT, "[]", sfloat_s_cast, -2);

#line 1 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_module.c"
    /*
      Document-module: Numo::SFloat::NMath
      
    */
    
    mTM = rb_define_module_under(cT, "Math");
    
    
    rb_define_module_function(mTM, "sqrt", sfloat_math_s_sqrt, 1);
    rb_define_module_function(mTM, "cbrt", sfloat_math_s_cbrt, 1);
    rb_define_module_function(mTM, "log", sfloat_math_s_log, 1);
    rb_define_module_function(mTM, "log2", sfloat_math_s_log2, 1);
    rb_define_module_function(mTM, "log10", sfloat_math_s_log10, 1);
    rb_define_module_function(mTM, "exp", sfloat_math_s_exp, 1);
    rb_define_module_function(mTM, "exp2", sfloat_math_s_exp2, 1);
    rb_define_module_function(mTM, "exp10", sfloat_math_s_exp10, 1);
    rb_define_module_function(mTM, "sin", sfloat_math_s_sin, 1);
    rb_define_module_function(mTM, "cos", sfloat_math_s_cos, 1);
    rb_define_module_function(mTM, "tan", sfloat_math_s_tan, 1);
    rb_define_module_function(mTM, "asin", sfloat_math_s_asin, 1);
    rb_define_module_function(mTM, "acos", sfloat_math_s_acos, 1);
    rb_define_module_function(mTM, "atan", sfloat_math_s_atan, 1);
    rb_define_module_function(mTM, "sinh", sfloat_math_s_sinh, 1);
    rb_define_module_function(mTM, "cosh", sfloat_math_s_cosh, 1);
    rb_define_module_function(mTM, "tanh", sfloat_math_s_tanh, 1);
    rb_define_module_function(mTM, "asinh", sfloat_math_s_asinh, 1);
    rb_define_module_function(mTM, "acosh", sfloat_math_s_acosh, 1);
    rb_define_module_function(mTM, "atanh", sfloat_math_s_atanh, 1);
    rb_define_module_function(mTM, "sinc", sfloat_math_s_sinc, 1);
    rb_define_module_function(mTM, "atan2", sfloat_math_s_atan2, 2);
    rb_define_module_function(mTM, "hypot", sfloat_math_s_hypot, 2);
    rb_define_module_function(mTM, "erf", sfloat_math_s_erf, 1);
    rb_define_module_function(mTM, "erfc", sfloat_math_s_erfc, 1);
    rb_define_module_function(mTM, "log1p", sfloat_math_s_log1p, 1);
    rb_define_module_function(mTM, "expm1", sfloat_math_s_expm1, 1);
    rb_define_module_function(mTM, "ldexp", sfloat_math_s_ldexp, 2);
    rb_define_module_function(mTM, "frexp", sfloat_math_s_frexp, 1);

#line 11 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/init_module.c"
    //  how to do this?
    //rb_extend_object(cT, mTM);
#line 50 "/Users/shou/rails/scrach_dnn_on_rails/vendor/bundle/ruby/2.5.0/gems/numo-narray-0.9.1.4/ext/numo/narray/gen/tmpl/lib.c"
}
