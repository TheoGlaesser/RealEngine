#pragma once

#include "Event.h"


namespace Real {

  class MouseMovedEvent : public Event 
  {
  public:
    MouseMovedEvent(double xPos, double yPos)
      : m_xPos(xPos), m_yPos(yPos) {}

    EVENT_CLASS_TYPE(EventType::MouseMoved);
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

    inline float getX() const {return m_xPos;}
    inline float getY() const {return m_yPos;}

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "MouseMovedEvent: (xPos: " << m_xPos << ", yPos: " << m_yPos << ")";
      return ss.str();
    }
          
  private:
    double m_xPos, m_yPos;
  };


  class MouseScrolledEvent : public Event
  {
  public:
    MouseScrolledEvent(double xOffset, double yOffset)
      : m_xOffset(xOffset), m_yOffset(yOffset) {}

    EVENT_CLASS_TYPE(EventType::MouseScrolled);
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

    inline float getX() const {return m_xOffset;}
    inline float getY() const {return m_yOffset;}

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "MouseScrolledEvent: (xOffset: " << m_xOffset << ", yOffset: " << m_yOffset << ")";
      return ss.str();
    }
          
  private:
    double m_xOffset, m_yOffset;
  };


  class MouseButtonEvent : public Event
  {
  public:
    MouseButtonEvent(int button)
      : m_button(button) {}

    inline int getMouseButton() const {return m_button;}

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
          
  private:
    int m_button;
  };

  class MouseButtonPressedEvent : public MouseButtonEvent
  {
  public: 
    MouseButtonPressedEvent(int button)
      : MouseButtonEvent(button) {}

    EVENT_CLASS_TYPE(EventType::MouseButtonPressed);

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseButtonPressedEvent: " << getMouseButton();
      return ss.str();
    }
  };

  
  class MouseButtonReleased : public MouseButtonEvent
  {
  public:
    MouseButtonReleased(int button)
      : MouseButtonEvent(button) {}

     EVENT_CLASS_TYPE(EventType::MouseButtonReleased);

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseButtonReleasedEvent: " << getMouseButton();
      return ss.str();
    }
  };

}
