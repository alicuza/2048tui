# include <ncurses.h>

# define MAX_WINDOW_NB 2

typedef struct s_pos
{
	uint16_t	x;
	uint16_t	y;
}	t_pos;

typedef struct s_dim
{
	uint16_t	h;
	uint16_t	w;
}	t_dim;

typedef struct s_window
{
	WINDOW	*ptr;
	t_pos	pos;
	t_dim	dim;
	t_color	fgcolor;
	t_color	bgcolor;
}	t_window;

typedef struct s_game
{
	uint32_t	board_size;
	char		*title[6];
	t_window	splash_win;
	t_window	menu_win;
	t_window	board_win;
}	t_game;

void	init_ncurses(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh(); //TODO: in the draw function?
}

void	init_splash()
{
	game->splash_win = newwin(0, 0, 0, 0);
	game->title[0] = "██████╗  ██████╗ ██╗  ██╗ █████╗-";
	game->title[1] = "╚════██╗██╔═████╗██║  ██║██╔══██╗";
	game->title[2] = " █████╔╝██║██╔██║███████║╚█████╔╝";
	game->title[3] = "██╔═══╝ ████╔╝██║╚════██║██╔══██╗";
	game->title[4] = "███████╗╚██████╔╝     ██║╚█████╔╝";
	game->title[5] = "╚══════╝ ╚═════╝      ╚═╝ ╚════╝-";
}

void	init_menu(t_game *game)
{
	game->menu_win = newwin(MENU_H, MENU_W, MENU_X, MENU_Y);
}

void	init_round(t_game *game, uint32_t board_size)
{
	game.board_size = board_size;
}

void	init_game(t_game *game)
{
	init_ncurses();
	memset(game, 0, sizeof(t_game)); //TODO: memset -> ft_memset
	init_splash();
	init_menu();
	init_round();
}
int	main(void)
{
	t_game	game;

	init_game(&game);
	init_round(&game);

	draw_board(BOARD_SIZE);
	WINDOW	*win[3];
	t_pos	pos[3];
	t_dim	dim[3];

	pos[0].x = 3;
	pos[0].y = 3;
	dim[0].h = 3;
	dim[0].w = 5;

	pos[1].x = 8;
	pos[1].y = 3;
	dim[1].h = 3;
	dim[1].w = 5;

	pos[2].x = 13;
	pos[2].y = 3;
	dim[2].h = 3;
	dim[2].w = 5;

	win[0] = newwin(dim[0].h, dim[0].w, pos[0].y, pos[0].x);
	box(win[0], 0, 0);
	wrefresh(win[0]);
	win[1] = newwin(dim[1].h, dim[1].w, pos[1].y, pos[1].x);
	box(win[1], 0, 0);
	wrefresh(win[1]);
	win[2] = newwin(dim[2].h, dim[2].w, pos[2].y, pos[2].x);
	box(win[2], 0, 0);
	wrefresh(win[2]);
	while (getch() != 'q')
		;
	endwin();

	return (0);
}
/*
	printw("Upper left corner "); addch(ACS_ULCORNER); printw("\n");
	printw("Lower left corner "); addch(ACS_LLCORNER); printw("\n");
	printw("Lower right corner "); addch(ACS_LRCORNER); printw("\n");
	printw("Tee pointing right "); addch(ACS_LTEE); printw("\n");
	printw("Tee pointing left "); addch(ACS_RTEE); printw("\n");
	printw("Tee pointing up "); addch(ACS_BTEE); printw("\n");
	printw("Tee pointing down "); addch(ACS_TTEE); printw("\n");
	printw("Horizontal line "); addch(ACS_HLINE); printw("\n");
	printw("Vertical line "); addch(ACS_VLINE); printw("\n");
	printw("Large Plus or cross over "); addch(ACS_PLUS); printw("\n");
	printw("Scan Line 1 "); addch(ACS_S1); printw("\n");
	printw("Scan Line 3 "); addch(ACS_S3); printw("\n");
	printw("Scan Line 7 "); addch(ACS_S7); printw("\n");
	printw("Scan Line 9 "); addch(ACS_S9); printw("\n");
	printw("Diamond "); addch(ACS_DIAMOND); printw("\n");
	printw("Checker board (stipple) "); addch(ACS_CKBOARD); printw("\n");
	printw("Degree Symbol "); addch(ACS_DEGREE); printw("\n");
	printw("Plus/Minus Symbol "); addch(ACS_PLMINUS); printw("\n");
	printw("Bullet "); addch(ACS_BULLET); printw("\n");
	printw("Arrow Pointing Left "); addch(ACS_LARROW); printw("\n");
	printw("Arrow Pointing Right "); addch(ACS_RARROW); printw("\n");
	printw("Arrow Pointing Down "); addch(ACS_DARROW); printw("\n");
	printw("Arrow Pointing Up "); addch(ACS_UARROW); printw("\n");
	printw("Board of squares "); addch(ACS_BOARD); printw("\n");
	printw("Lantern Symbol "); addch(ACS_LANTERN); printw("\n");
	printw("Solid Square Block "); addch(ACS_BLOCK); printw("\n");
	printw("Less/Equal sign "); addch(ACS_LEQUAL); printw("\n");
	printw("Greater/Equal sign "); addch(ACS_GEQUAL); printw("\n");
	printw("Pi "); addch(ACS_PI); printw("\n");
	printw("Not equal "); addch(ACS_NEQUAL); printw("\n");
	printw("UK pound sign "); addch(ACS_STERLING); printw("\n");
	refresh();
*/
