/* A lexical scanner generated by flex */

/* scanner skeleton version:
 * $Header: /usr/fsys/odin/a/vern/flex/RCS/flex.skel,v 2.16 90/08/03 14:09:36 vern Exp $
 */

#define FLEX_SCANNER

#include <stdio.h>

void *malloc( size_t );
void free( void* );

/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <stdlib.h>
#include <osfcn.h>

/* use prototypes in function declarations */
#define YY_USE_PROTOS

/* the "const" storage-class-modifier is valid */
#define YY_USE_CONST

#else	/* ! __cplusplus */

#ifdef __STDC__

#ifdef __GNUC__
#include <stddef.h>
#else
#include <stdlib.h>
#endif	/* __GNUC__ */

#define YY_USE_PROTOS
#define YY_USE_CONST

#endif	/* __STDC__ */
#endif	/* ! __cplusplus */


#ifdef __TURBOC__
#define YY_USE_CONST
#endif

#ifdef atarist
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define YY_INPUT(buf,result,max_size) \
	if ( (result = _yyread( fileno(mtxFile), (char *) buf, max_size )) < 0 ) \
	    YY_FATAL_ERROR( "read() in flex scanner failed" );
#endif


#ifndef YY_USE_CONST
#define const
#endif


#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
/* we can't get here if it's an ANSI C compiler, or a C++ compiler,
 * so it's got to be a K&R compiler, and therefore there's no standard
 * place from which to include these definitions
 */
int read();
#endif


/* amount of stuff to slurp up with each read */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* returned upon end-of-file */
#define YY_END_TOK 0

/* copy whatever the last rule matched to the standard output */

/* cast to (char *) is because for 8-bit chars, yytext is (unsigned char *) */
/* this used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite()
 */
#define ECHO (void) fwrite( (char *) yytext, yyleng, 1, yyout )

/* gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = read( fileno(mtxFile), (char *) buf, max_size )) < 0 ) \
	    YY_FATAL_ERROR( "read() in flex scanner failed" );
#endif
#define YY_NULL 0

/* no semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#define yyterminate() return ( YY_NULL )

/* report a fatal error */

/* The funky do-while is used to turn this macro definition into
 * a single C statement (which needs a semi-colon terminator).
 * This avoids problems with code like:
 *
 * 	if ( something_happens )
 *		YY_FATAL_ERROR( "oops, the something happened" );
 *	else
 *		everything_okay();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the YY_FATAL_ERROR() call.
 */

#define YY_FATAL_ERROR(msg) \
	do \
		{ \
		(void) fputs( msg, stderr ); \
		(void) putc( '\n', stderr ); \
		PauseAndGo(1); \
		} \
	while ( 0 )

/* default yywrap function - always treat EOF as an EOF */
#define yywrap() 1

/* enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN
 */
#define BEGIN yy_start = 1 + 2 *

/* action number for EOF rule of a given start state */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* special action meaning "start processing a new file" */
#define YY_NEW_FILE \
	do \
		{ \
		yy_init_buffer( yy_current_buffer, mtxFile ); \
		yy_load_buffer_state(); \
		} \
	while ( 0 )

/* default declaration of generated scanner - a define so the user can
 * easily add parameters
 */
#define YY_DECL int yylex YY_PROTO(( void )) 

/* code executed at the end of each rule */
#define YY_BREAK break;

#define YY_END_OF_BUFFER_CHAR 0

#ifndef YY_BUF_SIZE
#define YY_BUF_SIZE (YY_READ_BUF_SIZE * 2) /* size of default input buffer */
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;

#define YY_CHAR char
# line 1 "t2mf.fl"
#define INITIAL 0
/* $Id: t2mf.fl,v 1.3 1991/11/15 19:31:00 piet Rel $ */
# line 4 "t2mf.fl"

#include "Mtx2Midi.h"

#ifdef NO_YYLENG_VAR
int yylength;
#define YY_USER_ACTION	yylength = yyleng
#endif

int do_hex = 0;
int eol_seen = 0;
int lineno = 1;
long yyval;
long bankno();

#define QUOTE 1
#define HEX 2
# line 24 "t2mf.fl"

/* done after the current pattern has been matched and before the
 * corresponding action - sets up yytext
 */
#define YY_DO_BEFORE_ACTION \
	yytext = yy_bp; \
	yytext -= yy_more_len; \
	yyleng = yy_cp - yytext; \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* return all but the first 'n' matched characters back to the input stream */
#define yyless(n) \
	do \
		{ \
		/* undo effects of setting up yytext */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext )


