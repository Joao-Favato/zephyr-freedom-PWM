#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS1 5000
#define SLEEP_TIME_MS2 1000

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

#if DT_NODE_HAS_STATUS(LED1_NODE, okay)
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
#else
#error "Unsupported board: led1 devicetree alias is not defined"
#endif
#if DT_NODE_HAS_STATUS(LED2_NODE, okay)
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
#else
#error "Unsupported board: led2 devicetree alias is not defined"
#endif

typedef enum {
    STATE_GREEN,
    STATE_YELLOW,
    STATE_RED
} state_t;

void main(void)
{
    int ret;

    if (!gpio_is_ready_dt(&led0)) {
        printk("Error: LED device %s is not ready\n", led0.port->name);
        return;
    }

    ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
    ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
    ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_INACTIVE);
    
    if (ret < 0) {
        printk("Error %d: failed to configure LED pin\n", ret);
        return;
    }

    printk("LED blinking on %s pin %d\n", led0.port->name, led0.pin);
    printk("LED blinking on %s pin %d\n", led1.port->name, led1.pin);

    state_t state = STATE_GREEN;

    while (1) {
        switch(state){
        case STATE_GREEN:
            gpio_pin_set_dt(&led2, 0);
            gpio_pin_set_dt(&led0, 1);
            k_msleep(SLEEP_TIME_MS1);
            state = STATE_YELLOW;
            break;
        case STATE_YELLOW:
            gpio_pin_set_dt(&led2, 1);
            k_msleep(SLEEP_TIME_MS2);
            state = STATE_RED;
            break;
        case STATE_RED:
            gpio_pin_set_dt(&led0, 0);
            k_msleep(SLEEP_TIME_MS1);
            state = STATE_GREEN;
            break;
    }
    }
}