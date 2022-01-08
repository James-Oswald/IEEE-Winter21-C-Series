

typedef struct TermSize{
    unsigned int width;
    unsigned int height;
} TermSize;

#ifdef _WIN64
#include<windows.h>

void termSize(TermSize* tsize)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    tsize->width = csbi.dwSize.X;
    tsize->height = csbi.dwSize.Y;
}

#elif __linux
#include<sys/ioctl.h>
void termSize(TermSize* tsize)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    tsize->width = w.ws_row;
    tsize->height = w.ws_col;
}
#endif

typedef struct Snake{
    unsigned int row;
    unsigned int col;
} Snake;

int main(){
    TermSize tsize;
    termSize(&tsize);
    Snake* snakes = (Snake*)malloc(10 * sizeof(Snake));
    while(1){
        system("clear");
        

        Sleep(1000);
    }
}