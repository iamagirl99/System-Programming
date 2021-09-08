/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct
 */
team_t team = {
    "Kim Eeyoung",              /* name */
    
    "2019076708",     /* student ID */
    "iamagirl99@naver.com",  /* student email */
    
    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    
    for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i;
    int j;
    int tmp1=dim*dim;
    int tmp2=dim *31;
    int tmp3=tmp1-dim;
    int tmp4=tmp1+32;
    int tmp5=dim+31;
    dst+=tmp3;
    for(i=0; i< dim; i+=32)
    {
        for(j=0;j<dim;j++)
        {
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            dst++; src+=dim;
            *dst=*src;
            src++;
            src-=tmp2;
            dst-=tmp5;
        }
        src+=tmp2;
        dst+=tmp4;
    }
}



char rotate_descr2[] = "rotate2: ...";
void rotate2(int dim, pixel *src, pixel *dst)
{
    int i,j,i1,j1;
    for(i1=0;i1<dim;i1+=4)
    for(j1=0;j1<dim;j1+=4)
    for(i=i1;i<i1+4;i++)
    for(j=j1;j<j1+4;j++)
    dst[RIDX(dim-1-j,i,dim)]=src[RIDX(i,j,dim)];
    for(i1=0;i1<dim;i1+=32)
    for(j1=0;j1<dim;j1+=32)
    for(i=j1;i<i1+32;i+=1)
    for(j=j1;j<j1+32;j+=1)
    dst[RIDX(dim-1-j,i,dim)]=  src[RIDX(i,j,dim)];
}


#define COPY(d,s) *(d)=*(s)
char rotate_descr3[] = "rotate3: ...";
void rotate3( int dim,pixel *src,pixel *dst)
{
    int i,j;
    for(i=0;i<dim;i+=32)
    {
        for(j=dim-1;j>=0;j-=1)
        {
            pixel*dptr=dst+RIDX(dim-1-j,i,dim);
            pixel*sptr=src+RIDX(i,j,dim);
            COPY(dptr,sptr); sptr+=dim;
            COPY(dptr+1,sptr); sptr+=dim;
            COPY(dptr+2,sptr); sptr+=dim;
            COPY(dptr+3,sptr); sptr+=dim;
            COPY(dptr+4,sptr); sptr+=dim;
            COPY(dptr+5,sptr); sptr+=dim;
            COPY(dptr+6,sptr); sptr+=dim;
            COPY(dptr+7,sptr); sptr+=dim;
            COPY(dptr+8,sptr); sptr+=dim;
            COPY(dptr+9,sptr); sptr+=dim;
            COPY(dptr+10,sptr); sptr+=dim;
            COPY(dptr+11,sptr); sptr+=dim;
            COPY(dptr+12,sptr); sptr+=dim;
            COPY(dptr+13,sptr); sptr+=dim;
            COPY(dptr+14,sptr); sptr+=dim;
            COPY(dptr+15,sptr); sptr+=dim;
            COPY(dptr+16,sptr); sptr+=dim;
            COPY(dptr+17,sptr); sptr+=dim;
            COPY(dptr+18,sptr); sptr+=dim;
            COPY(dptr+19,sptr); sptr+=dim;
            COPY(dptr+20,sptr); sptr+=dim;
            COPY(dptr+21,sptr); sptr+=dim;
            COPY(dptr+22,sptr); sptr+=dim;
            COPY(dptr+23,sptr); sptr+=dim;
            COPY(dptr+24,sptr); sptr+=dim;
            COPY(dptr+25,sptr); sptr+=dim;
            COPY(dptr+26,sptr); sptr+=dim;
            COPY(dptr+27,sptr); sptr+=dim;
            COPY(dptr+28,sptr); sptr+=dim;
            COPY(dptr+29,sptr); sptr+=dim;
            COPY(dptr+30,sptr); sptr+=dim;
            COPY(dptr+31,sptr);
        }
    }
}

char rotate_descr4[]= "rotate4: ...";
void rotate4(int dim, pixel *src, pixel *dst){
    int i,j=0;
    dst += (dim-1)*dim;
    for(i=0;i<dim;i+=32){
        for(j=0;j<dim;j++){
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            //dst++;src+=dim;
            src-=31*dim;src++;
            dst-=31;dst-=dim;
        }
        src+=31*dim;
        dst+=32;dst+=dim*dim;
    }
}

char rotate_descr5[] = "rotate5: ... ";
void rotate5(int dim, pixel *src, pixel *dst)
{
    int i,j,k;
    int stride = 32;
    int count = dim >> 5;
    src += dim - 1;
    for(i=0;i<count;i++){
        for(j=0;j<dim;j++){
            for(k =0;k<stride;k++){
                 *dst++ = *src;
                  src += dim;
            }
            src -= dim * stride + 1;
            dst += dim - stride;
        }
            src += dim * (stride + 1);
            dst -= dim * dim - stride;
    }
}
  
char rotate_descr6[] = "rotate6: ... ";
void rotate6(int dim, pixel *src, pixel *dst)
{
    int i, j;
    int tmpd = (dim - 1) * dim;
    int tmps = 0;
    
    for(i = 0; i < dim; i += 32)
    {
      for(j = 0; j < dim; j++)
      {
          //No.1
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.2
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.3
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.4
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.5
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.6
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.7
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.8
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.9
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.10
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.11
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.12
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.13
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.14
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.15
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.16
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.17
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.18
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.19
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.20
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.21
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.22
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.23
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.24
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.25
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.26
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.27
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.28
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.29
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.30
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.31
          dst[tmpd] = src[tmps];
          tmpd++;
          tmps += dim;

          //No.32
          dst[tmpd] = src[tmps];
          tmps -= 31 * dim;
          tmps++;
          tmpd -= 31;
          tmpd -= dim;
      }
    tmpd += dim * dim;
    tmpd += 32;
    tmps += 31 * dim;
    }
}