struct yy_buffer_state
    {
    FILE *yy_input_file;

    YY_CHAR *yy_ch_buf;		/* input buffer */
    YY_CHAR *yy_buf_pos;	/* current position in input buffer */

    /* size of input buffer in bytes, not including room for EOB characters*/
    int yy_buf_size;	

    /* number of characters read into yy_ch_buf, not including EOB characters */
    int yy_n_chars;

    int yy_eof_status;		/* whether we've seen an EOF on this buffer */
#define EOF_NOT_SEEN 0
    /* "pending" happens when the EOF has been seen but there's still
     * some text process
     */
#define EOF_PENDING 1
#define EOF_DONE 2
    };

static YY_BUFFER_STATE yy_current_buffer;

/* we provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state"
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed */
static YY_CHAR yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */



#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

#ifndef YY_USER_INIT
#define YY_USER_INIT
#endif

extern YY_CHAR *yytext;
extern int yyleng;
extern FILE *mtxFile, *yyout;

YY_CHAR *yytext;
int yyleng;

FILE *mtxFile = (FILE *) 0, *yyout = (FILE *) 0;

#define YY_END_OF_BUFFER 56
typedef int yy_state_type;
static const short int yy_accept[185] =
    {   0,
        0,    0,   43,   43,    0,    0,   56,   53,    1,   49,
       42,   53,   53,   53,   29,   37,   37,   53,   52,   52,
       52,   52,   52,   52,   52,   52,   52,   52,   52,   52,
       52,   52,   43,   46,   44,   55,   51,    1,   42,   51,
       40,   51,   51,    0,    2,   39,   37,    0,    0,   48,
        0,   41,   52,   52,   52,   35,   52,   52,   52,   52,
       52,   52,   52,   52,   52,   52,   52,   33,   52,   52,
        6,   36,   52,   10,   52,   52,   52,   52,   52,   52,
       52,   52,   34,   52,   43,   45,   40,   50,   38,   28,
       32,   52,   52,   52,   52,   22,   52,   52,   52,   52,

       52,   52,   52,   52,   52,   52,    7,    9,   52,   52,
       52,   52,   52,   52,   52,   52,   52,   52,   52,   52,
       52,   12,   52,   52,   52,   52,   52,   52,   14,   52,
       52,    4,   52,   52,   52,    8,   11,   52,   52,   52,
       52,   52,   52,   16,   52,   52,   52,   52,   52,   52,
       20,   31,   52,    3,   30,    9,   52,   23,   52,   27,
       13,   25,   52,   52,   52,   52,   52,   24,   21,   52,
       52,   52,    5,   52,   52,   52,   18,   15,   26,   52,
       52,   17,   19,    0
    } ;

static const YY_CHAR yy_ec[128] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    2,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    4,    5,    6,    1,    1,    1,    1,
        1,    1,    7,    1,    7,    1,    8,    9,   10,   10,
       10,   10,   10,   10,   10,   10,   11,    8,    1,    1,
       12,    1,    1,    1,   14,   15,   16,   17,   18,   19,
       20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
       30,   31,   32,   33,   34,   35,   36,   37,   38,   36,
        1,   13,    1,    1,    1,    1,   14,   15,   16,   17,

       18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
       28,   29,   30,   31,   32,   33,   34,   35,   36,   37,
       38,   36,    1,    1,    1,    1,    1
    } ;

static const short int yy_base[194] =
    {   0,
        0,    0,   36,   38,   51,    0,  495,  496,  496,  496,
      496,  491,    0,   34,  496,   81,   37,   91,  114,  141,
       83,   91,  466,  474,  453,   94,   87,   78,  116,   88,
      118,  125,    0,  496,  496,    0,  496,  496,  496,  487,
        0,  107,    0,  486,  496,    0,  123,    0,  139,  496,
      148,  151,    0,  154,  473,  496,  154,   93,  469,  454,
      447,  453,  112,  450,  460,  454,  449,  496,  446,  459,
        0,  496,  446,    0,   78,  139,  446,  446,  442,  143,
      447,  448,  496,  446,    0,  496,  496,    0,    0,    0,
      496,  443,  438,  456,  429,    0,  433,  433,  442,  435,

      438,  447,  435,  431,  434,  439,    0,  442,  417,  423,
      432,  432,  143,  418,  432,  420,  415,  429,  154,  434,
      416,    0,  413,  412,  420,  425,  409,  421,    0,  420,
      406,    0,  424,  409,  405,    0,    0,  161,  140,  404,
      414,  394,  402,    0,  397,  395,  407,  364,  358,  298,
        0,    0,  278,    0,    0,    0,  282,    0,  262,    0,
        0,    0,  257,  258,  247,  243,  248,    0,    0,  243,
      166,  159,    0,  160,  155,  148,    0,    0,    0,  105,
       32,    0,    0,  496,  183,  221,  250,  267,  305,  343,
      373,  379,  409

    } ;

