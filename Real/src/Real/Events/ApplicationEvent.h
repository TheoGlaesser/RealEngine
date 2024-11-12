#pragma once

#include "Event.h"


namespace Real {

  class WindowResizeEvent : public Event 
  {
  public:
    WindowResizeEvent(unsigned int width, unsigned int height)
      : m_width(width), m_height(height) {}

    inline unsigned int getWidth() const {return m_width;}
    inline unsigned int getHeight() const {return m_height;}

    EVENT_CLASS_TYPE(EventType::WindowResize);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "WindowResizeEvent: " << m_width << ", " <<  m_height;
      return ss.str();
    }

  private:
    unsigned int m_width, m_height;
  };

  class WindowCloseEvent : public Event {
  public:
    WindowCloseEvent() {}

    EVENT_CLASS_TYPE(EventType::WindowClose);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };


  class AppTickEvent : public Event {
  public:
    AppTickEvent() {}

    EVENT_CLASS_TYPE(EventType::AppTick);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

  class AppUpdateEvent : public Event {
  public:
    AppUpdateEvent() {}

    EVENT_CLASS_TYPE(EventType::AppUpdate);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

  class AppRenderEvent : public Event {
  public:
    AppRenderEvent() {}

    EVENT_CLASS_TYPE(EventType::AppRender);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

}


