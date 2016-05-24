#ifndef _DRAWTYPES_RAMP_HPP_
#define _DRAWTYPES_RAMP_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "drawtypes/icon.hpp"

namespace drawtypes
{
  class Ramp
  {
    protected:
      std::vector<std::unique_ptr<Icon>> icons;

    public:
      Ramp(){}
      Ramp(std::vector<std::unique_ptr<Icon>> icons);

      void add(std::unique_ptr<Icon> &&icon);
      std::unique_ptr<Icon> &get(int idx);
      std::unique_ptr<Icon> &get_by_percentage(float percentage);

      operator bool() {
        return this->icons.size() > 0;
      }
  };

  std::unique_ptr<Ramp> get_config_ramp(const std::string& module_name, const std::string& ramp_name = "ramp", bool required = true);
}

#endif