static const short int yy_def[194] =
    {   0,
      184,    1,  185,  185,  184,    5,  184,  184,  184,  184,
      184,  186,  187,  184,  184,  184,  184,  184,  188,  188,
       20,  188,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,  189,  184,  184,  190,  184,  184,  184,  186,
      191,  184,  192,  186,  184,  187,  184,  193,  184,  184,
      184,  184,   22,   22,   22,  184,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,  184,   22,   22,
       22,  184,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,  184,   22,  189,  184,  184,  192,  193,   22,
      184,   22,   22,   22,   22,   22,   22,   22,   22,   22,

       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
       22,   22,   22,    0,  184,  184,  184,  184,  184,  184,
      184,  184,  184

    } ;

static const short int yy_nxt[535] =
    {   0,
        8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
       17,    8,   18,   19,   20,   21,   20,   20,   20,   20,
       22,   23,   22,   24,   25,   26,   27,   28,   29,   22,
       22,   30,   31,   22,   32,   22,   22,   22,   34,   35,
       34,   35,   47,   47,   47,   47,   47,   47,   36,  183,
       36,   37,   38,   10,   39,   40,   37,   37,   37,   41,
       41,   41,   37,   42,   41,   41,   41,   41,   41,   41,
       43,   43,   43,   43,   43,   43,   43,   43,   43,   43,
       43,   43,   43,   43,   43,   43,   43,   43,   43,   47,
       47,   47,   49,   50,   56,  184,   70,  184,   68,  184,

      184,  184,  109,   57,   71,   77,  110,   63,   49,   50,
       58,   64,   65,   78,   69,   66,   59,   48,   51,   94,
       51,   95,   52,   52,   52,   79,   67,   72,   54,   73,
       74,   47,   47,   47,  100,   80,   83,  182,   84,   81,
       49,   50,  101,   75,   55,   51,   76,   51,   82,   52,
       52,   52,   84,  157,  111,   54,   52,   52,   52,   52,
       52,   52,   52,   52,   52,   91,  112,   92,  116,  139,
      158,  146,   72,  181,  140,  180,  111,  177,  179,  117,
      147,  178,   93,   33,   33,   33,   33,   33,   33,   33,
       33,   33,   33,   33,   33,   33,   33,   33,   33,   33,

       33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
       33,   33,   33,   33,   33,   33,   33,   33,   33,   33,
       33,   44,   44,   44,   44,   44,   44,   44,   44,   44,
       44,   44,   44,   44,   44,   44,   44,   44,   44,   44,
       44,   44,   44,   44,   44,   44,   44,   44,   44,   44,
       44,   44,   44,   44,   44,   44,   44,   44,   44,   46,
      177,  176,  175,   46,   46,   46,   46,   46,   46,   46,
       46,   53,  174,   53,  173,   53,   53,   53,  172,  171,
       53,   53,   53,   53,   53,   53,   53,   53,   53,   53,
       53,   53,   53,   53,   53,   53,   53,   53,   53,   53,

       53,   53,   53,   53,   53,   85,   85,  170,  169,   85,
       85,   85,   85,   85,   85,   85,   85,  168,   85,   85,
       85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
       85,   85,   85,   85,   85,   85,   85,   85,   85,   85,
       85,   85,   85,   86,   86,   86,   86,   86,   86,   86,
       86,   86,   86,   86,   86,   86,   86,   86,   86,   86,
       86,   86,   86,   86,   86,   86,   86,   86,   86,   86,
       86,   86,   86,   86,   86,   86,   86,   86,   86,   86,
       86,   87,   87,   87,  167,  166,   87,   87,   87,   87,
       87,   87,   88,   88,   88,   88,   88,   88,   88,   88,

       88,   88,   88,   88,   88,   88,   88,   88,   88,   88,
       88,   88,   88,   88,   88,   88,   88,   89,   89,   89,
      165,  164,   89,   89,   89,   89,   89,   89,  163,  162,
      161,  160,  159,  110,  156,   68,  155,  154,  153,  152,
      151,  150,  149,  148,   93,   83,  145,  144,  143,  142,
      141,  138,  137,  136,  135,  134,  133,  132,  131,  130,
      129,  128,  127,  126,  125,  124,  123,   56,  122,  121,
      120,  119,  118,  115,  114,  113,  108,  107,  106,  105,
      104,  103,  102,   99,   98,   97,   96,   90,   45,   45,
       62,   61,   60,   45,  184,    7,  184,  184,  184,  184,

      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184
    } ;