char rotate_descr7[] = "rotate7: ... ";
void rotate7(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i+=32)
    for (j = 0; j < dim; j++) {
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
        dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
        dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
        dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
        dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
        dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
        dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
        dst[RIDX(dim-1-j, i+8, dim)] = src[RIDX(i+8, j, dim)];
        dst[RIDX(dim-1-j, i+9, dim)] = src[RIDX(i+9, j, dim)];
        dst[RIDX(dim-1-j, i+10, dim)] = src[RIDX(i+10, j, dim)];
        dst[RIDX(dim-1-j, i+11, dim)] = src[RIDX(i+11, j, dim)];
        dst[RIDX(dim-1-j, i+12, dim)] = src[RIDX(i+12, j, dim)];
        dst[RIDX(dim-1-j, i+13, dim)] = src[RIDX(i+13, j, dim)];
        dst[RIDX(dim-1-j, i+14, dim)] = src[RIDX(i+14, j, dim)];
        dst[RIDX(dim-1-j, i+15, dim)] = src[RIDX(i+15, j, dim)];
        dst[RIDX(dim-1-j, i+16, dim)] = src[RIDX(i+16, j, dim)];
        dst[RIDX(dim-1-j, i+17, dim)] = src[RIDX(i+17, j, dim)];
        dst[RIDX(dim-1-j, i+18, dim)] = src[RIDX(i+18, j, dim)];
        dst[RIDX(dim-1-j, i+19, dim)] = src[RIDX(i+19, j, dim)];
        dst[RIDX(dim-1-j, i+20, dim)] = src[RIDX(i+20, j, dim)];
        dst[RIDX(dim-1-j, i+21, dim)] = src[RIDX(i+21, j, dim)];
        dst[RIDX(dim-1-j, i+22, dim)] = src[RIDX(i+22, j, dim)];
        dst[RIDX(dim-1-j, i+23, dim)] = src[RIDX(i+23, j, dim)];
        dst[RIDX(dim-1-j, i+24, dim)] = src[RIDX(i+24, j, dim)];
        dst[RIDX(dim-1-j, i+25, dim)] = src[RIDX(i+25, j, dim)];
        dst[RIDX(dim-1-j, i+26, dim)] = src[RIDX(i+26, j, dim)];
        dst[RIDX(dim-1-j, i+27, dim)] = src[RIDX(i+27, j, dim)];
        dst[RIDX(dim-1-j, i+28, dim)] = src[RIDX(i+28, j, dim)];
        dst[RIDX(dim-1-j, i+29, dim)] = src[RIDX(i+29, j, dim)];
        dst[RIDX(dim-1-j, i+30, dim)] = src[RIDX(i+30, j, dim)];
        dst[RIDX(dim-1-j, i+31, dim)] = src[RIDX(i+31, j, dim)];
    }
}

char rotate_descr8[] = "rotate8: ... ";
void rotate8(int dim, pixel *src, pixel *dst)
{
    int i, j;
    int buff = dim*dim;

    dst += buff - dim;
    for (i = 0; i < dim; i += 32)
    {
            for (j = 0; j < dim; j++)
            {
                *dst = *src;
                src += dim;

                *(dst + 1)=*src;
                src += dim;

                *(dst + 2)=*src;
                src += dim;

                *(dst + 3)=*src;
                src += dim;

                *(dst + 4)=*src;
                src += dim;

                *(dst + 5)=*src;
                src += dim;

                *(dst + 6)=*src;
                src += dim;

                *(dst + 7)=*src;
                src += dim;

                *(dst + 8)=*src;
                src += dim;

                *(dst + 9)=*src;
                src += dim;

                *(dst + 10)=*src;
                src += dim;

                *(dst + 11)=*src;
                src += dim;

                *(dst + 12)=*src;
                src += dim;

                *(dst + 13)=*src;
                src += dim;

                *(dst + 14)=*src;
                src += dim;

                *(dst + 15)=*src;
                src += dim;

                *(dst + 16)=*src;
                src += dim;

                *(dst + 17)=*src;
                src += dim;

                *(dst + 18)=*src;
                src += dim;

                *(dst + 19)=*src;
                src += dim;

                *(dst + 20)=*src;
                src += dim;

                *(dst + 21)=*src;
                src += dim;

                *(dst + 22)=*src;
                src += dim;

                *(dst + 23)=*src;
                src += dim;

                *(dst + 24)=*src;
                src += dim;

                *(dst + 25)=*src;
                src += dim;

                *(dst + 26)=*src;
                src += dim;

                *(dst + 27)=*src;
                src += dim;

                *(dst + 28)=*src;
                src += dim;

                *(dst +29)=*src;
                src += dim;

                *(dst + 30)=*src;
                src += dim;

                *(dst + 31)=*src;

                 dst -= dim;
                src -= dim*31 - 1;
            }
            dst += 32 + buff;
            src += dim*31;
        }
    return;
}

char rotate_descr9[] = "rotate9: ... ";
void rotate9(int dim, pixel *src, pixel *dst)
{
    int i, j, a, b;
    int sdim = dim - 1;
    for (i = 0; i < dim; i += 8)
    {
        for (j = 0; j < dim; j += 8)
        {
            for (a = i; a < i + 8; a++)
            {
                for (b = j; b < j + 8; b++)
                {
                    dst[RIDX(sdim - b, a, dim)] = src[RIDX(a, b, dim)];
                }
            }
        }
    }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate, rotate_descr);
    add_rotate_function(&rotate2, rotate_descr2);
    add_rotate_function(&rotate3, rotate_descr3);
    add_rotate_function(&rotate4, rotate_descr4);
    add_rotate_function(&rotate5, rotate_descr5);
    add_rotate_function(&rotate6, rotate_descr6);
    add_rotate_function(&rotate7, rotate_descr7);
    add_rotate_function(&rotate8, rotate_descr8);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j)
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;
    
    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++)
    for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++)
    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    
    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */



char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst)
{
    int i,j,dest;
   
    dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)>>2;
    dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)>>2;
    dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)>>2;
    
    i=dim-1;
    j=dim*2-1;
    dst[i].red = (src[i].red+src[i-1].red+src[j].red+src[j-1].red)>>2;
    dst[i].blue = (src[i].blue+src[i-1].blue+src[j].blue+src[j-1].blue)>>2;
    dst[i].green = (src[i].green+src[i-1].green+src[j].green+src[j-1].green)>>2;
    
    i=dim*(dim-1);
    j=dim*(dim-2);
    dst[i].red = (src[i].red+src[i+1].red+src[j].red+src[j+1].red)>>2;
    dst[i].blue = (src[i].blue+src[i+1].blue+src[j].blue+src[j+1].blue)>>2;
    dst[i].green = (src[i].green+src[i+1].green+src[j].green+src[j+1].green)>>2;
    
    i=dim*dim-1;
    j=dim*(dim-1)-1;
    dst[i].red = (src[i].red+src[i-1].red+src[j].red+src[j-1].red)>>2;
    dst[i].blue = (src[i].blue+src[i-1].blue+src[j].blue+src[j-1].blue)>>2;
    dst[i].green = (src[i].green+src[i-1].green+src[j].green+src[j-1].green)>>2;
    
    dest = dim-1;
    i=dim+1;
    for (j = 1; j < dest; j++) {
        dst[j].red = (src[j-1].red+src[j].red+src[j+1].red+src[i-1].red+src[i].red
                      +src[i+1].red)/6;
        dst[j].green = (src[j-1].green+src[j].green+src[j+1].green+src[i-1].green+src[i].green
                        +src[i+1].green)/6;
        dst[j].blue = (src[j-1].blue+src[j].blue+src[j+1].blue+src[i-1].blue+src[i].blue
                       +src[i+1].blue)/6;
        i++;
    }
    
    dest = dim*dim-1;
    for (j = dim*(dim-1)+1; j < dest; j++) {
        i=j-dim;
        dst[j].red = (src[j-1].red+src[j].red+src[j+1].red+src[i-1].red+src[i].red
                      +src[i+1].red)/6;
        dst[j].green = (src[j-1].green+src[j].green+src[j+1].green+src[i-1].green+src[i].green
                        +src[i+1].green)/6;
        dst[j].blue = (src[j-1].blue+src[j].blue+src[j+1].blue+src[i-1].blue+src[i].blue
                       +src[i+1].blue)/6;
    }
    
    dest = dim*dim-dim;
    for (j = dim; j < dest; j+=dim) {
        dst[j].red = (src[j].red+src[j+1].red+src[j-dim].red+src[j-dim+1].red+src[j+dim].red+src[j+1+dim].red)/6;
        dst[j].green = (src[j].green+src[j+1].green+src[j-dim].green+src[j-dim+1].green+src[j+dim].green+src[j+1+dim].green)/6;
        dst[j].blue = (src[j].blue+src[j+1].blue+src[j-dim].blue+src[j-dim+1].blue+src[j+dim].blue+src[j+1+dim].blue)/6;
    }
    
    dest=dim*dim-1;
    for (j = dim+dim-1; j < dest; j+=dim) {
        dst[j].red = (src[j].red+src[j-1].red+src[j-dim].red+src[j-dim-1].red+src[j+dim].red+src[j-1+dim].red)/6;
        dst[j].green = (src[j].green+src[j-1].green+src[j-dim].green+src[j-1+dim].green+src[j+dim].green+src[j-dim-1].green)/6;
        dst[j].blue = (src[j].blue+src[j-1].blue+src[j-dim].blue+src[j-dim-1].blue+src[j+dim].blue+src[j-1+dim].blue)/6;
    }

    
    pixel *pixelA = &src[0];
    pixel *pixelB = &src[dim];
    pixel *pixelC = &src[dim+dim];
    pixel *pixelD = &src[dim+dim+dim];

    
    int sum0_red, sum0_green, sum0_blue;
    int sum1_red, sum1_green, sum1_blue;
    int sum2_red, sum2_green, sum2_blue;
    int sum3_red, sum3_green, sum3_blue;
    int sum4_red, sum4_green, sum4_blue;
    int sum5_red, sum5_green, sum5_blue;

    
    int index = dim+1;
    int index_ = index+dim;
    
    for (i = 1; i < dim - 2; i += 2) {
        sum0_red = pixelB->red;
        sum0_blue = pixelB->blue;
        sum0_green = pixelB->green;
        sum0_red += pixelC->red;
        sum0_blue += pixelC->blue;
        sum0_green += pixelC->green;
        sum3_red = sum0_red+pixelD->red;
        sum3_green = sum0_green+pixelD->green;
        sum3_blue = sum0_blue+pixelD->blue;
        sum0_red += pixelA->red;
        sum0_blue += pixelA->blue;
        sum0_green += pixelA->green;
        
        pixelA++;
        pixelB++;
        pixelC++;
        pixelD++;

        sum1_red = pixelB->red;
        sum1_blue = pixelB->blue;
        sum1_green = pixelB->green;
        sum1_red += pixelC->red;
        sum1_blue += pixelC->blue;
        sum1_green += pixelC->green;
        sum4_red = sum1_red+pixelD->red;
        sum4_green = sum1_green+pixelD->green;
        sum4_blue = sum1_blue+pixelD->blue;
        sum1_red += pixelA->red;
        sum1_blue += pixelA->blue;
        sum1_green += pixelA->green;
        
        pixelA++;
        pixelB++;
        pixelC++;
        pixelD++;

        sum2_red = pixelB->red;
        sum2_blue = pixelB->blue;
        sum2_green = pixelB->green;
        sum2_red += pixelC->red;
        sum2_blue += pixelC->blue;
        sum2_green += pixelC->green;
        sum5_red = sum2_red+pixelD->red;
        sum5_green = sum2_green+pixelD->green;
        sum5_blue = sum2_blue+pixelD->blue;
        sum2_red += pixelA->red;
        sum2_blue += pixelA->blue;
        sum2_green += pixelA->green;
        
        pixelA++;
        pixelB++;
        pixelC++;
        pixelD++;

        dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
        dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
        dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
        index++;

        dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
        dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
        dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
        index_++;
        
        sum0_red = sum1_red;
        sum1_red = sum2_red;
        sum0_green = sum1_green;
        sum1_green = sum2_green;
        sum0_blue = sum1_blue;
        sum1_blue = sum2_blue;
        sum3_red = sum4_red;
        sum4_red = sum5_red;
        sum3_green = sum4_green;
        sum4_green = sum5_green;
        sum3_blue = sum4_blue;
        sum4_blue = sum5_blue;
        
        
        for (j = 2; j < dim-4; j += 4) {
            
            sum2_red = pixelB->red;
            sum2_blue = pixelB->blue;
            sum2_green = pixelB->green;
            sum2_red += pixelC->red;
            sum2_blue += pixelC->blue;
            sum2_green += pixelC->green;
            sum5_red = sum2_red+pixelD->red;
            sum5_green = sum2_green+pixelD->green;
            sum5_blue = sum2_blue+pixelD->blue;
            sum2_red += pixelA->red;
            sum2_blue += pixelA->blue;
            sum2_green += pixelA->green;
            pixelA++;
            pixelB++;
            pixelC++;
            pixelD++;

            dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
            dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
            dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
            index++;

            dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
            dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
            dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
            index_++;

            sum0_red = sum1_red;
            sum1_red = sum2_red;
            sum0_green = sum1_green;
            sum1_green = sum2_green;
            sum0_blue = sum1_blue;
            sum1_blue = sum2_blue;
            sum3_red = sum4_red;
            sum4_red = sum5_red;
            sum3_green = sum4_green;
            sum4_green = sum5_green;
            sum3_blue = sum4_blue;
            sum4_blue = sum5_blue;

            
            sum2_red = pixelB->red;
            sum2_blue = pixelB->blue;
            sum2_green = pixelB->green;
            sum2_red += pixelC->red;
            sum2_blue += pixelC->blue;
            sum2_green += pixelC->green;
            sum5_red = sum2_red+pixelD->red;
            sum5_green = sum2_green+pixelD->green;
            sum5_blue = sum2_blue+pixelD->blue;
            sum2_red += pixelA->red;
            sum2_blue += pixelA->blue;
            sum2_green += pixelA->green;
            pixelA++;
            pixelB++;
            pixelC++;
            pixelD++;

            dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
            dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
            dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
            index++;

            dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
            dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
            dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
            index_++;

            sum0_red = sum1_red;
            sum1_red = sum2_red;
            sum0_green = sum1_green;
            sum1_green = sum2_green;
            sum0_blue = sum1_blue;
            sum1_blue = sum2_blue;
            sum3_red = sum4_red;
            sum4_red = sum5_red;
            sum3_green = sum4_green;
            sum4_green = sum5_green;
            sum3_blue = sum4_blue;
            sum4_blue = sum5_blue;

            
            sum2_red = pixelB->red;
            sum2_blue = pixelB->blue;
            sum2_green = pixelB->green;
            sum2_red += pixelC->red;
            sum2_blue += pixelC->blue;
            sum2_green += pixelC->green;
            sum5_red = sum2_red+pixelD->red;
            sum5_green = sum2_green+pixelD->green;
            sum5_blue = sum2_blue+pixelD->blue;
            sum2_red += pixelA->red;
            sum2_blue += pixelA->blue;
            sum2_green += pixelA->green;
            pixelA++;
            pixelB++;
            pixelC++;
            pixelD++;

            dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
            dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
            dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
            index++;

            dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
            dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
            dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
            index_++;

            sum0_red = sum1_red;
            sum1_red = sum2_red;
            sum0_green = sum1_green;
            sum1_green = sum2_green;
            sum0_blue = sum1_blue;
            sum1_blue = sum2_blue;
            sum3_red = sum4_red;
            sum4_red = sum5_red;
            sum3_green = sum4_green;
            sum4_green = sum5_green;
            sum3_blue = sum4_blue;
            sum4_blue = sum5_blue;

            
            sum2_red = pixelB->red;
            sum2_blue = pixelB->blue;
            sum2_green = pixelB->green;
            sum2_red += pixelC->red;
            sum2_blue += pixelC->blue;
            sum2_green += pixelC->green;
            sum5_red = sum2_red+pixelD->red;
            sum5_green = sum2_green+pixelD->green;
            sum5_blue = sum2_blue+pixelD->blue;
            sum2_red += pixelA->red;
            sum2_blue += pixelA->blue;
            sum2_green += pixelA->green;
            pixelA++;
            pixelB++;
            pixelC++;
            pixelD++;

            dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
            dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
            dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
            index++;

            dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
            dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
            dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
            index_++;

            sum0_red = sum1_red;
            sum1_red = sum2_red;
            sum0_green = sum1_green;
            sum1_green = sum2_green;
            sum0_blue = sum1_blue;
            sum1_blue = sum2_blue;
            sum3_red = sum4_red;
            sum4_red = sum5_red;
            sum3_green = sum4_green;
            sum4_green = sum5_green;
            sum3_blue = sum4_blue;
            sum4_blue = sum5_blue;

        }
       
        for (; j < dim-1; j++) {
            sum2_red = pixelB->red;
            sum2_blue = pixelB->blue;
            sum2_green = pixelB->green;
            sum2_red += pixelC->red;
            sum2_blue += pixelC->blue;
            sum2_green += pixelC->green;
            sum5_red = sum2_red+pixelD->red;
            sum5_green = sum2_green+pixelD->green;
            sum5_blue = sum2_blue+pixelD->blue;
            sum2_red += pixelA->red;
            sum2_blue += pixelA->blue;
            sum2_green += pixelA->green;
            pixelA++;
            pixelB++;
            pixelC++;
            pixelD++;

            dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
            dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
            dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
            index++;

            dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
            dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
            dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
            index_++;

            sum0_red = sum1_red;
            sum1_red = sum2_red;
            sum0_green = sum1_green;
            sum1_green = sum2_green;
            sum0_blue = sum1_blue;
            sum1_blue = sum2_blue;
            sum3_red = sum4_red;
            sum4_red = sum5_red;
            sum3_green = sum4_green;
            sum4_green = sum5_green;
            sum3_blue = sum4_blue;
            sum4_blue = sum5_blue;
        }

        
        pixelA += dim;
        pixelB += dim;
        pixelC += dim;
        pixelD += dim;
        index += dim+2;
        index_ += dim+2;
    }

}


