#ifndef LISTHOOKEDCONSUMER_HPP
#define LISTHOOKEDCONSUMER_HPP

#include <IOKit/hidsystem/IOHIKeyboard.h>

#include "ListHookedDevice.hpp"

class Params_KeyboardSpecialEventCallback;

namespace org_pqrs_Karabiner {
  class ListHookedConsumer : public ListHookedDevice {
  public:
    class Item : public ListHookedDevice::Item {
    public:
      Item(IOHIDevice* p);
      ~Item(void);

      bool isReplaced(void) const { return orig_keyboardSpecialEventAction_ != NULL; }

      void apply(const Params_KeyboardSpecialEventCallback& params);
      void disableNumLock(void);

    private:
      KeyboardSpecialEventCallback orig_keyboardSpecialEventAction_;
      OSObject* orig_keyboardSpecialEventTarget_;

      bool refresh(void);

      /** return true if event action is replaced. */
      bool replaceEventAction(void);
      /** return true if event action is replaced. */
      bool restoreEventAction(void);
    };

    static ListHookedConsumer& instance(void);

    bool apply(const Params_KeyboardSpecialEventCallback& params);
    void disableNumLock(void);
  };
}

#endif