static const short int yy_chk[535] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    3,    3,
        4,    4,   14,   14,   14,   17,   17,   17,    3,  181,
        4,    5,    5,    5,    5,    5,    5,    5,    5,    5,
        5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
        5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
        5,    5,    5,    5,    5,    5,    5,    5,    5,   16,
       16,   16,   18,   18,   21,   22,   28,   22,   27,   22,

       22,   22,   75,   21,   28,   30,   75,   26,   42,   42,
       21,   26,   26,   30,   27,   26,   21,   16,   19,   58,
       19,   58,   19,   19,   19,   30,   26,   29,   19,   29,
       29,   47,   47,   47,   63,   31,   32,  180,   32,   31,
       49,   49,   63,   29,   19,   20,   29,   20,   31,   20,
       20,   20,   32,  139,   76,   20,   51,   51,   51,   52,
       52,   52,   54,   54,   54,   57,   76,   57,   80,  113,
      139,  119,  138,  176,  113,  175,  138,  174,  172,   80,
      119,  171,   57,  185,  185,  185,  185,  185,  185,  185,
      185,  185,  185,  185,  185,  185,  185,  185,  185,  185,

      185,  185,  185,  185,  185,  185,  185,  185,  185,  185,
      185,  185,  185,  185,  185,  185,  185,  185,  185,  185,
      185,  186,  186,  186,  186,  186,  186,  186,  186,  186,
      186,  186,  186,  186,  186,  186,  186,  186,  186,  186,
      186,  186,  186,  186,  186,  186,  186,  186,  186,  186,
      186,  186,  186,  186,  186,  186,  186,  186,  186,  187,
      170,  167,  166,  187,  187,  187,  187,  187,  187,  187,
      187,  188,  165,  188,  164,  188,  188,  188,  163,  159,
      188,  188,  188,  188,  188,  188,  188,  188,  188,  188,
      188,  188,  188,  188,  188,  188,  188,  188,  188,  188,

      188,  188,  188,  188,  188,  189,  189,  157,  153,  189,
      189,  189,  189,  189,  189,  189,  189,  150,  189,  189,
      189,  189,  189,  189,  189,  189,  189,  189,  189,  189,
      189,  189,  189,  189,  189,  189,  189,  189,  189,  189,
      189,  189,  189,  190,  190,  190,  190,  190,  190,  190,
      190,  190,  190,  190,  190,  190,  190,  190,  190,  190,
      190,  190,  190,  190,  190,  190,  190,  190,  190,  190,
      190,  190,  190,  190,  190,  190,  190,  190,  190,  190,
      190,  191,  191,  191,  149,  148,  191,  191,  191,  191,
      191,  191,  192,  192,  192,  192,  192,  192,  192,  192,

      192,  192,  192,  192,  192,  192,  192,  192,  192,  192,
      192,  192,  192,  192,  192,  192,  192,  193,  193,  193,
      147,  146,  193,  193,  193,  193,  193,  193,  145,  143,
      142,  141,  140,  135,  134,  133,  131,  130,  128,  127,
      126,  125,  124,  123,  121,  120,  118,  117,  116,  115,
      114,  112,  111,  110,  109,  108,  106,  105,  104,  103,
      102,  101,  100,   99,   98,   97,   95,   94,   93,   92,
       84,   82,   81,   79,   78,   77,   73,   70,   69,   67,
       66,   65,   64,   62,   61,   60,   59,   55,   44,   40,
       25,   24,   23,   12,    7,  184,  184,  184,  184,  184,

      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184,  184,  184,  184,  184,  184,  184,
      184,  184,  184,  184
    } ;

static yy_state_type yy_last_accepting_state;
static YY_CHAR *yy_last_accepting_cpos;

/* the intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed
 */
#define REJECT reject_used_but_not_detected
static int yy_more_flag = 0;
static int yy_doing_yy_more = 0;
static int yy_more_len = 0;
#define yymore() { yy_more_flag = 1; }
#define YY_MORE_ADJ (yy_doing_yy_more ? yy_more_len : 0)

/* these variables are all declared out here so that section 3 code can
 * manipulate them
 */
/* points to current character in buffer */
static YY_CHAR *yy_c_buf_p = (YY_CHAR *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh mtxFile.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( void ));
static void yyunput YY_PROTO(( YY_CHAR c, YY_CHAR *buf_ptr ));
void yyrestart YY_PROTO(( FILE *input_file ));
void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
void yy_load_buffer_state YY_PROTO(( void ));
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));

#define yy_new_buffer yy_create_buffer

#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif

