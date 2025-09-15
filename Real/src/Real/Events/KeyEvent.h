#pragma once

#include "Event.h"

#include <sstream>


namespace Real {

  class KeyEvent : public Event
  {
  public: 
    inline bool getKeyCode() const {return m_keyCode;}

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);  
  protected:
    KeyEvent(int keyCode) 
      : m_keyCode(keyCode) {}

    int m_keyCode;
  };

  class KeyPressedEvent : public KeyEvent 
  {
  public:
    KeyPressedEvent(int keyCode, int repeatCount) 
      : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

    inline int getRepeatCount() const {return m_repeatCount;}

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats";
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyPressed);
  private:
    int m_repeatCount;

  };

  class KeyReleasedEvent : public KeyEvent 
  {
    KeyReleasedEvent(int keyCode) 
      : KeyEvent(keyCode) {}
  
    std::string toString() const override 
    {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << m_keyCode;
      return ss.str();
    }
    
    EVENT_CLASS_TYPE(EventType::KeyReleased);
  };

}











