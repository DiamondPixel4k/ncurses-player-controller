#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000

using namespace std;

void setup() {
	initscr();
	noecho();
	curs_set(FALSE);
}

int main(int argc, char *argv[]) {
	int x = 0, y = 0;
	int maxX = 0, maxY = 0;
	int nextX = 0;
	int direction = 1;

	setup();


	while(1) {
		getmaxyx(stdscr,maxY,maxX);

		clear();
		mvprintw(y,x,"o");
		refresh();

		usleep(DELAY);
		nextX = x + direction;

		if (nextX >= maxX || nextX < 0) {
			direction *= -1;
		}
		else {x += direction;}
	}

	endwin();

	return 0;
}