YY_DECL
    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp, *yy_bp;
    register int yy_act;


	if (do_hex) {
		BEGIN(HEX);
		do_hex = 0;
	}
	eol_seen = 0;
		

    if ( yy_init )
	{
	YY_USER_INIT;

	if ( ! yy_start )
	    yy_start = 1;	/* first start state */

	if ( ! mtxFile )
	    mtxFile = stdin;

	if ( ! yyout )
	    yyout = stdout;

	if ( yy_current_buffer )
	    yy_init_buffer( yy_current_buffer, mtxFile );
	else
	    yy_current_buffer = yy_create_buffer( mtxFile, YY_BUF_SIZE );

	yy_load_buffer_state();

	yy_init = 0;
	}

    while ( 1 )		/* loops until end-of-file is reached */
	{
	yy_more_len = 0;
	yy_doing_yy_more = yy_more_flag;
	if ( yy_doing_yy_more )
	    {
	    yy_more_len = yyleng;
	    yy_more_flag = 0;
	    }
	yy_cp = yy_c_buf_p;

	/* support of yytext */
	*yy_cp = yy_hold_char;

	/* yy_bp points to the position in yy_ch_buf of the start of the
	 * current run.
	 */
	yy_bp = yy_cp;

	yy_current_state = yy_start;
yy_match:
	do
	    {
	    register YY_CHAR yy_c = yy_ec[*yy_cp];
	    if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = yy_def[yy_current_state];
		}
	    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	    ++yy_cp;
	    }
	while ( yy_current_state != 184 );
	yy_cp = yy_last_accepting_cpos;
	yy_current_state = yy_last_accepting_state;

yy_find_action:
	yy_act = yy_accept[yy_current_state];

	YY_DO_BEFORE_ACTION;
	YY_USER_ACTION;