char smooth_descr2[] = "smooth2: ...";
void smooth2(int dim, pixel *src, pixel *dst)
{
    pixel_sum rowsum[530][530];
    int i, j, snum;
    for(i=0;i<dim; i++)
    {
        rowsum[i][0].red = (src[RIDX(i, 0, dim)].red+src[RIDX(i, 1, dim)].red);
        rowsum[i][0].blue = (src[RIDX(i, 0, dim)].blue+src[RIDX(i, 1,dim)].blue);
        rowsum[i][0].green = (src[RIDX(i, 0, dim)].green+src[RIDX(i, 1,dim)].green);
        rowsum[i][0].num = 2;
        for(j=1;j<dim-1; j++)
        {
            rowsum[i][j].red = (src[RIDX(i, j-1, dim)].red+src[RIDX(i, j,dim)].red+src[RIDX(i, j+1, dim)].red);
            rowsum[i][j].blue = (src[RIDX(i, j-1, dim)].blue+src[RIDX(i, j,dim)].blue+src[RIDX(i, j+1, dim)].blue);
            rowsum[i][j].green = (src[RIDX(i, j-1, dim)].green+src[RIDX(i, j,dim)].green+src[RIDX(i, j+1, dim)].green);
            rowsum[i][j].num = 3;
        }
        rowsum[i][dim-1].red = (src[RIDX(i, dim-2, dim)].red+src[RIDX(i, dim-1,dim)].red);
        rowsum[i][dim-1].blue = (src[RIDX(i, dim-2, dim)].blue+src[RIDX(i,dim-1, dim)].blue);
        rowsum[i][dim-1].green = (src[RIDX(i, dim-2, dim)].green+src[RIDX(i,dim-1, dim)].green);
        rowsum[i][dim-1].num = 2;
    }
    for(j=0;j<dim; j++)
    {
        snum = rowsum[0][j].num+rowsum[1][j].num;
        dst[RIDX(0,j, dim)].red = (unsigned short)((rowsum[0][j].red+rowsum[1][j].red)/snum);
        dst[RIDX(0,j, dim)].blue = (unsigned short)((rowsum[0][j].blue+rowsum[1][j].blue)/snum);
        dst[RIDX(0,j, dim)].green = (unsigned short)((rowsum[0][j].green+rowsum[1][j].green)/snum);
        for(i=1;i<dim-1; i++)
        {
            snum =rowsum[i-1][j].num+rowsum[i][j].num+rowsum[i+1][j].num;
            dst[RIDX(i, j, dim)].red = (unsigned short)((rowsum[i-1][j].red+rowsum[i][j].red+rowsum[i+1][j].red)/snum);
            dst[RIDX(i, j, dim)].blue = (unsigned short)((rowsum[i-1][j].blue+rowsum[i][j].blue+rowsum[i+1][j].blue)/snum);
            dst[RIDX(i, j, dim)].green = (unsigned short)((rowsum[i-1][j].green+rowsum[i][j].green+rowsum[i+1][j].green)/snum);
        }
        snum =rowsum[dim-1][j].num+rowsum[dim-2][j].num;
        dst[RIDX(dim-1, j, dim)].red = (unsigned short)((rowsum[dim-2][j].red+rowsum[dim-1][j].red)/snum);
        dst[RIDX(dim-1, j, dim)].blue = (unsigned short)((rowsum[dim-2][j].blue+rowsum[dim-1][j].blue)/snum);
        dst[RIDX(dim-1, j, dim)].green = (unsigned short)((rowsum[dim-2][j].green+rowsum[dim-1][j].green)/snum);
    }
}


char smooth_descr3[] = "smooth3: ...";
void smooth3(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            int ii, jj;
            pixel_sum sum;
            pixel current_pixel;
            sum.red = sum.green = sum.blue = 0;
            sum.num = 0;
            for(ii= max(i-1, 0); ii <= min(i+1, dim-1); ii++)
            {
                for(jj = max(j-1, 0); jj <=min(j+1, dim-1); jj++)
                {
                    pixel p=src[RIDX(ii, jj, dim)];
                    sum.red += (int) p.red;
                    sum.green+= (int) p.green;
                    sum.blue+= (int) p.blue;
                    sum.num++;
                }
                current_pixel.red = (unsigned short)(sum.red/sum.num);
                current_pixel.green = (unsigned short)(sum.green/sum.num);
                current_pixel.blue= (unsigned short) (sum.blue/sum.num);
                dst[RIDX(i, j, dim)] = current_pixel;
            }
        }
    }
}

