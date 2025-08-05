#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "ev-view.h"

void signal_handler_prev(int signum);
void signal_handler_next(int signum);
void __attribute__ ((constructor)) ev_signal_init(void);

void signal_handler_prev(int signum)
{
    printf("catch signal %d\n", signum);
    ev_view_pre_page_q();
}

void signal_handler_next(int signum)
{
    printf("catch signal %d\n", signum);
    ev_view_next_page_q();
}

void ev_signal_init()
{
    static int flag = 0;
    if (flag == 0) {
        signal(34, signal_handler_prev);
        signal(35, signal_handler_next);
        flag = 1;
    }
    return;
}