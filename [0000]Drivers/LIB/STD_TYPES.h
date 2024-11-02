/*
 * STD_TYPES.h
 *
 *  Author: Khalid Metwally
 *   Layer: LIB
 *
 */ 
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* 
	8  : char		[1B]
	16 : short		[2B]
	32 : long		[4B]
	64 : long long	[8B]
	f32: float		[4B]
	f64: double		[8B]
	u  : unsigned	[-2^(n-1) : 2^(n-1)-1]
	s  : signed		[	 0	  : 2^(n)-1  ]
*/
typedef unsigned char			u8	;
typedef unsigned short int		u16	;
typedef unsigned long int		u32	;
typedef unsigned long long int	u64	;
typedef signed char				s8	;
typedef signed short int		s16	;
typedef signed long int			s32	;
typedef signed long long int	s64	;
typedef float					f32	;
typedef double					f64	;

typedef enum
		{
			false = 0,
			true,
		}bool;
#define NULL 0
		
/* Functions States */
#define IDLE 0
#define BUSY 1

/* Personal States */
#define OK				0
#define NOK				1
#define NULL_POINTER	2
#define BUSY_STATE		3
#define	TIMEOUT_STATE	4

#endif /*STD_TYPES_H_*/