char smooth_descr4[] = "smooth4: ...";
void smooth4(int dim, pixel *src, pixel *dst) {
    
    int i,j;
    
    pixel *pixelA,*pixelB,*pixelC;
    int size = dim-1;
    
    pixelB = src;
    pixelC = pixelB + dim;
    dst->red = (pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)>>2;
    dst->green = (pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)>>2;
    dst->blue = (pixelB->blue + (pixelB+1)->blue + pixelC->blue + (pixelC+1)->blue)>>2;
    pixelB++;
    pixelC++;
    dst++;
   
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/6;
        dst->green = (pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/6;
        dst->blue = (pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/6;
        pixelB++;
        pixelC++;
        dst++;
    }
    
    dst->red = (pixelC->red + (pixelC-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelC->green + (pixelC-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelC->blue + (pixelC-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
    dst++;
    
    pixelA = src;
    pixelB = pixelA + dim;
    pixelC = pixelB + dim;
    for(i = 1; i < size; i++)
    {
        
        dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)/6;
        dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue + pixelC->blue+ (pixelC+1)->blue)/6;
        dst++;
        pixelA++;
        pixelB++;
        pixelC++;
        
        for(j = 1; j < dim-1; j++)
        {
            dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/9;
            dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/9;
            dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/9;
            pixelA++;
            pixelB++;
            pixelC++;
            dst++;
        }
        
        dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red + pixelC->red + (pixelC-1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green + pixelC->green + (pixelC-1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue + pixelC->blue+ (pixelC-1)->blue)/6;
        pixelA++;
        pixelB++;
        pixelC++;
        dst++;
    }
    
    dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red)>>2;
    dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue)>>2;
    dst++;
    pixelA++;
    pixelB++;
    
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue)/6;
        pixelA++;
        pixelB++;
        dst++;
    }
    
    dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
}

char smooth_descr5[] = "smooth5: ...";
void smooth5(int dim, pixel *src, pixel *dst) {
    
    int i=1,j=0;
    
    dst[0].red=(src[0].red+src[1].red+src[dim].red+src[dim+1].red)/4;
    dst[0].green=(src[0].green+src[1].green+src[dim].green+src[dim+1].green)/4;
    dst[0].blue=(src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)/4;
    
    for(j=1; j<dim-1; j++) {
        dst[j].red=(src[j-1].red+src[j].red+src[j+1].red+src[dim+j-1].red+src[dim+j].red+src[dim+j+1].red)/6;
        dst[j].green=(src[j-1].green+src[j].green+src[j+1].green+src[dim+j-1].green+src[dim+j].green+src[dim+j+1].green)/6;
        dst[j].blue=(src[j-1].blue+src[j].blue+src[j+1].blue+src[dim+j-1].blue+src[dim+j].blue+src[dim+j+1].blue)/6;
    }
    
    dst[j].red=(src[j].red+src[j-1].red+src[dim+j].red+src[dim+j-1].red)/4;
    dst[j].green=(src[j].green+src[j-1].green+src[dim+j].green+src[dim+j-1].green)/4;
    dst[j].blue=(src[j].blue+src[j-1].blue+src[dim+j].blue+src[dim+j-1].blue)/4;
    
    for(; i<dim-1; i++) {
        
        dst[i*dim].red=(src[(i-1)*dim].red+src[(i-1)*dim+1].red+src[i*dim].red+src[i*dim+1].red+src[(i+1)*dim].red+src[(i+1)*dim+1].red)/6;
        dst[i*dim].green=(src[(i-1)*dim].green+src[(i-1)*dim+1].green+src[i*dim].green+src[i*dim+1].green+src[(i+1)*dim].green+src[(i+1)*dim+1].green)/6;
        dst[i*dim].blue=(src[(i-1)*dim].blue+src[(i-1)*dim+1].blue+src[i*dim].blue+src[i*dim+1].blue+src[(i+1)*dim].blue+src[(i+1)*dim+1].blue)/6;
        
        for(j=1; j<dim-1; j++) {
            dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[(i-1)*dim+j+1].red+src[i*dim+j-1].red+src[i*dim+j].red+src[i*dim+j+1].red+src[(i+1)*dim+j-1].red+src[(i+1)*dim+j].red+src[(i+1)*dim+j+1].red)/9;
            dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[(i-1)*dim+j+1].green+src[i*dim+j-1].green+src[i*dim+j].green+src[i*dim+j+1].green+src[(i+1)*dim+j-1].green+src[(i+1)*dim+j].green+src[(i+1)*dim+j+1].green)/9;
            dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[(i-1)*dim+j+1].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[i*dim+j+1].blue+src[(i+1)*dim+j-1].blue+src[(i+1)*dim+j].blue+src[(i+1)*dim+j+1].blue)/9;
        }
       
        dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[i*dim+j-1].red+src[i*dim+j].red+src[(i+1)*dim+j-1].red+src[(i+1)*dim+j].red)/6;
        dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[i*dim+j-1].green+src[i*dim+j].green+src[(i+1)*dim+j-1].green+src[(i+1)*dim+j].green)/6;
        dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[(i+1)*dim+j-1].blue+src[(i+1)*dim+j].blue)/6;
    }
    
    dst[i*dim].red=(src[(i-1)*dim].red+src[(i-1)*dim+1].red+src[i*dim].red+src[i*dim+1].red)/4;
    dst[i*dim].green=(src[(i-1)*dim].green+src[(i-1)*dim+1].green+src[i*dim].green+src[i*dim+1].green)/4;
    dst[i*dim].blue=(src[(i-1)*dim].blue+src[(i-1)*dim+1].blue+src[i*dim].blue+src[i*dim+1].blue)/4;
    
    for(j=1; j<dim-1; j++) {
        dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[(i-1)*dim+j+1].red+src[i*dim+j-1].red+src[i*dim+j].red+src[i*dim+j+1].red)/6;
        dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[(i-1)*dim+j+1].green+src[i*dim+j-1].green+src[i*dim+j].green+src[i*dim+j+1].green)/6;
        dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[(i-1)*dim+j+1].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[i*dim+j+1].blue)/6;
    }
    
    dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[i*dim+j-1].red+src[i*dim+j].red)/4;
    dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[i*dim+j-1].green+src[i*dim+j].green)/4;
    dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[i*dim+j-1].blue+src[i*dim+j].blue)/4;
}

