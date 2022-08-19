/*================================ include ==================================*/

#include "FreeRTOS.h"

#include <BoardImplementation.hpp>
#include <Task.hpp>
#include <Scheduler.hpp>

/*================================ define ===================================*/

#define GREEN_LED_TASK_PRIORITY             ( tskIDLE_PRIORITY + 0 )

#define GREEN_LED_TASK_STACK_SIZE           ( 128 )

/*================================ typedef ==================================*/

/*=============================== prototypes ================================*/

static void prvGreenLedTask(void *pvParameters);

/*=============================== variables =================================*/

static Task heartbeatTask{(const char *) "Green", GREEN_LED_TASK_STACK_SIZE, GREEN_LED_TASK_PRIORITY, prvGreenLedTask, nullptr};

/*================================= public ==================================*/

int main(void)
{
  /* Initialize the board */
  board.init();

  /* Start the scheduler */
  Scheduler::run();

  return 0;
}

/*================================ private ==================================*/

static void prvGreenLedTask(void *pvParameters)
{
  /* Forever */
  while (true) {
    /* Turn off green LED for 9999 ms */
    led_green.off();
    Scheduler::delay_ms(999);

    /* Turn on green LED for 1 ms */
    led_green.on();
    Scheduler::delay_ms(1);
  }
}
