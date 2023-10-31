#include <lib/helper/wasm3-debugger.hpp>
void wasm3_error_printer(const char *func, const char *msg)
{
  Serial.print("Fatal: ");
  Serial.print(func);
  Serial.print(" ");
  Serial.println(msg);
  return;
}