do_action:	/* this label is used only to access EOF actions */


	switch ( yy_act )
	    {
	    case 0: /* must backtrack */
	    /* undo the effects of YY_DO_BEFORE_ACTION */
	    *yy_cp = yy_hold_char;
	    yy_cp = yy_last_accepting_cpos;
	    yy_current_state = yy_last_accepting_state;
	    goto yy_find_action;

case 1:
# line 31 "t2mf.fl"
/* skip whitespace */;
	YY_BREAK
case 2:
# line 32 "t2mf.fl"
/* skip comment */ lineno++;
	YY_BREAK
case 3:
# line 34 "t2mf.fl"
return MTHD;
	YY_BREAK
case 4:
# line 35 "t2mf.fl"
return MTRK;
	YY_BREAK
case 5:
# line 36 "t2mf.fl"
return TRKEND;
	YY_BREAK
case 6:
# line 38 "t2mf.fl"
return ON;
	YY_BREAK
case 7:
# line 39 "t2mf.fl"
return OFF;
	YY_BREAK
case 8:
# line 40 "t2mf.fl"
return POPR;
	YY_BREAK
case 9:
# line 41 "t2mf.fl"
return PAR;
	YY_BREAK
case 10:
# line 42 "t2mf.fl"
return PB;
	YY_BREAK
case 11:
# line 43 "t2mf.fl"
return PRCH;
	YY_BREAK
case 12:
# line 44 "t2mf.fl"
return CHPR;
	YY_BREAK
case 13:
# line 45 "t2mf.fl"
return SYSEX;
	YY_BREAK
case 14:
# line 46 "t2mf.fl"
return META;
	YY_BREAK
case 15:
# line 47 "t2mf.fl"
return SEQSPEC;
	YY_BREAK
case 16:
# line 48 "t2mf.fl"
return MTEXT;
	YY_BREAK
case 17:
# line 49 "t2mf.fl"
return COPYRIGHT;
	YY_BREAK
case 18:
# line 50 "t2mf.fl"
return SEQNAME;
	YY_BREAK
case 19:
# line 51 "t2mf.fl"
return INSTRNAME;
	YY_BREAK
case 20:
# line 52 "t2mf.fl"
return LYRIC;
	YY_BREAK
case 21:
# line 53 "t2mf.fl"
return MARKER;
	YY_BREAK
case 22:
# line 54 "t2mf.fl"
return CUE;
	YY_BREAK
case 23:
# line 55 "t2mf.fl"
return SEQNR;
	YY_BREAK
case 24:
# line 56 "t2mf.fl"
return KEYSIG;
	YY_BREAK
case 25:
# line 57 "t2mf.fl"
return TEMPO;
	YY_BREAK
case 26:
# line 58 "t2mf.fl"
return TIMESIG;
	YY_BREAK
case 27:
# line 59 "t2mf.fl"
return SMPTE;
	YY_BREAK
case 28:
# line 60 "t2mf.fl"
return ARB;
	YY_BREAK
case 29:
# line 61 "t2mf.fl"
return '/';
	YY_BREAK
case 30:
# line 63 "t2mf.fl"
return MINOR;
	YY_BREAK
case 31:
# line 64 "t2mf.fl"
return MAJOR;
	YY_BREAK
case 32:
# line 66 "t2mf.fl"
return CH;
	YY_BREAK
case 33:
# line 67 "t2mf.fl"
return NOTE;
	YY_BREAK
case 34:
# line 68 "t2mf.fl"
return VAL;
	YY_BREAK
case 35:
# line 69 "t2mf.fl"
return CON;
	YY_BREAK
case 36:
# line 70 "t2mf.fl"
return PROG;
	YY_BREAK
case 37:
# line 72 "t2mf.fl"
sscanf (yytext, "%ld", &yyval); return INT;
	YY_BREAK
case 38:
# line 73 "t2mf.fl"
sscanf (yytext+2, "%lx", &yyval); return INT;
	YY_BREAK
case 39:
# line 74 "t2mf.fl"
yyval = bankno (yytext+1, yyleng-1); return INT;
	YY_BREAK
case 40:
# line 75 "t2mf.fl"
sscanf (yytext, "%lx", &yyval); return INT;
	YY_BREAK
case 41:
# line 77 "t2mf.fl"
return NOTEVAL;
	YY_BREAK
case 42:
# line 79 "t2mf.fl"
BEGIN (QUOTE);
	YY_BREAK
case 43:
# line 80 "t2mf.fl"
yymore();
	YY_BREAK
case 44:
# line 81 "t2mf.fl"
BEGIN (0); return STRING;
	YY_BREAK
case 45:
# line 82 "t2mf.fl"
yymore();
	YY_BREAK
case 46:
# line 83 "t2mf.fl"
{ fprintf(stderr, "unterminated string");
			  lineno++; eol_seen++; BEGIN(0); return EOL;
			}
	YY_BREAK
case YY_STATE_EOF(QUOTE):
# line 86 "t2mf.fl"
fprintf(stderr, "EOF in string"); return EOF;
	YY_BREAK
case 48:
# line 88 "t2mf.fl"
lineno++;
	YY_BREAK
case 49:
# line 89 "t2mf.fl"
lineno++; eol_seen++; BEGIN(0); return EOL;
	YY_BREAK
case 50:
# line 91 "t2mf.fl"
BEGIN (0); return ERR;
	YY_BREAK
case 51:
# line 92 "t2mf.fl"
BEGIN (0); return ERR;
	YY_BREAK
case 52:
# line 93 "t2mf.fl"
return ERR;
	YY_BREAK
case 53:
# line 94 "t2mf.fl"
return ERR;
	YY_BREAK
case YY_STATE_EOF(INITIAL):
case YY_STATE_EOF(HEX):
# line 96 "t2mf.fl"
return EOF;
	YY_BREAK
case 55:
# line 98 "t2mf.fl"
YY_FATAL_ERROR( "flex scanner jammed" );
	YY_BREAK

	    case YY_END_OF_BUFFER:
		{
		/* amount of text matched not including the EOB char */
		int yy_amount_of_matched_text = yy_cp - yytext - 1;

		/* undo the effects of YY_DO_BEFORE_ACTION */
		*yy_cp = yy_hold_char;

		/* note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the end-
		 * of-buffer state).  Contrast this with the test in yyinput().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
		    /* this was really a NUL */
		    {
		    yy_state_type yy_next_state;

		    yy_c_buf_p = yytext + yy_amount_of_matched_text;

		    yy_current_state = yy_get_previous_state();

		    /* okay, we're now positioned to make the
		     * NUL transition.  We couldn't have
		     * yy_get_previous_state() go ahead and do it
		     * for us because it doesn't know how to deal
		     * with the possibility of jamming (and we
		     * don't want to build jamming into it because
		     * then it will run more slowly)
		     */

		    yy_next_state = yy_try_NUL_trans( yy_current_state );

		    yy_bp = yytext + YY_MORE_ADJ;

		    if ( yy_next_state )
			{
			/* consume the NUL */
			yy_cp = ++yy_c_buf_p;
			yy_current_state = yy_next_state;
			goto yy_match;
			}

		    else
			{
			    yy_cp = yy_last_accepting_cpos;
			    yy_current_state = yy_last_accepting_state;
			goto yy_find_action;
			}
		    }

		else switch ( yy_get_next_buffer() )
		    {
		    case EOB_ACT_END_OF_FILE:
			{
			yy_did_buffer_switch_on_eof = 0;

			if ( yywrap() )
			    {
			    /* note: because we've taken care in
			     * yy_get_next_buffer() to have set up yytext,
			     * we can now set up yy_c_buf_p so that if some
			     * total hoser (like flex itself) wants
			     * to call the scanner after we return the
			     * YY_NULL, it'll still work - another YY_NULL
			     * will get returned.
			     */
			    yy_c_buf_p = yytext + YY_MORE_ADJ;

			    yy_act = YY_STATE_EOF((yy_start - 1) / 2);
			    goto do_action;
			    }

			else
			    {
			    if ( ! yy_did_buffer_switch_on_eof )
				YY_NEW_FILE;
			    }
			}
			break;

		    case EOB_ACT_CONTINUE_SCAN:
			yy_c_buf_p = yytext + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_match;

		    case EOB_ACT_LAST_MATCH:
			yy_c_buf_p =
			    &yy_current_buffer->yy_ch_buf[yy_n_chars];

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yytext + YY_MORE_ADJ;
			goto yy_find_action;
		    }
		break;
		}

	    default:
#ifdef FLEX_DEBUG
		printf( "action # %d\n", yy_act );
#endif
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	    }
	}
    }


