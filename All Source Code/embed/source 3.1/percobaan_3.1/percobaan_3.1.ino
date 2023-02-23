#include <TaskScheduler.h>
// declare the function that we are going to use
void led_blink();
// create the Scheduler that will be in charge of managing the tasks
Scheduler runner;
// create the task indicating that it runs every 500 milliseconds,
// forever, and call the led_blink function
Task TaskBlinkLED(1000, TASK_FOREVER, &led_blink);
bool statusLED = false;
// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(9600);
// configure the internal led pin as output
pinMode(13, OUTPUT);
// add the task to the task scheduler
runner.addTask(TaskBlinkLED);
// activate the task
TaskBlinkLED.enable();
}
// the loop function runs over and over again forever
void loop() {
// It is necessary to run the runner on each loop
runner.execute();
}
void led_blink() {
statusLED = !statusLED;
digitalWrite(13, statusLED);
Serial.println((String)millis() + " - Led: " + (String)statusLED);
}
