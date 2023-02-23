/**
* TaskScheduler Test
*
* Initially only tasks 1 and 2 are enabled
* Task1 runs every 2 seconds 10 times and then stops
* Task2 runs every 3 seconds indefinitely
* Task1 enables Task3 at its first run
* Task3 run every 5 seconds
* Task1 disables Task3 on its last iteration and changed Task2 to run every 1/2 seconds
* At the end Task2 is the only task running every 1/2 seconds
*/
#include <TaskScheduler.h>
// Callback methods prototypes
void t1Callback();
void t2Callback();
void t3Callback();
//Tasks
Task t4();//empty task
Task t1(2000, 10, &t1Callback);//task 1 runs every 2000ms 10 times only
Task t2(3000, TASK_FOREVER, &t2Callback);//task 2 runs every 3000ms forever
Task t3(5000, TASK_FOREVER, &t3Callback);//task 3 runs every 5000ms forever
Scheduler runner;
void t1Callback() {
Serial.print("t1: ");
Serial.println(millis());
if (t1.isFirstIteration()) {
runner.addTask(t3);//add task 3 to chain
t3.enable();//enable task 3
Serial.println("t1: enabled t3 and added to the chain");
}
if (t1.isLastIteration()) {
t3.disable();//disable task 3
runner.deleteTask(t3);

t2.setInterval(500);
Serial.println("t1: disable t3 and delete it from the chain. t2 interval set to 500");
}
}
void t2Callback() {
Serial.print("t2: ");
Serial.println(millis());
}
void t3Callback() {
Serial.print("t3: ");
Serial.println(millis());
}
void setup () {
Serial.begin(115200);
Serial.println("Scheduler TEST");
runner.init();
Serial.println("Initialized scheduler");
runner.addTask(t1);//add task 1 to chain
Serial.println("added t1");
runner.addTask(t2);//add task 2 to chain
Serial.println("added t2");
delay(5000);
t1.enable();//enable task 1
Serial.println("Enabled t1");
t2.enable();//enable task 2
Serial.println("Enabled t2");
}
void loop () {
runner.execute();//execute task scheduler
}