/* yy_get_next_buffer - try to read in a new buffer
 *
 * synopsis
 *     int yy_get_next_buffer();
 *     
 * returns a code representing an action
 *     EOB_ACT_LAST_MATCH - 
 *     EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *     EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer()

    {
    register YY_CHAR *dest = yy_current_buffer->yy_ch_buf;
    register YY_CHAR *source = yytext - 1; /* copy prev. char, too */
    register int number_to_move, i;
    int ret_val;

    if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
	YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

    /* try to read more data */

    /* first move last chars to start of buffer */
    number_to_move = yy_c_buf_p - yytext;

    for ( i = 0; i < number_to_move; ++i )
	*(dest++) = *(source++);

    if ( yy_current_buffer->yy_eof_status != EOF_NOT_SEEN )
	/* don't do the read, it's not guaranteed to return an EOF,
	 * just force an EOF
	 */
	yy_n_chars = 0;

    else
	{
	int num_to_read = yy_current_buffer->yy_buf_size - number_to_move - 1;

	if ( num_to_read > YY_READ_BUF_SIZE )
	    num_to_read = YY_READ_BUF_SIZE;

	else if ( num_to_read <= 0 )
	    YY_FATAL_ERROR( "fatal error - scanner input buffer overflow" );

	/* read in more data */
	YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
		  yy_n_chars, num_to_read );
	}

    if ( yy_n_chars == 0 )
	{
	if ( number_to_move == 1 )
	    {
	    ret_val = EOB_ACT_END_OF_FILE;
	    yy_current_buffer->yy_eof_status = EOF_DONE;
	    }

	else
	    {
	    ret_val = EOB_ACT_LAST_MATCH;
	    yy_current_buffer->yy_eof_status = EOF_PENDING;
	    }
	}

    else
	ret_val = EOB_ACT_CONTINUE_SCAN;

    yy_n_chars += number_to_move;
    yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
    yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

    /* yytext begins at the second character in yy_ch_buf; the first
     * character is the one which preceded it before reading in the latest
     * buffer; it needs to be kept around in case it's a newline, so
     * yy_get_previous_state() will have with '^' rules active
     */

    yytext = &yy_current_buffer->yy_ch_buf[1];

    return ( ret_val );
    }


/* yy_get_previous_state - get the state just before the EOB char was reached
 *
 * synopsis
 *     yy_state_type yy_get_previous_state();
 */