char smooth_descr6[] = "smooth6: ...";
void smooth6(int dim, pixel *src, pixel *dst) {
    
    int i, j, rij;
    int rindex = dim;
    
    dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)>>2;
    dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)>>2;
    dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)>>2;
    dst[dim-1].red = (src[dim-1].red+src[dim-2].red+src[dim*2-1].red+src[dim*2-2].red)>>2;
    dst[dim-1].blue = (src[dim-1].blue+src[dim-2].blue+src[dim*2-1].blue+src[dim*2-2].blue)>>2;
    dst[dim-1].green = (src[dim-1].green+src[dim-2].green+src[dim*2-1].green+src[dim*2-2].green)>>2;
    
    dst[dim*(dim-1)].red = (src[dim*(dim-1)].red+src[dim*(dim-1)+1].red+src[dim*(dim-2)].red+src[dim*(dim-2)+1].red)>>2;
    dst[dim*(dim-1)].blue = (src[dim*(dim-1)].blue+src[dim*(dim-1)+1].blue+src[dim*(dim-2)].blue+src[dim*(dim-2)+1].blue)>>2;
    dst[dim*(dim-1)].green = (src[dim*(dim-1)].green+src[dim*(dim-1)+1].green+src[dim*(dim-2)].green+src[dim*(dim-2)+1].green)>>2;
    
    dst[dim*dim-1].red = (src[dim*dim-1].red+src[dim*dim-2].red+src[dim*(dim-1)-1].red+src[dim*(dim-1)-2].red)>>2;
    dst[dim*dim-1].blue = (src[dim*dim-1].blue+src[dim*dim-2].blue+src[dim*(dim-1)-1].blue+src[dim*(dim-1)-2].blue)>>2;
    dst[dim*dim-1].green = (src[dim*dim-1].green+src[dim*dim-2].green+src[dim*(dim-1)-1].green+src[dim*(dim-1)-2].green)>>2;
    for (j = 1; j < dim-1; j++)
    {
        dst[j].red = (src[j].red+src[j-1].red+src[j+1].red+src[j+dim].red+src[j+1+dim].red+src[j-1+dim].red)/6;
        dst[j].green = (src[j].green+src[j-1].green+src[j+1].green+src[j+dim].green+src[j+1+dim].green+src[j-1+dim].green)/6;
        dst[j].blue = (src[j].blue+src[j-1].blue+src[j+1].blue+src[j+dim].blue+src[j+1+dim].blue+src[j-1+dim].blue)/6;
    }
    for (j = dim*(dim-1)+1; j < dim*dim-1; j++)
    {
        dst[j].red = (src[j].red+src[j-1].red+src[j+1].red+src[j-dim].red+src[j+1-dim].red+src[j-1-dim].red)/6;
        dst[j].green = (src[j].green+src[j-1].green+src[j+1].green+src[j-dim].green+src[j+1-dim].green+src[j-1-dim].green)/6;
        dst[j].blue = (src[j].blue+src[j-1].blue+src[j+1].blue+src[j-dim].blue+src[j+1-dim].blue+src[j-1-dim].blue)/6;
    }
    for (j = dim; j < dim*(dim-1); j+=dim)
    {
        dst[j].red = (src[j].red+src[j-dim].red+src[j+1].red+src[j+dim].red+src[j+1+dim].red+src[j-dim+1].red)/6;
        dst[j].green = (src[j].green+src[j-dim].green+src[j+1].green+src[j+dim].green+src[j+1+dim].green+src[j-dim+1].green)/6;
        dst[j].blue = (src[j].blue+src[j-dim].blue+src[j+1].blue+src[j+dim].blue+src[j+1+dim].blue+src[j-dim+1].blue)/6;
    }
    for (j = dim+dim-1; j < dim*dim-1; j+=dim)
    {
        dst[j].red = (src[j].red+src[j-1].red+src[j-dim].red+src[j+dim].red+src[j-dim-1].red+src[j-1+dim].red)/6;
        dst[j].green = (src[j].green+src[j-1].green+src[j-dim].green+src[j+dim].green+src[j-dim-1].green+src[j-1+dim].green)/6;
        dst[j].blue = (src[j].blue+src[j-1].blue+src[j-dim].blue+src[j+dim].blue+src[j-dim-1].blue+src[j-1+dim].blue)/6;
    }
    for (i = 1; i < dim-1; i++)
    {
        for (j = 1; j < dim-1; j++)
        {
            rij = rindex+j;
            dst[rij].red = (src[rij].red+src[rij-1].red+src[rij+1].red+src[rij-dim].red+src[rij-dim-1].red+src[rij-dim+1].red+src[rij+dim].red+src[rij+dim+1].red+src[rij+dim-1].red)/9;
            dst[rij].green = (src[rij].green+src[rij-1].green+src[rij+1].green+src[rij-dim].green+src[rij-dim-1].green+src[rij-dim+1].green+src[rij+dim].green+src[rij+dim+1].green+src[rij+dim-1].green)/9;
            dst[rij].blue = (src[rij].blue+src[rij-1].blue+src[rij+1].blue+src[rij-dim].blue+src[rij-dim-1].blue+src[rij-dim+1].blue+src[rij+dim].blue+src[rij+dim+1].blue+src[rij+dim-1].blue)/9;
        }
        rindex += dim;
    }
    
}

