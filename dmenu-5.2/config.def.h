/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* default (nord) color names */
static const char col_nord0[] = "#2E3440";
static const char col_nord6[] = "#ECEFF4";
static const char col_nord8[] = "#88C0D0";

/* -b  option; if 0, dmenu appears at bottom */
static int topbar = 1;

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=10"
};

/* -p  option; prompt to the left of input field */
static const char *prompt = NULL; 

/* -nb,-nf,-sb,-sf options override default colors  */
static const char *colors[SchemeLast][2] = {
/*   scheme          fg         bg       */
	[SchemeNorm] = { col_nord6, col_nord0 },
	[SchemeSel]  = { col_nord0, col_nord8 },
	[SchemeOut]  = { "#000000", "#00ffff" },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/* Characters not considered part of a word while deleting words */
static const char worddelimiters[] = " "; /* example: " /?\"&[]" */

