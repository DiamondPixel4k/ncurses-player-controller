#include <ncurses.h>
#include <unistd.h>
#include <string>

#define DELAY 0000

using namespace std;

void erase(int y, int x) {
	mvaddch(y,x,' ');
}


void setup() {
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, true);
	curs_set(FALSE);
}

int main(int argc, char *argv[]) {
	setup();
	int ch;
	int next;
	int y = 0, x = 0;
	int maxY = 0, maxX = 0;
	string player = "O";

	mvprintw(y, x, player.c_str());
	refresh();
	while(true) {
		getmaxyx(stdscr, maxY, maxX);
		ch = getch();
		next = 0;
		if(ch == KEY_LEFT) {
			next = x - 1;
			if(next < 0) {continue;}
			erase(y,x);
			x -= 1;
			mvprintw(y,x,player.c_str());
		}
		if(ch == KEY_RIGHT) {
			next = x + 1;
			if(next > maxX - 1) {continue;}
			erase(y,x);
			x += 1;
			mvprintw(y,x,player.c_str());
		}
		if(ch == KEY_DOWN) {
			next = y + 1;
			if(next > maxY - 1) {continue;}
			erase(y,x);
			y += 1;
			mvprintw(y,x,player.c_str());
		}
		if(ch == KEY_UP) {
			next = y - 1;
			if(next < 0) {continue;}
			erase(y,x);
			y -= 1;
			mvprintw(y,x,player.c_str());
		}
		refresh();
		usleep(DELAY);
	}
	endwin();

	return 0;
}