char smooth_descr7[] = "smooth7: ...";
void smooth7(int dim, pixel *src, pixel *dst)
{
    int i,j;
    
    dst[0].red=(src[0].red+src[dim].red+src[1].red+src[dim+1].red)>>2;
    dst[0].blue=(src[0].blue+src[dim].blue+src[1].blue+src[dim+1].blue)>>2;
    dst[0].green=(src[0].green+src[dim].green+src[1].green+src[dim+1].green)>>2;
    dst[RIDX(0,dim-1,dim)].red=(src[RIDX(0,dim-1,dim)].red+src[RIDX(1,dim-1,dim)].red+src[RIDX(0,dim-2,dim)].red+src[RIDX(1,dim-2,dim)].red)>>2;
    dst[RIDX(0,dim-1,dim)].blue=(src[RIDX(0,dim-1,dim)].blue+src[RIDX(1,dim-1,dim)].blue+src[RIDX(0,dim-2,dim)].blue+src[RIDX(1,dim-2,dim)].blue)>>2;
    dst[RIDX(0,dim-1,dim)].green=(src[RIDX(0,dim-1,dim)].green+src[RIDX(1,dim-1,dim)].green+src[RIDX(0,dim-2,dim)].green+src[RIDX(1,dim-2,dim)].green)>>2;
    dst[RIDX(dim-1,0,dim)].red=(src[RIDX(dim-1,0,dim)].red+src[RIDX(dim-2,0,dim)].red+src[RIDX(dim-1,1,dim)].red+src[RIDX(dim-2,1,dim)].red)>>2;
    dst[RIDX(dim-1,0,dim)].blue=(src[RIDX(dim-1,0,dim)].blue+src[RIDX(dim-2,0,dim)].blue+src[RIDX(dim-1,1,dim)].blue+src[RIDX(dim-2,1,dim)].blue)>>2;
    dst[RIDX(dim-1,0,dim)].green=(src[RIDX(dim-1,0,dim)].green+src[RIDX(dim-2,0,dim)].green+src[RIDX(dim-1,1,dim)].green+src[RIDX(dim-2,1,dim)].green)>>2;
    dst[RIDX(dim-1,dim-1,dim)].red=(src[RIDX(dim-1,dim-1,dim)].red+src[RIDX(dim-1,dim-2,dim)].red+src[RIDX(dim-2,dim-1,dim)].red+src[RIDX(dim-2,dim-2,dim)].red)>>2;
    dst[RIDX(dim-1,dim-1,dim)].blue=(src[RIDX(dim-1,dim-1,dim)].blue+src[RIDX(dim-1,dim-2,dim)].blue+src[RIDX(dim-2,dim-1,dim)].blue+src[RIDX(dim-2,dim-2,dim)].blue)>>2;
    dst[RIDX(dim-1,dim-1,dim)].green=(src[RIDX(dim-1,dim-1,dim)].green+src[RIDX(dim-1,dim-2,dim)].green+src[RIDX(dim-2,dim-1,dim)].green+src[RIDX(dim-2,dim-2,dim)].green)>>2;
    
    for(i=1;i<dim-1;i++){
        int pos=i*dim;
        dst[pos].red=(src[pos].red+src[pos-dim].red+src[pos-dim+1].red+src[pos+1].red+src[pos+dim].red+src[pos+dim+1].red)/6;
        dst[pos].blue=(src[pos].blue+src[pos-dim].blue+src[pos-dim+1].blue+src[pos+1].blue+src[pos+dim].blue+src[pos+dim+1].blue)/6;
        dst[pos].green=(src[pos].green+src[pos-dim].green+src[pos-dim+1].green+src[pos+1].green+src[pos+dim].green+src[pos+dim+1].green)/6;
    }
    for(i=1;i<dim-1;i++){
        int pos=i*dim;
        dst[pos+dim-1].red=(src[pos+dim-1].red+src[pos-1].red+src[pos-2].red+src[pos-2+dim].red+src[pos+dim+dim-1].red+src[pos+dim+dim-2].red)/6;
        dst[pos+dim-1].blue=(src[pos+dim-1].blue+src[pos-1].blue+src[pos-2].blue+src[pos-2+dim].blue+src[pos+dim+dim-1].blue+src[pos+dim+dim-2].blue)/6;
        dst[pos+dim-1].green=(src[pos+dim-1].green+src[pos-1].green+src[pos-2].green+src[pos-2+dim].green+src[pos+dim+dim-1].green+src[pos+dim+dim-2].green)/6;
    }
    for(j=1;j<dim-1;j++){
        int pos=j;
        dst[pos].red=(src[pos].red+src[pos-1].red+src[RIDX(1,j-1,dim)].red+src[RIDX(1,j,dim)].red+src[RIDX(0,j+1,dim)].red+src[RIDX(1,j+1,dim)].red)/6;
        dst[pos].blue=(src[pos].blue+src[pos-1].blue+src[RIDX(1,j-1,dim)].blue+src[RIDX(1,j,dim)].blue+src[RIDX(0,j+1,dim)].blue+src[RIDX(1,j+1,dim)].blue)/6;
        dst[pos].green=(src[pos].green+src[pos-1].green+src[RIDX(1,j-1,dim)].green+src[RIDX(1,j,dim)].green+src[RIDX(0,j+1,dim)].green+src[RIDX(1,j+1,dim)].green)/6;
    }
    for(j=1;j<dim-1;j++){
        int pos=j+dim*(dim-1);
        dst[pos].red=(src[pos].red+src[pos+1].red+src[pos-1].red+src[pos-dim].red+src[pos-dim+1].red+src[pos-dim-1].red)/6;
        dst[pos].blue=(src[pos].blue+src[pos+1].blue+src[pos-1].blue+src[pos-dim].blue+src[pos-dim+1].blue+src[pos-dim-1].blue)/6;
        dst[pos].green=(src[pos].green+src[pos+1].green+src[pos-1].green+src[pos-dim].green+src[pos-dim+1].green+src[pos-dim-1].green)/6;
    }
    
    for(i=1;i<dim-1;i+=2)
        for(j=1;j<dim-1;j++){
            int pos=i*dim+j;
            dst[pos].red=(src[pos].red+src[pos+dim].red+src[pos-dim].red+src[pos-1].red+src[pos+dim-1].red+src[pos-dim-1].red+src[pos+1].red+src[pos+1+dim].red+src[pos+1-dim].red)/9;
            dst[pos].blue=(src[pos].blue+src[pos+dim].blue+src[pos-dim].blue+src[pos-1].blue+src[pos+dim-1].blue+src[pos-dim-1].blue+src[pos+1].blue+src[pos+1+dim].blue+src[pos+1-dim].blue)/9;
            dst[pos].green=(src[pos].green+src[pos+dim].green+src[pos-dim].green+src[pos-1].green+src[pos+dim-1].green+src[pos-dim-1].green+src[pos+1].green+src[pos+1+dim].green+src[pos+1-dim].green)/9;
            pos+=dim;
            dst[pos].red=(src[pos].red+src[pos+dim].red+src[pos-dim].red+src[pos-1].red+src[pos+dim-1].red+src[pos-dim-1].red+src[pos+1].red+src[pos+1+dim].red+src[pos+1-dim].red)/9;
            dst[pos].blue=(src[pos].blue+src[pos+dim].blue+src[pos-dim].blue+src[pos-1].blue+src[pos+dim-1].blue+src[pos-dim-1].blue+src[pos+1].blue+src[pos+1+dim].blue+src[pos+1-dim].blue)/9;
            dst[pos].green=(src[pos].green+src[pos+dim].green+src[pos-dim].green+src[pos-1].green+src[pos+dim-1].green+src[pos-dim-1].green+src[pos+1].green+src[pos+1+dim].green+src[pos+1-dim].green)/9;
        }
}

char smooth_descr8[] = "smooth8: ... ";
void smooth8(int dim, pixel *src, pixel *dst)
{
    int i,j;
    pixel *pixelA,*pixelB,*pixelC;
    int size = dim-1;
  
    
    pixelB = src;
    pixelC = pixelB + dim;
    dst->red = (pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)>>2;
    dst->green = (pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)>>2;
    dst->blue = (pixelB->blue + (pixelB+1)->blue + pixelC->blue + (pixelC+1)->blue)>>2;
    pixelB++;
    pixelC++;
    dst++;
  
    
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/6;
        dst->green = (pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/6;
        dst->blue = (pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/6;
        pixelB++;
        pixelC++;
        dst++;
    }
  
    
    dst->red = (pixelC->red + (pixelC-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelC->green + (pixelC-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelC->blue + (pixelC-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
    dst++;
  
    
  
    pixelA = src;
    pixelB = pixelA + dim;
    pixelC = pixelB + dim;
    for(i = 1; i < size; i++)
    {
        
        dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)/6;
        dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue + pixelC->blue+ (pixelC+1)->blue)/6;
        dst++;
        pixelA++;
        pixelB++;
        pixelC++;
        
        for(j = 1; j < dim-1; j++)
        {
            dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/9;
            dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/9;
            dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/9;
            pixelA++;
            pixelB++;
            pixelC++;
            dst++;
        }
        
        dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red + pixelC->red + (pixelC-1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green + pixelC->green + (pixelC-1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue + pixelC->blue+ (pixelC-1)->blue)/6;
        pixelA++;
        pixelB++;
        pixelC++;
        dst++;
    }
  
    
    dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red)>>2;
    dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue)>>2;
    dst++;
    pixelA++;
    pixelB++;
      
    
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue)/6;
        pixelA++;
        pixelB++;
        dst++;
    }
  
    
    dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
  
    
}

