/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2; /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 8; /* snap pixel */
static const int showbar            = 0; /* 0 means no bar */
static const int topbar             = 0; /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenu_font[]      = "monospace:size=10";
static const char col_nord0[]       = "#2E3440";
static const char col_nord6[]       = "#ECEFF4";
static const char col_nord8[]       = "#88C0D0";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_nord6, col_nord0, col_nord0 },
	[SchemeSel]  = { col_nord0, col_nord8, col_nord0 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "><>",      NULL },
	{ "[]=",      tile },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]  = { "st",        NULL };
static const char *menucmd[]  = { "dmenu_run", NULL };
static const char *webcmd[]   = { "firefox",   NULL };
static const char *fmcmd[]    = { "thunar",    NULL };

static const char *scrotcmd[] = { "scrot.sh", NULL };

static const char *mediaplaycmd[] = { "playerctl", "play-pause", NULL };
static const char *medianextcmd[] = { "playerctl", "next",       NULL };
static const char *mediaprevcmd[] = { "playerctl", "previous",   NULL };

static const char *volupcmd[]   = { "pamixer", "-i", "5", NULL };
static const char *voldowncmd[] = { "pamixer", "-d", "5", NULL };
static const char *volmutecmd[] = { "pamixer", "-t",      NULL };


static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = menucmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = fmcmd   } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = webcmd  } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_c,      movecenter,     {0} },
	{ MODKEY,                       XK_b,      setmfact,       {.f = +0.05 } },
	{ MODKEY,                       XK_v,      setmfact,       {.f = -0.05 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ 0,        XF86XK_AudioRaiseVolume,       spawn,          {.v = volupcmd   } },
	{ 0,        XF86XK_AudioLowerVolume,       spawn,          {.v = voldowncmd } },
	{ 0,               XF86XK_AudioMute,       spawn,          {.v = volmutecmd } },
	{ 0,               XF86XK_AudioPlay,       spawn,          {.v = mediaplaycmd } },
	{ 0,               XF86XK_AudioNext,       spawn,          {.v = medianextcmd } },
	{ 0,               XF86XK_AudioPrev,       spawn,          {.v = mediaprevcmd } },
	{ 0,                       XK_Print,       spawn,          {.v = scrotcmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

