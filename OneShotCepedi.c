#include "pico/stdlib.h"

#define BTN_PIN 5

volatile uint8_t lampadas[3] = {11, 12, 13};
volatile uint8_t indice = 0;

void configurar_lampadas();
void configurar_botao();
void acender_lampadas();
int64_t desligar_proximo_callback(alarm_id_t id, void *user_data);

int main() {
    configurar_lampadas();
    configurar_botao();

    uint8_t tempo_debounce = 200;
    absolute_time_t tempo_botao = delayed_by_ms(get_absolute_time(), tempo_debounce);

    while (1) {
        if (time_reached(tempo_botao)) {
            if (!gpio_get(BTN_PIN) && !gpio_get(lampadas[2])) {
                acender_lampadas();
                add_alarm_in_ms(3000, desligar_proximo_callback, NULL, false);
            }
        }
        sleep_ms(10);
    }
}

void configurar_lampadas() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_init(lampadas[i]);
        gpio_set_dir(lampadas[i], GPIO_OUT);
    }
}

void configurar_botao() {
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);
}

void acender_lampadas() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(lampadas[i], 1);
    }
}

int64_t desligar_proximo_callback(alarm_id_t id, void *user_data) {
    gpio_put(lampadas[indice], 0);
    indice++;
    if (indice > 2) {
        indice = 0;
        return 0;
    }
    return 3000000;
}