char smooth_descr9[] = "smooth9: ... ";
void smooth9(int dim, pixel *src, pixel *dst)
{
    int i, j, tmp, tmpi;

    
    dst[0].red = (src[0].red + src[1].red + src[dim].red + src[dim + 1].red) >> 2;
    dst[0].blue = (src[0].blue + src[1].blue + src[dim].blue + src[dim + 1].blue) >> 2;
    dst[0].green = (src[0].green + src[1].green + src[dim].green + src[dim + 1].green) >> 2;
    
    dst[dim - 1].red = (src[dim - 1].red + src[dim - 2].red +
                        src[dim * 2 - 1].red + src[dim * 2 - 2].red) >> 2;
    dst[dim - 1].blue = (src[dim - 1].blue + src[dim - 2].blue +
                         src[dim * 2 - 1].blue + src[dim * 2 - 2].blue) >> 2;
    dst[dim - 1].green = (src[dim - 1].green + src[dim - 2].green +
                          src[dim * 2 - 1].green + src[dim * 2 - 2].green) >> 2;
    
    dst[dim * (dim - 1)].red = (src[dim * (dim - 1)].red + src[dim * (dim - 1) + 1].red +
                                src[dim * (dim - 2)].red + src[dim * (dim - 2) + 1].red) >> 2;
    dst[dim * (dim - 1)].blue = (src[dim * (dim - 1)].blue + src[dim * (dim - 1) + 1].blue +
                                 src[dim * (dim - 2)].blue + src[dim * (dim - 2) + 1].blue) >> 2;
    dst[dim * (dim - 1)].green = (src[dim * (dim - 1)].green + src[dim * (dim - 1) + 1].green +
                                  src[dim * (dim - 2)].green + src[dim * (dim - 2) + 1].green) >> 2;
    
    dst[dim * dim - 1].red = (src[dim * dim - 1].red + src[dim * dim - 2].red +
                              src[dim * (dim - 1) - 1].red + src[dim * (dim - 1) - 2].red) >> 2;
    dst[dim * dim - 1].blue = (src[dim * dim - 1].blue + src[dim * dim - 2].blue +
                               src[dim * (dim - 1) - 1].blue + src[dim * (dim - 1) - 2].blue) >> 2;
    dst[dim * dim - 1].green = (src[dim * dim - 1].green + src[dim * dim - 2].green +
                                src[dim * (dim - 1) - 1].green + src[dim * (dim - 1) - 2].green) >> 2;
    
    for (j = 1; j < dim - 1; j++)
    {
        dst[j].red = (src[j].red + src[j - 1].red + src[j + 1].red +
                      src[j + dim].red + src[j + 1 + dim].red + src[j - 1 + dim].red) / 6;
        dst[j].blue = (src[j].blue + src[j - 1].blue + src[j + 1].blue +
                       src[j + dim].blue + src[j + 1 + dim].blue + src[j - 1 + dim].blue) / 6;
        dst[j].green = (src[j].green + src[j - 1].green + src[j + 1].green +
                        src[j + dim].green + src[j + 1 + dim].green + src[j - 1 + dim].green) / 6;
    }
    
    for (j = dim * (dim - 1) + 1; j < dim * dim - 1; j++)
    {
        dst[j].red = (src[j].red + src[j - 1].red + src[j + 1].red +
                      src[j - dim].red + src[j + 1 - dim].red + src[j - 1 - dim].red) / 6;
        dst[j].blue = (src[j].blue + src[j - 1].blue + src[j + 1].blue +
                       src[j - dim].blue + src[j + 1 - dim].blue + src[j - 1 - dim].blue) / 6;
        dst[j].green = (src[j].green + src[j - 1].green + src[j + 1].green +
                        src[j - dim].green + src[j + 1 - dim].green + src[j - 1 - dim].green) / 6;
    }
    
    for (j = dim; j < dim * (dim - 1); j += dim)
    {
        dst[j].red = (src[j].red + src[j - dim].red + src[j + 1].red +
                      src[j + dim].red + src[j + 1 + dim].red + src[j - dim + 1].red) / 6;
        dst[j].blue = (src[j].blue + src[j - dim].blue + src[j + 1].blue +
                       src[j + dim].blue + src[j + 1 + dim].blue + src[j - dim + 1].blue) / 6;
        dst[j].green = (src[j].green + src[j - dim].green + src[j + 1].green +
                        src[j + dim].green + src[j + 1 + dim].green + src[j - dim + 1].green) / 6;
    }
    
    for (j = dim + dim - 1; j < dim * dim - 1; j += dim)
    {
        dst[j].red = (src[j].red + src[j - 1].red + src[j - dim].red +
                      src[j + dim].red + src[j - dim - 1].red + src[j - 1 + dim].red) / 6;
        dst[j].blue = (src[j].blue + src[j - 1].blue + src[j - dim].blue +
                       src[j + dim].blue + src[j - dim - 1].blue + src[j - 1 + dim].blue) / 6;
        dst[j].green = (src[j].green + src[j - 1].green + src[j - dim].green +
                        src[j + dim].green + src[j - dim - 1].green + src[j - 1 + dim].green) / 6;
    }
    
    tmpi = dim;
    for (i = 1; i < dim - 1; i++)
    {
        for (j = 1; j < dim - 1; j++)
        {
            tmp = tmpi + j;
            dst[tmp].red = (src[tmp].red + src[tmp - 1].red + src[tmp + 1].red + src[tmp - dim].red + src[tmp - dim - 1].red +
                            src[tmp - dim + 1].red + src[tmp + dim].red + src[tmp + dim + 1].red + src[tmp + dim - 1].red) / 9;
            dst[tmp].green = (src[tmp].green + src[tmp - 1].green + src[tmp + 1].green + src[tmp - dim].green + src[tmp - dim - 1].green +
                              src[tmp - dim + 1].green + src[tmp + dim].green + src[tmp + dim + 1].green + src[tmp + dim - 1].green) / 9;
            dst[tmp].blue = (src[tmp].blue + src[tmp - 1].blue + src[tmp + 1].blue + src[tmp - dim].blue + src[tmp - dim - 1].blue +
                             src[tmp - dim + 1].blue + src[tmp + dim].blue + src[tmp + dim + 1].blue + src[tmp + dim - 1].blue) / 9;
        }
        tmpi += dim;
    }
}

/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&smooth2, smooth_descr2);
    add_smooth_function(&smooth3, smooth_descr3);
    add_smooth_function(&smooth4, smooth_descr4);
    add_smooth_function(&smooth5, smooth_descr5);
    add_smooth_function(&smooth6, smooth_descr6);
    add_smooth_function(&smooth7, smooth_descr7);
    add_smooth_function(&smooth8, smooth_descr8);
    add_smooth_function(&smooth9, smooth_descr9);
    /* ... Register additional test functions here */
}