static yy_state_type yy_get_previous_state()

    {
    register yy_state_type yy_current_state;
    register YY_CHAR *yy_cp;

    yy_current_state = yy_start;

    for ( yy_cp = yytext + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
	{
	register YY_CHAR yy_c = (*yy_cp ? yy_ec[*yy_cp] : 1);
	if ( yy_accept[yy_current_state] )
	    {
	    yy_last_accepting_state = yy_current_state;
	    yy_last_accepting_cpos = yy_cp;
	    }
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	    {
	    yy_current_state = yy_def[yy_current_state];
	    }
	yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	}

    return ( yy_current_state );
    }


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *     next_state = yy_try_NUL_trans( current_state );
 */

#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( register yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
register yy_state_type yy_current_state;
#endif

    {
    register int yy_is_jam;
    register YY_CHAR *yy_cp = yy_c_buf_p;

    register YY_CHAR yy_c = 1;
    if ( yy_accept[yy_current_state] )
	{
	yy_last_accepting_state = yy_current_state;
	yy_last_accepting_cpos = yy_cp;
	}
    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	{
	yy_current_state = yy_def[yy_current_state];
	}
    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
    yy_is_jam = (yy_current_state == 184);

    return ( yy_is_jam ? 0 : yy_current_state );
    }


#ifdef YY_USE_PROTOS
static void yyunput( YY_CHAR c, register YY_CHAR *yy_bp )
#else
static void yyunput( c, yy_bp )
YY_CHAR c;
register YY_CHAR *yy_bp;
#endif

    {
    register YY_CHAR *yy_cp = yy_c_buf_p;

    /* undo effects of setting up yytext */
    *yy_cp = yy_hold_char;

    if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	{ /* need to shift things up to make room */
	register int number_to_move = yy_n_chars + 2; /* +2 for EOB chars */
	register YY_CHAR *dest =
	    &yy_current_buffer->yy_ch_buf[yy_current_buffer->yy_buf_size + 2];
	register YY_CHAR *source =
	    &yy_current_buffer->yy_ch_buf[number_to_move];

	while ( source > yy_current_buffer->yy_ch_buf )
	    *--dest = *--source;

	yy_cp += dest - source;
	yy_bp += dest - source;
	yy_n_chars = yy_current_buffer->yy_buf_size;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
	    YY_FATAL_ERROR( "flex scanner push-back overflow" );
	}

    if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
	yy_cp[-2] = '\n';

    *--yy_cp = c;

    /* note: the formal parameter *must* be called "yy_bp" for this
     *       macro to now work correctly
     */
    YY_DO_BEFORE_ACTION; /* set up yytext again */
    }


#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif

    {
    int c;
    YY_CHAR *yy_cp = yy_c_buf_p;

    *yy_cp = yy_hold_char;

    if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
	{
	/* yy_c_buf_p now points to the character we want to return.
	 * If this occurs *before* the EOB characters, then it's a
	 * valid NUL; if not, then we've hit the end of the buffer.
	 */
	if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
	    /* this was really a NUL */
	    *yy_c_buf_p = '\0';

	else
	    { /* need more input */
	    yytext = yy_c_buf_p;
	    ++yy_c_buf_p;

	    switch ( yy_get_next_buffer() )
		{
		case EOB_ACT_END_OF_FILE:
		    {
		    if ( yywrap() )
			{
			yy_c_buf_p = yytext + YY_MORE_ADJ;
			return ( EOF );
			}

		    YY_NEW_FILE;

#ifdef __cplusplus
		    return ( yyinput() );
#else
		    return ( input() );
#endif
		    }
		    break;

		case EOB_ACT_CONTINUE_SCAN:
		    yy_c_buf_p = yytext + YY_MORE_ADJ;
		    break;

		case EOB_ACT_LAST_MATCH:
#ifdef __cplusplus
		    YY_FATAL_ERROR( "unexpected last match in yyinput()" );
#else
		    YY_FATAL_ERROR( "unexpected last match in input()" );
#endif
		}
	    }
	}

    c = *yy_c_buf_p;
    yy_hold_char = *++yy_c_buf_p;

    return ( c );
    }


#ifdef YY_USE_PROTOS
void yyrestart( FILE *input_file )
#else
void yyrestart( input_file )
FILE *input_file;
#endif

    {
    yy_init_buffer( yy_current_buffer, input_file );
    yy_load_buffer_state();
    }


#ifdef YY_USE_PROTOS
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
#else
void yy_switch_to_buffer( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif

    {
    if ( yy_current_buffer == new_buffer )
	return;

    if ( yy_current_buffer )
	{
	/* flush out information for old buffer */
	*yy_c_buf_p = yy_hold_char;
	yy_current_buffer->yy_buf_pos = yy_c_buf_p;
	yy_current_buffer->yy_n_chars = yy_n_chars;
	}

    yy_current_buffer = new_buffer;
    yy_load_buffer_state();

    /* we don't actually know whether we did this switch during
     * EOF (yywrap()) processing, but the only time this flag
     * is looked at is after yywrap() is called, so it's safe
     * to go ahead and always set it.
     */
    yy_did_buffer_switch_on_eof = 1;
    }


#ifdef YY_USE_PROTOS
void yy_load_buffer_state( void )
#else
void yy_load_buffer_state()
#endif

    {
    yy_n_chars = yy_current_buffer->yy_n_chars;
    yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
    mtxFile = yy_current_buffer->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
    }


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif

    {
    YY_BUFFER_STATE b;

    b = (YY_BUFFER_STATE) malloc( sizeof( struct yy_buffer_state ) );

    if ( ! b )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    b->yy_buf_size = size;

    /* yy_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->yy_ch_buf = (YY_CHAR *) malloc( (unsigned) (b->yy_buf_size + 2) );

    if ( ! b->yy_ch_buf )
	YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

    yy_init_buffer( b, file );

    return ( b );
    }


#ifdef YY_USE_PROTOS
void yy_delete_buffer( YY_BUFFER_STATE b )
#else
void yy_delete_buffer( b )
YY_BUFFER_STATE b;
#endif

    {
    if ( b == yy_current_buffer )
	yy_current_buffer = (YY_BUFFER_STATE) 0;

    free( (char *) b->yy_ch_buf );
    free( (char *) b );
    }


#ifdef YY_USE_PROTOS
void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif

    {
    b->yy_input_file = file;

    /* we put in the '\n' and start reading from [1] so that an
     * initial match-at-newline will be true.
     */

    b->yy_ch_buf[0] = '\n';
    b->yy_n_chars = 1;

    /* we always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;
    b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;

    b->yy_buf_pos = &b->yy_ch_buf[1];

    b->yy_eof_status = EOF_NOT_SEEN;
    }
# line 98 "t2mf.fl"

