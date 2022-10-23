#include "rust-example.h"
#include <jsi/jsi.h>
#include "rawrust.h"

using namespace facebook::jsi;
using namespace std;

namespace rustExample {
    void install(Runtime & jsiRuntime) {
      auto addWrapper = Function::createFromHostFunction(
          jsiRuntime, PropNameID::forAscii(jsiRuntime, "addInRust"), 2,
          [](Runtime &runtime, const Value &thisValue, const Value *arguments,
             size_t count) -> Value {
            int x = arguments[0].getNumber();
            int y = arguments[1].getNumber();
            return Value(add(x, y));
          });

        jsiRuntime.global().setProperty(jsiRuntime, "addInRust", move(addWrapper));
    }
}
