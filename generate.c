#include "generateSine.c"

int main(void)
{
    buzzer_start();
    buzzer_set_freq(400);
    sleep(1);
    buzzer_set_freq(0);
    sleep(1);
    buzzer_set_freq(500);
    sleep(1);
    buzzer_set_freq(600);
    sleep(1);
    buzzer_set_freq(700);
    sleep(1);
    buzzer_beep(2000, 500);
    sleep(2);

    buzzer_stop();

    return 0;
}

