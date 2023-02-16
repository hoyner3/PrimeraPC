#include <iostream>
#include <ctime>
using namespace std;
int main() {
    time_t now = time(nullptr); // get current time
    tm* timeinfo = localtime(&now); // convert to local time

  cout << "Hora actual es : " << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << endl;
  return 0;
}